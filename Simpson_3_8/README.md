# Simpson's 3/8 Rule

Simpson's 3/8 Rule is a numerical integration method that uses cubic interpolation to approximate definite integrals. It's an alternative to Simpson's 1/3 rule with different weighting factors.

### Basic Formula:

For an interval [a,b] divided into n subintervals (n must be multiple of 3):

∫[a to b] f(x)dx ≈ 3h/8[f(x₀) + 3f(x₁) + 3f(x₂) + 2f(x₃) + 3f(x₄) + 3f(x₅) + 2f(x₆) + ... + f(xₙ)]

where:
- h = (b-a)/n
- x₀ = a, xₙ = b
- n must be multiple of 3

### How It Works:

1. **Divide the Interval**:
   - Split [a,b] into n segments (n = 3m)
   - Calculate h = (b-a)/n

2. **Sum the Terms**:
   - First and last points: multiply by 1
   - Points at positions 3k: multiply by 2
   - All other points: multiply by 3

3. **Calculate Result**:
   - Multiply sum by 3h/8

### Key Features:

1. **Accuracy**:
   - Fourth-order method (error ∝ h⁴)
   - Similar accuracy to Simpson's 1/3 rule
   - Better for some types of functions

2. **Requirements**:
   - Number of segments must be multiple of 3
   - Equally spaced points
   - Continuous function

### Example Usage:
```c
// Integrate 1/(1+x²) from 0 to 1
float a = 0.0;    // Lower limit
float b = 1.0;    // Upper limit
int n = 99;       // Number of segments (multiple of 3)

result = simpsonsThreeEighthsRule(a, b, n);
// Result should be approximately π/4 ≈ 0.7854
```

### Practical Tips:

1. **Choosing n**:
   - Must be multiple of 3
   - Larger n for higher accuracy
   - Common values: 99, 102, 300

2. **Error Control**:
   - Compare with exact solutions
   - Try increasing n values
   - Check convergence pattern

### Comparison with 1/3 Rule:
- Similar accuracy in practice
- Different segment requirements
- Sometimes more convenient for certain n values
