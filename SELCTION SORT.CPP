#include <stdio.h>

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted array:\n");
    printArray(data, size);
    
    selectionSort(data, size);
    
    printf("Sorted array in Ascending Order:\n");
    printArray(data, size);
    
    return 0;
}

