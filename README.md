
# Parallel Matrix Multiplication with OpenMP

## Introduction
This project implements a parallel matrix multiplication program using OpenMP. The program demonstrates performance improvements through multithreaded execution and evaluates the speedup achieved with varying thread counts.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Performance Metrics](#performance-metrics)
- [Configuration](#configuration)
- [Dependencies](#dependencies)
- [Contributors](#contributors)
- [License](#license)

## Features
- **Matrix Multiplication**: Multiplies two dynamically allocated matrices.
- **Parallelization**: Uses OpenMP for parallel processing to enhance performance.
- **Speedup Analysis**: Calculates and displays speedup percentages for 2, 4, and maximum threads.
- **Dynamic Memory Allocation**: Handles dynamic allocation and deallocation of matrices.
- **Configurable Matrix Size**: Easily adjustable dimensions for matrices.

## Installation
1. Clone the repository or download the source code.
2. Ensure you have `gcc` and OpenMP installed on your system.
3. Compile the code:
   ```bash
   gcc -o main *.c -fopenmp
   ```

## Usage
Run the compiled program:
```bash
./main
```

### Example Output
The program will print:
- Matrix dimensions.
- Execution time for single-threaded and multithreaded runs.
- Speedup percentages for different thread counts.

## Code Structure
- **`main.c`**: Contains the entry point and the main logic for matrix multiplication and performance measurement.
- **`matrix_operations.c`**: Implements core functionalities:
  - Matrix allocation and deallocation.
  - Initialization of matrices with random values.
  - Parallel and serial matrix multiplication.
  - Speedup calculation.
- **`matrix_operations.h`**: Declares the functions for matrix operations.

## Performance Metrics
The program measures:
- Execution time for serial and parallel matrix multiplication.
- Speedup percentage for 2, 4, and maximum threads.
- The best speedup achieved among all thread counts.

### Performance Formula
- **Speedup**: \( 	ext{Speedup} = rac{	ext{Serial Time}}{	ext{Parallel Time}} \)
- **Speedup Percentage**: \( 	ext{Speedup Percentage} = \left( rac{	ext{Speedup} - 1}{	ext{Speedup}} 
ight) 	imes 100 \)

## Configuration
Matrix dimensions are defined in the `main.c` file:
```c
int M = 1000, N = 1200, W = 1300;
```
You can adjust these values for different matrix sizes.

## Dependencies
- **C Compiler**: GCC or any compatible C compiler with OpenMP support.
- **Libraries**:
  - OpenMP: For parallel processing.
  - Standard C libraries: `stdio.h`, `stdlib.h`, `time.h`.

## Contributors
- **Fiordi Toska** - Project Developer

## License
This project is licensed under the [MIT License](LICENSE.txt).

---
Feel free to contribute or report issues. Happy coding!
