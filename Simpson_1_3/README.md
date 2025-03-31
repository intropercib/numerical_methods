# Simpson's 1/3 Rule

Simpson's 1/3 Rule is a numerical integration method that approximates the definite integral of a function by using quadratic polynomials.

### Basic Formula:

For an interval [a,b] divided into n equal subintervals (n must be even):

∫[a to b] f(x)dx ≈ h/3[f(x₀) + 4f(x₁) + 2f(x₂) + 4f(x₃) + 2f(x₄) + ... + 4f(xₙ₋₁) + f(xₙ)]

where:
- h = (b-a)/n
- x₀ = a, xₙ = b
- n must be even

### How It Works:

1. **Divide the Interval**:
   - Split [a,b] into n even segments
   - Calculate h = (b-a)/n

2. **Sum the Terms**:
   - First and last points: f(a) and f(b)
   - Odd points: multiply by 4
   - Even points: multiply by 2

3. **Calculate Result**:
   - Multiply sum by h/3

### Key Features:

1. **Accuracy**:
   - Third-order method (error ∝ h⁴)
   - More accurate than trapezoidal rule
   - Exact for quadratic functions

2. **Requirements**:
   - Continuous function
   - Even number of segments
   - Equally spaced points

### Example Usage:
```c
// Integrate 1/(1+x²) from 0 to 1
float a = 0.0;    // Lower limit
float b = 1.0;    // Upper limit
int n = 100;      // Number of segments (even)

result = simpsonsRule(a, b, n);
// Result should be approximately π/4 ≈ 0.7854
```

### Practical Tips:

1. **Choosing n**:
   - Larger n: more accurate but slower
   - Must be even number
   - Start with n = 100 and adjust

2. **Error Checking**:
   - Compare with known results
   - Try different n values
   - Watch for oscillating results
