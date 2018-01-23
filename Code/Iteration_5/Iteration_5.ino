#include <Servo.h>  //Servo library is recquired to use Servo functions

//Creating Servo objects
Servo servo;
Servo servo2;

//Define pins on the Arduino in terms of the pins on the colour sensor
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

int frequency = 0;
int color=0;

int funnel = 99;  //Calibrated to this angle
int hole = 10;  //Calibrated to this angle
int colour = 48;  //Calibrated to this angle

int straightLine = 52;  //Calibrated to this angle
int marbleBox = 20; //Calibrated to this angle
int woodBox = 80; //Calibrated to this angle

void setup() {
  // put your setup code here, to run once:

  //Signals to Servos coming from pins 8 and 9
  servo.attach(8);
  servo2.attach(9);

  //Start seperating mechanism at the funnel
  servo.write(funnel);
  //Start the ramp at the default position (parallel to the static ramp)
  servo2.write(straightLine);
  
  //Signals to the colour sensor coming from pins 2 to 5
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  //RGB values from the colour sensor going to pin 6
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);

}

void loop() { 
  // put your main code here, to run repeatedly:

  while (true) {  //Machine components keep looping indefinitely
    delay(2000);

    //Move the quadrant from the funnel, to the colour sensor, at 30ms/θ°
    for (int i = funnel; i >= colour; i--) {
      servo.write(i);
      delay(30);
    }
  
    //Initialise sums of RGB values at 0
    int rSum = 0;
    int gSum = 0;
    int bSum = 0;
  
    for (int i = 0; i < 800; i++) { //Read RGB 800 times
  
      //Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      //Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int R = frequency;
      
      //Legacy code used to read every R reading
      /*
      //Printing the value on the serial monitor
      Serial.print("R= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.print("  ");
      */

      //Adding all the R values to rSum
      rSum += R;
      
      //Setting Green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      //Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int G = frequency;

      //Legacy code used to read every G reading
      /*
      //Printing the value on the serial monitor
      Serial.print("G= ");//printing name
      Serial.print(frequency);//printing GREEN color frequency
      Serial.print("  ");
      */

      //Adding all the G values to gSum
      gSum += G;
      
      //Setting Blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      //Reading the output frequency
      frequency = pulseIn(sensorOut, LOW);
      int B = frequency;
      
      //Legacy code used to read every B reading
      /*
      //Printing the value on the serial monitor
      Serial.print("B= ");//printing name
      Serial.print(frequency);//printing BLUE color frequency
      Serial.print("  ");
      */

      //Adding all the B values to bSum
      bSum += B;
  
    }

    //Dviding all the rgbSUMS by 800 to get the average RGB values
    float rAverage = rSum/800;
    float gAverage = gSum/800;
    float bAverage = bSum/800;
  
    Serial.print("R average= ");//printing name
    Serial.print(rAverage);//printing RED color frequency
  
    Serial.print("      G average = ");//printing name
    Serial.print(gAverage);//printing RED color frequency
  
    Serial.print("      B average= ");//printing name
    Serial.print(bAverage);//printing RED color frequency
    Serial.print("\n");
    Serial.print("\n");


    //Testing showed that unique to marbles, RGB values would all be negative
    //Some leeway given, in case sensor reads a very low positive value
    if (rAverage < 3 && gAverage < 3 && bAverage < 3) {
      servo2.write(marbleBox);  //Ramp will rotate and point to marbles box
    }

    //Testing showed that only wooden and pink gum balls have negative RB values
    //However, R values for the pink gum balls would always be below -15, and above -15 for the wooden balls
    //Again, soom leeway is given to account for extraneous variables
    if (rAverage < 3 && rAverage > -15 && bAverage < 3 && gAverage > 0) {
      servo2.write(woodBox);  //Ramp will rotate and point to the woob balls box
    }
    

    //Move the quadrant from the colour sensor, to the ramp entrance, at 30ms/θ°
    for (int i = colour; i >= hole; i--) {
      servo.write(i);
      delay(30);
    }

    //Move the quadrant from the ramp entrance, to the funnel opening, at 30ms/θ°
    for (int i = hole; i <= funnel; i++) {
      servo.write(i);
      delay(30);
    }

    //Rotate the ramp back to the default position
    servo2.write(straightLine);
    
  }

}


