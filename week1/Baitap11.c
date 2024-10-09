// Author: Pham Manh Cuong
#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.001

int compare_float(double a, double b) {
    return fabs(a - b) < EPSILON;
}

int main() {
    double arr[SIZE], sum = 0, avg;
    int i;
    for (i = 0; i < SIZE; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }
    avg = sum / SIZE;

    double min_diff = fabs(arr[0] - avg);
    for (i = 1; i < SIZE; i++) {
        if (fabs(arr[i] - avg) < min_diff) {
            min_diff = fabs(arr[i] - avg);
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (fabs(arr[i] - avg) - min_diff <= EPSILON) {
            printf("%.2lf ", arr[i]);
        }
    }

    return 0;
}
