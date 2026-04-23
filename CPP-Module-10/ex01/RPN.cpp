#include "RPN.hpp"




bool RPN::isOperator(const char c){
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    // si non on returnera false !!
    return false;
}

void    RPN::calculate(const std::string expression){

    std::stringstream stream(expression.c_str());
    std::string token;
    // float res;

    while (stream >> token)
    {
        if(token.size() != 1)
            throw std::runtime_error("Token : 1 seul caractère");

        // traitement de token 
        if(isdigit(token.c_str()[0])){container.push(std::atof(token.c_str())); continue ;}
        else if (isOperator(token.c_str()[0])){
            // faire un check on doit trouver deux numbers ou plus pour faire un calculation !!
            if(container.size() < 2)
                throw std::runtime_error("Erorr : On a besoin d'au moins deux opérandes");
            float v2 = container.top();
            container.pop();
            float v1 = container.top();
            container.pop();

            // calcul
            if(token == "+"){container.push(v1 + v2);}
            else if(token == "-"){container.push(v1 - v2);}
            else if(token == "*"){container.push(v1 * v2);}
            else if(token == "/"){
                // check si on a 0 sur v2 !
                if(v2 == 0)
                    throw std::runtime_error("Error: Division par zéro.");
                container.push(v1 / v2);
            }
        }
        else
            throw std::runtime_error("Obligatoire : 1 seul caractère (0-9 ou opérateur)");
    }
    if(container.size() != 1)
        throw std::runtime_error("Error : ");
    // tout passer goooood !
    std::cout << container.top() << std::endl;
}