#include <WiFi.h>
#include "FirebaseESP32.h"
#define FIREBASE_HOST "https://sensor-f47ac-default-rtdb.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "jzGMKue4IKv9u0cV9yBA9vpdi3iChdbK9WWFaPjS"
#define WIFI_SSID "GLWC-1_2.4G"
#define WIFI_PASSWORD "griet@66788"
//Define Firebase Data object
FirebaseData firebaseData;

float val = 0.0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void loop() {
  // put your main code here, to run repeatedly:
   Firebase.setFloat(firebaseData,"IOTLAB/My_App/Sensor_Value",val);
   val = val + 1.54;
   if(val > 10.0) val = 0.0;
   delay(1000);
}   
