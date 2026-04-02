#include <Servo.h> //Se usa la libreria servo.h para el uso de los svenvosfvkfvkf

int trigPinI = 12; 
int echoPinI = 13;

int trigPinD = A0;//nos quedamos sin pines digitales
const int echoPinD = A1;

const int trigPinC = A2;
const int echoPinC = A3;

Servo miServo; //instanciamos miServo

int pinServo = 3; 

int distanciaLimite = 20;

long distanciaDerecha = 0; //el valor a manejar es grande o largo
long distanciaCentro = 0;
long distanciaIzquierda = 0;



void setup() {
  pinMode(trigPinI, OUTPUT);
  pinMode(echoPinI, INPUT);
  
  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);

  pinMode(trigPinC, OUTPUT);
  pinMode(echoPinC, INPUT);

  miServo.attach(pinServo);
  miServo.write(90);

  Serial.begin(115200);
}

void loop() {

  // Medir distancias (rápido)
  distanciaDerecha = medirDistancia(trigPinD, echoPinD);
  distanciaCentro = medirDistancia(trigPinC, echoPinC);
  distanciaIzquierda = medirDistancia(trigPinI, echoPinI);

  Serial.print("Centro: ");
  Serial.println(distanciaCentro);

  if (distanciaCentro < 20 && distanciaCentro > 5) {
    miServo.write(0);
    delay(2000);
    miServo.write(70);
   // delay(5000);
  }

  delay(5); //
}


// Función optimizada
long medirDistancia(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH, 30000);

  // Si no hay lectura válida
  if (duracion == 0) {
    return 0;
  }

  long distancia = duracion * 0.034 / 2;
  return distancia;

}
