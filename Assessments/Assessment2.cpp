#include <iostream>
#include <cmath>


//Crear una función que resuelva una ecuación cuadrática de la forma ax^2 + bx + c = 0
/*
    Pseudocódigo:
    La función debe recibir los coeficientes a, b y c y debe imprimir las raices de la ecuación
    Si a es igual a cero, lanzar una excepción con el mensaje "Coeficiente no puede ser cero"
    Calcular el discriminante (b^2 - 4ac)
    Si el discriminante es mayor a cero, las raices son reales y diferentes
    Si el discriminante es igual a cero, las raices son reales e iguales
    Si el discriminante es menor a cero, las raices son complejas y diferentes
    Imprimir las raices en cada caso.
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

