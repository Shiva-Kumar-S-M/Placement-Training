/*help me to build optimized bubble sort algorithm in cSure! Below is an optimized version of the Bubble Sort algorithm in C. 
The optimization involves adding a flag to check if any swaps were made during a pass through the array. If no swaps were made,
 the array is already sorted, and we can exit early. Make the program dynamic and allow user input for the array elements.  */

#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Initialize swapped as false
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped to true
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0)
            break;
    }
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }   
    
    
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}   