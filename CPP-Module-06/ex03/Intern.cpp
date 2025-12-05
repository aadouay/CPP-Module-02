#include "Intern.hpp"


Intern::Intern(){
    std::cout << "Default constructor Intern is called" << std::endl;
}

Intern::Intern(const Intern& other){
    std::cout << "the constructor overloded Intern is called" << std::endl;
}

Intern&  Intern::operator=(const Intern& other){
    std::cout << "Copy assignment operator Intern is called" << std::endl;
    return *this;
}

Intern::~Intern(){
    std::cout << "Destructor Intern is called" << std::endl;
}



static AForm* makeShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form name not found.";
}

AForm* Intern::makeForm(std::string name_form, std::string target){

    std::string posibel_forms[]{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creat_form[])(std::string target){
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (size_t i = 0; i < 3; i++)
    {
        if(posibel_forms[i] == name_form){
            std::cout << "Intern creates " << target << std::endl;
            return (creat_form[i](target));
        }
            
    }
    std::cout << "Intern could not create form: " << target << std::endl;
    throw Intern::FormNotFoundException();
}