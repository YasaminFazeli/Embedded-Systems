// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 3
// Submission code: 0808xx (provided by your TA-s)

// define section - define the pin being used
#define temp_pin A5

const int delay_time = 500;  // delay time
double temp = 0;        // instantiate the variable used for tempeture

// setup function for the program
void setup()
{
  pinMode(temp_pin, INPUT);     // set the pin to input
  Serial.begin(9600);           // instantiate and start the serial
}

void loop()
{
  temp = analogRead(temp_pin);    // read the value from the pin
  temp = (double)temp / 1024;     // find percentage of input reading
  temp = temp * 5000;             // multiply by 5V to get m-voltage
  temp = (temp - 500) /10;        // convert it to C deg
  Serial.print(temp);             // print the value 
  Serial.print("\n");
  delay(delay_time);              // wait for 0.5 sec
}
