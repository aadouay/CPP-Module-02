#include "Span.hpp"

int main(){

    try
    {
        Span mydata(4);
        mydata.addNumber(23);
        mydata.addNumber(23);
        mydata.addNumber(22);
        mydata.addNumber(223);
        mydata.addNumber(234);
        // mydata.addNumber(243);
        // mydata.addNumber(253);
        // mydata.addNumber(243);
        mydata.print_la_block();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}