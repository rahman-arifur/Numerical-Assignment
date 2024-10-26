#include <bits/stdc++.h>
using namespace std;
const double tolerance = 1e-6;
#include "NonLinear.hpp"
#include "linear.hpp"
#include "MatrixInversion.hpp"
#include "RungeKutta.hpp"
int main() {
    int type = 0;
    do {
        cout << "0. Exit\n1. Linear Equation Solve\n2. Non-liner Equation Solve\n3. Differential Equation Solve\n4. Matrix inversion\nEnter your choice: "; 
        cin >> type;
        if (type == 1) {
            cout << "Enter the size of the matrix: ";
            int N; cin >> N;
            vector<vector<double>> matrix(N, vector<double>(N + 1));
            vector<double> B;
            cout << "Enter the augmented matrix (coefficients and constants):\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j <= N; j++) {
                    cin >> matrix[i][j];
                }
                B.push_back(matrix[i].back());
            }
            cout << "Solution of Linear Equations: \n\n";
            cout << "a. Jacobi iterative method\nb. Gauss-Seidel iterative method\nc. Gauss elimination\nd. Gausss-Jordan elimination\ne. LU factorization\n";
            char c; cin >> c;
            if (c == 'a') {
                jacobian(matrix, B);
            }
            else if (c == 'b') {
                auto x = gaussSeidel(matrix, B);
                if (size(x)) cout << "Solution:\n";
                for (int i = 0; i < size(x); ++i) {
                    printf("x[%d] = %.6lf\n", i, x[i]);
                }
            }
            else if (c == 'c') {
                auto x = gaussElimination(matrix);
                cout << "Solution:\n";
                for (int i = 0; i < N; ++i) {
                    printf("x[%d] = %.6lf\n", i, x[i]);
                }
            }
            else if (c == 'd') {
                auto x = gaussJordanElimination(matrix);
                cout << "Solution:\n";
                for (int i = 0; i < N; ++i) {
                    printf("x[%d] = %.6lf\n", i, x[i]);
                }
            }
            else if (c == 'e') {
                LUfactorization(matrix, B);
            }
            else cout << "Enter a valid option.\n";
        }
        else if (type == 2) {
            cout << "Max power of variable: ";
            int n; cin >> n;
            vector<double> A(n + 1);
            cout << "input in the form anx^n + a(n-1)x^(n-1) + ... + a1x + a0 = 0\n";
            for (int i = n; i >= 0; i--) cin >> A[i];
            cout << "\na. Bi-section Method\nb. False Position Method\nc. Secant Method\nd. Newton-Raphson Method\n";
            cout << "Select the method: ";
            char c; cin >> c;
            if (c == 'a' or c == 'b') {
                double a, b;
                cout << "Enter interval (a, b): ";
                cin >> a >> b;
                if (c == 'a') {
                    cout << "Bi-section Method solution: \n";
                    bisection(A, a, b);
                } else {
                    cout << "False Position Method solution: \n";
                    falsePosition(A, a, b);
                }
            }
            else if (c == 'c') {
                cout << "Secant Method solution:\n";
                secant(A);
            }
            else if (c == 'd') {
                cout << "Newton-Raphson Method solution:\n";
                newtonRaphson(A);
            }
            else cout << "please enter a valid choice.\n";
        }
        else if (type == 3) {
            cout << "Choose an equation to solve:\n";
            cout << "1. dy/dx = a * sin(x) + b * cos(x)\n";
            cout << "2. dy/dx = a * x^2 + b * x + c\n";
            cout << "3. dy/dx = e^(m * x)\n";
            cout << "4. dy/dx = p * x^a + q * y^b\n";
            int choice; cin >> choice;
            // Input initial conditions and step size
            double y0, x0, xf, h;
            cout << "Enter initial value y0: "; cin >> y0;
            cout << "Enter initial x value x0: "; cin >> x0;
            cout << "Enter final x value xf: "; cin >> xf;
            cout << "Enter step size h: "; cin >> h;

            vector<double> params;
            if (choice == 1) {
                double a, b;
                cout << "Enter values for a and b: ";
                cin >> a >> b;
                params = {a, b};
            } else if (choice == 2) {
                double a, b, c;
                cout << "Enter values for a, b, and c: ";
                cin >> a >> b >> c;
                params = {a, b, c};
            } else if (choice == 3) {
                double m;
                cout << "Enter value for m: ";
                cin >> m;
                params = {m};
            } else if (choice == 4) {
                double p, q, a, b;
                cout << "Enter values for p, q, a, and b: ";
                cin >> p >> q >> a >> b;
                params = {p, q, a, b};
            } else {
                cout << "Invalid choice!"; break;
            }

            // Select the equation and solve it
            auto selectedEquation = selectEquation(choice, params);
            auto result = rk4(selectedEquation, y0, x0, xf, h);

            // Display results
            cout << "solution\n";
            auto [x, y] = result.back();
            // for (const auto& [x, y] : result) {
                cout << "x = " << x << ", y = " << y << endl;
            // }

        }
        else if (type == 4) {
            cout << "size of the matrix: ";
            int n; cin >> n;
            vector matrix(n, vector<double> (n));
            inputMatrix(matrix, n);
            cout << "inverted matrix\n";
            printMatrix(invertMatrix(matrix));
        }
        else type = 0;
        cout << '\n';
    } while (type);
    return 0;
}
