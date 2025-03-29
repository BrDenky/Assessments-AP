#include <iostream>
#include <concepts>


//1.1 Task
template <typename T>
T maxValue(T a, T b) {
    return (a>b) ? a:b;
};
//1.2 Task
template <typename T>
T maxValue(T c, T d, T e) {
    return (c, maxValue(d,e));
};

//2 Task
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
};

//3.1 Task
template <typename T>
void printAll(T t) {
    std::cout << t << std::endl;
};

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    std::cout << t << " ";
    printAll(args...);
};


//3.2 Task
template <typename S>
S sum(S s) {
    return s;
}
template <typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}


//4.1 Task
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial <N-1> :: value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};


//4.2 Task
template <int N>
struct Fb {
    static constexpr int value = Fb <N-1>::value + Fb<N-2>::value;
};

template <>
struct Fb<0>{
    static constexpr int value = 0;
};

template <>
struct Fb<1> {
    static constexpr int value = 1;
};


int main(){
    //1.1 Task
    std::cout << "maxValue with 2 parameters: " <<std::endl;
    std::cout << maxValue(2,8) << std::endl; //8
    std::cout << maxValue(4.5,1.5) << std::endl; //4.5
    std::cout << maxValue(std::string("Hello"), std::string("World")) <<std::endl; //World

    //1.2 Task
    std::cout << "maxValue with 3 parameters: " <<std::endl;
    std::cout << maxValue(5,8,9) << std::endl; //9
    std::cout << maxValue(1.4,8.7,9.5) << std::endl; //9.5

    //2 Task
    std::cout << "Concepts: " <<std::endl;
    std::cout << add(5,2) <<std::endl; //7
    std::cout << add(5.7,1.3) << std::endl; //7

    //3.1 Task
    std::cout << "Variadic Templates: " <<std::endl;
    printAll(8, 4.5, "Mateo", 'P'); // 8 4.5 Mateo P

    //3.2 Task
    std::cout << "Variadic Templates for Summation: " <<std::endl;
    std::cout << sum(8,7,1,4) <<std::endl; //20
    std::cout << sum(1.2+1.2+2.6) <<std::endl; //5

    //4.1 Task
    std::cout << "Factorial Using Templates: " <<std::endl;
    constexpr int fact = Factorial<5>::value;
    std::cout << "The factorial number is: " <<  fact << std::endl;
    constexpr int fact2 = Factorial<0>::value;
    std::cout << "The factorial number is: " <<  fact2 << std::endl;

    //4.2 Task
    std::cout << "Fibonacci: " <<std::endl;
    constexpr int result = Fb<15>::value;
    std::cout << result << std::endl; //610
    constexpr int result2 = Fb<1>::value;
    std::cout << result2 << std::endl; //1
    constexpr int result3 = Fb<0>::value;
    std::cout << result3 << std::endl; //0
}
