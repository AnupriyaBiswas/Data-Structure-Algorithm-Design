#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool checkRange(double ratx, double raty, double foodx, double foody)
{
	double dist = pow((ratx - foodx), 2) + pow((raty - foody), 2);
	// cout << "Distance : " << dist << endl << endl;
	if(dist < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int moveRat(double top, double right, double bottom, double left, double ratx, double raty, double foodx, double foody, double p, int dir, int moves)
{
	double limit;
	
	if(dir == 1 || dir == 3) // Left and Right
	{
		limit = (right - left) * p;
	}
	else // Up and Down
	{
		limit = (top - bottom) * p;
	}
	
	if(limit < 1)
	{
		return -1;
	}
	
	if(dir == 0) //Going Up
	{
		top = bottom + limit;
		raty = top;
		
		// cout << "Up    : ";
	}
	else if(dir == 1) //Going Right
	{
		right = left + limit;
		ratx = right;
		
		// cout << "Right : ";
	}
	else if(dir == 2) //Going Down
	{
		bottom = top - limit;
		raty = bottom;
		
		// cout << "Down  : ";
	}
	else //Going Left
	{
		left = right - limit;
		ratx = left;
		
		// cout << "Left  : ";
	}
	// cout << "Rat X : " << ratx <<"\t\t, Rat Y : " << raty << "\t\t\t, ";
	if(checkRange(ratx, raty, foodx, foody))
	{
		return ++moves;
	}
	dir = (dir + 1) % 4;
	return moveRat(top, right, bottom, left, ratx, raty, foodx, foody, p, dir, ++moves);
}

void findFood(double l, double limit)
{
	double posx = l / 2;
	double posy = l / 2;
	
	int cnt = moveRat(l, l, 0, 0, 0, 0, posx, posy, limit/100, 0, 0);
	if(cnt != -1)
	{
		cout << "Tom gets Jerry in " << cnt << " Moves.";
	}
	else
	{
		cout << "Tom does Not get Jerry.";
	}
	
}

int main()
{
	double limit, posx, posy, l;
	
	cout << "Enter Length of Square     : ";
	cin >> l;
	cout << "Enter Limit of Movement    : ";
	cin >> limit;
	//cout << "Enter Position of Food (x) : ";
	//cin >> posx;
	//cout << "Enter Position of Food (y) : ";
	//cin >> posy;
	
	if(limit >= 100 || limit <= 0 || l < 0)
	{
		cout << "Invalid Input.\n";
	}
	else
	{
		findFood(l, limit);
	}
	
	
	return 0;
}
