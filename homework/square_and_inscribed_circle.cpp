//Рассмотрим произвольный квадрат с центром в начале координат и вписанный в него круг.
//Будем рассматривать только первую координатную четверть. В ней будет находиться четверть круга и четверть квадрата.
//Обозначим радиус круга R, тогда четверть квадрата тоже будет квадратом со стороной R.
//Будем случайным образом выбирать точки в этом квадрате и считать количество точек, попавших в четверть круга.
//Из теории вероятности известно, что отношение попаданий в четверть круга к попаданиям "в молоко"
//равно отношению площадей – pi/4.
//Реализовать указанный алгоритм вычислений. Количество выбираемых точек N (вычислено ранее).
//Сравнить вычисленные двумя способами значения числа pi. Можно сделать вывод какой способ сходится быстрее?

#include <iostream>
#include <random>

int main() {
    int r, n;
    int hit = 0, not_hit = 0;
    std::random_device rd;
    std::cout << "enter r, n: ";
    std::cin >> r >> n;
    std::uniform_int_distribution dist(0, r / 2);
    r /= 2;
    while (n) {
        int x = dist(rd);
        int y = dist(rd);
        if (x * x + y * y <= r * r)
            hit++;
        else
            not_hit++;
        n--;
        //std::cout << x << ' ' << y << ' ' << hit << ' ' << not_hit << ' ' << n << '\n';
    }
    if (!not_hit) {
        std::cout << "all the bullets hit the bull's eye!\n";
        exit(1);
    }
    std::cout << 1. * hit / (r * r / 4) << ' ' << 3.14 / 4 << '\n';
}