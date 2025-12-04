#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : _target("Defautl"), AForm("Robotomy Request", 72, 45){
    std::cout << "Default constructor RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("Robotomy Request", 72, 45), _target(name){
    std::cout << "the constructor overloded RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other) ,_target(other._target){
    std::cout << "the constructor overloded RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    std::cout << "Copy assignment operator RobotomyRequestForm is called" << std::endl;
    if(this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Destructor RobotomyRequestForm is called" << std::endl;
}

void    RobotomyRequestForm::action() const{
    
    std::cout << "KAZZZZZZZZZZZZZZZZZZZZZZZZZ..." << std::endl;
    std::cout << "VAVVVVVVVVVVVVVVVVVVVVVVVVV..." << std::endl;
    std::cout << "KAWWWWWWWWWWWWWWWWWWWWWWWWW..." << std::endl;

    std::srand(std::time(NULL));
    if(std::rand() % 2)
        std::cout << _target << " has been robotomized Successfully" << std::endl;
    else
        std::cout << _target << " has not robotomized" << std::endl;
}