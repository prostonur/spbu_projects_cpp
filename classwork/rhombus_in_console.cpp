#include <iostream>


int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int tabs = 1;
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        int temp_tabs = 0;
        while (temp_tabs != n - tabs)
        {
            std::cout << ' ';
            temp_tabs++;
        }
        int zvezdi = i;
        while (zvezdi) {
            std::cout << '*';
            zvezdi--;
        }
        std::cout << '\n';
        tabs++;
    }

    tabs = n - 1;
    for (int i = 2 * (n - 1) - 1; i >= 1; i -= 2) {
        int temp_tabs = n - tabs;
        while (temp_tabs != 0)
        {
            std::cout << ' ';
            temp_tabs--;
        }
        int zvezdi = (i <= 2 * n) ? i : 0;
        while (zvezdi)
        {
            std::cout << '*';
            zvezdi--;
        }
        std::cout << '\n';
        tabs--;
    }
}
