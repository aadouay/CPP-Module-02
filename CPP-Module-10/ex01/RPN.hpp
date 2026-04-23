#pragma once
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN{
    private:
       std::stack<float> container;
    public:
        // Forme Canonique
        // RPN();
        // RPN(const RPN& other);
        // RPN& operator=(const RPN& other);
        // ~RPN();

        void calculate(const std::string expression);
        bool isOperator(const char c);
};