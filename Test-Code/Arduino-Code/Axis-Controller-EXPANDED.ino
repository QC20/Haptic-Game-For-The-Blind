const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickButtonPin = 2;
const int vibratorPin = 8;

// Define the predefined path points
const int pathPoints[][2] = {
    {343, 341},  // Starting point
    {500, 341},  // Turn point 1
    {500, 600},  // Turn point 2
    {343, 600},  // Turn point 3
    {343, 341}   // End point
};
const int numPathPoints = sizeof(pathPoints) / sizeof(pathPoints[0]);

const int maxDeviation = 100;  // Maximum allowed deviation from the path

void setup() {
    pinMode(joystickButtonPin, INPUT_PULLUP);
    pinMode(vibratorPin, OUTPUT);
}

void loop() {
    int joystickX = analogRead(joystickXPin);
    int joystickY = analogRead(joystickYPin);
    bool joystickButtonPressed = digitalRead(joystickButtonPin) == LOW;

    int nearestPointIndex = findNearestPoint(joystickX, joystickY);
    int distanceToPath = calculateDistanceToPath(joystickX, joystickY, nearestPointIndex);

    if (distanceToPath > maxDeviation) {
        int vibrationIntensity = map(distanceToPath, maxDeviation, 0, 128, 255);
        analogWrite(vibratorPin, vibrationIntensity);
    } else {
        analogWrite(vibratorPin, 0);
    }

    if (joystickButtonPressed) {
        handleButtonPress(nearestPointIndex);
    }
}

int findNearestPoint(int x, int y) {
    int nearestIndex = 0;
    int shortestDistance = distanceSquared(x, y, pathPoints[0][0], pathPoints[0][1]);

    for (int i = 1; i < numPathPoints; i++) {
        int distance = distanceSquared(x, y, pathPoints[i][0], pathPoints[i][1]);
        if (distance < shortestDistance) {
            nearestIndex = i;
            shortestDistance = distance;
        }
    }

    return nearestIndex;
}

int distanceSquared(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return dx * dx + dy * dy;
}

int calculateDistanceToPath(int x, int y, int nearestIndex) {
    int x1 = pathPoints[nearestIndex][0];
    int y1 = pathPoints[nearestIndex][1];
    int x2 = pathPoints[(nearestIndex + 1) % numPathPoints][0];
    int y2 = pathPoints[(nearestIndex + 1) % numPathPoints][1];

    int A = y2 - y1;
    int B = x1 - x2;
    int C = x2 * y1 - x1 * y2;

    return abs(A * x + B * y + C) / sqrt(A * A + B * B);
}

void handleButtonPress(int nearestIndex) {
    if (nearestIndex == numPathPoints - 1) {
        vibrateNTimes(5);
    } else if (nearestIndex % 2 == 1) {
        vibrateNTimes(3);
    }
}

void vibrateNTimes(int n) {
    for (int i = 0; i < n; i++) {
        digitalWrite(vibratorPin, HIGH);
        delay(150);
        digitalWrite(vibratorPin, LOW);
        delay(150);
    }
}