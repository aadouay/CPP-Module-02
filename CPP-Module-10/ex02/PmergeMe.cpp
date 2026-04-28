#include "PmergeMe.hpp"


void    PmergeMe::parse_input(char **args){

    // faire un check sur tous les args[i] apres tout est bien stockeeee zmarrr ! 
    for (size_t i = 1; args[i] != NULL; i++)
    {
        std::stringstream ss(args[i]);
        int number;
        if (!(ss >> number))
            throw std::runtime_error("Error: invalid number -> '" + std::string(args[i]) + "'");
    
        if (!(ss >> std::ws).eof())
            throw std::runtime_error("Error: extra characters in input -> '" + std::string(args[i]) + "'");

        if (number < 0)
            throw std::runtime_error("Error: only positive numbers allowed -> '" + std::string(args[i]) + "'");

        // OK -> on stocke
        stock_vec.push_back(number);
        stock_deq.push_back(number);
    }
}


void    PmergeMe::print_container_vec(){
    
    for (size_t i = 0; i < stock_vec.size(); i++)
    {
        std::cout << stock_vec[i] << " ";
        if(i == 10){
            std::cout << "[...]";
            break ;
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::print_container_deq(){
    
    for (size_t i = 0; i < stock_deq.size(); i++)
    {
        std::cout << stock_deq[i] << " ";
        if(i == 10){
            std::cout << "[...]";
            break ;
        }
    }
    std::cout << std::endl;
}

std::vector<std::pair<int, int> >   PmergeMe::make_paire(const std::vector<int>& stock){

    std::vector<std::pair<int, int> > stock_paire;

    for(size_t i = 0; i + 1 < stock.size(); i+=2){
        int a = stock[i];
        int b = stock[i + 1];
        if(a > b)
            std::swap(a, b);
        stock_paire.push_back(std::pair<int, int>(a, b));
    }

    return stock_paire;
}

void    PmergeMe::insert_elements(std::vector<int>& stack, int value){

    std::vector<int>::iterator position = std::lower_bound(stack.begin(), stack.end(), value);
    stack.insert(position, value);
}

std::vector<int>    PmergeMe::jacobsthal(size_t n){

    std::vector<int> seq;
    if(n <= 1)
        return seq;
    seq.push_back(0); // j(0) = 0
    seq.push_back(1); // j(1) = 1 et j(2) = 1
    seq.push_back(1); // jacobsthal starts with : 0 1 1 ...

    // formule de récurrence : j(n) = j(n - 1) + 2 * j(n - 2)
    for (size_t i = 3; i < n; i++){                     // ind  0  1
        int next_value = seq[i - 1] + 2 * seq[i - 2];   // seq [0, 1] --> 3 - 1 = 2 , 3 - 2 = 1
        if(seq.back() > static_cast<int>(n))
            break ;
        seq.push_back(next_value);
    }

    return seq;
}

void    PmergeMe::sort_vec(std::vector<int>& stock){

    if (stock.size() <= 1)
    return;
    std::vector <std::pair<int, int> > stock_pair = make_paire(stock);

    int leftOver = -1;
    if (stock.size() % 2 == 1)
        leftOver = stock.back();
    std::vector<int> smallers;
    std::vector<int> biggers;
    for (size_t i = 0; i < stock_pair.size(); i++)
    {
        smallers.push_back(stock_pair[i].first);
        biggers.push_back(stock_pair[i].second);
    }

    sort_vec(biggers);
    std::vector<int> jseq = jacobsthal (smallers.size() + 2); // par example si smallers.size() = 2 , jacobsthal(4) = 0 1 1 3

    std::vector<int> isertionOrder;
    isertionOrder.push_back(0); // car on doit insérer le plus petit élément en premier
    for (int i = 3 ; i < static_cast<int> (jseq.size()); i++) // on commence à 3 car les trois premiers éléments de la séquence de jacobsthal sont 0, 1, 1 et on les a déjà traité
    {
        int second = jseq[i];
        int first = jseq[i - 1];
        for (int j = second - 1; j >= first; j--)
        {
            if (j < static_cast<int> (smallers.size()))
                isertionOrder.push_back(j);
        }
    }

    for (std::size_t i = 0; i < isertionOrder.size(); i++)
    {
        int c = smallers[isertionOrder[i]];
        insert_elements(biggers, c);
    }

    if(leftOver != -1)
        insert_elements(biggers, leftOver);
    stock = biggers;
}