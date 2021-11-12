#include <iostream>
#include <ctime>
int main() {
    srand(time(nullptr));
    int n, m;
    std::cout << "enter n, m: ";
    std::cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[m];
    std::cout.width(5);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            arr[i][j] = rand() % 1000;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;

}

