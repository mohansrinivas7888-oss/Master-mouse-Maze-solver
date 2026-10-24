#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// --- Maze Dimensions ---
#define MAZE_WIDTH  16
#define MAZE_HEIGHT 1=8

// --- TB6612FNG Motor Driver Pins ---
#define PIN_PWMA  4   // Left motor PWM speed
#define PIN_AIN1 16   // Left motor direction 1
#define PIN_AIN2 17   // Left motor direction 2
#define PIN_PWMB 18   // Right motor PWM speed
#define PIN_BIN1 19   // Right motor direction 1
#define PIN_BIN2 23   // Right motor direction 2
#define PIN_STBY  5   // Motor driver standby pin

// --- Distance Sensor Pins ---
#define PIN_IR_LEFT   34  // Analog pin for Left IR sensor
#define PIN_IR_RIGHT  35  // Analog pin for Right IR sensor
#define PIN_I2C_SDA   21  // ESP32 default SDA for VL53L0X ToF
#define PIN_I2C_SCL   22  // ESP32 default SCL for VL53L0X ToF

// --- Navigation & Thresholds (mm) ---
#define WALL_DISTANCE_THRESHOLD 120  // Wall presence detection limit
#define FORWARD_SPEED           180  // PWM value (0 - 255)
#define TURN_SPEED              150  // PWM value (0 - 255)

// --- Direction Constants ---
enum Direction {
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3
};

#endif // CONFIG_H
