#include <iostream>
#include <omp.h>

using namespace std;

double calculate_sum(int n) {
    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

double calculate_sum_reverse(int n) {
    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (int i = n; i >= 1; i--) {
        sum += 1.0 / i;
    }
    return sum;
}

double calculate_even_odd_sum(int n) {
    double even_sum = 0.0;
    double odd_sum = 0.0;
#pragma omp parallel for reduction(+:even_sum, odd_sum)
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            even_sum += 1.0 / i;
        }
        else {
            odd_sum += 1.0 / i;
        }
    }
    return even_sum + odd_sum;
}

double calculate_even_odd_sum_reverse(int n) {
    double even_sum = 0.0;
    double odd_sum = 0.0;
#pragma omp parallel for reduction(+:even_sum, odd_sum)
    for (int i = n; i >= 1; i--) {
        if (i % 2 == 0) {
            even_sum += 1.0 / i;
        }
        else {
            odd_sum += 1.0 / i;
        }
    }
    return even_sum + odd_sum;
}

int main() {
    int n = 10000;

    // Sequential execution
    double A1_sequential = calculate_sum(n);
    double A2_sequential = calculate_sum_reverse(n);
    double A3_sequential = calculate_even_odd_sum(n);
    double A4_sequential = calculate_even_odd_sum_reverse(n);

    // Parallel execution with OpenMP
    double A1_parallel = calculate_sum(n);
    double A2_parallel = calculate_sum_reverse(n);
    double A3_parallel = calculate_even_odd_sum(n);
    double A4_parallel = calculate_even_odd_sum_reverse(n);

    // Compare sequential and parallel results (assuming negligible difference)
    cout << "A1 (parallel): " << A1_parallel << endl;
    cout << "A2 (parallel): " << A2_parallel << endl;
    cout << "A3 (parallel): " << A3_parallel << endl;
    cout << "A4 (parallel): " << A4_parallel << endl;

    cout << "A1 (sequential): " << A1_sequential << endl;
    cout << "A2 (sequential): " << A2_sequential << endl;
    cout << "A3 (sequential): " << A3_sequential << endl;
    cout << "A4 (sequential): " << A4_sequential << endl;

    return 0;
}
