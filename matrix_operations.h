#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// Function prototypes
double matrix_multiply(int M, int N, int W, int** A, int** B, int** C, int num_threads);
double calculate_speedup_percentage(double serial_time, double parallel_time);
int** allocate_matrix(int rows, int cols);
void free_matrix(int** matrix, int rows);
void initialize_matrix(int** matrix, int rows, int cols, int max_val);

#endif // MATRIX_OPERATIONS_H
