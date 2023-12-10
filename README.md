
# Sensor-HC-SR04-e-Leds-alternando

Sem dúvidas meu projeto que me deu mais trabalho até agora, nem tanto pelo Hardware ou pelo código em si, a coisa que me deu mais trabalho foi conectar a biblioteca "Ultrasonic", pois foi minha primeira conexão com uma lib em C++ externa, sem ter um código de "exemplo" para facilitar.

## Desafios

Acredito que meus principais desafios nesse projeto foram:
- Entender os pinos do sensor.
- Utilizar a lib.
- Trabalhar com as distâncias.
## Aprendizados

Por final aprendi algumas coisas interessantes como: 
### Iniciando a lib

```c++
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
```


### Configuração Inicial
```c++
void setup(){
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}
```

### Função para receber a distância detectada
```c+++
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
``` 

### Função para converter a distância para Int e determinar qual led ligar.
#### O código funciona da seguinte forma:
##### resultInt <= 5cm: Led Vermelho
####
##### resultInt > 5cm && resultInt < 10cm: Led Amarelo
####
##### resultInt >= 10cm && resultInt < 15cm: Led Verde
####
##### resultInt >= 15cm: Led Azul
####
```c++
void loop(){
    
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"

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
  
  Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(result); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL
  
}
```

## Adicional 
Para os interessados, deixei a lib acima, o nome está como [Ultrasonic.zip](https://github.com/Victor-Lis/Sensor-HC-SR04-e-Leds-alternando/blob/main/Ultrasonic.zip)
## Resultado

[Ver vídeo do projeto funcionando!](https://youtube.com/shorts/X1GySaBlLOs)
## Autores

- [@Victor-Lis](https://github.com/Victor-Lis)
- [@Karlos-Eduardo (Amigo que acabei ensinando e ajudando durante projeto)](https://github.com/ImpressoraTelepatica)

## Agradecimentos
Devo meus agradecimentos a minha professora [Kátia Fushita](https://www.linkedin.com/in/katia-fushita-180522160/), que foi quem realmente me fez entender o uso dessa biblioteca e desse sensor, além de outros inúmeros projetos que vem me ajudando.
