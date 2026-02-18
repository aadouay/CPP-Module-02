#include <iostream>
#include <string>
#include <cctype>



// class Animal {
//     public:
//         int a = 10;
//         int b = 22;
//         virtual ~Animal();
// };

// class Cat : public Animal{
//     public:
//         int j = 0;
//         int l = 44;
// };

// class Dog {
//     public:
//         std::string name = "mawkli";
//         int age = 2;
// };

// int main() {

//     Animal *addr = new Cat; // upcast happing her hytach addr mn type animal not dog !
//     std::cout << "befor downcast" << std::endl;
//     std::cout << "a = " << addr->a << std::endl;

//     Dog *down = static_cast<Dog*> (addr);
//     // std::cout << "after downcast" << std::endl;
//     std::cout << "a = " << down->age << std::endl;


//     return 0;
// }

#include <iostream>
#include <string>

class Animal {
public:
    void help() {std::cout << "waykhan" << std::endl;}
    virtual ~Animal() {} // Needed for dynamic_cast
};

class Cat :public Animal {
public:
    void meow() { std::cout << "Meow!" << std::endl; }
};

class Dog :public Animal{
public:
    std::string secretDogCode = "BONE-123"; // Cat doesn't have this!
    void bark() { std::cout << "Barking: " << secretDogCode << std::endl; }
};

int main() {
    // 1. Create a CAT
    // Animal* ptr = new Cat();
    Dog obj;

    // 2. STATIC_CAST (The "Dangerous" Way)
    // This COMPILES because both are Animals.
    // Dog* badDog = static_cast<Dog*>(ptr); 
    
    // std::cout << "--- Static Cast Result ---" << std::endl;
    // // This will likely CRASH or print garbage because 
    // // it's trying to read 'secretDogCode' from memory that only contains a Cat.
    // badDog->bark(); 

    // 3. DYNAMIC_CAST (The "Safe" Way)
    std::cout << "\n--- Dynamic Cast Result ---" << std::endl;
    Cat* safeCat = dynamic_cast<Cat*>(&obj);

    // if (safeCat == nullptr) {
    //     std::cout << "Safety Check: This is NOT a dog. Pointer is NULL." << std::endl;
    // }
    // safeDog->help();
    // safeCog->bark();
    // safeCat->meow();
    Animal *ikhan = dynamic_cast<Animal *> (safeCat);
    ikhan->help();

    return 0;
}