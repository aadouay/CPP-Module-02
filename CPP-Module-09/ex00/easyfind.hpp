#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>

typename T::iterator   easyfind(T& data, int value){
    
    typename T::iterator it = std::find(data.begin(), data.end(), value);
    if(it != data.end())
        return it;
    throw std::runtime_error("Value not found");
}

