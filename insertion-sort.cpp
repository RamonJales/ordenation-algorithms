#include <iostream>

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int vector[], int lenght) {
  for (int i = 1; i < lenght; i++) {
    int temp = i;
    while (vector[temp] < vector[temp - 1] && temp > 0) {
      std::swap(vector[temp], vector[temp - 1]);     
      temp--;
    }
  }
}

int main(void) {
    int n = 5;
    
    int v[n];

    v[0] = 20;
    v[1] = 5;
    v[2] = 10;
    v[3] = 2;
    v[4] = 1;

    printArray(n , v);

    insertionSort(v, n);

    printArray(n , v);
    return 0;
}