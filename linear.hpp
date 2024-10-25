#include <bits/stdc++.h>
using namespace std;

const double tolerance = 1e-5;
void jacobian(vector<vector<double>>& A, vector<double>& b, int maxIterations = 100) {
    int n = A.size();
    vector<double> x(n, 0.0);  
    vector<double> x_new(n, 0.0);

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
       
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
 bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x_new[i] - x[i]) > tolerance) {
                converged = false;
                break;
            }
        }
        x = x_new;
if (converged) {
            cout << "Converged in " << iteration + 1 << " iterations.\n";
            break;
        }
    }
    cout << "Solution:\n";
    for (int i = 0; i < n; ++i) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }
}

