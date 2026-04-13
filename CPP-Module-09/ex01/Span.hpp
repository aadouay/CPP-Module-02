#pragma once
#include <vector>
#include <algorithm>
#include <iostream>


class Span{
    private:
        std::vector <int> _data;
        unsigned int _maxsize;
    public:
        Span();
        Span(unsigned int N);
        Span( const  Span &Other );
        Span	&operator=( const Span &Other );
        ~Span();

        // mumbers func !!
        void    addNumber(int value);
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);
        void    print_la_block();
        int    shortestSpan();
        int    longestSpan();
};

#include "Span.tpp"