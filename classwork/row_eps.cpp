#include <iostream>
#include <cmath>

int main() {
    double eps;
    std::cout << "enter eps: ";
    std::cin >> eps;
    double s = 1;
    int count = 1;
    double sign = 1.0;
    int i = 3;
    double mult = 1.0;
    double sign_2 = 1.0;
    while (mult * sign <= eps) {
        sign_2 *= -1.0;
        mult = sign_2 * (static_cast<double>(1) / i);
        s += mult;
        i += 2;
        if (mult < 0.0)
            sign = -1.0;
        else
            sign = 1.0;
    }
    std::cout << s * 4 << '\n';
}
