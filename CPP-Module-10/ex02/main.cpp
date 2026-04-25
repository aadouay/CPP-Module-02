#include <iostream>
#include <vector>


std::vector<std::pair<int, int> > make_pairs(const std::vector<int>& stock)
{
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < stock.size(); i += 2)
    {
        int a = stock[i];
        int b = stock[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    return pairs;
}

int main() {

    std::vector<int> stock = {9, 3, 7, 1, 8, 2};

    sort(stock);
}

void sort(std::vector<int> stock) {

    if (stock.size() <= 1)
        return;

    std::vector<std::pair<int, int> > stockPairs = make_pairs(stock);

    int leftOver = -1;
    if (stock.size() % 2 == 1)
        leftOver = stock.back();

    std::vector<int> smallers;
    std::vector<int> biggers;

    for (std::vector<std::pair<int, int> >::const_iterator it = stockPairs.begin(); it != stockPairs.end(); ++it)
    {
        smallers.push_back(it->first);
        biggers.push_back(it->second);
    }

    sort(biggers);

    // insert the smallers in the biggers

    
}