#include <WiFi.h>
#include <FirebaseESP32.h>

//Crie duas variaveis, uma para o nome da sua internet, e outra para a respectiva senha
const char* usuario = "Nome da rede";
const char* senha = "Sua senha do WI-Fi";

float temperatura;

#define Host "Host firebase"
#define Senha_Fire "Senha Firebase"


void setup() 
{
  
  //Inicialize a serial em 11520 de BaudRate
  Serial.begin(115200);
  
  //Inicializa a conexão com a internet com a rede e a senha
  WiFi.begin(usuario, senha);

  //Enquanto o status do WIFI for diferente de conectado, escreva na serial "Conectando ao WIFI..."
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Conectando ao WIFI..");
  }

  //Escreva na serial que o WIFI está conectado
  Serial.println("WIFI Conectado");  

  Firebase.begin(Host, Senha_Fire); 
}

void loop() 
{
  float min = 10;
  float max = 60;
  temperatura = random(100*min, 100*max);
  temperatura = temperatura/100;

  Firebase.setFloat("temp", temperatura);
   if (Firebase.failed()) { 
     Serial.print("setting /number failed:"); 
     Serial.println(Firebase.error());   
     return; 
   }else{
  Serial.println(temperatura);
  delay(2000).
   }
}
