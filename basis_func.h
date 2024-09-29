#ifndef BASIS_FUNC_H
#define BASIS_FUNC_H

#include <vector>
#include <functional>

// Function prototypes for generating basis functions and their derivatives
std::vector<std::function<double(double)>> generate_basis_functions(int degree);
std::vector<std::function<double(double)>> generate_basis_derivatives(int degree);

#endif
