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

//função de trocar dois elementos, mas com as varáveis no contexto do algoritmo
void shift(int vector[], int numberPosition, int minimumPosition) {
    if(vector[minimumPosition] != vector[numberPosition]) {
        int aux = vector[numberPosition];
        vector[numberPosition] = vector[minimumPosition];
        vector[minimumPosition] = aux;
    }
}

void selectionSort(int vector[], int size) {
    for (int i = 0; i < size-1; i++) {
        int min = minimum(vector, i, size - 1);
        shift(vector, i, min);
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

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    printf("\n");

    selectionSort(v, n);

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    printf("\n");

    return 0;
}