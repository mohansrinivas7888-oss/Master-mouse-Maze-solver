# High-Grip Traction Wheels (Differential Drive)

Master-Mouse utilizes lightweight, high-traction wheels coupled directly to the N20 / TT-BO DC gear motor shafts to translate rotational motor torque into precise linear displacement and rapid cornering across smooth maze surfaces.

## Phase 1: Mechanical & Geometric Specifications

The wheel assembly pairs a rigid ABS plastic hub with a high-friction rubber/silicone tread tire to minimize wheel slip during high-acceleration starts, hard braking, and zero-radius pivot turns.

### 1. Physical & Kinematic Parameters

* **Hub Material:** Molded ABS Composite
* **Tire / Tread Material:** High-Friction Silicone / Rubber Compound
* **Shaft Coupling Interface:** D-Profile / Dual-Flat Press-Fit Hub (zero backlash)
* **Wheel Diameter ($D$):** $42\text{ mm} - 65\text{ mm}$ (standard Micromouse / TT-BO profile)
* **Linear Displacement per Revolution ($C$):**

$$C = \pi \cdot D$$

* **Linear Velocity Relation ($v$):**

$$v = \omega \cdot r = \frac{2\pi \cdot r \cdot \text{RPM}}{60}$$

## Phase 2: Odometry & Traction Dynamics

Accurate maze cell tracking ($18\text{ cm}$ per unit cell) depends on maintaining consistent contact patch friction and minimizing rotational slip:

1. **Zero-Slip Torque Transfer:** The keyed D-shaft hub prevents the motor shaft from spinning independently inside the wheel bore under peak stall torque.
2. **Cornering Stability:** Narrow tread width reduces scrubbing friction during $90^\circ$ and $180^\circ$ in-place differential pivot turns.
3. **CAD Assembly Reference:** See the `.SLDPRT` / `.STEP` 3D model files in this directory for wheel hub geometry and chassis clearance.

---

## Component Visual Reference

![Micromouse Traction Wheel](./Wheels.jpg)
