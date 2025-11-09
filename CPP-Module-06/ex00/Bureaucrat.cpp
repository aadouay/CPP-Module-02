#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Defautl"), _grade(150){
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string  name, int grade):_name(name){
    std::cout << "Copy constructor called" << std::endl;
    set_Grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    std::cout << "Copy assignment operator called" << std::endl;
    // this->_name = other._name;
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    // this->_name = other._name;
    this->_grade = other._grade;
}

const   std::string Bureaucrat::get_name(){
    return  this->_name;
}
short   Bureaucrat::getGrade(){
    return this->_grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called" << std::endl;
}


void    Bureaucrat::set_Grade(int grade){

    if(grade >= 1 && grade <= 150)
        this->_grade = grade;
    else
        std::cout << "ikhanad orikhdm";
}

std::ostream&  operator<<(std::ostream& os, const Bureaucrat& other){
    os << other.get_name() << other.getGrade() << std::endl;
    return os;
}