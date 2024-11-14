# Bisection Method

The **Bisection Method** is one of the simplest and most widely used methods for solving **non-linear equations**. It is a **bracket method**, meaning it requires two initial guesses that bound the root of the function. The method is based on the **Intermediate Value Theorem**, which states that if a continuous function changes signs over an interval, then the function has at least one root within that interval.

### Key Characteristics of the Bisection Method:

- **Guaranteed Convergence**: The bisection method is guaranteed to converge if the initial guesses are chosen correctly, i.e., if the function values at the two guesses have opposite signs (i.e., f(a) \* f(b) < 0).
- **Slower Convergence**: Compared to methods like Newton's method, the bisection method has slower convergence. However, it’s robust and reliable.
- **Root-Finding Interval**: The method doesn't require the calculation of the derivative of the function, making it applicable to a wide range of problems.

### How the Bisection Method Works:

1. **Start with an Interval**:

   - Select two initial guesses, \(a\) and \(b\), such that the function \(f(a)\) and \(f(b)\) have opposite signs. This ensures that the root lies between them (because of the Intermediate Value Theorem).

2. **Find the Midpoint**:

   - Calculate the midpoint of the interval as \(m = \frac{a + b}{2}\).

3. **Evaluate the Function**:

   - Compute the function value at the midpoint, \(f(m)\).

4. **Check the Root Location**:

   - If \(f(m) = 0\), then \(m\) is the root, and the process terminates.
   - If \(f(a) \* f(m) < 0\), then the root lies between \(a\) and \(m\), so update the interval to \([a, m]\).
   - If \(f(m) \* f(b) < 0\), then the root lies between \(m\) and \(b\), so update the interval to \([m, b]\).

5. **Repeat**:

   - The method repeats steps 2-4, narrowing the interval with each iteration. After each iteration, the interval is halved, and the root is narrowed down to a smaller range.

6. **Stopping Criterion**:
   - The process continues until the length of the interval is smaller than a pre-defined tolerance or a maximum number of iterations is reached. The midpoint \(m\) will be the estimated root.

### Advantages of the Bisection Method:

- **Guaranteed Convergence**: If the function is continuous and the initial guesses `a` and `b` bracket the root, the method will always converge to a root.
- **Simplicity**: The algorithm is simple to implement and doesn't require derivative calculations.
- **Robustness**: Works well even for functions that are difficult to differentiate.

### Disadvantages of the Bisection Method:

- **Slow Convergence**: The method converges relatively slowly compared to other root-finding methods like Newton's method.
- **Requires Bracketing**: It requires the initial guesses `a` and `b` to be chosen such that the function values at these points have opposite signs. This might not always be possible if the root is not easily bracketed.
- **Not Effective for Multiple Roots**: If the function has multiple roots in the interval, the bisection method only finds one of them, which might not be the desired root.

### Use Cases for Bisection Method:

- The bisection method is often used in cases where the function is continuous but difficult to differentiate or where other methods might fail due to lack of initial information.
- It is particularly useful for solving equations in scientific computations, engineering, and mathematics.

In summary, the **Bisection Method** is a reliable, straightforward technique for solving non-linear equations that guarantees convergence but with slower convergence rates compared to other methods.
