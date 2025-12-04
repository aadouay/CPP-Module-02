#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void    action() const;
};

#endif