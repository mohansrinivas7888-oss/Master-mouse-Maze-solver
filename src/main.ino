#include <Wire.h>
#include <VL53L0X.h>
#include "config.h"

// Hardware instances
VL53L0X tofSensor;

// Robot orientation & position
int currentX = 0;
int currentY = 0;
Direction currentHeading = NORTH;

// Motor helper functions
void setMotorSpeed(int leftSpeed, int rightSpeed) {
    // Left motor direction
    if (leftSpeed >= 0) {
        digitalWrite(PIN_AIN1, HIGH);
        digitalWrite(PIN_AIN2, LOW);
    } else {
        digitalWrite(PIN_AIN1, LOW);
        digitalWrite(PIN_AIN2, HIGH);
        leftSpeed = -leftSpeed;
    }

    // Right motor direction
    if (rightSpeed >= 0) {
        digitalWrite(PIN_BIN1, HIGH);
        digitalWrite(PIN_BIN2, LOW);
    } else {
        digitalWrite(PIN_BIN1, LOW);
        digitalWrite(PIN_BIN2, HIGH);
        rightSpeed = -rightSpeed;
    }

    // Clamp PWM values
    analogWrite(PIN_PWMA, constrain(leftSpeed, 0, 255));
    analogWrite(PIN_PWMB, constrain(rightSpeed, 0, 255));
}

void moveForward() {
    setMotorSpeed(FORWARD_SPEED, FORWARD_SPEED);
}

void stopMotors() {
    setMotorSpeed(0, 0);
}

void turnLeft() {
    setMotorSpeed(-TURN_SPEED, TURN_SPEED);
    delay(250); // Calibrate delay based on chassis rotation
    stopMotors();
    currentHeading = (Direction)((currentHeading + 3) % 4);
}

void turnRight() {
    setMotorSpeed(TURN_SPEED, -TURN_SPEED);
    delay(250); // Calibrate delay based on chassis rotation
    stopMotors();
    currentHeading = (Direction)((currentHeading + 1) % 4);
}

void setup() {
    Serial.begin(115200);
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

    // Motor driver pin modes
    pinMode(PIN_PWMA, OUTPUT);
    pinMode(PIN_AIN1, OUTPUT);
    pinMode(PIN_AIN2, OUTPUT);
    pinMode(PIN_PWMB, OUTPUT);
    pinMode(PIN_BIN1, OUTPUT);
    pinMode(PIN_BIN2, OUTPUT);
    pinMode(PIN_STBY, OUTPUT);
    digitalWrite(PIN_STBY, HIGH); // Enable driver

    // Sensor pin modes
    pinMode(PIN_IR_LEFT, INPUT);
    pinMode(PIN_IR_RIGHT, INPUT);

    // Initialize Time-of-Flight sensor
    if (!tofSensor.init()) {
        Serial.println("Failed to detect VL53L0X ToF sensor!");
    } else {
        tofSensor.setTimeout(500);
        tofSensor.startContinuous();
    }

    Serial.println("Master-Mouse system initialized.");
    delay(1000);
}

void loop() {
    // 1. SENSE: Read clearance distances
    uint16_t frontDistance = tofSensor.readRangeContinuousMillimeters();
    int leftIR = analogRead(PIN_IR_LEFT);
    int rightIR = analogRead(PIN_IR_RIGHT);

    bool wallFront = (frontDistance < WALL_DISTANCE_THRESHOLD);
    bool wallRight = (rightIR > 2000); // ADC threshold for obstacle proximity
    bool wallLeft  = (leftIR > 2000);

    // 2. DECIDE: Wall-following / flood fill navigation logic
    if (!wallRight) {
        // Prioritize right wall opening
        turnRight();
        moveForward();
        delay(300);
    } else if (!wallFront) {
        // Proceed straight through corridor
        moveForward();
    } else if (!wallLeft) {
        // Turn toward open left flank
        turnLeft();
        moveForward();
        delay(300);
    } else {
        // Dead end: U-turn
        turnRight();
        turnRight();
    }

    // 3. DRIVE: Small control cycle delay
    delay(50);
}
