/*1. Write a program to check if the given array is a zigzag array or not. Zigzag Array: Let A[0,...,n-1] be an array of distinct integer, 
we call A as zigzag array if for some indices i and j, 0<i<j<n-1 and A [0,...,i] is sorted in increasing order, A[i,...,j] is sorted in 
decreasing order, and, Alj,...,n-1] is sorted in increasing order.
*/
#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	cout << "Enter Length of Array(n) : ";
	cin >> n;
	cout << "Enter First Index(i)     : ";
	cin >> i;
	cout << "Enter Second Index(j)    : ";
	cin >> j;
	
	int ar[n];
	for(int k = 0; k < n; k++)
	{
		cout << "Enter Data : ";
		cin >> ar[k];
	}
	
	for(int k = 0; k < i; k++)
	{
		if(ar[k] > ar[k+1])
		{
			cout << "Given Array is NOT a Zig-zag Array.\n";
			return 0;
		}
	}
	for(int k = i; k < j; k++)
	{
		if(ar[k] < ar[k+1])
		{
			cout << "Given Array is NOT a Zig-zag Array.\n";
			return 0;
		}
	}
	for(int k = j; k < n-1; k++)
	{
		if(ar[k] > ar[k+1])
		{
			cout << "Given Array is NOT a Zig-zag Array.\n";
			return 0;
		}
	}
	cout << "Given Array is a Zig-zag Array.\n";
	return 0;
}
