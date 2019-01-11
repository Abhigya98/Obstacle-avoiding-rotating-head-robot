#include <Servo.h>
#include <NewPing.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
const int pingPin = 7;
long cm,inches,duration;
int leftdist,rightdist;
int object = 10;
int maxdist = 100;
long readsensor();// variable to store the servo position
void setup() {
  Serial.begin(9600); 
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}
void loop() {
 readsensor();
 
 if((cm>object)&&(cm<maxdist))
 {
  lookleft();
  lookright(); 
 }
}
 
void lookleft() {
 myservo.write(150);
 delay(700);                                //wait for the servo to get there
 leftdist = digitalRead(pingPin);
 myservo.write(90);
 delay(700);                                 //wait for the servo to get there
 return;
}
void lookright () {
 myservo.write(30);
 delay(700);                           //wait for the servo to get there
 rightdist = digitalRead(pingPin);
 myservo.write(90);                                  
 delay(700);                        //wait for the servo to get there
 return;
}
long readsensor()
{   
 pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}

