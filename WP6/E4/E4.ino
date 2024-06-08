// (C) Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2023) 
// Work package 6
// Exercise 4 
// Submission code: 65828 (provided by your TA-s) 

//Library can be found at: https://github.com/DFRobot/DFRobot_MAX30102/blob/master/
#include <DFRobot_MAX30102.h>
//Initiate the oximeter sensor.
DFRobot_MAX30102 particleSensor;

void setup() {
  //Initiate the serial.
  Serial.begin(9600);
  //Check if the oximeter has been initiated.
  while (!particleSensor.begin()) {
    //If not, inform the user no oximeter has been found, and try again in 1 second.
    Serial.println("MAX30102 was not found");
    delay(1000);
  }
  //Configure the oximeter.
  particleSensor.sensorConfiguration(50, SAMPLEAVG_4, MODE_MULTILED, SAMPLERATE_100, PULSEWIDTH_411, ADCRANGE_16384);
}

//Initiate the variables to be read by the oximeter.
int32_t SPO2; //SPO2
int8_t SPO2Valid; //Flag to display if SPO2 calculation is valid
int32_t heartRate; //Heart-rate
int8_t heartRateValid; //Flag to display if heart-rate calculation is valid 

void loop() {
  //Inform the user to wait until the oximeter gets a valid reading.
  Serial.println(F("Wait about four seconds"));
  //Take a reading from the oximeter.
  particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid,&heartRate, &heartRateValid);
  //Print results
  Serial.print(F("heartRate="));
  Serial.print(heartRate, DEC);
  Serial.print(F("; SPO2="));
  Serial.println(SPO2, DEC);
}
