#include <iostream>
using namespace std;
int main()
{
	int N, no;
	
	cout << "Enter N      : ";
	cin >> N;
	
	int max = 0, smax = 0;
	for(int i = 0; i < N; i++)
	{
		cout << "Enter Number : ";
		cin >> no;
		
		if(no > smax)
		{
			if(no > max)
			{
				smax = max;
				max = no;
			}
			else
			{
				smax = no;
			}
		}
	}
	
	cout << "Second Maximum : " << smax;
	
	return 0;
}
