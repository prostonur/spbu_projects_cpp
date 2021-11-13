//Let be n an integer prime with 10 e.g. 7.
//1/7 = 0.142857 142857 142857 ....
// We see that the decimal part has a cycle: 142857. The length of this cycle is 6. In the same way:
//1/11 = 0.09 09 09 .... Cycle length is 2.
//Task
//Given an integer n (n > 1) the function cycle(n) returns the length of the cycle
// if there is one otherwise (n and 10 not coprimes) return -1.

#include <iostream>
#include <string>
//brute force for finding cycling substring
bool check(const std::string& source, int count_sym) {
    std::string comp1;
    std::string comp2;
    int count = 1;
    bool check = true;
    for (size_t i = 0; i < source.size(); ++i) {
        if (count < count_sym and check) {
            comp1 += source[i];
            count++;
        } else if (count < count_sym and !check) {
            comp2 += source[i];
            count++;
        } else {
            if (check and i == count_sym - 1) {
                comp1 += source[i];
                check = false;
                count = 1;
            } else if (check) {
                comp1 += source[i];
                if (comp1 != comp2) return false;
                check = false;
                comp2 = "";
                count = 1;
            } else if (!check) {
                comp2 += source[i];
                if (comp1 != comp2) return false;
                comp1 = "";
                check = true;
                count = 1;
            }
        }
    }
    return true;
}
//int checking(const std::string& str) {
//    int count_sym = 1;
//    std::string substring;
//    bool check = true;
//    while (count_sym != str.size() / 2) {
//        for (size_t i = 0; i < count_sym; ++i)
//            substring += str[i];
//        std::string temp_substring;
//        for (size_t i = count_sym; i < str.size(); ++i) {
//            if (temp_substring.size() != count_sym)
//                temp_substring += str[i];
//            else {
//                if (substring != temp_substring) {
//                    check = false;
//                    break;
//                }
//                check = true;
//                temp_substring = str[i];
//            }
//        }
//        if (check) return substring.size();
//        substring = "";
//        count_sym++;
//    }
//    return -1;
//}
struct three {
    int x;
    int y;
    int z;
};
// return x - remainder of the division, y - degree of 10 to get the x, z - dividend
three ost(int num, int del) {
    int count = 0;
    while (num / del == 0) {
        num *= 10;
        count++;
    }
    return {num - (num / del) * del, count - 1, num / del};
}
//return a string 100000 characters long
std::string working_str(int n) {
    int count = 0;
    std::string out_str;
    int first = 1;
    while (count != 100000) {
        int x = ost(first, n).x;
        int y = ost(first, n).y;
        int z = ost(first, n).z;
        while (y != 0) {
            out_str += '0';
            y--;
        }
        out_str += std::to_string(z);
        first = x;
        count++;
    }
    return out_str;
}
// iterate over all substrings up to half lines
//int cycle(int n) {
//    return checking(working_str(n));
////    std::string work_str = working_str(n);
////    int count_sym = 1;
////    while (count_sym < work_str.size() / 2) {
////        if (check(work_str, count_sym)) return count_sym;
////        count_sym++;
////    }
////    return -1;
//}
int cycle(int n) {
    std::string str = working_str(n);
    int count_sym = 1;
    std::string substring;
    bool check = true;
    while (count_sym != str.size() / 2) {
        for (size_t i = 0; i < count_sym; ++i)
            substring += str[i];
        std::string temp_substring;
        for (size_t i = count_sym; i < str.size() / 2; ++i) {
            if (temp_substring.size() != count_sym)
                temp_substring += str[i];
            else {
                if (substring != temp_substring) {
                    check = false;
                    break;
                }
                check = true;
                temp_substring = str[i];
            }
        }
        if (check) return substring.size();
        substring = "";
        count_sym++;
    }
    return -1;
}
int main() {
    std::cout << cycle(13) << '\n';
}