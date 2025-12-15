#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cmath> // for std::isinf and std::isnan

bool isPseudoLiteral(const std::string& s) {
    return s == "nan"   || s == "+inf"  || s == "-inf" ||
           s == "nanf"  || s == "+inff" || s == "-inff";
}

int main() {
    for (auto s : {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"}) {
        float v;
        std::stringstream ss(s);
        ss >> v;
        std::cout << s << " -> " << v;
        if (std::isnan(v)) std::cout << " (NaN)";
        if (std::isinf(v)) std::cout << " (Inf)";
        std::cout << '\n';
    }
}