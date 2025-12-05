#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Defautl"), AForm("Presidential Pardon Request", 25, 5){
    std::cout << "Default constructor PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("Presidential Pardon Request", 25, 5), _target(name){
    std::cout << "the constructor overloded PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other) ,_target(other._target){
    std::cout << "the constructor overloded PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    std::cout << "Copy assignment operator PresidentialPardonForm is called" << std::endl;
    if(this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructor PresidentialPardonForm is called" << std::endl;
}

void    PresidentialPardonForm::action() const{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}