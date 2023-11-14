#include <iostream>
#include <cmath>

double f(double x) {
    return pow(x, 3) - 29 * x + 34;
}

double successive_approximations(double initial_approximation, double epsilon, int max_iterations) {
    double x = initial_approximation;
    int iter = 0;

    while (iter < max_iterations) {
        double x_new = pow(29 - x, 1.0/3.0);

        std::cout << "Iterația " << iter << ":\t x = " << x << ", f(x) = " << f(x) << std::endl;

        if (fabs(x_new - x) < epsilon) {
            return x_new;
        }

        x = x_new;
        iter++;
    }

    std::cout << "Metoda generării succesive nu a convergat în numărul maxim de iterații." << std::endl;
    return -1;
}

int main() {
    double initial_approximation = -1; // Aproximare inițială a soluției
    double epsilon = 0.00001; // Precizia dorită
    int max_iterations = 1000; // Numărul maxim de iterații

    double approximation = successive_approximations(initial_approximation, epsilon, max_iterations);

    if (approximation != -1) {
        std::cout << "Aproximarea soluției este: " << approximation << std::endl;
    }

    return 0;
}
