#include <iostream>

//menor elemento de um vetor dado um "range" desse vetor
int minimum(int vector[], int startPosition, int endPosition) {
    int min = startPosition;
    for (int i = startPosition; i <= endPosition; i++) {
        if (vector[i] < vector[min]) {
            min = i;
        }
    }
    return min;
}

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void selectionSort(int vector[], int size) {
    for (int i = 0; i < size-1; i++) {
        int min = minimum(vector, i, size - 1);
        std::swap(vector[i], vector[min]);
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

    selectionSort(v, n);

    printArray(n, v);

    return 0;
}