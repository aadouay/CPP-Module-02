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


class printer{
    std::string _name;
    int _availabelpaper;

    public:
        printer(std::string name, int paper){
            _name = name;
            _availabelpaper = paper;
        }
        void    print(std::string txtDoc){
            int requiredPaper = txtDoc.length() / 10;
            if(requiredPaper > _availabelpaper){
                throw "No paper";
            }
            std::cout << "printing..." << txtDoc << std::endl;
            _availabelpaper -= requiredPaper;
        }
};

int main(){
    printer myPrinter("HP Deskjak", 10);

    try
    {
        myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
        myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
        myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
    }
    catch(const char *txtEx)
    {
        std::cerr << "Ex :" << txtEx << std::endl;
    }
}