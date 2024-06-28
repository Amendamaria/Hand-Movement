#include <Servo.h>

// Create a Servo object
Servo myServo;

// Define the pin where the servo is connected
const int lHand = 9;
const int rHand = 10;

// Define the desired speed (delay between each step in milliseconds)
int speedDelay = 15; // Adjust this value to control speed (lower value = faster movement)

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);
}

void loop() {
  // Move the servo from 0 to 180 degrees at the specified speed
  moveServoSmoothly(100, 180, speedDelay);

  // Move the servo from 180 to 0 degrees at the specified speed
  moveServoSmoothly(180, 100, speedDelay);

  // Pause for a moment before repeating
  // delay(1000);
}

// Function to move the servo smoothly from startAngle to endAngle
void moveServoSmoothly(int startAngle, int endAngle, int delayTime) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      myServo.write(angle);
      delay(delayTime); // Delay to control speed
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      myServo.write(angle);
      delay(delayTime); // Delay to control speed
    }
  }
}
