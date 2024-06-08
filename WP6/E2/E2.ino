// (C) Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2023) 
// Work package 6
// Exercise 2 
// Submission code: 65828 (provided by your TA-s) 

//Define sensor pins.
#define trigPin 12
#define echoPin 11
#define buzzerPin 9
//Define distance thresholds, in cm.
#define maxDistance 200
#define distanceStep 60
#define criticalDistance 25

void setup(){
  //Initilise LED pins.
  DDRD = B00111100;
  PORTD = B00000000;
  //Initialise the buzzer pin.
  pinMode(buzzerPin, OUTPUT);
  //Initialise the proximity sensor pins.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin serial.
  Serial.begin(9600);
}

//Function to get the distance of the nearest object in front of the proximity sensor.
long getDistance(){
  //Initialise values to be read.
  long duration, cm;
  //Reset the sensor pin.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //Send out a 10 microsecond pulse.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Read the echo duration.
  duration = pulseIn(echoPin, HIGH);
  //Convert the duration to distance traveled.
  cm = duration * 0.034 / 2;
  //Print and return the result.
  Serial.println(cm);
  return cm;
}

//Function to update the lit LEDs, taking in distance as an argument.
void updateLights(int cm){
  //Reset the LED ports.
  PORTD = B00111100;
  //If the object is in critical range, delay to cause blinking.
  delay(100 * (cm <= criticalDistance));
  //Turn on the appropriate number of LEDs, or turn all LEDs of to cause blinking if the object is in critical range.
  (cm > criticalDistance) ? PORTD = PORTD >> (cm/distanceStep - 2) : PORTD = ~PORTD;
}

//Function to update the buzzer, taking in distance as an argument.
void updateBuzzer(int cm){
  //Turn the buzzer of if the nearest object is more than the maxDistance away, or appropriately increase its frequency, with an extra jolt when the object enters critical distance.
  (cm > maxDistance) ? noTone(buzzerPin) : tone(buzzerPin, ((maxDistance+distanceStep-cm)/distanceStep)*100 + 400 * (cm<=criticalDistance), 1000);
}

void loop(){
  //Get the distance of the nearest object in front of the proximity sensor.
  long distance = getDistance();
  //Update the LEDs and the buzzer, based on the distance.
  updateLights(distance);
  updateBuzzer(distance);
  //Delay for .1 second.
  delay(100);       
}
