//speed value is 0-255
//delay in miliseconds

//left motor definitions
#define INT1 6
#define INT2 9

//right motor definitions
#define INT3 10
#define INT4 11

//ultrasonic sensor definitions
#define trig 4
#define echo 3

float time = 0.0;
float distance = 0.0;

//functions
void moveForward() {
  //left motor
  digitalWrite(INT1, HIGH);
  digitalWrite(INT2, LOW);

  //right motor
  digitalWrite(INT3, HIGH);
  digitalWrite(INT4, LOW);

}

void forwardSpeed(int speed) {
  //left motor
  analogWrite(INT1, 0);
  analogWrite (INT2, speed - 25); // -25

  //right motor
  analogWrite(INT3, speed + 1);
  analogWrite(INT4, 0);

}

void turnLeft(int speed){
  //left motor
  analogWrite(INT2, 0);
  analogWrite(INT1, speed - 25); // - 25

  //right motor
  analogWrite(INT3, speed + 1);
  analogWrite(INT4, 0);

}

void stopMotor() {
  //left motor
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, LOW);

  //right motor
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, LOW);

}

void setup() {
  // put your setup code here, to run once:
  //left motor intialization
  pinMode(INT1, OUTPUT);
  pinMode(INT2, OUTPUT);

  //right motor intialization
  pinMode(INT3, OUTPUT);
  pinMode(INT4, OUTPUT);

  //ultrasonic sensor intialization
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //test code 1 run
  /*
  forwardSpeed(110);
  delay(2000);
  stopMotor();
  delay(500);
  turnLeft(110);
  delay(250);
  stopMotor();
  delay(500); */

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);

  distance = time * 0.0343 / 2;

  if (distance <= 8) { 
    turnLeft(110);
    delay(620);
    stopMotor();
    delay(50);

  }

  else {
    forwardSpeed(80);
    delay(10);

  }

}
