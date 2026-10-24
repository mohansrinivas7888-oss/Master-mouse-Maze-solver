# Master-Mouse: Autonomous Maze Solver

An autonomous Micromouse robot engineered to navigate, map, and sprint unknown mazes without human intervention or GPS reliance.

---

## Overview


Master-Mouse operates on a two-phase navigation workflow:
1. **Search & Map Phase:** Systematically explores unknown corridors using wall detection and a dynamic **Flood Fill** algorithm to map grid weights and prevent circular loops.
2. **Speed Run Phase:** Computes the shortest trajectory using **A* / Dijkstra** pathfinding and executes a high-speed sprint to the maze center.

---

## Hardware Specifications

| Component | Detail | Purpose |
| :--- | :--- | :--- |
| **Microcontroller** | ESP32-S Core (Dual-Core, 240MHz) | Path computation and motor control loops |
| **Distance Sensors** | VL53L0X Laser Time-of-Flight (ToF) + Analog IR | Precise forward/lateral wall detection |
| **Motor Driver** | TB6612FNG Dual H-Bridge | PWM-based motor speed and direction |
| **Motors** | N120 / TT DC Micro Motors | High-torque wheel actuation |
| **Power Supply** | 7.4V 2S LiPo Battery Pack | Prevents brownouts during motor acceleration |
| **Development** | Arduino IDE / C++ | Firmware and sensor integration |

---

## System Architecture


The robot executes a continuous real-time control loop:
```text
  [SENSE]  ---> IR & VL53L0X ToF read distances at every cell
     │
     ▼
  [DECIDE] ---> ESP32 updates maze grid weights & runs Flood Fill / A*
     │
     ▼
  [DRIVE]  ---> TB6612FNG sends PWM pulses to drive N120 motors
     │
     └─── (Loop returns to Sense)
