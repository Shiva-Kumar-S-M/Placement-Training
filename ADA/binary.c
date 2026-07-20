//using binary search finding the first occurence and last occurence of an element in a sorted array make it dynamic and take input from user
#include <stdio.h>

int first_occurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            if (mid == 0 || arr[mid - 1] < x)
                return mid;
            else
                high = mid - 1;
        } else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int last_occurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            if (mid == n - 1 || arr[mid + 1] > x)
                return mid;
            else
                low = mid + 1;
        } else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    printf("First occurrence of %d is at index %d\n", x, first_occurrence(arr, n, x));
    printf("Last occurrence of %d is at index %d\n", x, last_occurrence(arr, n, x));
    return 0;
}


/* Arrays
↓

Strings
↓

Hashing
↓

Two Pointers
↓

Sliding Window
↓

Binary Search
↓

Linked List
↓

Stack
↓

Queue
↓

Trees
↓

Graphs
↓

DP 
*/
