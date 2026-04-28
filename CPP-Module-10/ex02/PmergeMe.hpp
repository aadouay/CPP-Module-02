#pragma once
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <chrono> // pour calcul le temps

class PmergeMe{

    public:
        // PmergeMe();
        // PmergeMe(const PmergeMe& other);
        // PmergeMe&   operator=(const PmergeMe& other);
        // ~PmergeMe();

        std::vector<int> stock_vec;
        std::deque<int> stock_deq;
        void    parse_input(char **args);
        void    print_container_vec();
        void    print_container_deq();
        std::vector<std::pair<int, int> >   make_paire(const std::vector<int>& stock);
        void    insert_elements(std::vector<int>& stack, int value);
        std::vector<int> jacobsthal(size_t n);
        void    sort_vec(std::vector<int>& stock);

};