// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 1
// Submission code: 0808xx (provided by your TA-s)

// define section - defining the pins being used
#define blinking_led 9 
#define push_led 5

// seting up the program 
void setup()
{
  pinMode(blinking_led, OUTPUT);    // initilizing and setting the pin mode to output
  pinMode(push_led, OUTPUT);        // initilizing and setting the pin mode to output
  digitalWrite(push_led, HIGH);    // set the pin to high
}

// loop function (running constantly)
void loop()
{
  digitalWrite(9, HIGH);  // switch the pin to high
  delay(1000);            // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);   // switch the pin to low
  delay(1000);            // Wait for 1000 millisecond(s)
}
