#pragma once
#include <iostream>

template<typename T>

T   easyfind(T data, int value){

    for (data::iterator it = data.begin(); it != data.end() ; ++it){
        if(*it == value)
            return *it;
    }
}