#define FIREBASE_HOST "https://sensor-f47ac-default-rtdb.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "jzGMKue4IKv9u0cV9yBA9vpdi3iChdbK9WWFaPjS"
#define WIFI_SSID "GLWC-1_2.4G"
#define WIFI_PASSWORD "griet@66788"
#include <Wire.h>
#include "SSD1306.h" 
#include "FirebaseESP32.h"
FirebaseData firebaseData;
SSD1306  display(0x3c, 21, 22);
