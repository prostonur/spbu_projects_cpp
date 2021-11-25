#include "matrix.h"
// "" ищет сначала в родных директорияз
// <> ищет сначала в системнх директорияъ
double** create_matrix(size_t rows, size_t cols) {
    double** matrix = new double*[rows];
    for (size_t i = 0; i < rows; ++i)
        matrix[i] = new double[cols];
    return matrix;
}

void delete_matrix(double** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void input_matrix(double** matrix, size_t rows, size_t cols) {
    std::cout << "enter nums: ";
    for (int i = 0; i < rows; ++i) {
        std::cout << "input: " << i << "row\n";
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(double** matrix, size_t rows, size_t cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void fill(double** matrix, size_t rows, size_t cols, double val) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = val;
        }
    }
}

void zeros(double** matrix, size_t rows, size_t cols) {
    fill(matrix, rows, cols, 0);
}

void ones(double** matrix, size_t rows, size_t cols) {
    fill(matrix, rows, cols, 1);
}

double **linspace(size_t length) {
    double** vec = create_matrix(1, length);
    for (size_t idx = 0; idx < length; ++idx)
        vec[0][idx] = idx + 1;
    return vec;
}

double** transpose(double** matrix, size_t rows, size_t cols)
{
    double** transposed = create_matrix(cols, rows);
    for (size_t r = 0; r < rows; ++r) {
        for (size_t c = 0; c < cols; ++c)
            transposed[c][r] = matrix[r][c];
    }
    return transposed;
}

template <typename Type>
void Swap(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

void rotate180(double** matrix, size_t rows, size_t cols)
{
    // Step 1. reverse elements in each row
    for (size_t r = 0; r < rows; ++r) {
        for (size_t c = 0; c < cols / 2; ++c)
            Swap(matrix[r][c], matrix[r][cols - c - 1]);
    }
    //Step 2. reverse rows
    for (size_t r = 0; r < rows / 2; ++r)
        Swap(matrix[r], matrix[rows - r - 1]);
}

double& findMinimum(double** matrix, size_t rows, size_t cols)
{
    double minimum = **matrix;
    size_t r_min = 0;
    size_t c_min = 0;
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] < minimum)
            {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
    return matrix[r_min][c_min];
}

double** sum(double** matrix1, double** matrix2, size_t rows, size_t cols) {
    double ** sum_matrix = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    return sum_matrix;
}

double** min(double** matrix1, double** matrix2, size_t rows, size_t cols) {
    double** min_matrix = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            min_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
    return min_matrix;
}

double** product(double** matrix1, double** matrix2, size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
    double** buffer = create_matrix(rows1, cols2);
    if (cols1 != rows2) {
        std::cout << "error. product doesn't work with those matrix\n";
        return nullptr;
    }
    for (size_t i = 0; i < rows1; ++i) {
        size_t temp_cols = 0;
        while (temp_cols != cols2) {
            double elem = 0;
            for (size_t j = 0; j < cols1; ++j)
                elem += (matrix1[i][j] * matrix2[j][temp_cols]);
            buffer[i][temp_cols] = elem;
            temp_cols++;
        }
    }
    return buffer;
}