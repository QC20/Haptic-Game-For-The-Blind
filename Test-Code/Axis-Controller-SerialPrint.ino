const int joystickXPin = A0;      // Joystick X-axis analog pin
const int joystickYPin = A1;      // Joystick Y-axis analog pin
const int vibrationMotorPin = 8;  // Vibration motor pin

struct Waypoint {
  int x;
  int y;
};

// Define the correct path waypoints
Waypoint correctPath[] = {
  {10, 0},   // Start
  {10, 5},
  {0, 5},
  {0, 15},
  {10, 15},
  {10, 10},
  {25, 10},
  {25, 20},
  {17, 20},
  {17, 14},
  {11, 14},
  {11, 27},
  {15, 27}    // End
};

int currentWaypoint = 0;

void setup() {
  pinMode(vibrationMotorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int joystickX = analogRead(joystickXPin);
  int joystickY = analogRead(joystickYPin);

  String direction = getJoystickDirection(joystickX, joystickY);
  
  // Update the current position based on joystick movement
  updateCurrentPosition(direction);

  // Check if the current position is part of the correct path
  bool isOnCorrectPath = checkCorrectPath(currentWaypoint, joystickX, joystickY);

  Serial.print("Current Position: ");
  Serial.println(currentWaypoint);
  Serial.print("Waypoint: ");
  Serial.print(correctPath[currentWaypoint].x);
  Serial.print(", ");
  Serial.println(correctPath[currentWaypoint].y);

  if (isOnCorrectPath) {
    digitalWrite(vibrationMotorPin, LOW); // No vibration
  } else {
    digitalWrite(vibrationMotorPin, HIGH); // Vibrate to indicate deviation
  }

  // Additional loop code if needed
}

String getJoystickDirection(int x, int y) {
  if (x < 300) {
    return "left";
  } else if (x > 700) {
    return "right";
  } else if (y < 300) {
    return "up";
  } else if (y > 700) {
    return "down";
  } else {
    return "neutral";
  }
}

void updateCurrentPosition(String direction) {
  if (direction == "up") {
    currentWaypoint--; // Move backwards in the path
    if (currentWaypoint < 0) {
      currentWaypoint = 0; // Don't go before the start
    }
  } else if (direction == "down") {
    currentWaypoint++; // Move forwards in the path
    if (currentWaypoint >= sizeof(correctPath) / sizeof(correctPath[0])) {
      currentWaypoint = sizeof(correctPath) / sizeof(correctPath[0]) - 1; // Don't go beyond the end
    }
  }
}

bool checkCorrectPath(int waypointIndex, int currentX, int currentY) {
  if (waypointIndex >= sizeof(correctPath) / sizeof(correctPath[0])) {
    // Reached the end of the correct path
    return true;
  }
  
  int expectedX = correctPath[waypointIndex].x;
  int expectedY = correctPath[waypointIndex].y;
  
  int thresholdX = 10; // Adjust these thresholds as needed
  int thresholdY = 10; // Adjust these thresholds as needed
  
  // Compare current joystick position with expected waypoint position using thresholds
  if (abs(currentX - expectedX) <= thresholdX && abs(currentY - expectedY) <= thresholdY) {
    return true;
  }
  
  return false;
}