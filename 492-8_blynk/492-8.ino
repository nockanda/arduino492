
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
#include "DHT.h"
#define DHTPIN D1 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

BLYNK_CONNECTED() {
  //데이터를 클라우드로 전송한다!
  Blynk.sendInternal("utc", "iso"); 
}

BLYNK_WRITE(InternalPinUTC) {
  String cmd = param[0].asStr();
  if (cmd == "iso") {
    //시간값을 측정한다!
    String iso_time = param[1].asStr();
    Serial.print("ISO-8601 time:   "); Serial.println(iso_time);
    Blynk.virtualWrite(V2, iso_time); //V2
     
    Serial.println("센서데이터를 전송합니다!");
    float h = dht.readHumidity(); //습도(V0)
    float t = dht.readTemperature(); //온도(V1)
    Blynk.virtualWrite(V0, h); //un-block
    Blynk.virtualWrite(V1, t); //un-block
    
    //딥슬립한다!
    Serial.println("10초간 딥슬립하겠습니다!!");
    ESP.deepSleep(10e6);
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  dht.begin();
  //Blynk서버와 연결!
  BlynkEdgent.begin(); //block
}

void loop() {
  BlynkEdgent.run();
}
