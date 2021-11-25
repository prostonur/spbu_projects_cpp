#pragma once
#include <iostream>

double** create_matrix(size_t cols, size_t rows); // function thar allocates memory for matrix

void delete_matrix(double** matrix, size_t rows, size_t cols);

void input_matrix(double** matrix, size_t rows, size_t cols);

void zeros(double** matrix, size_t rows, size_t cols);

void ones(double** matrix, size_t rows, size_t cols);

void fill(double** matrix, size_t rows, size_t cols, double val = 0);

void print_matrix(double** matrix, size_t rows, size_t cols);

double** linspace(size_t length);

double** transpose(double** matrix, size_t rows, size_t cols);

//1 2 3 4   -> 12 11 10 9
//5 6 7 8   -> 8 7 6 5
//9 10 11 12-> 4 3 2 1
void rotate180(double** matrix, size_t rows, size_t cols);

double& findMinimum(double** matrix, size_t rows, size_t cols);

double** sum(double** matrix1, double** matrix2, size_t rows, size_t cols);

double** min(double** matrix1, double** matrix2, size_t rows, size_t cols);

double** product(double** matrix1, double** matrix2, size_t rows1, size_t cols1, size_t rows2, size_t cols2);