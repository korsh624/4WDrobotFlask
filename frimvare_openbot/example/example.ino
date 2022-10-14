
#include <NewPing.h>
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
volatile int counter = 0;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(5,OUTPUT);//levo for
  pinMode(6,OUTPUT);//levo res
  pinMode(9,OUTPUT);//pravo for
  pinMode(10,OUTPUT);//pravo res
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  int s=sonar.ping_cm();
  Serial.print(s); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print("cm  ");
  Serial.println(counter);
  if(s>20){
    forvard();
  }
  else{
   rezvard();
   delay(500);
   rotation();
   delay(500);
   stopallmotor();
   delay(1000);
  }
  
}
void forvard(){
  digitalWrite(6,0);
  digitalWrite(10,0);
  digitalWrite(5,1);
  digitalWrite(9,1);
}
void rezvard(){
  digitalWrite(5,0);
  digitalWrite(9,0);
  digitalWrite(6,1);
  digitalWrite(10,1);
}
void rotation(){
  digitalWrite(6,0);
  digitalWrite(9,0);
  digitalWrite(5,1);
  digitalWrite(10,1);
}
void stopallmotor(){
    digitalWrite(6,0);
  digitalWrite(9,0);
  digitalWrite(5,0);
  digitalWrite(10,0);
}
