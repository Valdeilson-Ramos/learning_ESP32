// conectar o esp32 a internet via Wi-Fi
#include <WiFi.h>

const char* usuario = "nome da rede";
const char* senha = "senha da rede";

void setup() {
  Serial.begin(115200);
  WiFi.begin(usuario, senha);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("conectando ao WiFi..");
    }
    Serial.println("conectado ao WiFi!");
 
}

void loop() {
  

}
