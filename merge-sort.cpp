#include <iostream>

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int list[], int init, int middle, int end) {
  //calcular o comprimento dos subvetores da esquerda e direita
  int leftLenght = middle - init + 1;
  int rightLenght = end - middle;

  //criar duas sublistas para copiar as metades esquerda e direita do vetor original
  int leftList[leftLenght];
  int rightList[rightLenght];

  //copiar as metades esquerda e direita para cada subvetor
  for (int i = 0; i < leftLenght; i++){
    leftList[i] = list[init + i];
  }
  for (int i = 0; i < rightLenght; i++) {
    rightList[i] = list[middle + i + 1];
  }

  int l = 0, r = 0;

  for(int k = init; k <= end; k++) {
    if (l >= leftLenght) {
      list[k] = rightList[r];
      r++;
    }
    else if (r >= rightLenght) {
      list[k] = leftList[l];
      l++;
    }
    else if (leftList[l] <= rightList[r]) {
      list[k] = leftList[l];
      l++;
    }
    else {
      list[k] = rightList[r];
      r++;
    }
  }
}

void mergeSort(int list[], int init, int end) {
    if (init < end) {
        int middle = init + (end - init) / 2;
        mergeSort(list, init, middle);
        mergeSort(list, middle + 1, end);
        merge(list, init, middle, end);
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

    mergeSort(v, 0, n - 1);

    printArray(n, v);

    return 0;
}