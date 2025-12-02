#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;
class Form{
    private:
        const   std::string _Name;
        bool    _Signed;
        const   int     _Grade_sign;
        const   int     _Sign_execute;
    
    public:
        Form();
        Form(const std::string& name, int grade_sign, int sign_ex);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };
        void    beSigned(Bureaucrat& man);
        const   std::string& getName() const;
        bool    getSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif