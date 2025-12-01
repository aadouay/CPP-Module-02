#include "Form.hpp"

Form::Form():_Name("Defautl"), _Signed(false), _Grade_sign(150), _Sign_execute(150){
    std::cout << "Default constructor Form is called" << std::endl;
}

Form::Form(const std::string& name, int grade_sign, int sign_ex): _Name(name),
_Signed(false),_Grade_sign(grade_sign), _Sign_execute(sign_ex){
    std::cout << "the constructor overloded Form is called" << std::endl;
    if (grade_sign < 1 || sign_ex < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || sign_ex > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other): _Name(other._Name), _Signed(other._Signed),
_Grade_sign(other._Grade_sign), _Sign_execute(other._Sign_execute){
    std::cout << "Copy constractor Form is called" << std::endl;
}

Form&   Form::operator=(const Form& other){
    std::cout << "Copy assignment operator form is called" << std::endl;
    if (this != &other)
        this->_Signed = other._Signed;
    return *this;
}

Form::~Form(){
    std::cout << "Destructor form is called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade To High\n";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade To Low\n";
}

