#pragma once

template <typename T>
void swap(T &a, T &b){
    T tem;
    tem = a;
    a = b;
    b = tem;
}

template <typename T>
T min(T a, T b){
    if (a == b)
        return b;
    // condition ? valeur_si_vrai : valeur_si_faux.
    return (a < b) ? a : b;
}

template <typename T>

T max(T a, T b){
    if (a == b)
        return b;
    return (a > b) ? a : b;
}