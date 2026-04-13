#include "Span.hpp"

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
    std::cout << "Span détruit et mémoire libérée." << std::endl;
}

void    Span::addNumber(int value){
    // faire un petite check pour if mon stockage est plain ou bien non avent ajouter un element !!
    if(_data.size() < _maxsize){
        _data.push_back(value);
    }
    else
        throw std::runtime_error("Exception : Capacité maximale dépassée.");
}

void    Span::print_la_block(){
    for (int i = 0 ; i < _maxsize ; i++){
        std::cout << _data[i] << std::endl;
    }
}

int    Span::longestSpan(){

    if(_data.size() < 2)
        throw std::runtime_error("Erreur : Nombre d'éléments insuffisant pour calculer un écart.");
    
    std::vector<int>::iterator min = std::min_element(_data.begin(), _data.end());
    std::vector<int>::iterator max = std::max_element(_data.begin(), _data.end());
    return (*max - *min);
}

int Span::shortestSpan(){
    if(_data.size() < 2)
        throw std::runtime_error("Erreur : Nombre d'éléments insuffisant pour calculer un écart.");
    std::vector<int> tabel = _data;
    int deff;
    std::sort(tabel.begin(), tabel.end());
    int min_distance = tabel[1] - tabel[0];
    for (size_t index = 1; index < tabel.size(); index++){
        deff = tabel[index] - tabel[index - 1];
        if(deff < min_distance)
            min_distance = deff;
    }
    return(min_distance);
}

template <typename Iterator>
void    Span::addRange(Iterator begin, Iterator end){
    size_t elements = std::distance(begin, end);
    size_t place_restante = _maxsize - _data.size();
    if(elements > place_restante)
        throw std::runtime_error("Exception : Capacité maximale dépassée");
    _data.insert(_data.end(), begin, end);
}