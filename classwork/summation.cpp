#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <climits>
#include <iomanip>

std::vector<int> josephus(std::vector<int> items, int k) {
    std::vector<int> out;
    size_t count_elem = -1;
    size_t added = 0;
    int orig = items.size();
    while (!items.empty()) {
        if (count_elem + k - added < items.size()) {
            count_elem += k;
//            std::cout << "//" << count_elem << ' ';
//            std::cout << items[count_elem - added] << ' ' << count_elem << '\n';
        } else {
            if (items.size() == orig)
                count_elem++;
            count_elem += k;
            //std::cout << count_elem << '/';
            count_elem %= (items.size() + added);
            while (count_elem >= items.size())
                count_elem %= items.size();
            added = 0;
//            std::cout << count_elem << ' ';
//            if (count_elem - added < items.size())
//                std::cout << items[count_elem - added] << ' ' << count_elem << '\n';
        }
        out.push_back(items[count_elem - added]);
        items.erase(items.begin() + count_elem - added);
//        for (const auto& x : items)
//            std::cout << x << ' ';
//        std::cout << '\n';
        added++;
    }
    return out;
}

int main() {
    //printf("%.9F", 19.0F, 7.0F);
    for (const auto& x : josephus({0,1,2,3}, 5))
        std::cout << x << ' ';
    //std::cout << cycle(33) << '\n';
    //std::cout << str(13) << '\n';
    //std::cout << findMissing({1,2,4}) << '\n';
//    init();
//    for (int i = 0; i < 30; ++i)
//        std::cout << vec[i] << ' ';
//    std::cout << '\n';
//    std::cout << is_square(25);
//std::cout << sumTwoSmallestNumbers({ 5, 8, 12, 19, 22 }) << '\n';
}