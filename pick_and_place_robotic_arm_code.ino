// TCS230 or TCS3200 pins wiring to Arduino

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
String c = "";
int a,b;

int dummyvar = 0;
int z;
int countrevs_stepper = 0;

//Gripper servo
#include <Servo.h>
int pos = 0;
Servo servo_11;

// Define pin connections & motor's steps per revolution
const int dirPin = 8;
const int stepPin = 9;
const int stepsPerRevolution = 60;
int enablepin = 10;

// Stores the red. green and blue colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

//Function for opening and closing of the gripper
void gripperclosing()
{
 for (pos = 45; pos <= 120; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_11.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  delay(3000);
}

void gripperopening()
{
  for (pos = 120; pos >= 60; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_11.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  
}

void readcolor()
{
    // Setting RED (R) filtered photodiodes to be read    
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    // Reading the output frequency
    redFrequency = pulseIn(sensorOut, LOW);
    // Remaping the value of the RED (R) frequency from 0 to 255
    redColor = map(redFrequency, 52, 103, 255,0);
        
    // Setting GREEN (G) filtered photodiodes to be read
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    // Reading the output frequency
    greenFrequency = pulseIn(sensorOut, LOW);
    // Remaping the value of the GREEN (G) frequency from 0 to 255
    greenColor = map(greenFrequency, 78, 123, 255, 0);

    // Setting BLUE (B) filtered photodiodes to be read
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    // Reading the output frequency
    blueFrequency = pulseIn(sensorOut, LOW);
    // Remaping the value of the BLUE (B) frequency from 0 to 255
    blueColor = map(blueFrequency, 45, 106, 255, 0);
}

void checkcolor()
{
    
  if(redColor > greenColor && redColor > blueColor && a==4)
    {
      Serial.println(" - Red detected!");
      b = a+1;
      dummyvar = dummyvar+1;
      digitalWrite(enablepin,HIGH);  //Stopping the stepper motor
      delay(3000);
      gripperclosing();
      
    }
    
    if(greenColor > redColor && greenColor > blueColor && a==6)
    {
      Serial.println(" - GREEN detected!");
      b=a+1;
      dummyvar = dummyvar+1;
      digitalWrite(enablepin,HIGH);   //Stopping the stepper motor
      delay(3000);
      gripperclosing();
    }
    
    if(blueColor > redColor && blueColor > greenColor && a==5)
    {
      Serial.println(" - BLUE detected!");
      b=a+1;
      dummyvar = dummyvar+1;
      digitalWrite(enablepin,HIGH);   //Stopping the stepper motor
      delay(3000); 
      gripperclosing();
    }
}

void setup() {
  // Setting the outputs of color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Setting Outputs for stepper motor driver
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablepin ,OUTPUT);
  
  // pinMode(input1, OUTPUT);
  //pinMode(input2, OUTPUT);
  servo_11.attach(11, 500, 2500);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);

  // Declare pins as Outputs for stepper
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() 
{
  //Taking input from the user in Serial Monitor
  Serial.println("Enter the color");
  while(Serial.available()==0)
  {
               
  }
  while(Serial.available() >0)
  {
    c = Serial.readString();
  }
  b = 0 ;
  a = c.length();
  Serial.println(c);
  
  digitalWrite(enablepin,LOW);  //Enabling the driver module
  digitalWrite(dirPin, LOW);    // Stepper motor rotates in CW direction (viewed from front)
  z = 0;
  
  while(a>b)
  {
    // Stepper motor
    for(int x = 0; x < stepsPerRevolution; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(10000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(10000);
      z = z+1;
    }

    readcolor();
    checkcolor(); // Checks the current detected color and prints a message in the serial monitor
    
  }

  // Stepper Motor returning to home position
  if(dummyvar==1)
  {
    digitalWrite(enablepin,LOW);  //Enabling the driver module
  }
  
  if( dummyvar ==1)
  {
   digitalWrite(dirPin, HIGH);    // Stepper motor rotates in CCW direction (viewed from front)

    for(int x = 0; x < z-50; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(5000);
    }
   delay(1000);
   gripperopening();
  }
  dummyvar = 0;
}
