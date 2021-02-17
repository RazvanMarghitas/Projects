#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Servo.h>
Servo myservo;
int servo_pin=3;
LiquidCrystal lcd(12, 11, 5, 2, 13, 6);
int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int EN1=3;
int M1A=4;
int M1B=7;
long cm_v;
const int pingPin = 8;
int b=0;
int dir=0;
int deschis=0;
int inchis=1;
int veloc;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  lcd.begin(16, 2);
  myservo.attach(servo_pin);
  myservo.write(0);
}

void loop(){
  lcd.clear();
  if (irrecv.decode(&results)) {
    if (results.value == 16580863 && dir==0){
		int i=0;
      dir=1;
	  cm_v = distance();
	  while(i!=180)
	  {
        if(b==0)
        {
          lcd.print("deschidere");
        }
		cm_v = distance();
		if(cm_v>50)
		{
          myservo.write(i++);
		  delay(15);
          lcd.clear();
          b=0;
		}
		else
		{
         if(b==0)
         {
           lcd.clear();
           lcd.print("blocat");
         }
         b=1;
		}
	  }
      deschis=1;
      inchis=0;
    }
    else if (results.value == 16580863 && dir==1){
		int i=180;
      dir=0;
	  cm_v = distance();
	  while(i!=0)
	  {
        if(b==0)
        {
          lcd.print("inchidere");
        }
		cm_v = distance();
		if(cm_v>50)
		{
          myservo.write(i--);
		  delay(15);
          lcd.clear();
          b=0;
		}
		else
		{
         if(b==0)
         {
           lcd.clear();
           lcd.print("blocat");
         }
         b=1;
		}
	  }
      inchis==1;
      deschis=0;
    }
    irrecv.resume();
  }
  lcd.clear();
  if(deschis==1)
  { 
    lcd.print("deschis");
  }
  else
  {
   lcd.print("inchis"); 
  }
  delay(100);
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

long distance()
{
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  return cm;
}

