#define relayPin 13
void setup()
{
  pinMode(relayPin,OUTPUT);
}
void loop()
{
  digitalWrite(relayPin,HIGH);
  delay(10000);
  digitalWrite(relayPin,LOW);
  delay(10000);
}

