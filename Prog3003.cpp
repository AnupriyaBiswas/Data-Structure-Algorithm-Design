/*3. Given a List of daily stock price (in integer), return the buy and sell price that will maximize the single buy/sell profit. If you 
can’t make profit, try to minimize the loss. (The price will be in sorted form with respect to market hours of the day).
Sample Input: 8, 5, 12, 9, 19, 1: profit of 14 Rs.
Sample Input: 21, 12, 11, 9, 6, 3: Loss of 1 Rs.
*/
#include <iostream>
using namespace std;
int main()
{
	int N;
	cout << "Enter No of Prices : ";
	cin >> N;
	
	int pr[N];
	for(int i = 0; i < N; i++)
	{
		cout << "Enter Price : ";
		cin >> pr[i];
	}
	
	int profit, minbuy = pr[0], buy = pr[0], sell = pr[0], maxpr = 0;
	for(int i = 0; i < N; i++)
	{
		profit = pr[i] - minbuy;
		if(profit > maxpr)
		{
			maxpr = profit;
			buy = minbuy;
			sell = pr[i];
		}
		
		if(pr[i] < minbuy)
		{
			minbuy = pr[i];
		}
	}
	
	if(maxpr > 0)
	{
		cout << "Maximum Profit : " << maxpr << endl;
		cout << "Buy at         : " << minbuy << endl;
		cout << "Sell at        : " << sell << endl;
	}
	else
	{
		cout << "Profit Not Possible.\n";
		cout << "Minimum Loss : " << maxpr <<endl;
		cout << "Buy at       : " << minbuy << endl;
		cout << "Sell at      : " << sell << endl;
	}
	return 0;
}
