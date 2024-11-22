#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrix_operations.h"

// Function to perform matrix multiplication of A (MxN) and B (NxW)
double matrix_multiply(int M, int N, int W, int** A, int** B, int** C, int num_threads) {
    double start_time = omp_get_wtime(); // Start timing

    // Parallel region for matrix multiplication
    #pragma omp parallel for num_threads(num_threads) collapse(2)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < W; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end_time = omp_get_wtime(); // End timing
    double time_taken = end_time - start_time;
    printf("Time taken with %d threads: %f seconds\n", num_threads, time_taken);
    return time_taken;
}

// Function to calculate the speedup percentage
double calculate_speedup_percentage(double serial_time, double parallel_time) {
    if (parallel_time == 0.0) {
        return 0.0;
    }
    double speedup = serial_time / parallel_time;
    return ((speedup - 1) / speedup) * 100.0;
}

// Function to allocate a 2D matrix dynamically
int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a dynamically allocated 2D matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to initialize a matrix with random values
void initialize_matrix(int** matrix, int rows, int cols, int max_val) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % max_val + 1; // Values between 1 and max_val
        }
    }
}
