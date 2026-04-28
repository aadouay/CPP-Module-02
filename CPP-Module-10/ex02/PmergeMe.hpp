#pragma once
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime> // pour calcul le temps

class PmergeMe{
    private:
        std::vector<int> stock_vec;
        std::deque<int> stock_deq;
    public:
        // PmergeMe();
        // PmergeMe(const PmergeMe& other);
        // PmergeMe&   operator=(const PmergeMe& other);
        // ~PmergeMe();

        // std::vector<int> stock_vec;
        // std::deque<int> stock_deq;
        void    parse_input_and_sort(char **args);
        void    print_container_vec();
        void    print_container_deq();
        std::vector<std::pair<int, int> >   make_paire_vec(const std::vector<int>& stock);
        std::deque<std::pair<int, int> >   make_paire_deq(const std::deque<int>& stock);
        void    insert_elements_vec(std::vector<int>& stack, int value);
        void    insert_elements_deq(std::deque<int>& stack, int value);
        std::vector<int> jacobsthal(size_t n);
        void    sort_vec(std::vector<int>& stock);
        void    sort_deq(std::deque<int>& stock);

};