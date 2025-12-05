#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;
class AForm{
    private:
        const   std::string _Name;
        bool    _Signed;
        const   int     _Grade_sign;
        const   int     _Sign_execute;
    
    public:
        AForm();
        AForm(const std::string& name, int grade_sign, int sign_ex);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();
        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public: 
                virtual const char* what() const throw();
        };
        void    beSigned(Bureaucrat& man);
        const   std::string& getName() const;
        bool    getSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;
        void    execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif