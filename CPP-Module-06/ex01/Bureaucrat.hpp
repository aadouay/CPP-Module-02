#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int garde);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };
        const   std::string get_name() const;
        short   getGrade() const;
        void    set_Grade(int grade);
        void    increment();
        void    decrement();
        void    signForm(Form& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif