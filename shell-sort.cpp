#include <iostream>

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void shellSort(int vector[], int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = vector[i];
            int j;
            for (j = i; j >= gap && vector[j - gap] > temp; j -= gap) {
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
}

int main() {
    int n = 5;
    int v[n];

    v[0] = 20;
    v[1] = 5;
    v[2] = 7;
    v[3] = 7;
    v[4] = 1;

    printArray(n, v);

    shellSort(v, n);

    printArray(n, v);

    return 0;
}