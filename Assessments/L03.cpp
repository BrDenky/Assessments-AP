#include <iostream>
#include <tuple>

/*
    Part 1: Using three types of initialization:
    - Direct Initialization (DI)
    - Uniform Initialization (UI)
    - Structured Binding (SB)
*/

// Direct Initialization
int a = 10;
double b = 10.5;
std::string name = "Mateo";
bool c = true;

// Uniform Initialization
int d{20};
double e{15.28};
std::string name2{"Ulices"};
bool f{false};

// Function that returns a tuple for structured binding initialization
std::tuple<std::string, int, double, bool> getClassInfoE() {
    std::string name = "Ariel";
    int age = 20;
    double average = 9.5;
    bool passed = true;
    return {name, age, average, passed};
}

// Structure definition for Part 4
struct Point {
    int x;
    int y;
    int z;
};

int main() {
    /*
        Part 2: Print initial values
    */
    std::cout << "Initial values: " << std::endl;
    std::cout << "DI: int: " << a << ", double: " << b << ", string: " << name << ", bool: " << c << std::endl;
    std::cout << "UI: int: " << d << ", double: " << e << ", string: " << name2 << ", boolean: " << f << std::endl;

    // Structured Binding Initialization
    auto [nameE, age, average, passed] = getClassInfoE();
    std::cout << "SB: string: " << nameE << ", int: " << age << ", double: " << average << ", bool: " << passed << std::endl;

    /*
        Part 3: References - Modifying variable values
    */
    // Direct Initialization References
    int& A = a;
    A = 78;
    double& B = b;
    B = 65.98;
    std::string& Name = name;
    Name = "Eric";
    bool& C = c;
    C = false;

    // Uniform Initialization References
    int& D = d;
    D = 100;
    double& E = e;
    E = 99.99;
    std::string& Name2 = name2;
    Name2 = "Luis";
    bool& F = f;
    F = true;

    // Structured Binding References
    auto NewData = getClassInfoE();
    std::string& Name3 = std::get<0>(NewData);
    Name3 = "Carlos";
    int& Age = std::get<1>(NewData);
    Age = 25;
    double& Average = std::get<2>(NewData);
    Average = 8.5;
    bool& Passed = std::get<3>(NewData);
    Passed = false;

    /*
        Part 4: Print modified values
    */
    std::cout << "Modified values: " << std::endl;
    std::cout << "DI: int: " << a << ", double: " << b << ", string: " << name << ", bool: " << c << std::endl;
    std::cout << "UI: int: " << d << ", double: " << e << ", string: " << name2 << ", boolean: " << f << std::endl;
    std::cout << "SB: string: " << std::get<0>(NewData) << ", int: " << std::get<1>(NewData) << ", double: " << std::get<2>(NewData) << ", bool: " << std::get<3>(NewData) << std::endl;

    /*
        Part 5: Structured Binding with Structs
    */
    Point p = {5, 10, 15};
    auto [x, y, z] = p;
    std::cout << "Structured Binding: " << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

    /*
        Part 6: L-values and R-values Analysis
    */
    a = 42; // 'a' is an L-value (can be assigned)
    
    int x_2 = a + b; // 'a' and 'b' are L-values, but '(a + b)' is an R-value (result of an operation)
    
    int* ptr = &a; // '&a' is an R-value (can only be obtained, not modified)

    std::string s = c + " World"; // 'c' is an L-value, but " World" is an R-value

    int& refx = x; // 'refx' is an L-value reference, and 'x' is an L-value

    int&& rref = 100; // 'rref' is an R-value reference, and '100' is an R-value

    /*
        Part 7: Print L-values and R-values
    */
    std::cout << "L-values and R-values: " << std::endl;
    std::cout << "a: " << a << ", x: " << x_2 << ", s: " << s << ", refx: " << refx << ", rref: " << rref << std::endl;

    return 0;
}
