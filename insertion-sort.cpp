#include <iostream>

void shift(int vector[], int position1, int position2) {
  int aux = vector[position1];
  vector[position1] = vector[position2];
  vector[position2] = aux;
}

void insertionSort(int vector[], int lenght) {
  for (int i = 1; i < lenght; i++) {
    int temp = i;
    while (vector[temp] < vector[temp - 1] && temp > 0) {
      shift(vector, temp, temp - 1);     
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

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    printf("\n");

    insertionSort(v, n);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    printf("\n");
    return 0;
}