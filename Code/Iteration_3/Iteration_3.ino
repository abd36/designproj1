#include <Servo.h>

Servo servo;

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;

int funnel = 118;
int hole = 28;
int colour = 69;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(hole);

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

    int r = 0;
    int g = 0;
    int b = 0;

    for (int i = 0; i < 10; i++) {
  
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
      r += R;
      
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
      g += G;
      
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
      b += B;

    }

    Serial.print("R average= ");//printing name
    Serial.print(r/10);//printing RED color frequency

    Serial.print("      G average = ");//printing name
    Serial.print(g/10);//printing RED color frequency

    Serial.print("      B average= ");//printing name
    Serial.print(b/10);//printing RED color frequency

    delay(3000);

    
  
}
