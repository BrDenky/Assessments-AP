#include <iostream>
#include <vector>

#include <chrono>

/*

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy
    std::vector<int> v3 = std::move(v1); // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    return 0;
}

/*
    What is the output of this program?
    v1 size: 0, v2 size: 4, v3 size: 4
    v1 was moved to V3, so its size is 0. While v2 is a copie of the original vector, its size is 4. 
    And how the V1 was moved to V3, the size of V3 is also 4.

    Why does v1.size() return 0 after the move?
    This is because when we move data from one variable to another, the original variable is left in a valid but unspecified state

    What does std::move do?
    Is a utility function that convert an object to an rvalue reference.
    It essentially indicates that the object can be "moved from," meaning its resources can be transferred to another object.
    
    Why is v1 still in a valid but unspecified state?
    Because std::move does not actually move the object, it just allows the move constructor or move assignment operator to take ownership of the resources.   
*/


class Buffer {
    private:
        int* data;
        size_t size;
    
    public:
        Buffer(size_t s) : size(s), data(new int[s]) {
            std::cout << "Constructor called\n";
        }
    
        ~Buffer() {
            delete[] data;
            std::cout << "Destructor called\n";
        }
    
        // Copy constructor and Assignment operator
        Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
            std::copy(other.data, other.data + other.size, data);
            std::cout << "Copy constructor called\n";
        }

        Buffer& operator=(const Buffer& other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                data = new int[size];
                std::copy(other.data, other.data + size, data);
                std::cout << "Copy assignment called\n";
            }
            return *this;
        }
    

        // Move constructor and Assignment operator
        Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move constructor called\n";
        }
        
        Buffer& operator=(Buffer&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = other.data;
                size = other.size;
        
                other.data = nullptr;
                other.size = 0;
                std::cout << "Move assignment called\n";
            }
            return *this;
        }
    };
/*
int main() {
    Buffer b1(100);
    Buffer b2 = b1;           // Should call copy constructor
    Buffer b3 = std::move(b1); // Should call move constructor

    Buffer b4(50);
    b4 = b2;                  // Should call copy assignment
    b4 = std::move(b2);       // Should call move assignment
    return 0;
}

/*
    What constructors and assignments are called and when?
    - Constructor called when b1 is created.
    - Copy constructor called when b2 is created from b1.
    - Move constructor called when b3 is created from b1 (after the move, b1 is in a valid but unspecified state).
    - Constructor called when b4 is created.
    - Copy assignment called when b4 is assigned from b2.
    - Move assignment called when b4 is assigned from b2 (after the move, b2 is in a valid but unspecified state).

    What happens to the source object after a move?
    After a move, the soource object is left in a valid but unspecified state.
    This means that the object is still valid and can be destructed.
    DATA pointer is set to nullptr and its size is set to 0.

    What would happen if you didn’t define the move constructor/assignment?
    The compiler would either delete them or generate default versions.
    This defatult versions would perfom shallow copies, which could lead to both objects would point to the same memory location.
    When both objects get destroyed, we are going to have an error because delete[] will be called twice on the same memory location.
*/


int main() {

    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy
    std::vector<int> v3 = std::move(v1); // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    Buffer b1(100);
    Buffer b2 = b1;           // Should call copy constructor
    Buffer b3 = std::move(b1); // Should call move constructor

    Buffer b4(50);
    b4 = b2;                  // Should call copy assignment
    b4 = std::move(b2);       // Should call move assignment

    
    const size_t bigSize = 10'000'000;

    // large buffer
    Buffer original(bigSize);

    // Measure copy
    auto start_copy = std::chrono::high_resolution_clock::now();
    Buffer copied = original;
    auto end_copy = std::chrono::high_resolution_clock::now();

    std::cout << "Copy duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_copy - start_copy).count()
              << " ms\n";

    // Measure move
    auto start_move = std::chrono::high_resolution_clock::now();
    Buffer moved = std::move(original);
    auto end_move = std::chrono::high_resolution_clock::now();

    std::cout << "Move duration: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_move - start_move).count()
              << " ms\n";

    return 0;
}
/*
    PART 4
    With buffer size 10,000,000. The results are: Copy duration: 8 ms, Move duration: 0 ms.
*/

/*
    PART 5
    What did you learn about move semantics?
    Allow to transfer resources from one object to another without copying the data.
    This is particularly useful for large objects, as it can significantly improve performance.

    In what kinds of projects do you think this would matter?
    In projects where performance is critical, such as game development, real-time systems, or high-performance computing.
    In these cases, the overhead of copying large objects can be significant, and move semantics can help to reduce this overhead.

    What are some risks of using std::move incorrectly?
    It can end up with pointers where its memory location is not avaliable anymore or double deletions.
*/

