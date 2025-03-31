# Runge-Kutta 4th Order Method

The **Runge-Kutta 4th Order Method** (RK4) is a numerical technique for solving ordinary differential equations (ODEs). It improves upon simpler methods like Euler's method by using weighted averages of slopes at multiple points.

### Basic Concept:

Given a differential equation dy/dx = f(x,y) with initial value y(x₀) = y₀, RK4 finds approximate values of y at different points.

### The Method:

1. **Calculate four slopes**:
   - m₁ = f(x, y)
   - m₂ = f(x + h/2, y + m₁h/2)
   - m₃ = f(x + h/2, y + m₂h/2)
   - m₄ = f(x + h, y + m₃h)

2. **Calculate weighted average**:
   - m = (m₁ + 2m₂ + 2m₃ + m₄)/6

3. **Update solution**:
   - y(x + h) = y + mh

where h is the step size.

### Key Features:

1. **Accuracy**:
   - 4th order accuracy (error ∝ h⁴)
   - More accurate than lower-order methods
   - Stable for most problems

2. **Implementation**:
   - Requires only function evaluations
   - No derivatives needed
   - Easy to program

3. **Limitations**:
   - More computations per step than simpler methods
   - Fixed step size in basic version
   - Not suitable for stiff equations

### Example Usage:
```c
// Solve dy/dx = 2y/x
float x0 = 1.0;    // Initial x
float y0 = 1.0;    // Initial y
float h = 0.1;     // Step size
float xp = 2.0;    // Target x

result = rungeKutta(x0, y0, xp, h);
```

### Best Practices:

1. **Choose appropriate step size**:
   - Smaller h: more accurate but slower
   - Larger h: faster but less accurate

2. **Verify results**:
   - Compare with analytical solution if available
   - Try different step sizes
   - Check for stability
