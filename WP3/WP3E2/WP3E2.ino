// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 2
// Submission code: 0808xx (provided by your TA-s)

// define section for the pins being used
#define blue_pin 10
#define red_pin 12
#define green_pin 8
#define temp_pin A5
#define light_pin A0

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
  temp = analogRead(temp_pin);    // reads the value returned from the pin
  temp = (double)temp / 1024;     //find percentage of input reading
  temp = temp * 5;                //multiply by 5V to get voltage
  temp = temp - 0.5;              //Subtract the offset
  temp = temp * 100;              //Convert to degrees
  Serial.print(temp);             // print the value
  Serial.print("\n");

  light = analogRead(light_pin);        // reads the value returned from the pin
  light = map(light, 26, 923, 0, 100);  // maps the value to the 0-100 (percent) scale
  Serial.print(light);                  // print the value
  Serial.print("\n");

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
