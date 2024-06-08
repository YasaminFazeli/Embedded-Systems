// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 4 
// Exercise 3
// Submission code: 8989cc (provided by your TA-s) 

#include <Adafruit_NeoPixel.h>

//Pin number that Neopixle connects to.
#define PIN  9
// Number of pixels in strip
#define NUMBER_OF_PIXELS 12
// The pin to which the temperature sensor is attached.
#define SENSORPIN A0

#define TEMP_STEP 10

//Define neopixel
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN,   NEO_GRB + NEO_KHZ800);


// initial temperature
const float temp = 20.0;

void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
  // Initialize the neopixel library.
  pixels.begin();
  // Set the pin numbers of pixels as ouputs
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber,   OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  
  //Interrupt setup courtesy of https://www.instructables.com/Arduino-Timer-Interrupts/
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (1610^6) / (11024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
  // Call the updateLight method
  updateLight();
}
ISR(TIMER1_COMPA_vect){
  //Calls to update the LEDs.
  updateLight();
}

// The function that updates the lights based on temperature
void updateLight()
{  pixels.clear();
  // Get the value of temperature sensor
   int sensorValue = analogRead(SENSORPIN);
  // Find percentage of input reading and multiply by
  // 5v to get voltage
  float voltage = (sensorValue  / 1024.0) * 5.0;
  //Subtract the offset and convert to degrees
  float temperature   = (voltage - .5) * 100;
  //Print the temperature
  Serial.print(temperature);
  Serial.print("\n");

  
    // Loop over all the ranges of temperature
    // o-10, 10-20,..
    for(int i=0; i<temperature/TEMP_STEP +1; i++)
    {    // set the neopixels color
         pixels.setPixelColor(i, pixels.Color(225,0,0)); 
        // Show the lights
         pixels.show();
      // If the number of tunred on pixles is 12
      // which means there are no more pixles to be turned on
         if(i==11){
           // Turn the LED on
          digitalWrite(LED_BUILTIN, HIGH);
         //  pixels.fill();
      }
    }

  }
  

void loop() {
   
}
