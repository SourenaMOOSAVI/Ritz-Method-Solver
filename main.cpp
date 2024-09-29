#include <iostream>
#include <vector>
#include "solver.h"  
#include "KF.h"

int main() {
    int degree;
    double E = 1.0, A = 1.0, l = 1.0, F_ext = 1.0;
    auto b = [](double x) { return 1.0 * x; };

    std::cout << "Enter the degree of the Ritz method: ";
    std::cin >> degree;

    // Resize vectors according to the degree
    std::vector<std::vector<double>> K(degree, std::vector<double>(degree, 0.0));
    std::vector<double> F(degree, 0.0);

    // Assemble system
    assemble_system(K, F, degree, E, A, l, b, F_ext);

    // Solve for coefficients
    std::vector<double> c = gaussian_elimination(K, F);

    // Output results
    std::cout << "Coefficients: ";
    for (int i = 0; i < degree; ++i) {
        std::cout << "c" << i + 1 << " = " << c[i] << " ";
    }
    std::cout << std::endl;

    // Output approximate solution
    std::cout << "Approximate solution U(x) = ";
    for (int i = 0; i < degree; ++i) {
        std::cout << 0.5 * c[i] << " * x^" << i + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
