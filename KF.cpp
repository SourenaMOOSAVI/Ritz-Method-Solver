#include <vector>
#include <functional>
#include "basis_func.h"

// Integrate function to accept std::function
double integrate(std::function<double(double)> f, double a, double b, int n = 100) {
    double h = (b - a) / n;
    double result = 0.0;

    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        double weight = (i == 0 || i == n) ? 0.5 : 1.0;
        result += weight * f(x);
    }

    return result * h;
}

// K_entry using analytical integration or numerical integration as needed
double K_entry(int i, int j, double E, double A, double l, const std::vector<std::function<double(double)>>& dphi) {
    return E * A * integrate([i, j, &dphi](double x) -> double {
        return dphi[i - 1](x) * dphi[j - 1](x);
    }, 0, l);
}

// F_entry using analytical integration or numerical integration as needed
double F_entry(int i, double l, std::function<double(double)> b, const std::vector<std::function<double(double)>>& phi, double F_ext) {
    return integrate([i, &phi, &b](double x) -> double {
        return b(x) * phi[i - 1](x);
    }, 0, l) + F_ext * phi[i - 1](l); // Including boundary term
}

// Assembling stiffness matrix and force vector
void assemble_system(std::vector<std::vector<double>>& K, std::vector<double>& F, int degree, double E, double A, double l, double (*b)(double), double F_ext) {
    auto phi = generate_basis_functions(degree);
    auto dphi = generate_basis_derivatives(degree);

    for (int i = 1; i <= degree; ++i) {
        for (int j = 1; j <= degree; ++j) {
            K[i - 1][j - 1] = K_entry(i, j, E, A, l, dphi);  // Use K_entry
        }
        F[i - 1] = F_entry(i, l, b, phi, F_ext);  // Use F_entry
    }
}
