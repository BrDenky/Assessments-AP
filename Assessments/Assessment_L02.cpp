#include <iostream>
#include <cmath>


//Create a function that solves a quadratic equation of the form ax^2 + bx + c = 0
/*
Pseudocode:
The function must receive the coefficients a, b and c and must print the roots of the equation.
If a is equal to zero, throw an exception with the message "The coefficient cannot be zero"
Calculate the discriminant (b^2 - 4ac)
If the discriminant is greater than zero, the roots are real and different.
If the discriminant is equal to zero, the roots are real and equal
If the discriminant is less than zero, the roots are complex and different.
Print the roots in each case.
*/

#include <iostream>
#include <cmath>

void function(double a, double b, double c) {
    if (a == 0) {
        std::cout << "The coefficient cannot be zero";
        return;
    }

    double op = b * b - 4 * a * c;
    if (op > 0) {
        double x1 = (-b + std::sqrt(op)) / (2 * a);
        double x2 = (-b - std::sqrt(op)) / (2 * a);

        std::cout << "The roots are real and different" << std::endl;
        std::cout << "The first answer is: " << x1 << std::endl;
        std::cout << "The second answer is: " << x2 << std::endl;
    } else if (op == 0) {
        double root = -b / (2 * a);
        std::cout << "The root is real and equal" << std::endl;
        std::cout << "The first answer is: " << root << std::endl;
        std::cout << "The second answer is: " << root << std::endl;
    } else {
        double real = -b / (2 * a);
        double imaginary = std::sqrt(-op) / (2 * a);
        std::cout << "The roots are complex and different" << std::endl;
        std::cout << "The first answer is: " << real << " + " << imaginary << "i" << std::endl;
        std::cout << "The second answer is: " << real << " - " << imaginary << "i" << std::endl;
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients a, b, and c: ";
    std::cin >> a >> b >> c;

    try {
        function(a, b, c);
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

