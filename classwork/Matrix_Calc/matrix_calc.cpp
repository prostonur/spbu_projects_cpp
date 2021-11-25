#include "matrix.h"
int main() {
    size_t const rows = 5;
    size_t const cols = 4;
    double** matrix1 = create_matrix(rows, cols);
    double** matrix2 = create_matrix(rows, cols);
    double** res = create_matrix(rows, cols);
    fill(matrix1, rows, cols, 2);
    fill(matrix2, rows, cols, 3);
    res = min(matrix1, matrix2, rows, cols);
    print_matrix(res, rows, cols);
    res = sum(matrix1, matrix2, rows, cols);
    print_matrix(res, rows, cols);
    double** pr_test_1 = create_matrix(3, 2);
    double** pr_test_2 = create_matrix(2,3);
    double **pr_test_res = create_matrix(3,3);
    zeros(pr_test_res, 3,3 );
    fill(pr_test_1, 3, 2, 2);
    fill(pr_test_2, 2, 3, 3);
    if (product(pr_test_1, pr_test_2, 3, 2, 2 ,3) != nullptr)
        pr_test_res = product(pr_test_1, pr_test_2, 3, 2, 2 ,3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j)
            pr_test_1[i][j] = i * j + 1;
    }
    print_matrix(pr_test_1, 3, 2);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j)
            pr_test_2[i][j] = i * j + 2;
    }
    print_matrix(pr_test_2, 2, 3);
    if (product(pr_test_1, pr_test_2, 3, 2, 2 ,3) != nullptr)
        pr_test_res = product(pr_test_1, pr_test_2, 3, 2, 2 ,3);
    print_matrix(pr_test_res, 3, 3);
    delete_matrix(matrix1, rows, cols);
    delete_matrix(matrix2, rows, cols);
}

