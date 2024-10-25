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
vector<double> gaussElimination(vector<vector<double>> matrix) {
	int n = size(matrix);
    // Forward elimination process
    for (int i = 0; i < n - 1; i++) {
        // Pivoting: find the row with the maximum element in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap the rows if needed
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
        }

        // Eliminate entries below the pivot
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back substitution process
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--) {
            matrix[j][n] -= matrix[j][i] * solution[i];
        }
    }

    return solution;
}
