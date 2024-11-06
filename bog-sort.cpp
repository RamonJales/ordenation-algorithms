#include <iostream>
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

bool isSorted(int v[], int n) {
  for(int i = 0; i < n-1; i++) {
    if(v[i] > v[i+1]) return false;
  }
  return true;
}

void shuffle(int v[], int n) {
  for(int i = 0; i < n; i++) {
    swap(v[i], v[rand() % n]);
  }
}

void bogoSort(int v[], int n) {
  while(!isSorted(v, n)) shuffle(v, n);
}
