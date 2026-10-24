# Micromouse Navigation Algorithms

Master-Mouse operates on a structured, two-phase algorithmic strategy to map and solve unknown $16 \times 16$ grid mazes without external telemetry or pre-loaded maps.

---

## Phase 1: Search & Maze Exploration

The exploration stage establishes connectivity and wall states across cells while updating a Manhattan distance array.

### 1. Flood Fill Logic
- Every cell $(x, y)$ in the $16 \times 16$ grid maintains a potential distance value relative to the target center:
  $$\text{Target Center} = \{(7,7), (7,8), (8,7), (8,8)\}$$
- The center cells are initialized to zero ($0$), and perimeter/intermediate cells increment based on Manhattan distance.
- At each cell arrival:
  1. Forward, left, and right sensors detect walls.
  2. The local cell wall memory bitmask is updated.
  3. If the current cell value is not exactly $1 + \min(\text{accessible neighbor values})$, a flood-fill recalculation recalculates neighboring cell weights.
  4. The robot steers into the lowest-value accessible neighboring cell.

---

## Phase 2: Speed Run (Optimal Path Sprint)

Once a path to the center is confirmed:
- **A\* / Dijkstra Path Execution:** The verified cell graph computes the absolute lowest cost path.
- **Diagonal & Straightaway Optimization:** Adjacent linear cells are combined into continuous straightaway velocity ramps, maximizing acceleration on clear straights and braking prior to $90^\circ$ turns.
