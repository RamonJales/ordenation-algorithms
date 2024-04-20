#include <iostream>

struct Heap {
    int *array;
    int size;
    int heapSize;
};

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void initHeap(Heap *heap, int size) {
    heap->array = (int *) malloc(size * sizeof(int));
    heap->size = size;
    heap->heapSize = size - 1;
}

void maxHeapify(Heap *heap, int i) {
    
    while(true) {
        int leftSonPosition = 2*i + 1;
        int rightSonPosition = 2*i + 2;
        
        int largestPosition = i;

        if (leftSonPosition <= heap->heapSize && heap->array[leftSonPosition] > heap->array[largestPosition]) {
            largestPosition = leftSonPosition;
        }

        if (rightSonPosition <= heap->heapSize && heap->array[rightSonPosition] > heap->array[largestPosition]) {
            largestPosition = rightSonPosition;
        }

        if (largestPosition == i) {
            break;
        }

        std::swap(heap->array[i], heap->array[largestPosition]);

        i = largestPosition;
    }

}

void buildMaxHeap(Heap *heap) {
    for (int i = heap->heapSize / 2; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}

void heapSort(Heap *heap) {
    buildMaxHeap(heap);

    for (int i = heap->heapSize; i > 0; i--) {
        std::swap(heap->array[0], heap->array[i]);
        heap->heapSize--;
        maxHeapify(heap, 0);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);

    Heap heap;
    initHeap(&heap, size);
    heap.array = array;

    heapSort(&heap);

    printArray(heap.array, size);

    return 0;
}