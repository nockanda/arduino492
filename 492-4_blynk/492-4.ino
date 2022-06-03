
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLXGIsfAKE"
#define BLYNK_DEVICE_NAME "nockanda"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <ESP8266WiFi.h>
#include <espnow.h>

byte board[] = {0x68,0xC6,0x3A,0x9D,0x68,0x9F};

unsigned long t = 0;

struct Nockanda{
  float temp;
  float humi;
};

Nockanda mydata;

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  esp_now_send(board, (uint8_t *) &pinValue, sizeof(pinValue));
}

BLYNK_CONNECTED() { 
  WiFi.mode(WIFI_STA); //제일 처음 할일! 와이파이모드를 스테이션 모드로!

  //ESPNOW의 기능을 활성화한다!
  if (esp_now_init() != 0) {
    //ESP NOW 시작 실패!
    Serial.println("ESPNOW 실패!");
    return;
  }else{
     //ESP NOW 시작 성공!
     Serial.println("ESPNOW 성공!");
  }

  //지금 이보드의 역할은 주고 받는것을 다하겠다!
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  //나의 슬레이브를 등록해야겠다!
  esp_now_add_peer(board, ESP_NOW_ROLE_COMBO, 1, NULL, 0);//뒤에 2개는 ID, PW

  //송신완료 콜백함수 등록
  esp_now_register_send_cb(OnDataSent);

  //수신완료 콜백 함수 등록
  esp_now_register_recv_cb(OnDataRecv);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  
}

void loop() {
  BlynkEdgent.run();
}

//송신콜백함수 원형:
void OnDataSent(uint8_t *mac, uint8_t status) {
   //status가 0일때 송신 완료!
   if(status == 0){
      Serial.println("성공적으로 송신했음!");
   }else{
      Serial.println("송신 실패!!");
   }
}


//수신콜백함수 원형:
void OnDataRecv(uint8_t * mac, uint8_t * data, uint8_t len) {
  memcpy(&mydata,data,sizeof(mydata));
  Blynk.virtualWrite(V0, mydata.temp);
  Blynk.virtualWrite(V1, mydata.humi);
  Serial.print("온도=");
  Serial.print(mydata.temp);
  Serial.print("'C, 습도=");
  Serial.print(mydata.humi);
  Serial.println("%");
}
