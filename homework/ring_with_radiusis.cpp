//Задача 3. На вход подаются координаты точки на плоскости.
//Проверить, попадает ли она в кольцо, образованное пространством между границей внешней окружности радиуса R
//и внутренней окружности радиуса r.

#include <iostream>
#include <cmath>


int main() {
    int x, y;
    std::cout << "enter x, y: ";
    std::cin >> x >> y;
    int r, R;
    std::cout << "enter r, R: ";
    std::cin >> r >> R;
    if (sqrt(pow(x, 2) + pow(y, 2)) <= pow(R, 2) and sqrt(pow(x, 2) + pow(y, 2)) >= pow(r, 2))
        std::cout << "Est' probitie!\n";
    else
        std::cout << "Missed\n";
}
