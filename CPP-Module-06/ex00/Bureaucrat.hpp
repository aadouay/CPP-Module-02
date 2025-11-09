#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

    const   std::string get_name() const;
    short   getGrade() const;
    void    set_Grade(int grade);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif