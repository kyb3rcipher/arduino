#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
LiquidCrystal lcd(7,6,5,4,3,2);

int trig=10;
int echo=9;
int time;
int distance;
int read;
int temperature;

void setup() {
  	lcd.begin(16, 2);
	Serial.begin(9600);
	pinMode(trig,OUTPUT);
	pinMode(echo,INPUT);
  	pinMode(A0, INPUT);
}

void loop() {
  	delay(200);
	digitalWrite(trig,LOW);  
	digitalWrite(trig,HIGH);
	digitalWrite(trig,LOW);
	time=pulseIn(echo,HIGH);     
	distance=time/58;
  	read = analogRead(0);
  	temperature = ( read * (500.0 / 1023.0) ) - 50.0;
  	Serial.write (10);	// line break on serial monitor
 	/* //Uncomment for print on serial the distance & temperature
    Serial.print("Distance: ");
	Serial.print(distance);
    Serial.print(" cm | ");
    Serial.print("Temperature: ");
  	Serial.print(temperature);
  	Serial.print(" degrees");*/

	if(distance <=50) {
      if(temperature <= 50) {
      	myservo.attach(8);
      	lcd.print("Continue :D");
        delay(300);
        lcd.clear();
      }
      else {
        (temperature >50);
        lcd.print("OMFG!");
        lcd.setCursor(0, 1);
        lcd.print("kill them D:");
		tone(11, 220, 100);
        delay(300);
        lcd.clear();
      }
	}
  	else {
      	(distance >50 && distance<100);
      	//myservo.attach(5);	// for turn off myservo
  		Serial.print("Ur fxcking distance!!!");
	}
}
