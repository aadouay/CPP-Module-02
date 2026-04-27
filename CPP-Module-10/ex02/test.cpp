#include <iostream>
#include <vector>
#include <algorithm>



std::vector<std::pair<int, int> >   make_paire(const std::vector<int>& stock){

    std::vector<std::pair<int, int> > stock_paire;

    for(size_t i = 0; i + 1 < stock.size(); i+=2){
        int a = stock[i];
        int b = stock[i + 1];
        if(a > b)
            std::swap(a, b);
        stock_paire.push_back({a, b});
    }

    return stock_paire;
}

void    insert_elements(std::vector<int>& stack, int value){

    std::vector<int>::iterator position = std::lower_bound(stack.begin(), stack.end(), value);
    stack.insert(position, value);
}

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void    sort(std::vector<int>& stock){
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

    sort(biggers);
    insert_elements(biggers, smallers[0]);
    // Insertion des autres éléments selon l'ordre de Jacobsthal !
    int step = 2;

    while (true){
        int current = jacobsthal(step + 1);
        int previous = jacobsthal(step);

        
    }
    
    if(leftOver != -1)
        insert_elements(biggers, leftOver);
    stock = biggers;
}

int main(){
    std::vector<int> stock = {9, 3, 7, 1, 8, 2};
    sort(stock);
}