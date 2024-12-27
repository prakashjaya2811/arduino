#include <WiFi.h>
#include "FirebaseESP32.h"
#define FIREBASE_HOST "https://sensor-f47ac-default-rtdb.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "jzGMKue4IKv9u0cV9yBA9vpdi3iChdbK9WWFaPjS"
#define WIFI_SSID "GLWC-1_2.4G"
#define WIFI_PASSWORD "griet@66788"

#define magSW 16

//Define Firebase Data object
FirebaseData firebaseData;


void setup() {

  pinMode(magSW,INPUT_PULLUP);
Serial.begin(115200);


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
  String sw_status;
  // put your main code here, to run repeatedly:
  
  sw_status = digitalRead(magSW);
  if (sw_status)
  Serial.println("Switch open");
  else
  Serial.println("Switch closed");
  Firebase.setString(firebaseData,"IOTLAB/MAG_SWITCH",String(sw_status));
 
 delay(1000);
}   


