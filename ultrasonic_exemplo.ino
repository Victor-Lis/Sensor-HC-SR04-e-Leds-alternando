#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO

const int echoPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
const int ledVermelho = 11; //PINO LED VERMELHO
const int ledAzul = 2; //PINO LED VERDE
const int ledAmarelo = 10; //PINO LED AMARELO
const int ledVerde = 12; //PINO LED VERDE

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO ARDUINO

int distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup(){
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL

   pinMode(ledVermelho, OUTPUT);
   pinMode(ledAzul, OUTPUT);
   pinMode(ledAmarelo, OUTPUT);
   pinMode(ledVerde, OUTPUT);
}

void loop(){

  int resultInt = result.toInt();

  if(resultInt <= 5){

    digitalWrite(ledVermelho, HIGH);
  
  }else{

    digitalWrite(ledVermelho, LOW);
    
  }

  if(resultInt > 5 && resultInt < 10){

      digitalWrite(ledAmarelo, HIGH);   
  
  }else{
    
      digitalWrite(ledAmarelo, LOW);  
    
  }

  if(resultInt >= 10 && resultInt < 15){

     digitalWrite(ledVerde, HIGH);
  
  }else{
    
     digitalWrite(ledVerde, LOW);  
  
  }

  if(resultInt >= 15){

     digitalWrite(ledAzul, HIGH);
  
  }else{
    
     digitalWrite(ledAzul, LOW);  
  
  }
  
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"
  Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(result); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL
  
}

//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04(){
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
    delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
    //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
    //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
    //NA VARIAVEL "distancia"
    distancia = (ultrasonic.Ranging(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
    result = String(distancia); //VARIÁVEL GLOBAL DO TIPO STRING RECEBE A DISTÂNCIA(CONVERTIDO DE INTEIRO PARA STRING)
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
 }
