// ═══════════════════════════════════════════════════════════════
//  LES 3 VERSIONS DE shortestSpan()
//  Du plus lent au plus rapide
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <vector>
#include <algorithm>  // std::sort, std::min_element
#include <cstdlib>    // std::abs
#include <ctime>      // std::clock

// ───────────────────────────────────────────────────────────────
//  VERSION 1 — O(n³) — LA PIRE
// ───────────────────────────────────────────────────────────────
//
//  PROBLEME :
//  Tu as une 3eme boucle CACHEE a l'interieur.
//  Au lieu de garder juste une variable "currentMin",
//  tu stockes TOUTES les differences dans un vecteur,
//  puis tu le reparcours a chaque fois pour trouver le min.
//
//  AVEC 10 000 NOMBRES :
//  - Boucle i        : 10 000 tours
//  - Boucle j        : 10 000 tours
//  - Boucle k (min)  : jusqu'a 50 000 000 tours
//  = 10000 * 10000 * 50000000 / 6 ≈ des milliards d'operations
//  → Ton ordi tourne pendant des HEURES
//
//  AUTRE PROBLEME :
//  Le vecteur "results" grandit a chaque iteration de i.
//  A la fin il contient n*(n-1)/2 elements.
//  Pour 10 000 nombres = 50 MILLIONS d'elements en RAM.
//  → Risque de crash memoire (out of memory)

