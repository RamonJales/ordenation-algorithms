#include <iostream>

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    int n = 5;
    int v[n];

    v[0] = 20;
    v[1] = 5;
    v[2] = 10;
    v[3] = 2;
    v[4] = 1;

    printArray(n, v);

    bubbleSort(v, n);

    printArray(n, v);

    return 0;
}