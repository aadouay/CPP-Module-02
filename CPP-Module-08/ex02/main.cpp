#include "Array.hpp"
#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time
#include <iostream>

#define MAX_VAL 750
// int main(int, char **) {
//   Array<int> numbers(MAX_VAL);
//   int *mirror = new int[MAX_VAL];
//   std::srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     numbers[i] = value;
//     mirror[i] = value;
//   }
//   // SCOPE
//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     numbers[-2] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     numbers[MAX_VAL] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }

//   delete[] mirror;

//   std::cout << "All tests passed successfully!" << std::endl;
//   return 0;
// }

int main() {
    try {
        // 1. Test de création et remplissage
        Array<int> nombres(5);
        for (unsigned int i = 0; i < nombres.size(); i++) {
            nombres[i] = i * 10;
        }

        // 2. Test de la Deep Copy (Copie profonde)
        std::cout << "--- Test Deep Copy ---" << std::endl;
        Array<int> copie = nombres;
        copie[0] = 999;
        
        std::cout << "Original[0]: " << nombres[0] << " (devrait être 0)" << std::endl;
        std::cout << "Copie[0]:    " << copie[0] << " (devrait être 999)" << std::endl;

        std::cout << "\n--- Test return size of array ---" << std::endl;
        std::cout << nombres.size() << std::endl;
        // 3. Test de l'exception (Hors limites)
        std::cout << "\n--- Test Exception ---" << std::endl;
        std::cout << "Tentative d'accès à l'index 10 (taille 5)..." << std::endl;
        std::cout << nombres[10] << std::endl;


    } catch (const std::exception& e) {
        // C'est ici que ton message "Index out of bounds" va s'afficher
        std::cerr << "ERREUR ATTRAPEE : " << e.what() << std::endl;
    }

    return 0;
}