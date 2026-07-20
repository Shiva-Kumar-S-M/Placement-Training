// Help me to build ternary search function in c
//Sure! A ternary search is a divide-and-conquer algorithm that can be used to find an element in a sorted array. It works by dividing the array into three parts and determining which part contains the target element. Here's a simple implementation of a ternary search function in C:```c
#include <stdio.h>

int ternary_search(int arr[], int left, int right, int key) {
    while (left <= right) {
        int third = (right - left) / 3;
        int mid1 = left + third;
        int mid2 = right - third;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            right = mid1 - 1;
        } else if (key > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d sorted integers in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    int key;
    printf("Enter value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    int result = ternary_search(arr, 0, n - 1, key);
    if (result >= 0) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

/* Help me understand the codeSure! Let's break down the code step by step:
1. **Function Definition**: The `ternary_search` function takes four parameters: the array `arr`, the left index `left`, the right index `right`, and the `key` to search for. It returns the index of the key if found, or -1 if not found.
2. **While Loop**: The loop continues as long as `left` is less than or equal to `right`. This ensures that we are still searching within the bounds of the array.
*/