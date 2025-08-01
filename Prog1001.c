/*1. Write a program that takes in a date of the year 2024 and prints out which day it is. 
     You may use the fact that 1st January, 2024 was Monday.
	 Sample Input: Enter Day and Month: 19 4
	 Sample Output: Friday */

#include <stdio.h>

int main()
{
    int d, m, nod;

    printf ("Enter Date   : ");
    scanf("%d", &d);
    printf ("Enter Month  : ");
    scanf("%d", &m);
	
	int monthcap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(m > 12)
	{
		printf("Invalid Input!");
	}
	else if(monthcap[m] < d)
	{
		printf("Invalid Input!");
	}
	else
	{
		int days[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    	char dow[7][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    	
		nod = (d + days[m - 1]) % 7;
    	printf("%s", dow[nod - 1]);
	}

    return 0;
}
