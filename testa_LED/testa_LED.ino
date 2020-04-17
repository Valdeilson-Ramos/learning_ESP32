#define LED 2 //atribuindo o LED embarcado na placa

void setup() {
  pinMode(LED, OUTPUT); //definindo o LED embarcado como saida

}

void loop() {
  digitalWrite(LED, HIGH); //setando o valor da saida para nivel alto (LED aceso)

}
