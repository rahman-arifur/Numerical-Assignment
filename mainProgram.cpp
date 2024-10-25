#include <bits/stdc++.h>
using namespace std;
#include "jacobi_gauss.hpp"
#include "NonLinear.hpp"
int main() {
    int type = 0;
    do {
        cout << "0. Exit\n1. Linear Equation Solve\n2. Non-liner Equation Solve\n3. Differential Equation Solve\n4. Matrix inversion\nEnter your choice: "; 
        cin >> type;
        if (type == 1) {
            cout << "Enter the size of the matrix: ";
            int N; cin >> N;
            vector<vector<double>> matrix(N, vector<double>(N + 1));
            cout << "Enter the augmented matrix (coefficients and constants):\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j <= N; j++) {
                    cin >> matrix[i][j];
                }
            }
            cout << "Solution of Linear Equations: \n\n";
            cout << "a. Jacobi iterative method\nb. Gauss-Seidel iterative method\nc. Gauss elimination\nd. Gausss-Jordan elimination\ne. LU factorization";
            char c; cin >> c;
            
            if (c == 'a') {

            }
            else if (c == 'b') {

            }
            else if (c == 'd') {

            }
            else if (c == 'e') {

            }
        }
        else if (type == 2) {
            cout << "Max power of variable: ";
            int n; cin >> n;
            vector<double> a(n + 1);
            cout << "input in the form anx^n + a(n-1)x^(n-1) + ... + a1x + a0 = 0\n";
            for (int i = n; i >= 0; i--) cin >> a[i];
            cout << "\na. Bi-section Method\nb. False Position Method\nc. Secant Method\nd. Newton-Raphson Method\n";
            cout << "Select the method: ";
            char c; cin >> c;
            if (c == 'a' or c == 'b') {
                double a, b;
                cout << "Enter interval (a, b): ";
                cin >> a >> b;

            }
        }
        else if (type == 3) {

        }
        else if (type == 4) {

        }
        else type = 0;
    } while (type);
    return 0;
}
