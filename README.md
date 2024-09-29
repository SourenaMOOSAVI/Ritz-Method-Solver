# Ritz method custom solver
The solver in this repository allows the user to solve the partial differential equation (PDE) representing a bar in traction using Ritz method. The problem definition is represented in this [article](https://medium.com/@SourenAM/ritz-method-a-gateway-to-finite-element-method-b7cc9c8421d2).  
## What does the solver do?
The solver is solving the equation `Kc=F` where `K` is the stiffness matrix, `c` is the coefficient vector and `F` is the force vector. the entries to `K` and `F` are found using the numerical integration (Trapezoidal rule) then the equation is solved using Gaussian Elimination implemented in `solver.cpp`.
## How to use the solver?
Simply download the source code and compile it using:
```
g++ main.cpp KF.cpp solver.cpp basis_func.cpp -o main
```
Then run `./main` and you will be prompted to enter a degree which is the degree of polynomial approximation, for instance if you want to have a three parameter Ritz solution you need to enter `3`.  
For more details regarding the theoretical and mathematical nuances please read this [article](https://medium.com/@SourenAM/ritz-method-a-gateway-to-finite-element-method-b7cc9c8421d2).
