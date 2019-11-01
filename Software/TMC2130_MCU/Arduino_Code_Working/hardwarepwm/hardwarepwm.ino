long system_clock = 16000000;
long prescaler = 256;
#define DIR_1 44
#define STEP_1 5
#define DIR_2 48
#define STEP_2 46
#define DIR_3 30
#define STEP_3 11
#define DIR_4 28
#define STEP_4 6
#define MOSI 51
#define SCK 52

#define FREQ 10000
void setup() {
  pinMode(MOSI, OUTPUT);
  digitalWrite(MOSI, HIGH);
  pinMode(SCK, OUTPUT);
  digitalWrite(SCK, HIGH);
  motorFrequency(1, FREQ, 1);  // motor number: 1, 2, 3, 4  frquency(speed) derection: 1, 0
  motorFrequency(2, FREQ, 1); 
  motorFrequency(3, FREQ, 1);  
  motorFrequency(4, FREQ, 1); 
}
void motorFrequency(int motorNum, int frequency, int direct){
  //motorNum = 1  pin 5   
  //motorNum = 2  pin 46
  //motorNum = 3  pin 11
  //motorNum = 4  pin 6
  
  long Top = (system_clock /( frequency * 2 * prescaler)) - 1;   // TOP  frequency=(system clock)/ [2 * prescaler * (TOP +1)]
  switch(motorNum){
    case 1:
      pinMode(STEP_1, OUTPUT);
      TCCR3A = B01010111;    // Fast PWM
      TCCR3B = TCCR3B & B11100000 | B00011100;         // Prescaler = 256
      OCR3A = Top;
      pinMode(DIR_1, OUTPUT);
      if(direct){ 
        digitalWrite(DIR_1, HIGH);
      }else{
        digitalWrite(DIR_1, LOW);
      }
      break;
    case 2:
      pinMode(46, OUTPUT);
      TCCR4A = B01010111;    // Fast PWM
      TCCR4B = TCCR4B & B11100000 | B00011100;         // Prescaler = 256
      OCR4A = Top;
      pinMode(DIR_2, OUTPUT);
      if(direct){ 
        digitalWrite(DIR_2, HIGH);
      }else{
        digitalWrite(DIR_2, LOW);
      }
      break;
    case 3:
      pinMode(11, OUTPUT);
      TCCR1A = B01010111;    // Fast PWM
      TCCR1B = TCCR1B & B11100000 | B00011100;         // Prescaler = 256
      OCR1A = Top;
      pinMode(DIR_3, OUTPUT);
      if(direct){ 
        digitalWrite(DIR_3, HIGH);
      }else{
        digitalWrite(DIR_3, LOW);
      }
      break;
    case 4:
      pinMode(6, OUTPUT);
      TCCR5A = B01010111;    // Fast PWM
      TCCR5B = TCCR5B & B11100000 | B00011100;         // Prescaler = 256
      OCR5A = Top;
      pinMode(DIR_4, OUTPUT);
      if(direct){ 
        digitalWrite(DIR_4, HIGH);
      }else{
        digitalWrite(DIR_4, LOW);
      }
      break;
  }
//  Serial.begin(115200);
//  Serial.println(Top);
//  Serial.println(TCCR5B,BIN);
//  delay(1000);
}
void loop() {
//  Serial.begin(115200);
//  Serial.println(TCCR5A,BIN);
//  Serial.println(TCCR5B,BIN);
//  delay(1000);
}

