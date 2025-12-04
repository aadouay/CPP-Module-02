#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():_Name("Defautl"), _Signed(false), _Grade_sign(150), _Sign_execute(150){
    std::cout << "Default constructor Form is called" << std::endl;
}

AForm::AForm(const std::string& name, int grade_sign, int sign_ex): _Name(name),
_Signed(false),_Grade_sign(grade_sign), _Sign_execute(sign_ex){
    std::cout << "the constructor overloded Form is called" << std::endl;
    if (grade_sign < 1 || sign_ex < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || sign_ex > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _Name(other._Name), _Signed(other._Signed),
_Grade_sign(other._Grade_sign), _Sign_execute(other._Sign_execute){
    std::cout << "Copy constractor Form is called" << std::endl;
}

AForm&   AForm::operator=(const AForm& other){
    std::cout << "Copy assignment operator form is called" << std::endl;
    if (this != &other)
        this->_Signed = other._Signed;
    return *this;
}

AForm::~AForm(){
    std::cout << "Destructor form is called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade To High\n";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade To Low\n";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form not signed";
}

void    AForm::beSigned(Bureaucrat& man){
    if(man.getGrade() <= this->_Grade_sign){
        this->_Signed = true;
    }
    else
        throw  GradeTooLowException();
}

const std::string& AForm::getName() const {
    return _Name;
}

bool AForm::getSigned() const {
    return _Signed;
}

int AForm::getGradeToSign() const {
    return _Grade_sign;
}

int AForm::getGradeToExecute() const {
    return _Sign_execute;
}

void    AForm::execute(Bureaucrat const & executor) const{
    if (this->_Signed == false)
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->_Sign_execute)
        throw AForm::GradeTooLowException();

    // in this line we should add the action of exeute !
    this->action();
}

std::ostream& operator<<(std::ostream& os, const AForm& other){
    os  << "Name of Form : " << other.getName() << std::endl
        << "Form is signed : " << other.getSigned() << std::endl
        << "Grade to sign : " << other.getGradeToSign() << std::endl
        << "Grade to execute : " << other.getGradeToExecute() << std::endl;
    return os;
}


