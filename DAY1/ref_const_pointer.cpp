#include <iostream>

int main() {
    int a = 10, b = 20, c = 30;

    // Original valid pointer declarations
    const int *p = &a;         // Pointer to a const int
    int* const q = &b;         // Const pointer to an int
    const int* const r = &c;   // Const pointer to a const int

    // References to the pointers
    const int*& ref_p = p;
    int* const& ref_q = q;
    const int* const& ref_r = r;

    // Demonstrate use via references (e.g., dereferencing)
    std::cout << "ref_p points to value: " << *ref_p << std::endl;
    std::cout << "ref_q points to value: " << *ref_q << std::endl;
    std::cout << "ref_r points to value: " << *ref_r << std::endl;

    return 0;
}

