# Finite State Machine (FSM) Architecture

Master-Mouse operates on an event-driven Finite State Machine to transition between initialization, sensor calibration, maze exploration, return routing, and the high-speed run.

---

## State Diagram

```text
       ┌───────────────┐
       │     INIT      │
       └───────┬───────┘
               │ (Hardware & Sensor Checks OK)
               ▼
       ┌───────────────┐
       │   CALIBRATE   │
       └───────┬───────┘
               │ (Read Ambient IR Baselines)
               ▼
       ┌───────────────┐       Wall Detected       ┌───────────────┐
       │  SENSE_CELLS  │ ────────────────────────> │  UPDATE_MAP   │
       └───────▲───────┘                           └───────┬───────┘
               │                                           │
               │ (Step Complete)                           │ (Run Flood Fill)
               │                                           ▼
       ┌───────┴───────┐   PWM / Motor Pulse       ┌───────────────┐
       │     DRIVE     │ <──────────────────────── │ DECIDE_ACTION │
       └───────┬───────┘                           └───────────────┘
               │ (Center Coordinates Reached)
               ▼
       ┌───────────────┐
       │  RETURN_HOME  │ (Traverse back to Start [0,0])
       └───────┬───────┘
               │ (Ready for Final Run)
               ▼
       ┌───────────────┐
       │   SPEED_RUN   │ (Execute A* Shortest Path Sprint)
       └───────────────┘
