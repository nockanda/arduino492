
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

BLYNK_CONNECTED() {
  //데이터를 클라우드로 전송한다!
  Serial.println("센서데이터를 전송합니다!");
  Blynk.virtualWrite(V0, 123); //un-block
  //딥슬립한다!
  Serial.println("10초간 딥슬립하겠습니다!!");
  ESP.deepSleep(10e6);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  //Blynk서버와 연결!
  BlynkEdgent.begin(); //block
}

void loop() {
  BlynkEdgent.run();
}
