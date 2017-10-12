/*
  LeoShieldCT1234.ino from:
  https://github.com/openenergymonitor/emontx-shield/blob/master/firmware/Shield_CT1234_Voltage_SerialOnly/Shield_CT1234_Voltage_SerialOnly.ino
  EmonTx CT123 Voltage Serial Only example 
  Part of the openenergymonitor.org project
  Licence: GNU GPL V3 
  Author: Trystan Lea
*/
#define leo        // Leonardo second serial is Serial1 for TTL
//#define sensitive  // means CT4 high accuracy, comment out for CT1

#include "EmonLib.h"

// Create  instances for each CT channel
//EnergyMonitor ct1,ct2,ct3,ct4;
#ifdef sensitive
  EnergyMonitor ct4;
#else
  EnergyMonitor ct1;
#endif

// On-board emonTx LED
const int LEDpin = 9;                                                    

void setup() 
{
  Serial.begin(9600);
  //while (!Serial) {}   // wait for serial port to connect. Needed for Leonardo only
  
  Serial.println("emonTX Shield CT123 Voltage Serial Only example"); 
  Serial.println("OpenEnergyMonitor.org");
  Serial1.begin(9600); // start TTL
  // Calibration factor = CT ratio / burden resistance = (100A / 0.05A) / 33 Ohms = 60.606
  //ct1.current(1, 60.606);
  //ct2.current(2, 60.606);                                     
  //ct3.current(3, 60.606);
  //ct4.current(4, 60.606); 
  
  #ifdef sensitive
    ct4.current(4, 60.606);
  #else
    ct1.current(1, 60.606);    // range of 58.18 to 63.02 for shield and default x with range 86.35 – 95.45 emonTx
  #endif
  

  
  /* (ADC input, calibration, phase_shift)  // use CalVRef.ino sketch to get READVCC_CALIBRATION_CONST 1115000L for Leonardo
  ct1.voltage(0, 300.6, 1.7);                                
  ct2.voltage(0, 300.6, 1.7);                                
  ct3.voltage(0, 300.6, 1.7);
  ct4.voltage(0, 300.6, 1.7);
  */
  //ct1.voltage(0, 268.8, 1.25);          // phase 1.7 default is calculated by comparing real and apparent with 100% PF device                  
  //ct2.voltage(0, 265.8, 1.25);                                
  //ct3.voltage(0, 265.8, 1.25);          // 268 97 per https://learn.openenergymonitor.org/electricity-monitoring/ctac/calibration
  //ct4.voltage(0, 265.8, 1.25);

  #ifdef sensitive
    ct4.voltage(0, 268.8, 1.25);
  #else
    ct1.voltage(0, 268.8, 1.25);
  #endif  
  
  // Setup indicator LED
  pinMode(LEDpin, OUTPUT);                                              
  digitalWrite(LEDpin, HIGH);                                                                                  
}

void loop() 
{ 
  // Calculate all. No.of crossings, time-out 
  //ct1.calcVI(20,2000);                                                  
  //ct2.calcVI(20,2000);
  //ct3.calcVI(20,2000);
  //ct4.calcVI(20,2000);

  #ifdef sensitive
    ct4.calcVI(20,2000);
  #else
    ct1.calcVI(20,2000);  
  #endif 
    
  // Print power 
  //Serial.print(ct1.realPower);     
  //Serial.print(" "); 
  //Serial.print(ct2.realPower);
  //Serial.print(" "); 
  //Serial.print(ct3.realPower);
  //Serial.print(" "); 
  //Serial.print(ct4.realPower);
  //Serial.print(" "); 

  #ifdef sensitive
    Serial.print(ct4.realPower);
    Serial.print(" "); 
    Serial.print(ct4.apparentPower);
    Serial.print(" ");  
    Serial.print(ct4.powerFactor);
    Serial.print(" ");  
    Serial.print(ct4.Irms); 
    Serial.print(" ");   
    Serial.print(ct4.Vrms); 
    Serial1.print(String(ct4.realPower, 3) + "," + String(ct4.apparentPower, 3) + "," +  String(ct4.powerFactor, 2) + "," + String(ct4.Irms, 4) + "," + String(ct4.Vrms, 3) + "\n");
  #else
    Serial.print(ct1.realPower);
    Serial.print(" "); 
    Serial.print(ct1.apparentPower);
    Serial.print(" ");  
    Serial.print(ct1.powerFactor);
    Serial.print(" ");  
    Serial.print(ct1.Irms);   
    Serial.print(" ");   
    Serial.print(ct1.Vrms); 
    Serial1.print(String(ct1.realPower, 3) + "," + String(ct1.apparentPower, 3) + "," +  String(ct1.powerFactor, 2) + "," + String(ct1.Irms, 4) + "," + String(ct1.Vrms, 3) + "\n");
  #endif 

  Serial.println();
    
  // Available properties: ct1.realPower, ct1.apparentPower, ct1.powerFactor, ct1.Irms and ct1.Vrms
  delay(1500);
  //delay(5000);
}
