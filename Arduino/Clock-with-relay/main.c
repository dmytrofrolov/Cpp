/*
  Simple binary alarm clock,
  what turns on the light bulb
  
  Dmytro Frolov
  25.01.2015
 */
 

const int minuteButtonPIN = 33;
const int hourButtonPIN = 39;
const int switchButtonPIN = 23;
const int relayPIN = 51;
const int switchLED = 13;
const int analogStrength = 600;

const int minutesLED[] = {3, 6, 8, 2, 4, 5};
const int hoursLED[] = {7, 9, 10, 11, 12};

//all LEDs turned off
int minutesState[] = {0, 0, 0, 0, 0, 0};
int hoursState[] = {0, 0, 0, 0, 0};

int alarmMinutes = 0, alarmHours = 0;

//do user sets alarm at this moment
bool isAlarmSet = false;

int seconds = 0, minutes = 0, hours = 0;

void setup() {                 
  pinMode(minuteButtonPIN, INPUT);  // minute button
  pinMode(hourButtonPIN, INPUT);  // hour button
  pinMode(switchButtonPIN, INPUT);  // hour button
  pinMode(relayPIN, OUTPUT);  // hour button
  pinMode(switchLED, OUTPUT);  // switch clock/alarm
  for(int i = 0; i<6; i++){
    pinMode(minutesLED[i], OUTPUT);
  }
  for(int i = 0; i<5; i++){
    pinMode(hoursLED[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 5; i++){
    int isMinuteButton = digitalRead(minuteButtonPIN);
    int isHourButton = digitalRead(hourButtonPIN);
    int isSwitchButton = digitalRead(switchButtonPIN);
    if(isSwitchButton==HIGH){  //if 
      if(isAlarmSet==false){
        isAlarmSet = true;
        analogWrite(switchLED, analogStrength);
        changeMinutes(alarmMinutes);
        changeHours(alarmHours);
      }else{
        isAlarmSet = false;
        analogWrite(switchLED, 0);
        changeMinutes(minutes);
        changeHours(hours);
      }
    }
    if(isMinuteButton == HIGH){
      if(isAlarmSet==true){
        alarmMinutes++;
        if(alarmMinutes==60)alarmMinutes=0;
        changeMinutes(alarmMinutes);
      }
      else{
        minutes++;
        if(minutes==60)minutes=0;
        changeMinutes(minutes);
      }
    }
    if(isHourButton == HIGH){
      if(isAlarmSet==true){
        alarmHours++;
        if(alarmHours==24)alarmHours=0;
        changeHours(alarmHours);
      }
      else{
        hours++;
        if(hours==24)hours=0;
        changeHours(hours);
      }
    }
    delay(200);
  }
  
  if(((hours==alarmHours && minutes >= alarmMinutes) || (hours==(alarmHours+1) && minutes <= alarmMinutes)) && isAlarmSet == false){
    digitalWrite(relayPIN, HIGH);
  }else{
    digitalWrite(relayPIN, LOW);
  }
  
  seconds++;
  if(seconds==60 ){
    seconds=0;
    minutes++;
    if(minutes==60){
      hours++;
      if(hours==24)hours = 0;
      if(isAlarmSet==false)changeHours(hours);
      minutes=0;
    }
    if(isAlarmSet==false)
      changeMinutes(minutes);  
  }
  
}

void changeHours(int newHours){
  for(int i = 0; i<5; i++){hoursState[i]=0;}
  int i = 0;
  while(newHours!=0){
    hoursState[i]=newHours%2;
    i++;
    newHours/=2;
  }
  for(int i = 0; i<6; i++){
    analogWrite(hoursLED[i], hoursState[i]*analogStrength);
  }
}

void changeMinutes(int newMinutes){
  for(int i = 0; i<6; i++){minutesState[i]=0;}
  int i = 0;
  while(newMinutes!=0){
    minutesState[i]=newMinutes%2;
    i++;
    newMinutes/=2;
  }
  for(int i = 0; i<6; i++){
    analogWrite(minutesLED[i], minutesState[i]*analogStrength);
  }
}