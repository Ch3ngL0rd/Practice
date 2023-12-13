#include <iostream>
#include <cassert>

// Function prototypes
int* declareAndInitialize(int& variable);
void dereferenceAndModify(int* pointer, int newValue);
int performPointerArithmetic(int* array, int index);
int* accessArrayElement(int array[], int index);
int** createDoublePointer(int* pointer);

int main() {
    // Test for Exercise 1: Declare and Initialize
    int var = 10;
    int* ptr = declareAndInitialize(var);
    assert(*ptr == var);

    // Test for Exercise 2: Dereference and Modify
    dereferenceAndModify(ptr, 20);
    assert(var == 20);

    // Test for Exercise 3: Pointer Arithmetic
    int arr[] = {1, 2, 3, 4, 5};
    int value = performPointerArithmetic(arr, 2);
    assert(value == 3);

    // Test for Exercise 4: Access Array Element
    int* elementPtr = accessArrayElement(arr, 3);
    assert(*elementPtr == 4);

    // Test for Exercise 5: Pointer to Pointer
    int** doublePtr = createDoublePointer(ptr);
    assert(**doublePtr == 20);

    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Exercise 1: Declare and Initialize a Pointer
int* declareAndInitialize(int& variable) {
    // TODO: Return a pointer that points to 'variable'

}

// Exercise 2: Dereference and Modify
void dereferenceAndModify(int* pointer, int newValue) {
    // TODO: Modify the value of the variable pointed by 'pointer' to 'newValue'

}

// Exercise 3: Pointer Arithmetic
int performPointerArithmetic(int* array, int index) {
    // TODO: Return the value at 'index' in 'array' using pointer arithmetic

}

// Exercise 4: Access Array Element
int* accessArrayElement(int array[], int index) {
    // TODO: Return a pointer to the element at 'index' in 'array'

}

// Exercise 5: Pointer to Pointer
int** createDoublePointer(int* pointer) {
    // TODO: Create a pointer to a pointer that points to 'pointer' and return it

}
