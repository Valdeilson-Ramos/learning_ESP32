//programa que faz o LED interno da placa aumentar o brilho de forma gradativa
int freq = 5000;
int ledChannel = 0;
int resolution = 7;

void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
}


void loop() {
  ledcWrite(ledChannel, 25);
  delay(2000);
  ledcWrite(ledChannel, 50);
  delay(2000);            
  ledcWrite(ledChannel, 75);
  delay(2000);         
  ledcWrite(ledChannel, 100);
  delay(2000);
}
