#define smPin 34
#define onboardLED 2
#define relayPin 13
int smValue;
int smLimit = 1500;
int delayTime = 2000;
void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  Serial.begin(115200);
  pinMode(onboardLED,OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
smValue = 4095 - analogRead(smPin);
Serial.print("Soil Moisture = ");
Serial.println(smValue);

if (smValue < smLimit){
digitalWrite(relayPin,HIGH);
Serial.println("Motor turned ON");
digitalWrite(onboardLED,HIGH);
}
else{
digitalWrite(relayPin,LOW);
Serial.println("Motor turned OFF");
digitalWrite(onboardLED,LOW);
}

delay(delayTime);


}
