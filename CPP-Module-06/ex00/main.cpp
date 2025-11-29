// Example: Handling division by zero exception
// #include <iostream>
// #include <stdexcept>
#include "Bureaucrat.hpp"
// class printer{
//     std::string _name;
//     int _availabelpaper;

//     public:
//         printer(std::string name, int paper){
//             _name = name;
//             _availabelpaper = paper;
//         }
//         void    print(std::string txtDoc){
//             int requiredPaper = txtDoc.length() / 10;
//             if(requiredPaper > _availabelpaper){
//                 throw "No paper";
//             }
//             std::cout << "printing..." << txtDoc << std::endl;
//             _availabelpaper -= requiredPaper;
//         }
// };

int main(){ 
//     printer myPrinter("HP Deskjak", 10);

//     try
//     {
//             myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
//             myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
//             myPrinter.print("hello my name is ayoub, I'm a sofware engenrie");
//     }
//     catch(const char *txtEx)
//     {
//         std::cerr << "Ex : " << txtEx << std::endl;
//     }
//     catch(int a){
//         std::cerr << "Ex : " << a << std::endl;
//     }
//     catch(...){
//         std::cerr << "an exception happened !\n";
//     }
    try
    {
        Bureaucrat obj("ikhan",2);
        obj.increment();
        std::cout << obj;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}