// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2023) 
// Work package 5 
// Exercise 3
// Submission code: 121314AA (provided by your TA-s)

//Define section - define the pin being used & the size of the step for temperature cutoffs.

// define section for the pins being used
#define blue_pin 10
#define red_pin 12
#define green_pin 8
#define temp_pin A5
#define light_pin A0

//Initialise variables to read thermistor values.
int ThermistorPin = 5;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1=0.7904710802e-3, c2=2.251846924e-4, c3=0.87060700625e-7;

const double low = 997;         // the variable for the highest number read from the tempeture sensor
const double high = 100;        // the variable for the lowest number read from the tempeture sensor
const int delay_time = 1000;    // the delay for each iteration

double temp = 0;                // instantiate the variable for tempeture
double light = 0;               // instantiate the variable for light

// setup method for the program
void setup() {
  pinMode(blue_pin, OUTPUT);    // setting the pin as an output
  pinMode(green_pin, OUTPUT);   // setting the pin as an output
  pinMode(red_pin, OUTPUT);     // setting the pin as an output
  
  pinMode(temp_pin, INPUT);     // setting the pin as an input
  pinMode(light_pin, INPUT);    // setting the pin as an input
  Serial.begin(9600);           // instantiate and start the serial

}

// the loop function for the program
void loop() {
  //Read the value from the temperature input pin. Circuit calculations provided courtesy of Jan Kelar, whom I owe a beer.
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  temp = T - 273.15;

  Serial.print("Temperature: "); 
  Serial.println(temp);
  light = analogRead(light_pin);        // reads the value returned from the pin
  light = map(light, 0, 900, 0, 100);  // maps the value to the 0-100 (percent) scale
  Serial.print("light: ");                  // print the value
  Serial.println(light);
  

  if (light == 0)                       // if the light is equal to 0 percent
  {
      if (temp < -12)                     // if the tempeture is lower than -12 deg
      {
        digitalWrite(red_pin, LOW);       // turn off the red led
        digitalWrite(blue_pin, LOW);      // turn off the blue led
        digitalWrite(green_pin, HIGH);    // turn on the green led
      } else                              // otherwise
      {
        digitalWrite(red_pin, HIGH);      // turn on the red led
        digitalWrite(blue_pin, LOW);      // turn off the blue led
        digitalWrite(green_pin, LOW);     // turn off the green led
      }
  } else if (light >= 1 && light <= 20) // if the light is between 1 and 20 percent
  {
      if (temp >= -12 && temp <= 0)       // if the tempeture is between -12 and 0 deg
      {
        digitalWrite(red_pin, LOW);         // turn off the red led
        digitalWrite(blue_pin, LOW);        // turn off the blue led
        digitalWrite(green_pin, HIGH);      // turn on the green led
      } else if (temp < -12)              // if the tempeture is lower than -12 deg
      {
        digitalWrite(red_pin, LOW);         // turn off the red led
        digitalWrite(blue_pin, HIGH);       // turn on the blue led
        digitalWrite(green_pin, LOW);       // turn off the green led
      } else if (temp > 0)                // if the tempeture is higher than 0 deg
      {
        digitalWrite(red_pin, HIGH);        // turn on the red led
        digitalWrite(blue_pin, LOW);        // turn off the blue led
        digitalWrite(green_pin, LOW);       // turn off the green led
      }
    
  } else if (light >= 21 && light <= 60)  // if the light is between 21 and 60 percent
  {

      if (temp >= 0 && temp <= 20)          // if the tempeture is between 0 and 20 deg
      {
        digitalWrite(red_pin, LOW);           // turn off the red led
        digitalWrite(blue_pin, LOW);          // turn off the blue led
        digitalWrite(green_pin, HIGH);        // turn on the green led
      } else if (temp < 0)                  // if the tempeture is lower than 0 deg
      {
        digitalWrite(red_pin, LOW);           // turn off the red led
        digitalWrite(blue_pin, HIGH);         // turn on the blue led
        digitalWrite(green_pin, LOW);         // turn off the green led
      } else if (temp > 20)                 // if the tempeture is higher than 20 deg
      {
        digitalWrite(red_pin, HIGH);          // turn on the red led
        digitalWrite(blue_pin, LOW);          // turn off the blue led
        digitalWrite(green_pin, LOW);         // turn off the green led
      }
  } else if (light >= 61 && light <= 100) // if the light is between 61 and 100 percent
  {

      if (temp >= 21)                       // if the tempeture is higher than 21 deg
      {
        digitalWrite(red_pin, LOW);           // turn off the red led
        digitalWrite(blue_pin, LOW);          // turn off the blue led
        digitalWrite(green_pin, HIGH);        // turn on the green led
      } else if (temp < 21)                 // if the tempeture is lower than 21 deg
      {
        digitalWrite(red_pin, LOW);           // turn off the red led
        digitalWrite(blue_pin, HIGH);         // turn on the blue led
        digitalWrite(green_pin, LOW);         // turn off the green led
      } 
  }
  

  delay(delay_time);    // wait for 1 sec

}
