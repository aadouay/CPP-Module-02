#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Defautl"), _grade(150){
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string  name, int grade):_name(name){
    std::cout << "constractor overloading called" << std::endl;
    set_Grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name){
    std::cout << "Copy constractor called" << std::endl;
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    std::cout << "Copy assignment operator called" << std::endl;
    // this->_name = other._name;
    this->_grade = other._grade;
    return *this;
}

const   std::string Bureaucrat::get_name() const{
    return  this->_name;
}
short   Bureaucrat::getGrade() const{
    return this->_grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade To High\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade To Low\n";
}

void    Bureaucrat::set_Grade(int grade){

    if(grade >= 1 && grade <= 150)
        this->_grade = grade;
    else if(grade < 1)
        throw GradeTooHighException();
    else
        throw GradeTooLowException();
}

void    Bureaucrat::increment(){
    if(_grade > 1)
        this->_grade -= 1;
    else
        throw GradeTooHighException();
}
void    Bureaucrat::decrement(){
    if(_grade < 150)
        this->_grade += 1;
    else
        throw GradeTooLowException();
}

std::ostream&  operator<<(std::ostream& os, const Bureaucrat& other){
    os << other.get_name() << " bureaucrat grade is " << other.getGrade() << std::endl;
    return os;
}