#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 0, i;
    char input[256];

    printf("Enter orders Priority Number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Count the number of priority numbers
    for (i = 0; input[i]; i++) {
        if (input[i] == ',') n++;
    }
    n++; // for the last number

    int orders[n];
    char *token = strtok(input, ",");
    for (i = 0; token != NULL; i++) {
        orders[i] = atoi(token);
        token = strtok(NULL, ",");
    }

    // Sort the orders
    bubbleSort(orders, n);

    // Print the sorted orders
    printf("After Sorting Orders Priority: ");
    for (i = 0; i < n; i++) {
        printf("%d", orders[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}

