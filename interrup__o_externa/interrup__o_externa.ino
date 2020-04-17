/*Cria um código por meio de interrupção que seja capaz de detectar o apertar de um botão, e daí mantenha um led ligado por 2 segundos*/

  #define botao 2
  #define Led 4

  volatile int sinal = 0;

  portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

  void IRAM_ATTR interrupcao()
  {
    portENTER_CRITICAL_ISR(&mux);
    sinal++;
    portEXIT_CRITICAL_ISR(&mux);
  }


void setup() 
{

  pinMode(botao, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(botao), interrupcao, RISING);
  
  digitalWrite(Led, LOW);  
}

void loop() 
{
  if(sinal>0)
  {
    portENTER_CRITICAL_ISR(&mux);
    sinal = 0;
    portEXIT_CRITICAL_ISR(&mux);
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Led, LOW);
  } 

}
