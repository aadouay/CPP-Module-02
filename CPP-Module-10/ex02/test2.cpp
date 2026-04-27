#include <vector>

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


std::vector<int> generateJacobsthalSequence(int size) {
    if (size <= 1)
        return std::vector<int>();  
    
    std::vector<int> sequence;

    
    return sequence;
}

#include <iostream>

int main() {


    
    return 0;
}