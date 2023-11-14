#include <iostream>
#include <cmath>

double f(double x) {
    return x*x*x +29*x+34;
}

double f_prime(double x) {
    return 3*x*x +29;
}

double newton_method(double initial_guess, double epsilon, int max_iterations) {
    double x = initial_guess;
    int iter = 0;

    while (iter < max_iterations) {
        double x_new = x - f(x) / f_prime(x);

        std::cout << "Iterația " << iter << ":\t x = " << x << ", f(x) = " << f(x) << std::endl;

        if (fabs(x_new - x) < epsilon) {
            return x_new;
        }

        x = x_new;
        iter++;
    }

    std::cout << "Metoda lui Newton nu a convergat în numărul maxim de iterații." << std::endl;
    return -1;
}

int main() {
    double initial_guess = 1.5; // Aproximare inițială a rădăcinii
    double epsilon = 0.00001; // Precizia dorită
    int max_iterations = 1000; // Numărul maxim de iterații

    double root = newton_method(initial_guess, epsilon, max_iterations);

    if (root != -1) {
        std::cout << "Rădăcina aproximativă este: " << root << std::endl;
    }

    return 0;
}
