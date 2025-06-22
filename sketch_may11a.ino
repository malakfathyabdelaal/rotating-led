int emptyLetter[]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int A[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int C[] = {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};
int F[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0};
int I[] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};
int U[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
// contain the binary representation of A,C,F,I,U according to the 5x8 grid of LEDs.

int*lettersarr[] = {A, C, F, I,U}; // array of pointers to letter arrays

int Spacebt_letters; //to adjust the space between the letters
int dotdisblayTime; //time for dots to appear

void setup() {
  Serial.begin(9600);// initializes serial communication
  for ( int i = 2; i < 10 ; i++ ) {
    pinMode(i, OUTPUT);// sets pins 2-9 as output pins
  }
  Spacebt_letters= 6;    // defining the space between the letters (ms)
  dotdisblayTime = 1;        // defining the time dots appear (ms)
}


// Function to print the letter represented by a binary array

void printLetter(int letter[]) {
  int y; // y is the loop variable for rows

  // Iterate over the first 8 rows
  for (y = 0; y < 8; y++) {       // printing the first  row of the letter
    digitalWrite(y + 2, letter[y]);// write the first row to the corresponding pin (2-9)
  }
  delay(dotdisblayTime);// delay for dot time

  // Iterate over the second 8 rows
  for (y = 0; y < 8; y++) {       // printing the second  row of the letter
    digitalWrite(y + 2, letter[y + 8]); // Write the  second row to the corresponding pin (2-9)
  }
  delay(dotdisblayTime);// delay for dot time

  // Iterate over the third 8 rows
  for (y = 0; y < 8; y++) {       // printing the third  row of the letter
    digitalWrite(y + 2, letter[y + 16]);// Write the third row to the corresponding pin (2-9)
  }
  delay(dotdisblayTime); //delay for dot time

  // Iterate over the fourth 8 rows
  for (y = 0; y < 8; y++) {    //printing the fourth row of the letter
    digitalWrite(y + 2, letter[y + 24]); // write the fourth row to the corresponding pin(2-9)
  }
  delay(dotdisblayTime); //delay for dot time


// Iterate over the fourth 8 rows

  for (y = 0; y < 8; y++) {  //printing the fifth row of the letter
    digitalWrite(y + 2, letter[y + 32]); // write the fifth row to the corresponding pin(2-9)
  }
  delay(dotdisblayTime);//delay for dot time

// Clear the LEDs for letter spacing
  for (y = 0; y < 8; y++) {       
    digitalWrite(y + 2, 0); // Turn off LEDs
  }
  delay(Spacebt_letters); // Delay for letter spacing
}

void loop() {     
  // Print the letters "FCAI"      
  printLetter (F);
  printLetter (C);
  printLetter (A);
  printLetter (I);

  printLetter (emptyLetter);//print space

//print the letters "CU"
  printLetter (C);
  printLetter (U);

  printLetter (emptyLetter);//print space
}