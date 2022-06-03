
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

//타이머를 만든다
BlynkTimer timer;

//타이머가 해야할일을 정의한다
void myTimerEvent()
{
  //아두이노의 현재 시간값을 가상핀 0번에 전송한다
  Blynk.virtualWrite(V0, millis() / 1000);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  if(pinValue == 0){
    Serial.println("스위치가 OFF상태가 되었다!");
  }else if(pinValue == 1){
    Serial.println("스위치가 ON상태가 되었다!");
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  //타이머가 1초에 한번마다 해야할일을 수행한다!
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
