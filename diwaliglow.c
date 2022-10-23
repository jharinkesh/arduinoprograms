
int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 10;    // how many points to fade the LED by
boolean isfade = true;

int bp = 7;

int trigPin = 10;    // TRIG pin
int echoPin = 8;    // ECHO pin

float duration_us, distance_cm;

void setup() {
  // put your setup code here, to run once:
  // pinMode(led, OUTPUT);
  // begin serial port
  Serial.begin (9600);
  pinMode(led, OUTPUT);
  pinMode(bp, OUTPUT);


  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(2,HIGH);
  // delay(1000);
  // digitalWrite(2,LOW);
  // delay(1000);

// generate 10-microsecond pulse to TRIG pin
  // digitalWrite(13, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  if(distance_cm<16){
      isfade = true;
      digitalWrite(bp, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);
      digitalWrite(bp, LOW);   // turn the LED on (HIGH is the voltage level)
  }else{
      isfade = false;
  }

  delay(500);

  if(isfade == true){
    int count = 0;
    while(count <600){
        fade();
        count++;
    }    
  }
  analogWrite(led, 255);


}

void fade() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}
