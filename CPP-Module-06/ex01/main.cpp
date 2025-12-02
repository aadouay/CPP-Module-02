#include "Bureaucrat.hpp"
// #include "Form.hpp"

int main() {
    std::cout << "\n--- TEST 1 : FONCTIONNEMENT NORMAL (SIGNATURE REUSSIE) ---" << std::endl;
    try {
        // Un chef (Grade 1)
        Bureaucrat boss("Boss", 1);
        // Un formulaire facile à signer (Grade 50 requis)
        Form contract("Contrat d'embauche", 50, 50);

        // On affiche l'état avant
        std::cout << contract << std::endl;

        // Le boss essaie de signer
        boss.signForm(contract);

        // On affiche l'état après (devrait être signé)
        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2 : ECHEC DE SIGNATURE (GRADE TROP BAS) ---" << std::endl;
    try {
        // Un stagiaire (Grade 150)
        Bureaucrat noob("Stagiaire", 150);
        // Un formulaire difficile (Grade 10 requis)
        Form constitution("Constitution", 10, 10);

        std::cout << constitution << std::endl;

        // Le stagiaire essaie de signer (L'erreur sera gérée DANS signForm)
        noob.signForm(constitution);
        
        // Le formulaire ne doit pas être signé
        std::cout << constitution << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3 : ERREUR DE CREATION DE FORMULAIRE ---" << std::endl;
    try {
        // Grade 0 est interdit (le max est 1)
        std::cout << "Tentative de creer un form avec grade 0..." << std::endl;
        Form impossible("Impossible", 0, 50);
    }
    catch (std::exception& e) {
        std::cerr << "EXCEPTION ATTRAPEE : " << e.what() << std::endl;
    }

    try {
        // Grade 151 est interdit (le min est 150)
        std::cout << "Tentative de creer un form avec grade 151..." << std::endl;
        Form impossible2("TropNul", 151, 50);
    }
    catch (std::exception& e) {
        std::cerr << "EXCEPTION ATTRAPEE : " << e.what() << std::endl;
    }

    return 0;
}