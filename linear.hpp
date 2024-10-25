const double tolerance = 1e-5;
bool makeDiagonallyDominant(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    vector<int> used(n, 0); // To track if a row has been used in reordering

    for (int i = 0; i < n; ++i) {
        int maxRow = -1;
        double maxValue = 0.0;

        // Find the row with the largest absolute value in the current column
        for (int k = 0; k < n; ++k) {
            if (!used[k] && fabs(A[k][i]) > maxValue) {
                maxValue = fabs(A[k][i]);
                maxRow = k;
            }
        }

        // If no suitable row found, return false (cannot make it diagonally dominant)
        if (maxRow == -1 || maxValue == 0) {
            return false;
        }

        // Swap rows if maxRow is not the current row
        if (maxRow != i) {
            swap(A[i], A[maxRow]);
            swap(b[i], b[maxRow]);
        }

        // Mark the row as used
        used[maxRow] = 1;
    }

    // Verify if it is now diagonally dominant
    for (int i = 0; i < n; ++i) {
        double rowSum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i != j) rowSum += fabs(A[i][j]);
        }
        if (fabs(A[i][i]) <= rowSum) {
            return false; // Not diagonally dominant
        }
    }
    return true; // Successfully made it diagonally dominant
}

void jacobian(vector<vector<double>> &A, vector<double> &b, int maxIterations = 100) {
    int n = A.size();
    vector<double> x(n, 0.0);
    vector<double> x_new(n, 0.0);

    if (!makeDiagonallyDominant(A, b)) {
        cout << "Matrix cannot be made diagonally dominant. Jacobi method may not converge.\n";
        return;
    }

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

vector<double> gaussJordanElimination(vector<vector<double>>& matrix) {
	int n = size(matrix);
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        double diag = matrix[i][i];
        if (diag == 0) {
            cout << "Matrix is singular and cannot be solved using Gauss-Jordan Elimination." << endl;
            return {}; // Return empty vector if there's no unique solution
        }
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= diag;
        }

        // Make all other elements in the current column 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Extract solutions from the last column
    vector<double> solution(n);
    for (int i = 0; i < n; i++) {
        solution[i] = matrix[i][n];
    }

    return solution;
}

void LUfactorization(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
      
        for (int k = i; k < n; ++k) {
            double sum = 0.0;
            for (int j = 0; j < i; ++j)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

       
        for (int k = i; k < n; ++k) {
            if (i == k)
                L[i][i] = 1.0; 
            else {
                double sum = 0.0;
                for (int j = 0; j < i; ++j)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    vector<double> y(n, 0.0);
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j)
            sum += L[i][j] * y[j];
        y[i] = (b[i] - sum);
    }
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }
    cout << "Solution:\n";
    for (int i = 0; i < n; ++i) {
        printf("x[%d] = %.6lf\n", i, x[i]);
    }
}

