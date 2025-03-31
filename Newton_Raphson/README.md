# Newton-Raphson Method

The **Newton-Raphson Method** is a widely used iterative technique for finding the roots of a real-valued function. It is an open method, meaning it requires an initial guess, but it does not require two initial guesses as in methods like the Bisection method. This method uses the **tangent line** at a point to approximate the root of the function.

<div style="background:white; width:200px; height:200px; margin:0 auto;"><img src="https://upload.wikimedia.org/wikipedia/commons/8/83/Methode_newton.png" height="200px" width="200px"> </div>

###### Image Source: [Wikipedia](https://en.wikipedia.org/wiki/Newton%27s_method)

### Key Characteristics of the Newton-Raphson Method:

- **Fast Convergence**: The Newton-Raphson method generally converges faster than methods like the Bisection method, especially when the initial guess is close to the root.
- **Derivative Required**: This method requires the derivative of the function, making it less applicable when the derivative is difficult to compute.
- **Open Method**: Unlike the Bisection method, the Newton-Raphson method only requires a single initial guess.

### How the Newton-Raphson Method Works:

1. **Start with an Initial Guess**:

   - Choose an initial guess \(x_0\) that is close to the root of the function. The method works best if the initial guess is close to the actual root.

2. **Apply the Newton-Raphson Formula**:

   - The formula used for iteration is:
     \[
     x\_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
     \]
   - Here, \(f(x)\) is the function for which we are trying to find the root, and \(f'(x)\) is the derivative of the function.

3. **Check for Convergence**:

   - After applying the formula, check if the difference between the current approximation and the previous one is smaller than a pre-defined tolerance, or if a maximum number of iterations has been reached.

4. **Repeat**:

   - If the stopping criterion is not met, repeat the process by using the new value of \(x\_{n+1}\) as the next guess. This process is repeated until the root is found with sufficient accuracy.

5. **Stopping Criterion**:
   - The process continues until the difference between consecutive approximations is smaller than the desired tolerance, i.e., \(|x\_{n+1} - x_n| < \text{tolerance}\), or a maximum number of iterations is reached. The method will return the value of \(x\) as the estimated root.

### Advantages of the Newton-Raphson Method:

- **Fast Convergence**: When the initial guess is close to the true root, the Newton-Raphson method converges very quickly, often with quadratic convergence.
- **Requires Only One Guess**: Unlike methods like Bisection, which require two initial guesses, the Newton-Raphson method only needs a single initial guess.
- **Widely Used**: The method is widely used in numerical methods, engineering, and computational mathematics due to its speed and effectiveness when applicable.

### Disadvantages of the Newton-Raphson Method:

- **Derivative Calculation**: The method requires the derivative of the function. This can be difficult or cumbersome to compute for complex functions.
- **Poor Convergence for Bad Initial Guesses**: If the initial guess is far from the true root, or if the derivative at the guess is zero (or near zero), the method can diverge or fail to converge.
- **Not Suitable for Functions Without Derivatives**: If the function is not differentiable, or the derivative does not exist at the root, the method cannot be used.
- **Multiple Roots**: The method may not reliably find all roots in a function, especially if there are multiple roots.

### Use Cases for the Newton-Raphson Method:

- The Newton-Raphson method is particularly effective for finding roots of functions where derivatives are easily computable.
- It is widely used in scientific computing, optimization problems, and engineering applications, particularly for solving equations in physics, chemistry, and economics.
- The method is often used in applications such as solving nonlinear equations in circuit analysis, fluid dynamics, and other engineering disciplines.

In summary, the **Newton-Raphson Method** is an efficient and fast technique for solving non-linear equations, but it requires the function's derivative and an appropriate initial guess. When the conditions are favorable, it converges quickly and accurately to the root of the function. However, it can be less reliable for poorly chosen initial guesses or functions with tricky derivatives.
