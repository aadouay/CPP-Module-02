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
        void addRange(Iterator begin, Iterator end){
            size_t elements = std::distance(begin, end);
            size_t place_restante = _maxsize - _data.size();
            if(elements > place_restante)
                throw std::runtime_error("Exception : Capacité maximale dépassée");
            _data.insert(_data.end(), begin, end);
        }
        void    print_la_block();
        int    shortestSpan();
        int    longestSpan();
};