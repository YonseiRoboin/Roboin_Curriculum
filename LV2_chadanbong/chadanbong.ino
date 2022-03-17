// servo control library
#include <Servo.h>
Servo myservo; 

int pos = 0; // servo position in angle
int ref_distance = 10; // reference distance
int ref_counter = 0; // counter
float act_distance = 0.0;
int open = 90;
int close = 0;

// us pins
int echo = 12;
int trig = 13;

// distance calc
float get_distance() {
  float cycletime; 
  float distance; 
  // activate trig pin for 0.01s
  digitalWrite(trig, HIGH); 
  delay(10); 
  digitalWrite(trig, LOW); 
  // calc time til echo recieves reflected signal
  cycletime = pulseIn(echo, HIGH); 
  distance = ((340 * cycletime) / 10000) / 2; 
  
  Serial.print("Distance:"); 
  Serial.print(distance); 
  Serial.println("cm"); 
  delay(500);
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT)
  myservo.attach(9);
}

void loop() {
  act_distance = get_distance();
  if(act_distance < ref_distance){
    myservo.write(open);
    Serial.println("object detected in %f distance - opening the gate", act_distance);
    delay(5000);
  }
  else{
    println("no object detected");
  }
}

