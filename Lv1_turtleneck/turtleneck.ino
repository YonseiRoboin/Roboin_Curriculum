// set pin numbers for each digital i/o
int echo = 12;
int trig = 13;
int led = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT)
}

void loop() {
  float cycletime; 
  float distance; 
  // activate trig pin for 0.01s
  digitalWrite(trig, HIGH); 
  delay(10); 
  digitalWrite(trig, LOW); 
  // calc time til echo recieves reflected signal
  cycletime = pulseIn(echo, HIGH); 
  distance = ((340 * cycletime) / 10000) / 2; 

  if(distance<=50){
    digitalWrite(8, HIGH)
  }
  Serial.print("Distance:"); 
  Serial.print(distance); 
  Serial.println("cm"); 
  delay(500);
}
