#include "FirebaseESP32.h"
#define FIREBASE_HOST "https://sensor-f47ac-default-rtdb.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "jzGMKue4IKv9u0cV9yBA9vpdi3iChdbK9WWFaPjS"
#define WIFI_SSID "GLWC-1_2.4G"
#define WIFI_PASSWORD "griet@66788"

#define onboardLED 2
//Define Firebase Data object
FirebaseData firebaseData;

#include <Wire.h>
#include "SSD1306.h" 
 
SSD1306  display(0x3c, 21, 22);


// defines pins numbers
const int trigPin = 25;
const int echoPin = 26;

// defines variables
long duration;
int distance;
int delayTime = 2000;

void setup() {

  pinMode(onboardLED,OUTPUT);
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication

 //Connecting to Wi-Fi network
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

 display.init();
 display.setFont(ArialMT_Plain_16);
  }



void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Firebase.setInt(firebaseData,"IOTLAB/Range_Meter/Range",distance);

  display.clear();
  String myString = "";
  myString.concat(distance);
  myString.concat(" cm");
  display.drawString(0,0,myString);
  display.display();
delay(delayTime);

if(distance>10)
{
   digitalWrite(onboardLED,LOW);
}
  else
  {
    digitalWrite(onboardLED,HIGH);
 
}

}




