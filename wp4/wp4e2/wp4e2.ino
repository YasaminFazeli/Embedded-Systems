// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 4 
// Exercise 2
// Submission code: 8989cc (provided by your TA-s) 

// including servo library
#include <Servo.h>

// variable declaration
Servo myservo;    // instantiating servo
int count = 0;    // instantiating count for timer
int second = 0;   // instantiating the second
int clockwise = 1;  // boolean for clockwise 

void setup() {  
  myservo.attach(10); // attaching the pin to the servo
  Serial.begin(9600); // starting the serial
  cli();  // stoping all the interrupts
    //set timer2 interrupt at 8kHz
    TCCR2A = 0;// set entire TCCR2A register to 0
    TCCR2B = 0;// same for TCCR2B
    TCNT2  = 0;//initialize counter value to 0
    // set compare match register for 8khz increments
    OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM21);
    // Set CS21 bit for 8 prescaler
    TCCR2B |= (1 << CS21);   
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);
  sei();  //allow interrupts
}

void loop() {

}

// timer2 method, calling the method inside 8000 times per second
ISR(TIMER2_COMPA_vect){
  timer();
} 

// method to call the functions after timer2 has ticked 8000 times (1 second)
void timer() {
  count++;        // increasing the count by one
  if(count == 8000) { // when reached 8000 (1 second)
    time();     // calling the time method
    move();     // calling the move method
    count = 0;    // setting the count to 0
  }
}

// moving the servo 
void move() {
  int position = map(second, 0, 60, 0, 180);  // map the time to position (between 0-180)
  myservo.write(position);            // setting the position for the servo
}

// increasing the time
void time() {
  if (second == 60 || second == -1) { // when the "clock" turns 180 degrees
    clockwise = !clockwise;       // change the rotation
  }
  
  if(clockwise) {       // when it’s clockwise
    second++;         // increase the time by 1
  }
  else if (!clockwise) {    // when it’s anticlockwise 
    second--;         // decrease the time by 1
  }
  
  if(second != -1)        // if the second variable is not -1, print the time on the serial
  Serial.println(second);   // printing the time
}
