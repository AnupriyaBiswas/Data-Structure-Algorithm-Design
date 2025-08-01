/*2. You are given an unsorted array A = {a1, a2, ...., an} of n elements and a target sum T. Your task is to locate two 
elements a_i, a_j, in A (with i! = j) such that a_i + a_j is as large as possible, but no larger than T.
*/

#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
using namespace std;

int main() {
    int n, T;
    
    // Input the array size and the target sum
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    cout << "Enter the target sum T: ";
    cin >> T;
    
    vector<int> A(n);
    
    // Input the array elements
    for (int i = 0; i < n; i++) 
	{
    	cout << "Enter Data : ";
        cin >> A[i];
    }
    
    // Sort the array
    sort(A.begin(), A.end());
    
    // Two-pointer approach to find the closest pair
    int left = 0, right = n - 1;
    int maxSum = -1;  // Stores the maximum valid sum found
    int result_i = -1, result_j = -1;  // To store the indices of the elements
    
    while (left < right) {
        int currentSum = A[left] + A[right];
        
        // If the sum is within the limit and is the largest found so far, update the result
        if (currentSum <= T) {
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result_i = left;
                result_j = right;
            }
            // Move the left pointer to increase the sum
            left++;
        } else {
            // Move the right pointer to reduce the sum
            right--;
        }
    }
    
    if (maxSum == -1) {
        cout << "No valid pair found." << endl;
    } else {
        cout << "The Largest Sum is " << maxSum << " and Elements are " << A[result_i] << " and " << A[result_j] << endl;
    }

    return 0;
}

