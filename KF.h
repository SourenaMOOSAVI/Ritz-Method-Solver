#ifndef KF_H
#define KF_H

#include <vector>

double K_entry(int i, int j, double E, double A, double l, const std::vector<double (*)(double)>& dphi);
double F_entry(int i, double l, double (*b)(double), const std::vector<double (*)(double)>& phi, double F_ext);
void assemble_system(std::vector<std::vector<double>>& K, std::vector<double>& F, int degree, double E, double A, double l, double (*b)(double), double F_ext);

#endif
