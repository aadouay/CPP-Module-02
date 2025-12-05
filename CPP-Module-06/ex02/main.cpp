#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    std::cout << "-------- test1---------" << std::endl;
    try{
        Bureaucrat man("Naser", 250);
        ShrubberyCreationForm form("park");
        man.signForm(form);
        man.executeForm(form);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------- test2---------" << std::endl;
    try{
        Bureaucrat bon("Ahmed", 45);
        RobotomyRequestForm rob1("SUPERMAN-MACHIN");
        bon.signForm(rob1);
        bon.executeForm(rob1);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------- test3---------" << std::endl;
    try{
        Bureaucrat man1("ali", 4);
        PresidentialPardonForm form2("Imad");
        man1.signForm(form2);
        man1.executeForm(form2);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}