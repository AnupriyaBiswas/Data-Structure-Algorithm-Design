#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool checkRange(double ratx, double raty, double len)
{
	double dist = pow((ratx - len/2), 2) + pow((raty - len/2), 2);
    cout << "Distance from food : " << dist << endl; 
	return dist < 1;
}

int moveRat(double ratx, double raty, int len, int dir, int moves)
{
    if(checkRange(ratx, raty, len))
	{
		return moves;
	}

    double limit = len * 0.9;
    if(dir == 0)
    {
        raty = raty + limit;
    }
    else if(dir == 1)
    {
        ratx = ratx + limit;
    }
    else if(dir == 2)
    {
        raty = raty - limit;
    }
    else
    {
        ratx = ratx - limit;
    }
	dir = (dir + 1) % 4;
	return moveRat(ratx, raty, limit, dir, moves+1);
}

void findFood(double len)
{
    int moves = moveRat(0, 0, len, 0, 0);
    cout << "The Rat gets the food in " << moves << " Moves." <<endl;
}

int main()
{
	double l;
	
	cout << "Enter Length of Square     : ";
	cin >> l;
	
	if(l < 0)
	{
		cout << "Invalid Input.\n";
	}
	else
	{
		findFood(l);
	}
	return 0;
}
