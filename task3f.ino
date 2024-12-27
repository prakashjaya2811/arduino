#define magSW 16
void setup() 
{
  pinMode(magSW,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() 
{
  int sw_status;
  sw_status = digitalRead(magSW);
  if (sw_status)
  Serial.println("switch open");
  else
  Serial.println("switch close");
delay(100000);
}

