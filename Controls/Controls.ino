#include <OneWire.h>
#include <DallasTemperature.h>

#define pHsensor //Put what pin its connected to
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

const int stepsPerRevolution = 200;
const int Thermometerpin = A1; //Change these values to what pins they are connected to
const int motorpin = 8 ;
const int dOpin = 6;
const int opump = 9;

float tempCelsius;
unsigned long previousMillis = 0;
unsigned long int avgValue;
const long interval = x; //interval to start pumping in o2

int buf[10],temp;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// arrays to hold device address
DeviceAddress insideThermometer;

void setup() {

pinMode(Thermometerpin, OUTPUT);
pinMode(motorpin, OUTPUT);
pinMode(dOpin, OUTPUT);
pinMode(opump, OUTPUT); 
Serial.begin(9600);
sensors.begin(); //initalize sensors

}

void loop() {

unsigned long currentMillis = millis();
digitalWrite(motorPin, HIGH);

for(int i=0;i<3;i++)  //get 3 sample values and smooth
  {
    buf[i]=analogRead(pHsensor);
    delay(10)
  }
  for(int i=0;i<2;i++) //sort small to large
  {
    for(int j=i+1;j<3;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)
    avgValue+=buf[i];
  float phValue=(float)avgValue*5/1024/6; //conv analog to mc
  phValue=-6.7*phValue+28.9; //conert to pH value

sensors.requestTemperatures();
tempCelsius = sensors.getTempCByIndex(0);
  Serial.print(tempCelsius);
  Serial.print("'");
  Serial.println(phValue,2);

  delay(500);
 if (tempCelsius < 30 || tempCelsius > 50 || phValue < 7.5){
    tone(8, 300);
    delay(10000);
    noTone(8);
    delay(20000);
 }
 else{
    noTone(8);
 }

 if (phValue <7.5){
  digitalWrite(opump, HIGH);
  delay(100);
  digitalWrite(opump, LOW):
  delay(30000);
 }
 else{
 digitalWrite(opump, LOW);
    }
  }
}
