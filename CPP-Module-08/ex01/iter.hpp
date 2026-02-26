#pragma once

template <typename T, typename F>

void   iter(T *array, const int lenght, F function){
    for (int i = 0; i < lenght; i++) {function(array[i]);}
}
