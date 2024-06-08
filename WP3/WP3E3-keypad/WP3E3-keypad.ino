// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 3 (keypad)
// Submission code: 0808xx (provided by your TA-s)

//Define constants for numbers of rows and columns.
const byte rows = 4;
const byte columns = 4;

//Create a table of characters, corresponding to that of the keypad.
char keys [rows][columns] {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Create arrays containing the numbers of the column and row pins.
int row_pins[rows] = {11, 10, 9, 8};
int column_pins[columns] = {7, 6, 5, 4};


void setup(){
  //Loop through each element of the row and column arrays.
  for(int i = 0; i < 4; i++){
    pinMode(row_pins[i], OUTPUT);
    pinMode(column_pins[i], INPUT);
  }
  Serial.begin(9600);
}

void loop(){
  //Loop through all existing rows
  for (int i = 0; i < rows; i++){
    //Take readings of all the column pins.
    digitalWrite(row_pins[i], LOW);
    int c1 = digitalRead(7);
    int c2 = digitalRead(6);
    int c3 = digitalRead(5);
    int c4 = digitalRead(4);
    //Reset the power to base level.
    digitalWrite(row_pins[i], HIGH);
  
    //Check if the character is present in the current column
    if(c1*c2*c3*c4==0){
      //Creae an output character, by taking the value of the appropriate column, multiplied by the index of the proper character.
      char output_char = keys[i][0]*!c1 +
                          keys[i][1]*!c2 +
                         keys[i][2]*!c3 +
                         keys[i][3]*!c4;
      //Print out the output character.
      Serial.println(output_char);
      //Wait 1 sec.
      delay(500);
    }
  } 
}
