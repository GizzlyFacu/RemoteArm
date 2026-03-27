#include <WiFi.h>
#include <functional>
#include "src/commandprocessor.h"
#include "src/brazovirtual.h"
#include "src/esp32actuator.h"

const char* ssid = "";
const char* password = "";
WiFiServer server(1234);

const int ledPin = 2;
CommandProcessor cmd;
BrazoVirtual brazo;
Esp32Actuator esp32;

void setup() {
  //The esp32 will do something(in this case "set an angle in a hypothetical arm bone") when a command is sent.
  std::function<void()> subscriberHighBoneESP=[&brazo,&esp32](){
        esp32.setAngleHighBone(brazo.get("H"));
  };
  //The "Virtual Arm" that "lives" inside the esp32 will notify esp32actuator when something changes.
  brazo.subscribe(subscriberHighBoneESP);
  //CommandProcessor "cmd" is the manager in charge of "understand" an "send" the commands to BrazoVirtual brazo.
  cmd.setBrazo(brazo);

  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Cliente conectado");

    String mensaje = "";

    while (client.connected()) {
      digitalWrite(ledPin, HIGH);

      if (client.available()) {
        char c = client.read();
        
        // when the message is finished \n
        if (c == '\n') {
          // Full mesagge:
          Serial.print("Mensaje completo: ");
          Serial.println(mensaje);
          
          // Here I can process the message
          std::string mesanjeStdString = mensaje.c_str();
          cmd.sendMessage(mesanjeStdString);
          mensaje = "";

          client.print("OK\n");  // Send respone to my client.
        } 
        else {
          mensaje += c;  // packing the last letters in mensaje
        }
      }
    }

    client.stop();
    Serial.println("Cliente desconectado");
    digitalWrite(ledPin, LOW);
  }
}
//Why the comments are in english and the variables in spanish haha lol.
