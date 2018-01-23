#include <Servo.h>

Servo servo;
Servo servo2;

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
int frequency = 0;
int color=0;

int funnel = 99;
int hole = 10;
int colour = 48;

int straightLine = 52;
int woodBox = 80;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  servo2.attach(9);
  servo.write(funnel);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);

}

void loop() { 
  // put your main code here, to run repeatedly:

  //servo.write(funnel);
  //servo.write(170);
  delay(3000);

  servo2.write(woodBox);
  //servo.write(170);
  delay(3000);

  /*servo.write(hole);
  delay(1000);
  servo.write(funnel);
  delay(1000);*/

  
  /*for (int i = funnel; i >= colour; i--) {
    servo.write(i);
    delay(20);
  }
  delay(3000);*/


  /*for (int i = 0; i < 20; i++) {
    // Setting red filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    int R = frequency;
    // Printing the value on the serial monitor
    Serial.print("R= ");//printing name
    Serial.print(frequency);//printing RED color frequency
    Serial.print("  ");
    delay(10);
    
    // Setting Green filtered photodiodes to be read
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    int G = frequency;
    // Printing the value on the serial monitor
    Serial.print("G= ");//printing name
    Serial.print(frequency);//printing GREEN color frequency
    Serial.print("  ");
    delay(10);
    
    // Setting Blue filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    int B = frequency;
    // Printing the value on the serial monitor
    Serial.print("B= ");//printing name
    Serial.print(frequency);//printing BLUE color frequency
    Serial.println("  ");
    delay(10);
  }*/
  
  
  /*for (int i = colour; i >= hole; i--) {
    servo.write(i);
    delay(20);
  }
  for (int i = hole; i <= funnel; i++) {
    servo.write(i);
    delay(20);
  }*/
  
  
  
  

}

/*int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing GREEN color frequency
  Serial.print("  ");
  delay(50);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing BLUE color frequency
  Serial.println("  ");
  delay(50);

  return 0;
}*/
