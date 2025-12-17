#include <iostream>
#include <cstdint>   // for uintptr_t

struct Data {
    int value;
};

int main() {
    Data data;
    data.value = 42;

    // Original pointer
    Data* originalPtr = &data;

    // Pointer → integer (reinterpretation)
    uintptr_t raw = reinterpret_cast<uintptr_t>(originalPtr);

    // Integer → pointer (reinterpretation)
    Data* restoredPtr = reinterpret_cast<Data*>(raw);

    // Proof: same address
    std::cout << "Original pointer : " << originalPtr << std::endl;
    std::cout << "Restored pointer : " << restoredPtr << std::endl;

    // Proof: same object
    std::cout << "Value via restored pointer: "
              << restoredPtr->value << std::endl;
    return 0;
}
