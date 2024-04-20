#include <iostream>

void printArray(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int list[], int subInit, int subEnd) {
  int pivot = list[subEnd];
  int l = subInit - 1;
  for (int r = subInit; r <= subEnd - 1; r++) {
    //r == l evita trocar quando estão na mesma posição
    if (list[r] < pivot && r != l) {
      l++;
      std::swap(list[l], list[r]);
    }
  }
  l += 1;
  std::swap(list[l], list[subEnd]);
  return l;
}

void quickSort(int list[], int init, int end) {
  if (init >= end)
    return;
  else {
    int pivotPosition = partition(list, init, end);
    quickSort(list, init, pivotPosition - 1);
    quickSort(list, pivotPosition + 1, end);
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

    quickSort(v, 0, n - 1);

    printArray(n, v);

    return 0;
}