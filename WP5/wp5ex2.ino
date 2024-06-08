// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2023) 
// Work package 5 
// Exercise 2
// Submission code: 121314AA (provided by your TA-s)

//Define section - define the pin being used & the size of the step for temperature cutoffs.
#define temp_pin A0
#define TEMP_STEP 10
int ThermistorPin = 0;
//Initialise variables to read thermistor values.
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1=0.7904710802e-3, c2=2.251846924e-4, c3=0.87060700625e-7;

//Instantiate the variable used for tempeture.
double temp = 0;

//Setup function for the program
void setup() {
  Serial.begin(9600);
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
  //Read the value from the temperature input pin. Circuit calculations provided courtesy of Jan Kelar, whom I owe a beer.
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  //Print out the current temperature.
  Serial.println(T);
  
  //Reset the output values.
  PORTD = B00000001;
  //Update the LEDs based on the temperature reading, by setting all bits right of the nearest cutoff to 1.
  PORTD = (PORTD << (int) T/TEMP_STEP + 1) * 2 - 1;
}

void loop() {
  //Twidling its thumbs, and letting the interrupts do the work.
}
