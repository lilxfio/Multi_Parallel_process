//  run
//  gcc -o main *.c -fopenmp  
//  ./main
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "matrix_operations.h"

int main(int argc, char** argv) {
    srand(time(NULL)); // Seed for random number generation

    // Matrix dimensions for the problem
    int M = 1000, N = 1200, W = 1300;
    printf("Matrix dimensions: M = %d, N = %d, W = %d\n", M, N, W);

    // Allocate memory for matrices
    int** A = allocate_matrix(M, N);
    int** B = allocate_matrix(N, W);
    int** C = allocate_matrix(M, W);

    // Initialize matrices A and B with random values
    initialize_matrix(A, M, N, 15);
    initialize_matrix(B, N, W, 15);

    // Perform matrix multiplication with various thread counts
    double serial_time = matrix_multiply(M, N, W, A, B, C, 1); // Single-threaded execution
    double parallel_time_2 = matrix_multiply(M, N, W, A, B, C, 2); // 2 threads
    double parallel_time_4 = matrix_multiply(M, N, W, A, B, C, 4); // 4 threads
    int max_threads = omp_get_max_threads();
    double parallel_time_max = matrix_multiply(M, N, W, A, B, C, max_threads); // Maximum threads

    // Calculate speedups and performance improvement percentages
    double speedup_2 = calculate_speedup_percentage(serial_time, parallel_time_2);
    double speedup_4 = calculate_speedup_percentage(serial_time, parallel_time_4);
    double speedup_max = calculate_speedup_percentage(serial_time, parallel_time_max);

    // Print performance metrics
    printf("Speedup percentage with 2 threads: %f%%\n", speedup_2);
    printf("Speedup percentage with 4 threads: %f%%\n", speedup_4);
    printf("Speedup percentage with max threads (%d): %f%%\n", max_threads, speedup_max);

    // Determine the best performance improvement
    double best_speedup = speedup_2;
    if (speedup_4 > best_speedup) best_speedup = speedup_4;
    if (speedup_max > best_speedup) best_speedup = speedup_max;
    printf("Best speedup percentage: %f%%\n", best_speedup);

    // Free dynamically allocated memory
    free_matrix(A, M);
    free_matrix(B, N);
    free_matrix(C, M);

    return 0;
}
