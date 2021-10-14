#include <iostream>

int main() {
     size_t n;
     std::cout << "enter n: ";
     std::cin >> n;
     for (size_t i = 1; i <= n; ++i) {
         int count = 0;
         while (count != i) {
             std::cout << '*';
             count++;
         }
         std::cout << '\n';
     }
}

