/***********************
*
* Morse Code Generator Script
*
* This script is designed to produce Morse code vibrations for a predefined text.
* It offers flexibility for easy adaptation, allowing you to replace the vibration motor
* with alternative components such as an LED.
*
* Instructions:
* 1. Specify the desired message in the 'morseCode' function.
* 2. Adjust the delay timings for Morse code playback, as needed.
* 3. Optionally, modify the 'morseCharacter' function to include additional characters.
* 4. Experiment by substituting the vibration motor with other components for diverse outputs.
*
***********************/

const int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Morse code for the word 'HELLO'
  morseCode("Yunus");

  delay(2000);  // Pause between repetitions
}

// Function to convert a given message into Morse code and play it using vibration motor
void morseCode(String message) {
    // Iterate through each character in the message
  for (int i = 0; i < message.length(); i++) {
    // Extract the current character
    char letter = message.charAt(i);

    // Check if the character is a space (indicating a word break)
    if (letter == ' ') {
      delay(500);  // Pause between words
    } else {
      // Translate and play Morse code for each character
      morseCharacter(letter);
      delay(300);  // Pause between letters
    }
  }
}

void morseCharacter(char character) {
  // Convert lowercase letters to uppercase
  character = toupper(character);

  if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) {
    if (character == 'A' || character == 'a') {
      dot(); dash();
    } else if (character == 'B' || character == 'b') {
      dash(); dot(); dot(); dot();
    } else if (character == 'C' || character == 'c') {
      dash(); dot(); dash(); dot();
    } else if (character == 'D' || character == 'd') {
      dash(); dot(); dot();
    } else if (character == 'E' || character == 'e') {
      dot();
    } else if (character == 'F' || character == 'f') {
      dot(); dot(); dash(); dot();
    } else if (character == 'G' || character == 'g') {
      dash(); dash(); dot();
    } else if (character == 'H' || character == 'h') {
      dot(); dot(); dot(); dot();
    } else if (character == 'I' || character == 'i') {
      dot(); dot();
    } else if (character == 'J' || character == 'j') {
      dot(); dash(); dash(); dash();
    } else if (character == 'K' || character == 'k') {
      dash(); dot(); dash();
    } else if (character == 'L' || character == 'l') {
      dot(); dash(); dot(); dot();
    } else if (character == 'M' || character == 'm') {
      dash(); dash();
    } else if (character == 'N' || character == 'n') {
      dash(); dot();
    } else if (character == 'O' || character == 'o') {
      dash(); dash(); dash();
    } else if (character == 'P' || character == 'p') {
      dot(); dash(); dash(); dot();
    } else if (character == 'Q' || character == 'q') {
      dash(); dash(); dot(); dash();
    } else if (character == 'R' || character == 'r') {
      dot(); dash(); dot();
    } else if (character == 'S' || character == 's') {
      dot(); dot(); dot();
    } else if (character == 'T' || character == 't') {
      dash();
    } else if (character == 'U' || character == 'u') {
      dot(); dot(); dash();
    } else if (character == 'V' || character == 'v') {
      dot(); dot(); dot(); dash();
    } else if (character == 'W' || character == 'w') {
      dot(); dash(); dash();
    } else if (character == 'X' || character == 'x') {
      dash(); dot(); dot(); dash();
    } else if (character == 'Y' || character == 'y') {
      dash(); dot(); dash(); dash();
    } else if (character == 'Z' || character == 'z') {
      dash(); dash(); dot(); dot();
    }
  }
}

// Function to represent a short Morse code signal (dot)
void dot() {
  analogWrite(motorPin, 255);  // Maximum intensity
  delay(150); // Duration of the dot
  analogWrite(motorPin, 0);    // Turn off
  delay(150); // Pause between signals
}

// Function to represent a long Morse code signal (dash)
void dash() {
  analogWrite(motorPin, 255);  // Maximum intensity
  delay(450); // Duration of the dash
  analogWrite(motorPin, 0);    // Turn off
  delay(150); // Pause between signals
}
