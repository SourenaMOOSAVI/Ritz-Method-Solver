#include <vector>
#include <iostream>
#include <cmath>

// Gaussian elimination to solve K * c = F
std::vector<double> gaussian_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int n = A.size();
    
    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Search for maximum in this column
        double maxEl = std::abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(A[k][i]) > maxEl) {
                maxEl = std::abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row
        for (int k = i; k < n; k++) {
            std::swap(A[maxRow][k], A[i][k]);
        }
        std::swap(b[maxRow], b[i]);

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++) {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
            b[k] += c * b[i];
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }
    
    return x;
}