int shortestSpan_V1(std::vector<int> _vNumber)
{
    if (_vNumber.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> results;

    for (size_t i = 0; i < _vNumber.size(); i++)
    {
        for (size_t j = i + 1; j < _vNumber.size(); j++)
        {
            int diff = std::abs(_vNumber[i] - _vNumber[j]);
            results.push_back(diff);

            // ← ICI la 3eme boucle cachee :
            // Au lieu de juste faire : if (diff < currentMin) currentMin = diff;
            // On reparcourt tout "results" pour trouver le min a chaque fois
            // C'est completement inutile et c'est ca qui cree le O(n³)
            int currentMin = results[0];
            for (size_t k = 1; k < results.size(); k++)  // ← BOUCLE INUTILE
            {
                if (results[k] < currentMin)
                    currentMin = results[k];
            }
            (void)currentMin; // on utilise pas le resultat ici, juste pour montrer le probleme
        }
    }

    // On trie quand meme a la fin pour retourner le bon resultat
    std::sort(results.begin(), results.end());
    return results[0];
}


// ───────────────────────────────────────────────────────────────
//  VERSION 2 — O(n²) — TON CODE ACTUEL
// ───────────────────────────────────────────────────────────────
//
//  PROBLEME 1 — Complexite O(n²) :
//  Tu compares CHAQUE element avec TOUS les autres.
//  Pour n elements, tu fais n*(n-1)/2 comparaisons.
//
//  AVEC 10 000 NOMBRES :
//  10000 * 9999 / 2 = 49 995 000 comparaisons
//  + trier un vecteur de 50 millions d'elements
//  → Quelques secondes, mais ca explose sur 100 000+ nombres
//
//  PROBLEME 2 — Memoire :
//  Tu crees "RangeToNumber" qui va contenir 50 MILLIONS d'entiers
//  50 000 000 * 4 bytes = 200 MB de RAM juste pour ce calcul
//  → Risque de crash sur machines avec peu de RAM (comme les 42 machines)
//
//  PROBLEME 3 — Effet de bord (le plus dangereux) :
//  Tu tries DIRECTEMENT _vNumber (l'original).
//  Si quelqu'un appelle addNumber() apres shortestSpan(),
//  les donnees sont dans un ordre different = comportement imprevu.
//  C'est un BUG silencieux, le pire type de bug.

int shortestSpan_V2(std::vector<int> _vNumber, size_t _maxSize)
{
    if (_vNumber.size() < 2)
        throw std::runtime_error("Not enough numbers");

    // BUG : on trie l'ORIGINAL, pas une copie
    std::sort(_vNumber.begin(), _vNumber.end());  // ← MODIFIE L'ETAT INTERNE

    std::vector<int> RangeToNumber;               // ← VA GROSSIR JUSQU'A 50M D'ELEMENTS

    for (size_t index = 0; index < _maxSize; index++)
    {
        for (size_t NextIndex = index + 1; NextIndex < _maxSize; NextIndex++)
        {
            // Pour 10 000 elements, cette ligne est executee 50 MILLIONS de fois
            RangeToNumber.push_back(std::abs(_vNumber[index] - _vNumber[NextIndex]));
        }
    }

    std::sort(RangeToNumber.begin(), RangeToNumber.end()); // ← Trier 50M d'elements
    return RangeToNumber[0];
}


// ───────────────────────────────────────────────────────────────
//  VERSION 3 — O(n log n) — LA BONNE VERSION
// ───────────────────────────────────────────────────────────────
//
//  INSIGHT CLE :
//  Apres tri, la plus petite distance est FORCEMENT
//  entre deux elements adjacents (voisins directs).
//
//  POURQUOI ?
//  Imagine : {3, 6, 9, 11, 17} (deja trie)
//  Si la distance minimale etait entre 3 et 9 (= 6),
//  alors forcement la distance entre 3 et 6 (= 3) serait plus petite.
//  Donc on n'a JAMAIS besoin de comparer des non-voisins.
//
//  AVEC 10 000 NOMBRES :
//  - Copier le vecteur    : 10 000 operations  → O(n)
//  - Trier la copie       : ~130 000 operations → O(n log n)
//  - Boucle sur voisins   : 9 999 operations   → O(n)
//  Total : ~150 000 operations au lieu de 50 000 000
//  → 333x PLUS RAPIDE que V2 sur 10 000 nombres
//  → Instantane meme sur 1 000 000 de nombres
//
//  AVANTAGES :
//  ✅ Ne modifie pas _vNumber (on travaille sur une copie)
//  ✅ Memoire extra = O(n) seulement (juste la copie)
//  ✅ Une seule variable min au lieu d'un vecteur de 50M
//  ✅ Rapide meme sur de tres grands datasets

int shortestSpan_V3(std::vector<int> _vNumber)
{
    if (_vNumber.size() < 2)
        throw std::runtime_error("Not enough numbers");

    // ETAPE 1 : Copie pour ne pas toucher l'original
    std::vector<int> sorted(_vNumber);            // ← COPIE, pas l'original

    // ETAPE 2 : Trier la copie — O(n log n)
    std::sort(sorted.begin(), sorted.end());

    // ETAPE 3 : Une seule variable pour le minimum
    int minSpan = sorted[1] - sorted[0];         // ← JUSTE UN INT, pas un vecteur

    // ETAPE 4 : Boucle simple sur les voisins — O(n)
    for (size_t i = 1; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];     // ← Voisins adjacents seulement
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}


// ───────────────────────────────────────────────────────────────
//  MAIN — Comparaison des 3 versions avec chronometre
// ───────────────────────────────────────────────────────────────

int main( void )
{
    // Preparation : vecteur de 10 000 nombres aleatoires
    std::srand(42); // seed fixe pour avoir les memes nombres a chaque run
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(std::rand());

    std::cout << "Test sur " << numbers.size() << " nombres aleatoires\n" << std::endl;

    // ── VERSION 1 ──
    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║  VERSION 1 — O(n³)           ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;
    std::cout << "⚠️  ATTENTION : Tres lent sur 10 000 nombres !" << std::endl;
    std::cout << "   (commente ce bloc pour ne pas attendre)" << std::endl;
    // clock_t start1 = std::clock();
    // int result1 = shortestSpan_V1(numbers);
    // clock_t end1 = std::clock();
    // std::cout << "Resultat : " << result1 << std::endl;
    // std::cout << "Temps    : " << (double)(end1 - start1) / CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "[SKIPPE — trop lent pour la demo]\n" << std::endl;

    // ── VERSION 2 ──
    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║  VERSION 2 — O(n²)  TON CODE ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;
    clock_t start2 = std::clock();
    int result2 = shortestSpan_V2(numbers, numbers.size());
    clock_t end2 = std::clock();
    std::cout << "Resultat : " << result2 << std::endl;
    std::cout << "Temps    : " << (double)(end2 - start2) / CLOCKS_PER_SEC << "s\n" << std::endl;

    // ── VERSION 3 ──
    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║  VERSION 3 — O(n log n)  BON ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;
    clock_t start3 = std::clock();
    int result3 = shortestSpan_V3(numbers);
    clock_t end3 = std::clock();
    std::cout << "Resultat : " << result3 << std::endl;
    std::cout << "Temps    : " << (double)(end3 - start3) / CLOCKS_PER_SEC << "s\n" << std::endl;

    // ── VERDICT ──
    std::cout << "╔══════════════════════════════════════════╗" << std::endl;
    std::cout << "║  VERDICT                                 ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════╝" << std::endl;
    if (result2 == result3)
        std::cout << "✅ V2 et V3 donnent le meme resultat : " << result3 << std::endl;
    else
        std::cout << "❌ Resultats differents — bug quelque part !" << std::endl;

    std::cout << "\nConclusion :" << std::endl;
    std::cout << "  V1 O(n³)      → des heures     → JAMAIS utiliser" << std::endl;
    std::cout << "  V2 O(n²)      → quelques secs  → trop lent + bug effet de bord" << std::endl;
    std::cout << "  V3 O(n log n) → instantane     → C'EST CELLE-LA qu'il faut" << std::endl;

    return 0;
}