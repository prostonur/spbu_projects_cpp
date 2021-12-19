#include <iostream>

void dec_to_hex_for_symb(int num, char symb[3]) {
    int temp = num;
    int deg = 1;
    while ((temp /= 16) != 0)
        deg *= 16;
    int count = 0;
    while (deg) {
        if (num / deg > 9)
            symb[count++]= static_cast<char>(55 + num / deg);
        else
            symb[count++]= static_cast<char>(48 + num / deg);
        num %= deg;
        deg /= 16;
    }
    symb[3] = 0;
}
int dec_to_hex(int num, char symb[10]) {
    int temp = num;
    int deg = 1;
    while ((temp /= 16) != 0)
        deg *= 16;
    int count = 0;
    while (deg) {
        if (num / deg > 9)
            symb[count++]= static_cast<char>(55 + num / deg);
        else
            symb[count++]= static_cast<char>(48 + num / deg);
        num %= deg;
        deg /= 16;
    }
    return count;
}
void print_bin(int num) {
    char string[10];
    int start = dec_to_hex(num, string);
    int iter = 0;
    for (int i = 0; i < 10; ++i) {
        if (i >= 10 - start)
            std::cout << string[iter++];
        else
            std::cout << '0';
    }
    std::cout << ": ";
}
int main() {
    char string[] = "zvezda1zvezda11111";
    char substring[17];
    int count = 0;
    int iter_substring = 0;
    int num = 16;
    print_bin(num);
    while (true) {
        if (string[count] == '\0') {
            while (count % 16 != 0) {
                if (count % 8 == 0)
                    std::cout << "| ";
                count++;
                std::cout << "   ";
            }
            std::cout << ' ';
            for (int j = 0; j < iter_substring; ++j)
                std::cout << substring[j];
            std::cout << '\n';
            break;
        }
        if (count == 8)
            std::cout << "| ";
        else if (count == 16) {
            std::cout << ' ';
            for (int j = 0; j < iter_substring; ++j)
                std::cout << substring[j];
            std::cout << '\n';
            num += 16;
            print_bin(num);
            iter_substring = 0;
        }
        substring[iter_substring++] = string[count];
        char symb[3];
        dec_to_hex_for_symb(static_cast<int>(string[count]), symb);
        std::cout << symb << ' ';
        count++;
    }
}

