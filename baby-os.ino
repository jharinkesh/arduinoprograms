
#include <LiquidCrystal.h>
// Baby OS

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(3, 0);
  lcd.print("welcome to");
  delay(1000);
  
  lcd.clear();
  //lcd.autoscroll();
  lcd.setCursor(5, 1);
  lcd.print("Baby os");
  animate();

}

void animate(){
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(50);
  }
 
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(50);
  }

  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(50);
  }

  delay(1000);
}

boolean up = true, down = false, enter = true, back = true;

void stopwatch(){
  lcd.clear();
  int sec = 0;
  int prevback = 0;
  int count = 0;
  while(1){
    for(int i=0;i<100;i++){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Stopwatch App");
      lcd.setCursor(0, 1);
      if(i == 99)
        sec+=1;
      lcd.print(sec);
      lcd.print(":");
      lcd.print(i);

      back =  digitalRead(8);
      if(back == 1 && prevback == 1)
        count++;
        if(count > 100)
          return;
      prevback = back;
      delay(10);
    }
  }
}

void music(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Playing music");
    int prevback = 0;
    int count = 0;
    while(1){
    for(int i=0;i<100;i++){
        back =  digitalRead(8);
        if(back == 1 && prevback == 1)
          count++;
          if(count > 1) {
           digitalWrite(13,LOW);
           return;
        }
        prevback = back;
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
        digitalWrite(13,HIGH);
      }
    }
}

int prevup = 0,prevdown = 0;
int opt = 0;
void loop() {

  up = digitalRead(6);
  down =  digitalRead(7);

  if(up == 1 && prevup == 1 && (opt==0||opt==2)){
    stopwatch();
    opt = 1;
  }
    
  if(down == 1 && prevdown == 1 && (opt==0||opt==1)){
    music();
    opt = 2;
  }
    
  prevup = up;
  prevdown = down;
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Menu");

  lcd.setCursor(5, 0);
  lcd.print("1.Stopwatch");

  lcd.setCursor(5, 1);
  lcd.print("2.Music");
  
  delay(500);
 
}
