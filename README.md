
# Console application focused on solving linear and non linear equation, some basic differential equations and matrix inversion.

### 1. Solution of Linear Equations
   - **Jacobi Iterative Method**
   - **Gauss-Seidel Iterative Method**
   - **Gauss Elimination**
   - **Gauss-Jordan Elimination**
   - **LU Factorization**

### 2. Solution of Non-linear Equations
   - **Bi-section Method**
   - **False Position Method**
   - **Secant Method**
   - **Newton-Raphson Method**

### 3. Solution of Differential Equations
   - **Runge-Kutta Method**

### 4. Matrix Inversion

## Deployment

### To deploy this project run

```bash
  git clone https://github.com/rahman-arifur/Numerical-Assignment.git
```

### To run the project
```bash
Compile and Run mainProgram.cpp file
```
## Explanation
### 1. Solution of Linear Equations
- **Jacobi Iterative Method**: Iteratively solves a system of linear equations using an initial guess and refines it until convergence. We made sure that the matrix was diagonally dominant.
   ```
  Repeat until convergence:
      For each variable x_i:
          x_new[i] = (b[i] - sum(A[i][j] * x[j] for j ≠ i)) / A[i][i]
      Update x with x_new
   ```
- **Gauss-Seidel Iterative Method**: Similar to Jacobi but updates each variable immediately within the same iteration, leading to faster convergence.
   ```
   Repeat until convergence:
    For each variable x_i:
        x[i] = (b[i] - sum(A[i][j] * x[j] for j < i) - sum(A[i][j] * x_old[j] for j > i)) / A[i][i]
   ```
- **Gauss Elimination**: A direct method for transforming the coefficient matrix to upper triangular form and solving via back-substitution.
   ```
   For each row i:
    Normalize row i to make A[i][i] = 1
    Eliminate elements below A[i][i] in column i
   Back-substitute to solve
   ```
- **Gauss-Jordan Elimination**: An extension of Gauss elimination, fully reducing the matrix to find solutions directly.
   ```
   For each row i:
   Normalize row i to make A[i][i] = 1
   Eliminate elements in column i for all other rows
   ```
- **LU Factorization**: Decomposes the matrix into lower and upper triangular matrices, simplifying the solution of multiple systems with the same matrix.
   ```
   Decompose A into L and U such that A = L * U
   Solve L * y = b for y
   Solve U * x = y for x
   ```
### 2. Solution of Non-Linear Equations
- **Bisection Method**: Finds the root of a continuous function by repeatedly bisecting the interval.
   ```
   While interval [a, b] is large:
    c = (a + b) / 2
    If f(c) is close to zero, return c
    Else if f(a) * f(c) < 0, set b = c
    Else set a = c
   ``
- **False Position Method**: Combines the bisection and secant methods, selecting points based on function values to find roots.
   ```
   Repeat until convergence:
    c = b - f(b) * (b - a) / (f(b) - f(a))
    If f(c) is close to zero, return c
    Else if f(a) * f(c) < 0, set b = c
    Else set a = c
   ``
- **Secant Method**: Uses two initial points to approximate roots, improving efficiency compared to the bisection method.
   ```
   Repeat until convergence:
    x_new = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
    Update x0 = x1, x1 = x_new
   ```
- **Newton-Raphson Method**: Iterative method utilizing the function's derivative for rapid convergence to a root.
   ```
   Repeat until convergence:
    x_new = x - f(x) / f'(x)
    Update x = x_new
   ```
### 3. Solution of Differential Equations
- **Runge-Kutta Method**: A fourth-order method for solving ordinary differential equations, providing a balance between efficiency and accuracy.
   ```
   For each step from t_0 to t_n:
    k1 = h * f(t, y)
    k2 = h * f(t + h/2, y + k1/2)
    k3 = h * f(t + h/2, y + k2/2)
    k4 = h * f(t + h, y + k3)
    y = y + (k1 + 2*k2 + 2*k3 + k4) / 6
    ```
### 4. Matrix Inversion
- Implements an algorithm to invert matrices, essential for solving systems of equations and other linear algebra applications.
   ```
   Augment matrix A with the identity matrix
   Apply Gauss-Jordan elimination on A to form the identity matrix
   Resultant augmented matrix is the inverse of A
   ```

## Lessons Learned
Through this assignment we learned about the practical use of git and github. This assignment gave us an overview of how to work in groups and collaborate in a project properly
We did go through mismanagement and misconnections while working on this assignment online. It did really made us understand how group work happens in the industry. 

## Group Members

- [Arifur Rahman](https://github.com/rahman-arifur)
- [Shakibuzzaman Akash](https://github.com/ShakibAkash)
- [Nuzhat Tasmin](https://github.com/NuzhatTasnim82)
