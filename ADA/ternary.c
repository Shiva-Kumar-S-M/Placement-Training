//Building linear search program for c with explaining comments
#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
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
    printf("Enter %d integers:\n", n);
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

    int result = linear_search(arr, n, key);
    if (result >= 0) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}


/*
// Understanding the Code:
1. **Function Definition**: The `linear_search` function takes three parameters: the array `arr`, the number of elements `n`, and the `key` to search for. It returns the index of the key if found, or -1 if not found.
2. **For Loop**: The loop iterates through each element of the array. If the current element matches the key, the function returns the index of that element.
3. **Main Function**: The `main` function handles user input for the number of elements, the elements themselves, and the key to search for. It calls the `linear_search` function and prints the result based on whether the key was found or not.
// 
*/


/*
//help me write an alogorithm for linear search that is easy to understand and applicable for any programming language Sure! Here's a simple and easy-to-understand algorithm for linear search that can be applied in any programming language:
**Algorithm: Linear Search**
1. Start
2. Input: An array of elements `arr` and a value `key` to search
3. Initialize a variable `n` to the length of the array `arr`
4. For each index `i` from 0 to `n-1`:
   a. If `arr[i]` is equal to `key`, then:
      i. Return the index `i` (key found)
5. If the loop completes without finding the key, return -1 (key not found)
6. End      

*/

/* python implementation of linear search 
def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

*/

/* Time complexity: O(n) */
/* Space complexity: O(1) */    
