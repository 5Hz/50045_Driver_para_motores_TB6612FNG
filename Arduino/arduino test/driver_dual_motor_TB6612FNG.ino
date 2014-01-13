/*
http://www.5hz-electronica.com
Ejemplo que muestra el funcionamiento del TB6612FNG

*/



int STBY = 10; //standby

//Motor A
int PWMA = 3; //control de velocidad pin 3 arduino
int AIN1 = 9; //Dirección pin 9 arduino
int AIN2 = 8; //Direccción  pin 8 arduino

//Motor B
int PWMB = 5; //control del velocidad 
int BIN1 = 11; //Dirección
int BIN2 = 12; //Dirección

void setup(){
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop(){
  move(1, 255, 1); //motor 1, velocidad máxima, izquierda
  move(2, 255, 1); //motor 2, velocidad máxima, izquierda

  delay(1000); //retardo de 1 seg
  stop(); //stop
  delay(250); //retardo de 250 mseg

  move(1, 128, 0); //motor 1, velocidad media, derecha
  move(2, 128, 0); //motor 2, velocidad media, derecha

  delay(50);
  stop();
  delay(10);
}

void move(int motor, int speed, int direction){
//Mueve el motor asignado a la velocidad y dirección dada
//motor: 0 para B y 1 para A
//velocidad: 0 es detenido, y 255 es máxima velocidad
//dirección: 0 es un sentido y 1 el sentido contrario :p

  digitalWrite(STBY, HIGH); //desabilita el standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){
//activa standby  
  digitalWrite(STBY, LOW);
}
