#include "Span.hpp"
#include <iostream>

Span::Span():_maxsize(0){}

Span::Span(unsigned int N):_maxsize(N){}

Span::Span( const  Span &Other ) : _maxsize(Other._maxsize) {
	*this = Other;
}

Span	&Span::operator=( const Span &Other ) {
	if (this != &Other) {
		this->_maxsize = Other._maxsize;
		for (size_t i = 0; i < this->_maxsize; i++)
			_data.push_back(Other._data[i]);
	}
	return *this;
}

Span::~Span(){
    std::cout << "la block a etais suprimier !" << std::endl;
}

void    Span::addNumber(int value){
    // faire un petite check pour if mon stockage est plain ou bien non avent ajouter un element !!
    if(_data.size() < _maxsize){
        _data.push_back(value);
    }
    else
        throw std::runtime_error("t'auras dépasser la limit de bloc !");
}

void    Span::print_la_block(){
    for (int i = 0 ; i < _maxsize ; i++){
        std::cout << _data[i] << std::endl;
    }
}

int    Span::longestSpan(){

    if(_maxsize < 2)
        throw std::runtime_error("Nombre insuffisant pour trouver une Span");
    
    std::vector<int>::iterator min = std::min_element(_data.begin(), _data.end());
    std::vector<int>::iterator max = std::max_element(_data.begin(), _data.end());
    return (max - min);
}

int Span::shortestSpan(){
    std::vector<int> tabel = _data;
    std::vector<int> destance;
    std::sort(tabel.begin(), tabel.end());
    for (size_t index = 0; index < _maxsize; index++){
        for(size_t next_index = (index + 1); next_index < _maxsize; next_index++){
            destance.push_back(std::abs(tabel[index] - tabel[next_index]));
        }
    }
    std::sort(destance.begin(), destance.end());
    return(destance[0]);
}