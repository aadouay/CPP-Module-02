// #include <iostream>
// #include "iter.hpp"

// void multi(int &n){n = n * 2;}

// void    remplir_stcok(int *array, int start_value, int size){
//     for(int i = 0; i < size; i++){
//         array[i] = start_value + i;
//     }
// }

// int main(){
//     int array[10];
//     remplir_stcok(array, 20, 10);

//     std::cout << "avant apliquer la function" << std::endl;
//     std::cout << "|";
//     for(int i = 0; i < 10; i++){
//         std::cout << array[i] << " | ";
//     }
//     std::cout << std::endl;

//     std::cout << "apres apliquer la function" << std::endl;
//     iter(array, 10, multi);

//     std::cout << "|";
//     for(int i = 0; i < 10; i++){
//         std::cout << array[i] << " | ";
//     }
//     std::cout << std::endl;
//     std::cout << std::endl;

//     std::cout << "tout est terminer !";
// }

// #include <iostream>
// #include <string>
// #include "iter.hpp"

// // Test 1: Fonction qui modifie (non-const)
// void increment(int &n) {
//     n++;
// }

// // Test 2: Fonction qui lit seulement (const)
// void display_int(const int &n) {
//     std::cout << n << " ";
// }

// // Test 3: Template de fonction (pour le piège de l'énoncé)
// template<typename T>
// void display_gen(const T &val) {
//     std::cout << val << " | ";
// }

// // Test 4: Travail sur des strings
// void upper_string(std::string &s) {
//     for (size_t i = 0; i < s.length(); i++) {
//         s[i] = toupper(s[i]);
//     }
// }

// int main() {
//     // --- TEST 1 & 2 : Entiers ---
//     int tab[] = {0, 1, 2, 3, 4};
//     std::cout << "Tableau de base : ";
//     iter(tab, 5, display_int);
//     std::cout << std::endl;

//     iter(tab, 5, increment);
//     std::cout << "Après incrément : ";
//     iter(tab, 5, display_int);
//     std::cout << "\n" << std::endl;

//     // --- TEST 3 : Utilisation d'un template de fonction ---
//     // Note: On doit parfois aider le compilateur pour les templates de fonctions 
//     // en spécifiant le type entre < >
//     std::cout << "Test avec template display_gen : ";
//     iter(tab, 5, display_gen<int>);
//     std::cout << "\n" << std::endl;

//     // --- TEST 4 : Strings ---
//     std::string strings[] = {"hello", "world", "cpp", "templates"};
//     std::cout << "Strings de base : ";
//     iter(strings, 4, display_gen<std::string>);
//     std::cout << std::endl;

//     iter(strings, 4, upper_string);
//     std::cout << "Strings en MAJUSCULES : ";
//     iter(strings, 4, display_gen<std::string>);
//     std::cout << std::endl;

//     return 0;
// }

#include <iostream>
#include "iter.hpp"

// Une fonction qui prend un argument CONSTANT
// Elle promet de ne pas modifier l'élément
void print_const(const int &n) {
    std::cout << "[Const View: " << n << "] ";
}

int main() {
    int tab[] = {10, 20, 30, 40, 50};
    
    // Test 1: Tableau normal avec fonction const
    std::cout << "Test avec fonction const sur tableau normal :" << std::endl;
    iter(tab, 5, print_const);
    std::cout << "\n" << std::endl;

    // Test 2: Tableau CONSTANT avec fonction const (Le test ultime !)
    const int const_tab[] = {1, 2, 3};
    std::cout << "Test avec tableau CONSTANT :" << std::endl;
    // Si ton iter est bien écrit avec 'T *array', 
    // il faudra peut-être une surcharge pour 'const T *array'
    // Mais voyons si ta version actuelle passe :
    iter(const_tab, 3, print_const);
    std::cout << "\n" << std::endl;

    return 0;
}