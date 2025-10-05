#include <stdio.h>

int array_min(const int arr[], int size) {
    int i, m;
    if (size <= 0) return 0;
    m = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

int array_max(const int arr[], int size) {
    int i, m;
    if (size <= 0) return 0;
    m = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int array_sum(const int arr[], int size) {
    int i, s = 0;
    for (i = 0; i < size; i++) s += arr[i];
    return s;
}

float array_avg(const int arr[], int size) {
    if (size <= 0) return 0.0f;
    return (float)array_sum(arr, size) / (float)size;
}
