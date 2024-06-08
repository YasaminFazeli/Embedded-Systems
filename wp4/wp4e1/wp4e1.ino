// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 4 
// Exercise 1
// Submission code: 8989cc (provided by your TA-s) 

//Define section - define the pin being used & the size of the step for temperature cutoffs.
#define temp_pin A0
#define TEMP_STEP 10

//Instantiate the variable used for tempeture.
double temp = 0;

//Setup function for the program
void setup() {
  //Set the temperature reading pin to input.
  pinMode(temp_pin, INPUT);
  //Set the appropriate output pins.
  DDRD = B00111110;
  
  //Interrupt setup courtesy of https://www.instructables.com/Arduino-Timer-Interrupts/
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
  
  //Set the initial values of the LEDs.
  updateLight();
}

//Timer 1 interrupts at 1Hz.
ISR(TIMER1_COMPA_vect){
  //Calls to update the LEDs.
  updateLight();
}

//Function to update which LEDs are switched on, base on the current temperature.
void updateLight(){
  //Read the value from the temperature input pin.
  temp = ((double) analogRead(temp_pin) / 1024) * 500 - 50;
  
  //Reset the output values.
  PORTD = B00000001;
  //Update the LEDs based on the temperature reading, by setting all bits right of the nearest cutoff to 1.
  PORTD = (PORTD << (int) temp/TEMP_STEP + 1) * 2 - 1;
}

void loop() {
  //Twidling its thumbs, and letting the interrupts do the work.
}
