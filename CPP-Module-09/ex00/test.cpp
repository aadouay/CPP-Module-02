#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    std::cout << "Taille : " << v.size() << std::endl;         // Affiche 0
    std::cout << "Capacité : " << v.capacity() << std::endl; // Affiche 0
    if (v.data() == NULL) // .data() renvoie le pointeur vers le bloc interne
        std::cout << "Le pointeur interne est NULL, aucune mémoire sur le tas !" << std::endl;

    return 0;
}