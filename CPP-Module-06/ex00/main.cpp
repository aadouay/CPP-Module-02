// Example: Handling division by zero exception
#include <iostream>
#include <stdexcept>

// double divide(double numerator, double denominator) {
//     if (denominator == 0) {
//         throw invalid_argument("Division by zero is not allowed!");
//     }
//     return numerator / denominator;
// }

// int main() {
//     double num = 10.0;
//     double denom = 0.0;
    
//     try {
//         double result = divide(num, denom);
//         cout << "Result: " << result << endl;
//     }
//     catch (const invalid_argument& e) {
//         cout << "Exception caught: " << e.what() << endl;
//         cout << "Program continues running instead of terminating abnormally." << endl;
//     }
    
//     cout << "Program completed successfully!" << endl;
//     return 0;
// }

int main(){

    try{
        int *ptr = new int[10000000000];
        std::cout << "alocation is done !\n";
        delete[] ptr;
    }
    catch(std::bad_alloc& e){
        std::cout << "bad alocation adada mohim program nk haty ratnkml anzry lmochkilad !\n";
    }
    std::cout << "howa hadak\n";
}
/* Output:
Exception caught: Division by zero is not allowed!
Program continues running instead of terminating abnormally.
Program completed successfully!
*/