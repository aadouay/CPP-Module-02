#include <iostream>
#include <vector>

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

void    sort(const std::vector<int>& stock){
    if (stock.size() <= 1)
        return;
    std::vector <std::pair<int, int> > stock_pair = make_paire(stock);
    // for (size_t i = 0; i < stock_pair.size(); i++)
    // {
    //     std::cout << "first -> " << stock_pair[i].first << " | second -> " << stock_pair[i].second << std::endl;
    // }
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
}

int main(){
    std::vector<int> stock = {9, 3, 7, 1, 8, 2};
    sort(stock);
}