#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm&  other);
        ~PresidentialPardonForm();
        void action() const;
};

#endif