#include <iostream>

// functions add in all format of data !

// int add(int a, int b) { return a + b; }
// float add(float a, float b) { return a + b; }
// std::string add(std::string a, std::string b) { return a + b; }
// char add(char a, char b) { return a + b; }

template <typename T>

T add(T a, T b) {
  return a + b;
}

int main() {
    std::cout << add(std::string ("ikhan"), std::string (" atgit")) << std::endl;
}