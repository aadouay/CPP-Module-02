#include <iostream>
#include <string>

// Dans cet exemple on a créé une classe IntArray qui initialise juste un
// tableau. Si on veut, on pourrait créer une autre classe StringArray par
// exemple, mais c'est une mauvaise méthode (redondance de code) alors la
// solution c'est un class template !!

// Alors c'est quoi un class template ?
// Un "class template" (ou modèle de classe) est comme un moule ou un plan de
// construction. Il te permet de dire au compilateur : "Voici une classe, mais
// je ne vais pas te dire tout de suite quel type de données elle va manipuler.
// Je l'appellerai 'T'. Tu remplaceras 'T' par le vrai type (int, float,
// std::string...) quand je l'utiliserai." Cela permet d'écrire le code une
// seule fois, et de l'utiliser avec n'importe quel type !

template <typename T> class Array {
private:
  T *array;
  int size;

public:
  Array() : array(nullptr), size(0) {}

  Array(int n) : size(n) {
    array = new T[size](); // Ajout des () pour initialiser par défaut
    std::cout << "Le tableau est créé avec la taille : " << size << std::endl;
  }

  // Ajout d'un destructeur ! C'est TRÈS important pour éviter les fuites de
  // mémoire (memory leaks)
  ~Array() { delete[] array; }

  void fill(T value) {
    for (int i = 0; i < size; i++)
      array[i] = value;
  }

  T &at(int index) { return array[index]; }
};

int main() {
  // Utilisation avec un array de INT
  std::cout << "--- Test INT ---" << std::endl;
  Array<int> my_int_array(5);
  my_int_array.fill(20);
  std::cout << "Valeur index 1 : " << my_int_array.at(1) << std::endl;

  // Utilisation avec un array de STRING
  std::cout << "\n--- Test STRING ---" << std::endl;
  Array<std::string> my_string_array(3);
  my_string_array.fill("Bonjour !");
  std::cout << "Valeur index 2 : " << my_string_array.at(2) << std::endl;

  return 0;
}