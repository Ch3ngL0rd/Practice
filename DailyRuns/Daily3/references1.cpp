#include <iostream>
#include <cassert>

// Function prototypes
void modifyReference(int& ref);
void swapValues(int& a, int& b);
int& returnReference(int& a);

int main() {
    // Test for modifyReference
    int x = 10;
    modifyReference(x);
    assert(x == 20); // x should be modified to 20
    std::cout << "modifyReference Test Passed" << std::endl;

    // Test for swapValues
    int y = 15;
    swapValues(x, y);
    assert(x == 15 && y == 20); // x and y values should be swapped
    std::cout << "swapValues Test Passed" << std::endl;

    // Test for returnReference
    int& ref = returnReference(x);
    ref = 25; // This should modify x
    assert(x == 25); // x should be modified to 25
    std::cout << "returnReference Test Passed" << std::endl;

    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Function definitions
void modifyReference(int& ref) {
    // TODO: Modify the reference to double its value
    ref = ref * 2;
}

void swapValues(int& a, int& b) {
    // TODO: Swap the values of a and b
    int temp = a;
    a = b;
    b = temp;
}

int& returnReference(int& a) {
    // TODO: Return a reference to the variable passed in
    return a;
}
