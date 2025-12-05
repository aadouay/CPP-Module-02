#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Defautl"), AForm("Shrubbery Creation", 145, 137){
    std::cout << "Default constructor ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("Shrubbery Creation", 145, 137), _target(name){
    std::cout << "the constructor overloded ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other) ,_target(other._target){
    std::cout << "the constructor overloded ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    std::cout << "Copy assignment operator ShrubberyCreationForm is called" << std::endl;
    if(this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Destructor ShrubberyCreationForm is called" << std::endl;
}

void    ShrubberyCreationForm::action() const{

    std::ofstream file(_target + "_shrubbery");

    if(!file.is_open()){
        throw std::runtime_error("Could not open file for shrubbery creation.");
    }

    file << "           ,          " << std::endl;
    file << "          / \\         " << std::endl;
    file << "        .'   '.       " << std::endl;
    file << "       /       \\      " << std::endl;
    file << "      /.-.   .-.\\     " << std::endl;
    file << "      `/  '.'    \\    " << std::endl;
    file << "     .'          '.   " << std::endl;
    file << "    /.--.     .--.\\   " << std::endl;
    file << "     /   '. .'    \\   " << std::endl;
    file << "   .'      `       '. " << std::endl;
    file << "  /.---.       .----.\\" << std::endl;
    file << "   /    `.   .'     \\ " << std::endl;
    file << " .'       `.'        '." << std::endl;
    file << "/,----,          ,----,\\" << std::endl;
    file << "`'-.__.;-,____,-;.__.-'" << std::endl;
    file << "         |||||        " << std::endl;
    file << "         |||||        " << std::endl;
    
    std::cout << "ShrubberyCreationForm executed successfully! File " 
                  << _target << "_shrubbery" << " created." << std::endl;
}