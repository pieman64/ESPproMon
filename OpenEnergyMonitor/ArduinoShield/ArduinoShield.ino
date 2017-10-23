*
  USE CT4 !!!!!
  ArduinoShieldV3.ino for Leonardo or Uno WAS LeoShieldCT1234v3.ino with DS18B20 option from:
  https://github.com/openenergymonitor/emontx-shield/blob/master/firmware/Shield_CT1234_Voltage_SerialOnly/Shield_CT1234_Voltage_SerialOnly.ino
  Use micro USB to upload new sketches NOT TTL, TTL is just to receive data and only requires 2 pins GND and TX (labelled RX on shield as it
  goes to RX allocated pin on the ESP).
  EmonTx CT1234 Voltage Serial Only example 
  Part of the openenergymonitor.org project 
  Licence: GNU GPL V3 
  Author: Trystan Lea and minor mods by ESPproMon©
*/

#include "EmonLib.h"

EnergyMonitor ct1,ct2,ct3,ct4;  // Create  instances for each CT channel
bool DEBUG = 1;                 // Print serial debug
#ifdef  ARDUINO_AVR_LEONARDO
    #define FOUND_LEONARDO
#endif // not a LEONARDO so must be an UNO

#include <OneWire.h>                    //http://www.pjrc.com/teensy/td_libs_OneWire.html
#include <DallasTemperature.h>          //http://download.milesburton.com/Arduino/MaximTemperature/DallasTemperature_LATEST.zip
const int TEMPERATURE_PRECISION=  11;   //9 (93.8ms),10 (187.5ms) ,11 (375ms) or 12 (750ms) bits equal to resplution of 0.5C, 0.25C, 0.125C and 0.0625C
const byte MaxOnewire=             2;   // assume no more than 2 sensors
#define ASYNC_DELAY 375                 // DS18B20 conversion delay - 9bit requres 95ms, 10bit 187ms, 11bit 375ms and 12bit resolution takes 750ms
#define ONE_WIRE_BUS               4    // DS18B20 Data
int temp[MaxOnewire];
//-------------------------------------------------------------------------------------------------------------------------------------------

//Setup DS128B20
bool DS18B20_STATUS;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
byte allAddress [MaxOnewire][8];  // 8 bytes per address
byte numSensors;

//-------------------------------------------------------------------------------------------------------------------------------------------

const int LEDpin = 9; // On-board emonTx LED

typedef struct {
  int temp[MaxOnewire];
  unsigned long pulseCount;
} PayloadTX;     // create structure - a neat way of packaging data for RF comms

PayloadTX emontx;

void setup() 
{
  Serial.begin(115200);
  //while (!Serial) {}   // wait for serial port to connect. Normally for Leonardo but not needed
  Serial.println("emonTX Shield CT1234 with Voltage & DS18B20 - Serial Only example"); 
  Serial.println("OpenEnergyMonitor.org");
  #ifdef  FOUND_LEONARDO
    Serial1.begin(115200); // start Serial1 on Leonardo
  #endif
  // Calibration factor = CT ratio / burden resistance = (100A / 0.05A) / 33 Ohms = 60.606
  ct1.current(1, 60.606); // range of 58.18 to 63.02 for shield [default 90.9 with range 86.35 – 95.45 for emonTx 22 Ohms]
  ct2.current(2, 60.606);                                     
  ct3.current(3, 60.606);
  // CT 4 is high accuracy @ low power - 4.5kW Max for emonTx but NOT shield (2000 turns / 120 Ohm burden resistor = 16.66 for emonTx) 
  ct4.current(4, 58.50); // shield doesn't have high accuracy CT4, normal 33 Ohms
  
  /* (ADC input, calibration, phase_shift)  // use CalVRef.ino sketch to get READVCC_CALIBRATION_CONST 1115000L for Leonardo
  default normally: ct1.voltage(0, 300.6, 1.7);         // Robert thinks new CT's might need 1.85
  */
  ct1.voltage(0, 268.97, 1.205);      // phase 1.7 default is calculated by comparing real and apparent with 100% PF device                  
  ct2.voltage(0, 268.97, 1.205);      // was 265.8, 1.25                          
  ct3.voltage(0, 268.97, 1.205);      // 268.97 per https://learn.openenergymonitor.org/electricity-monitoring/ctac/calibration
  ct4.voltage(0, 268.97, 1.205);
  
  // Setup indicator LED
  pinMode(LEDpin, OUTPUT);                                              
  digitalWrite(LEDpin, HIGH);    

  //################################################################################################################################
  //Setup and test for presence of DS18B20
  //################################################################################################################################

  sensors.begin();
  sensors.setWaitForConversion(false);             // disable automatic temperature conversion to reduce time spent awake, conversion will be implemented manually in sleeping
                                                   // http://harizanov.com/2013/07/optimizing-ds18b20-code-for-low-power-applications/
  numSensors=(sensors.getDeviceCount());
  if (numSensors > MaxOnewire) numSensors=MaxOnewire;   //Limit number of sensors to max number of sensors

  byte j=0;                                        // search for one wire devices and
                                                   // copy to device address arrays.
  while ((j < numSensors) && (oneWire.search(allAddress[j])))  j++;

  if (numSensors==0) DS18B20_STATUS=0;
    else DS18B20_STATUS=1;

  //################################################################################################################################

  if (DS18B20_STATUS==1) {
    Serial.print("Detected Temp Sensors: ");
    Serial.println(numSensors);
  } else {
    Serial.println("No temperature sensor");
  }

  Serial.print("CT1 CT2 CT3 CT4 VRMS PULSE");
  
  if (DS18B20_STATUS==1){Serial.print(" Temperature 1-"); Serial.print(numSensors);}
    
  for(byte j=0;j<MaxOnewire;j++)
      emontx.temp[j] = 3000;      // If no temp sensors connected default to status code 3000
                                    // will appear as 300 once multipled by 0.1 in emonhub   
  Serial.println();
                                                                              
}

void loop() 
{ 
  // Calculate all. No.of crossings, time-out 
  ct1.calcVI(20,2000);                                                  
  ct2.calcVI(20,2000);
  ct3.calcVI(20,2000);
  ct4.calcVI(20,2000);
  
  if (DS18B20_STATUS==1)
  {
    for(int j=0;j<numSensors;j++)
      sensors.setResolution(allAddress[j], TEMPERATURE_PRECISION);                    // and set the A to D conversion resolution of each.
    sensors.requestTemperatures();
    for(byte j=0;j<numSensors;j++)
      emontx.temp[j]=get_temperature(j);
  }
    
   if (DEBUG==1) {  // for Leonardo will print to Serial and Serial1, but just Serial for Uno
    Serial.print("ct1:");   Serial.print(ct1.realPower);
    //Serial.print(",ct1ap:");  Serial.print(int(ct1.apparentPower)); // was only used for "1.7" phase cal
    Serial.print(",ct2:");  Serial.print(int(ct2.realPower));
    Serial.print(",ct3:");  Serial.print(int(ct3.realPower));
    Serial.print(",ct4:");  Serial.print(int(ct4.realPower));
    //Serial.print(",ct4ap:");  Serial.print(int(ct4.apparentPower)); // was only used for "1.7" phase cal
    Serial.print(",vrms:"); Serial.print(int(ct1.Vrms * 100));
    Serial.print(",pulse:");Serial.print(emontx.pulseCount);
    if (DS18B20_STATUS==1){
      for(byte j=0;j<numSensors;j++){
        Serial.print(",t"); Serial.print(j); Serial.print(":");
        Serial.print(emontx.temp[j]);
      }
    }
    Serial.print(",mA:");Serial.print(int(ct4.Irms * 1000));  // TODO ONLY amps from one CT for apparent power calcs
    Serial.println();
    delay(50);
  }

#ifdef FOUND_LEONARDO
    Serial1.print("ct1:");   Serial1.print(int(ct1.realPower));
    Serial1.print(",ct2:");  Serial1.print(int(ct2.realPower));
    Serial1.print(",ct3:");  Serial1.print(int(ct3.realPower));
    Serial1.print(",ct4:");  Serial1.print(int(ct4.realPower));
    Serial1.print(",vrms:"); Serial1.print(int(ct1.Vrms * 100));
    Serial1.print(",pulse:");Serial1.print(emontx.pulseCount);
    if (DS18B20_STATUS==1){
      for(byte j=0;j<numSensors;j++){
        Serial1.print(",t"); Serial1.print(j); Serial1.print(":");
        Serial1.print(emontx.temp[j]);
      }
    }
    Serial1.print(",mA:");Serial1.print(int(ct4.Irms * 1000));  // TODO ONLY amps from one CT for apparent power calcs
    Serial1.println();
    delay(50);
#endif  
    
  // Available properties: ct1.realPower, ct1.apparentPower, ct1.powerFactor, ct1.Irms and ct1.Vrms
  delay(1500);
  //delay(5000);
}


int get_temperature(byte sensor)
{
  float temp=(sensors.getTempC(allAddress[sensor]));
  if ((temp<125.0) && (temp>-55.0)) return(temp*10);   //if reading is within range for the sensor convert float to int ready to send via TTL
}
