#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

    Bureaucrat man("Naser", 137);
    ShrubberyCreationForm form("park");
    man.signForm(form);
    man.executeForm(form);

    std::cout << "-------- test2---------" << std::endl;

    Bureaucrat bon("Ahmed", 45);
    RobotomyRequestForm rob1("SUPERMAN-MACHIN");
    bon.signForm(rob1);
    bon.executeForm(rob1);

    // std::cout << "-------- test3---------" << std::endl;
}