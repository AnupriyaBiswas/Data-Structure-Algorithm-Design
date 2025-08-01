/*1. Let A be an unsorted array with n=2k integers. It is given that exactly half of the elements of array are positive and half of them are negative. Write a program t change A such that the negative and positive elements of the array are positioned alternatively.
- the swapping should be done in-place (do not use extra array)
- the complexity of the program should be O(n)
*/
#include <iostream>
using namespace std;

// Utility function to swap elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to rearrange the array
void arrange(int A[], int n) {
    int i = 0, j = 1;  // i for positive elements, j for negative elements

    while (i < n && j < n) {
        // Find the first positive element that is out of place (on an odd index)
        while (i < n && A[i] >= 0) {
            i += 2;
        }

        // Find the first negative element that is out of place (on an even index)
        while (j < n && A[j] < 0) {
            j += 2;
        }

        // If both positive and negative elements are out of place, swap them
        if (i < n && j < n) {
            swap(A[i], A[j]);
        }
    }
}

int main() {
    int n;

    // Input size of array (which must be 2k)
    cout << "Enter Size of Array (n=2k) : ";
    cin >> n;

    // Input array elements
    int A[n];
    cout << "Enter Elements (half positive, half negative):\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Rearrange the array to have alternating positive and negative elements
    arrange(A, n);

    // Output the rearranged array
    cout << "Result Sequence :\n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

