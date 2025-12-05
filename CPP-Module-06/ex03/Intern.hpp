#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern{

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern&  other);
        ~Intern();
        AForm*  makeForm(std::string name_form, std::string target);
        class FormNotFoundException : public std::exception {
                    public:
                        virtual const char* what() const throw();
                };
        };
#endif