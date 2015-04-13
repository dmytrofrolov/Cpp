const int analogInPin = A2;
const int analogLED = 13;
const int alarmOutPin = 51;

int sensorValue = 0;       
int outputValue = 0;      

void setup() {
  Serial.begin(9600);
  pinMode(alarmOutPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  if(outputValue>20){
    digitalWrite(alarmOutPin, HIGH);
    analogWrite(analogLED, outputValue);
    delay(1000 * 60 * 5);
    digitalWrite(alarmOutPin, LOW);
    
  }

  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(500);
}
