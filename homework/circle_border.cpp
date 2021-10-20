//Задача 7. Дана окружность с целочисленным радиусом R<10^6.
//Посчитать число точек с целочисленными координатами, лежащих внутри окружности,
//в том числе и находящихся на границе окружности.

#include <iostream>
#include <cmath>
#include <set>


int main() {
    int r;
    std::set<std::pair<int, int>> st;
    std::cout << "enter r: ";
    std::cin >> r;
    int count = 0;
    for (int x = -r; x <= r; ++x)
        for (int y = -r; y <= r; ++y)
            if (pow(x,2) + pow(y, 2) <= pow(r, 2))
                st.emplace(std::make_pair(x,y));
    std::cout << "number of dots: " << st.size() << '\n';
}

// another solution
//int main() {
//    int r;
//    std::cout << "enter r: ";
//    std::cin >> r;
//    bool arr[2 * r + 1][2 * r + 1];
//    for (int x = -r; x <= r; ++x) {
//        for (int y = -r; y <= r; ++y)
//            arr[x][y] = false;
//    }
//    for (int x = -r; x <= r; ++x) {
//        for (int y = -r; y <= r; ++y)
//            std::cout << arr[x][y] << ' ';
//        std::cout << '\n';
//    }
//
//
//    int count = 0;
//    for (int x = -r; x <= r; ++x)
//        for (int y = -r; y <= r; ++y)
//            if (pow(x,2) + pow(y, 2) <= pow(r, 2)) {
//                if (!arr[x][y]) {
//                    count++;
//                    arr[x][y] = true;
//                }
//            }
//    std::cout << "----------------------------------------\n";
//    for (int x = -r; x <= r; ++x) {
//        for (int y = -r; y <= r; ++y)
//            std::cout << arr[x][y] << ' ';
//        std::cout << '\n';
//    }
//    std::cout << "number of dots: " << count << '\n';
//}

