#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void test_exceptions() {
    // 1. std::out_of_range Test
    std::vector<int> v = {1, 2, 3};
    try {
        std::cout << v.at(5) << std::endl; // Throws out_of_range
    }
    // 2. std::invalid_argument Test
    // catch (const std::out_of_range& e) {
    //     throw std::invalid_argument("Out-of-range caught. Testing invalid_argument now.");
    // }
    // 3. std::bad_alloc Test (can be hard to reliably trigger)
    // You'd try new int[large_number_of_bytes] if system resources are low
    catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument caught. Testing runtime_error now." << std::endl;
        throw std::runtime_error("Simulated runtime issue.");
    }
}

int main(){
    try
    {
        test_exceptions();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}