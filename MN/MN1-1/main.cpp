#include <iostream>
#include <cmath>

double f(double x) {
    return x*3 + 29*x+ 34;
}

double bisection(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        std::cout << "Metoda Bisectiei nu se poate aplica pe acest interval." << std::endl;
        return -1;
    }

    double c;
    int iter = 1;

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }

        std::cout << "Iteratia " << iter << ":\t a = " << a << ", b = " << b << ", c = " << c << ", f(c) = " << f(c) << std::endl;

        iter++;
    }
    return c;
}


int main() {
    double a = -2.0;
    double b = 2.0;
    double epsilon = 0.00001;

    double root = bisection(a, b, epsilon);

    if (root != -1) {
        std::cout << "Rădăcina aproximativă este: " << root << std::endl;
    }

    return 0;
}
