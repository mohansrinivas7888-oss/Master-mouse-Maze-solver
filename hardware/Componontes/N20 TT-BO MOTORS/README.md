# N20 / TT-BO 6V DC Micro Gear Motor

Master-Mouse utilizes **6V DC Gear Motors** (N20 / TT-BO series) in a differential-drive configuration to provide high-torque propulsion, rapid acceleration, and precise pivot turns within $18\text{ cm} \times 18\text{ cm}$ maze corridors.

## Phase 1: Electromechanical Specifications

The actuator pairs a high-speed brushed permanent-magnet DC motor with a reduction gearbox, converting high rotational velocity into the low-speed, high-torque output required for rapid maze traversal.

### 1. Operating Parameters

* **Motor Type:** Brushed DC Gear Motor (N20 / TT-BO Series)
* **Operating Voltage Range:** $3.0\text{ V}$ to $6.0\text{ V DC}$ (Driven via TB6612FNG PWM)
* **Nominal Voltage:** $6.0\text{ V DC}$
* **Current Consumption ($@\,6\text{ V}$):**

$$I_{\text{no-load}} \approx 70\text{ mA} - 150\text{ mA}, \quad I_{\text{stall}} \approx 0.8\text{ A} - 1.5\text{ A}$$

* **No-Load Rotational Speed ($@\,6\text{ V}$):** $200\text{ RPM} - 300\text{ RPM}$ (dependent on gear reduction ratio)
* **Output Shaft Type:** D-Profile / Dual-Flat Shaft for zero-slip wheel coupling

## Phase 2: Kinematics & Differential Drive Control

Two independent motors drive the left and right wheels, allowing the robot to execute straight-line sprints and zero-radius point turns by varying the relative angular velocities ($\omega_L, \omega_R$) via the **TB6612FNG** dual H-bridge driver:

$$\begin{aligned}
\omega_L = \omega_R &> 0 \implies \text{Forward Linear Translation} \\
\omega_L = -\omega_R &\neq 0 \implies \text{Zero-Radius In-Place Pivot Turn}
\end{aligned}$$

### 1. Closed-Loop Integration

1. **PWM Speed Modulation:** Driven by high-frequency PWM signals from the **ESP32-S3** to regulate linear velocity during maze exploration and high-speed runs.
2. **Dynamic Braking:** Supports rapid short-braking through the H-bridge driver to eliminate overshoot at maze cell boundaries and $90^\circ$ corners.
3. **3D CAD Asset:** See [`Mini Gear DC Motor 6 V Yellow.STEP`](./Mini%20Gear%20DC%20Motor%206%20V%20Yellow.STEP) in this directory for mechanical chassis mounting and clearance geometry.
