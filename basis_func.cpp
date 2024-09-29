#include <vector>
#include <functional>
#include <cmath>

// Basis function generator
std::vector<std::function<double(double)>> generate_basis_functions(int degree) {
    std::vector<std::function<double(double)>> basis_functions;
    
    for (int i = 1; i <= degree; ++i) {
        basis_functions.push_back([i](double x) -> double {
            return 0.5 * std::pow(x, i);  // 0.5 * x^i
        });
    }

    return basis_functions;
}

// Basis function derivative generator
std::vector<std::function<double(double)>> generate_basis_derivatives(int degree) {
    std::vector<std::function<double(double)>> basis_derivatives;
    
    for (int i = 1; i <= degree; ++i) {
        basis_derivatives.push_back([i](double x) -> double {
            return (i == 0) ? 0.0 : 0.5 * i * std::pow(x, i - 1);  // 0.5 * i * x^(i-1)
        });
    }

    return basis_derivatives;
}
