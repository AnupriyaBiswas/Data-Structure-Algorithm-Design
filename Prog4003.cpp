/*3. Given an integer n, return the least number of perfect squares numbers that sum to n.
- a perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1.4.9.16 are perfect squares
- Input: 12, Output: 4 + 4 + 4
- Input: 13, Output: 4 + 9
*/
#include <iostream>
#include <vector>
using namespace std;

void findSquares(int n) {
    // DP array to store the least number of perfect squares summing up to each value
    vector<int> dp(n + 1, INT_MAX);
    // Parent array to keep track of the squares used
    vector<int> parent(n + 1, 0);
    
    // Base case
    dp[0] = 0;

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (dp[i - j * j] + 1 < dp[i]) {
                dp[i] = dp[i - j * j] + 1;
                parent[i] = j * j; // Track the square used to form i
            }
        }
    }

    // Print the least number of perfect squares
    cout << "The least number of perfect squares that sum to " << n << " is: " << dp[n] << endl;

    // Backtrack to print the sequence of perfect squares used
    cout << "Sequence of squares: ";
    int sum = n;
    while (sum > 0) {
        cout << parent[sum] << " ";
        sum -= parent[sum];
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    findSquares(n);
    
    return 0;
}

