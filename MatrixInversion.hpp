#include <bits/stdc++.h>
using namespace std;
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            printf("%.6lf ", val);
        }
        puts("");
    }
    puts("");
}
vector<vector<double>> invertMatrix(vector<vector<double>> matrix) {
    int n = matrix.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = matrix[i][j];
        }
        augmented[i][i + n] = 1;
    }
    for (int i = 0; i < n; ++i) {
        double pivot = augmented[i][i];

        if (fabs(pivot) < 1e-6) {
            for (int row = i + 1; row < n; ++row) {
                if (fabs(augmented[row][i]) > 1e-6) {
                    swap(augmented[i], augmented[row]);
                    pivot = augmented[i][i];
                    break;
                }
            }
        }

        if (fabs(pivot) < 1e-6) {
            throw runtime_error("Matrix is singular and cannot be inverted.");
        }
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= pivot;
        }
        for (int row = 0; row < n; ++row) {
            if (row != i) {
                double multiplier = augmented[row][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[row][j] -= multiplier * augmented[i][j];
                }
            }
        }
    }
    vector<vector<double>> inverted(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverted[i][j] = augmented[i][j + n];
        }
    }
    return inverted;
}
void inputMatrix(vector<vector<double>>& matrix, int n) {
    cout << "Enter the coefficients of the matrix (space-separated):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}
