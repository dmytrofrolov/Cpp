/*
*    Alarm clock with analog input
*    It turns on the light if the analog output from
*    my cellphone audio jack is playing
*    Dmytro Frolov
*    12.04.2015
*/

// ports to read from
const int analogInPin = A2;

// ports to write
const int analogLED = 13;    // analog led to show input intensivity
const int alarmOutPin = 51;  // digital port for relay

// values for analog input
int sensorValue = 0;       
int outputValue = 0;      

void setup() {
  // start Serial communication by USB
  Serial.begin(9600);
  
  // mark alarmOutPin as outtput pin (for relay)
  pinMode(alarmOutPin, OUTPUT);
}

void loop() {
  // read from analog port
  sensorValue = analogRead(analogInPin);
  
  // map sensorValue to outputValue
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  // if outputValue is good enought
  if(outputValue>15){
    // turn on the light
    digitalWrite(alarmOutPin, HIGH);
    // for 20 minutes
    delay(1000 * 60 * 20);
    // turn off the light
    digitalWrite(alarmOutPin, LOW);
    
  }
  // change the analog LED intensivity
  analogWrite(analogLED, outputValue);

  // write results to serial port
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait for 0.5 second to next iteration
  delay(500);
}
