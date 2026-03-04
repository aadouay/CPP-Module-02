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



// rapelle le concept de const en nos objects !!
// Le const à la fin : La promesse de l'objet 
//... operator[](unsigned int index) const
/*
  C'est ce qu'on appelle une méthode constante.

  Le rôle : Ce const dit au compilateur : "Je promets que cette fonction ne modifiera
  aucun attribut de la classe (elle ne touchera ni à _data, ni à _size)".

  Pourquoi c'est vital ? En C++, si tu as un objet constant (ex: const Array<int> myTab(5);),
  tu ne peux appeler sur lui que des méthodes qui finissent par const. Sans ce const à la fin,
  tu ne pourrais même pas lire le contenu d'un tableau constant !
*/

// Le const au début : La protection de la donnée
// const T & ...

/*
  Ici, on parle de ce que la fonction renvoie.

  Le rôle : La fonction renvoie une référence vers l'élément dans le tableau,
  mais elle y ajoute un verrou "lecture seule".

  L'effet : Si tu écris myTab[0] = 42; avec cette version de l'opérateur,
  le compilateur dira : "Impossible ! Tu essaies de modifier une valeur qui est protégée par un const."

*/

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