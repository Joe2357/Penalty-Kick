#include <Servo.h>							// using servo motor
#include <LiquidCrystal_I2C.h>				// using I2C LCD display
#include <Wire.h>							// using I2C LCD display
Servo myservo;								// set servo motor object
LiquidCrystal_I2C lcd(0x27, 16, 2);			// set LCD display object

int outPin = 10;							// trig pin of ultrasonic sensor
int inPin = 11;								// echo pin of ultrasonic sensor
int E1 = 2;									// left infrared sensor - shoot 
int O1 = 3;									// left infrared sensor - get
int E2 = 4;									// right infrared sensor - shoot
int O2 = 5;									// right infrared sensor - get

void setup() {								// setup function
	pinMode(E1, OUTPUT);					// setting all pinMode
	pinMode(O1, INPUT);
	pinMode(E2, OUTPUT);
	pinMode(O2, INPUT);
	pinMode(outPin, OUTPUT);
	pinMode(inPin, INPUT);
	myservo.attach(9);						// initialize servo motor
	lcd.init();								// initialize I2C LCD monitor
	lcd.backlight();						// turn on the LCD backlight ( blue light )
}

void loop() {								// loop function
	digitalWrite(outPin, HIGH);				// 1st - calcutate distance of ultrasonic sensor and field 
	delayMicroseconds(50);
	digitalWrite(outPin, LOW); 
	int temp;
	int duration = pulseIn(inPin, HIGH);	// How long did time take?
	int result = duration;					// result = 1st calcutate distance
	myservo.write(115);						// turn servo motor to the center
	int left = 0;							// is left infrared sensor detect any signal?
	int right = 0;							// is right infrared sensor detect any signal?
	lcd.setCursor(0, 0);					// set lcd cursor to start
	lcd.print("Shoot!");					// print "Shoot!" to lcd
	while (true) {							// while left and right sensor get same signal
		digitalWrite(E1, HIGH);
		digitalWrite(E2, HIGH);
		delayMicroseconds(50);
		digitalWrite(E1, LOW);
		digitalWrite(E2, LOW);
		left = digitalRead(O1);				// left = did left infrared sensor detect any signal?
		right = digitalRead(O2);			// right = did right infrared sensor detect any signal?
		if (left != right) {				// if they get different signal
			if (left)						// if left sensor detect the signal
				myservo.write(70);			// goalkeeper defense left side
			else if (right)					// else if right sensor detect the signal
				myservo.write(160);			// goalkeeper defense right side
			lcd.clear();					// erase "Shoot!"
			break;							// end loop
		}
		delay(5);							// for evey 0.005 seconds
	}										// loop and loop
	for(int i = 0; i < 100; i++) {			// loop 100 times ( max 2 seconds )
		digitalWrite(outPin, HIGH);			// ultrasonic sensor detect ball
		delayMicroseconds(50);
		digitalWrite(outPin, LOW); 
		int temp = pulseIn(inPin, HIGH);
		if (duration > temp)				// if calculated distance is lower than existing duration ( did sensor detected the ball? )
			duration = temp;				// set duration to minimun value
		delay(20);
	}
	if (duration + 15 < result) {			// if sensor detected the ball
		char str[16] = "Congratulations!";	// display "Congratulations!" to LCD display
		for(int i = 0; i < 16; i++) {
			lcd.clear();
			lcd.setCursor(i, 0);
			lcd.print(str[i]);
			delay(200);
		}
		for(int i = 0; i < 5; i++) {
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print(str);
			delay(200);
		}
	}
	else {									// else if ultrasonic sensor didn't detect the ball
		char str[16] = "No Goal!";			// display "No Goal!" to LCD display
		for(int i = 0; i < 8; i++) {
			lcd.clear();
			lcd.setCursor(i, 0);
			lcd.print(str[i]);
			delay(200);
		}
		for(int i = 0; i < 5; i++) {
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print(str);
			delay(200);
		}
	}
	while (!digitalRead(8))					// if user press "reset button"
		delay(10);
		lcd.clear();						// clear LCD display
	delay(10);
}											// loop end, another loop start