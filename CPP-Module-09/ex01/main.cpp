// #include "Span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;

// }

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Span.hpp"

// ══════════════════════════════════════════
//  UTILS
// ══════════════════════════════════════════

static void	printSeparator(const std::string &title)
{
	std::cout << "\n";
	std::cout << "╔══════════════════════════════════════╗" << std::endl;
	std::cout << "║  " << title << std::endl;
	std::cout << "╚══════════════════════════════════════╝" << std::endl;
}

// ══════════════════════════════════════════
//  BLOC 1 — Test exact du sujet (PDF)
// ══════════════════════════════════════════

static void	testSubject( void )
{
	printSeparator("BLOC 1 : Test exact du sujet");

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortestSpan → " << sp.shortestSpan() << "  (attendu: 2)"  << std::endl;
	std::cout << "longestSpan  → " << sp.longestSpan()  << "  (attendu: 14)" << std::endl;
}

// ══════════════════════════════════════════
//  BLOC 2 — Test 10 000 nombres aleatoires
// ══════════════════════════════════════════

static void	testBigSpan( void )
{
	printSeparator("BLOC 2 : 10 000 nombres aleatoires");

	std::srand(std::time(0));

	Span big(10000);
	for (int i = 0; i < 10000; i++)
		big.addNumber(std::rand());

	std::cout << "shortestSpan → " << big.shortestSpan() << std::endl;
	std::cout << "longestSpan  → " << big.longestSpan()  << std::endl;
	std::cout << "[OK] Aucun crash sur 10 000 elements" << std::endl;
}

// ══════════════════════════════════════════
//  BLOC 3 — Exception : sac plein
// ══════════════════════════════════════════

static void	testFullSpan( void )
{
	printSeparator("BLOC 3 : Exception sac plein");

	Span full(3);
	full.addNumber(1);
	full.addNumber(2);
	full.addNumber(3);

	try
	{
		full.addNumber(4);
		std::cout << "[KO] Aucune exception lancee !" << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "[OK] Exception attrapee : " << e.what() << std::endl;
	}
}

// ══════════════════════════════════════════
//  BLOC 4 — Exception : pas assez d'elements
// ══════════════════════════════════════════

static void	testNotEnoughElements( void )
{
	printSeparator("BLOC 4 : Exception pas assez d'elements");

	// Cas 1 : Span vide
	Span empty(5);
	try
	{
		empty.shortestSpan();
		std::cout << "[KO] Aucune exception sur Span vide !" << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "[OK] Span vide - shortestSpan : " << e.what() << std::endl;
	}

	try
	{
		empty.longestSpan();
		std::cout << "[KO] Aucune exception sur Span vide !" << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "[OK] Span vide - longestSpan  : " << e.what() << std::endl;
	}

	// Cas 2 : Span avec un seul element
	Span lonely(5);
	lonely.addNumber(42);
	try
	{
		lonely.shortestSpan();
		std::cout << "[KO] Aucune exception sur Span a 1 element !" << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "[OK] 1 element - shortestSpan : " << e.what() << std::endl;
	}
}

// ══════════════════════════════════════════
//  BLOC 5 — Valeurs identiques
// ══════════════════════════════════════════

static void	testSameValues( void )
{
	printSeparator("BLOC 5 : Valeurs identiques");

	Span same(5);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);
	same.addNumber(42);

	std::cout << "shortestSpan → " << same.shortestSpan() << "  (attendu: 0)" << std::endl;
	std::cout << "longestSpan  → " << same.longestSpan()  << "  (attendu: 0)" << std::endl;
}

// ══════════════════════════════════════════
//  MAIN
// ══════════════════════════════════════════

int	main( void )
{
	testSubject();
	testBigSpan();
	testFullSpan();
	testNotEnoughElements();
	testSameValues();

	std::cout << "\n✅  Tous les tests sont passes.\n" << std::endl;
	return (0);
}