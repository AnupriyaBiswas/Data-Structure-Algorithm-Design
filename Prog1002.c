/*2. Write a program that takes in an integer between 1 and 99 (both inclusive) and prints the number in words.
     Sample Input: Enter an integer between 1 and 99: 17
     Sample Output: Seventeen */

#include <stdio.h>
int main()
{
    int n;

    printf ("Enter Number  : ");
    scanf("%d", &n);

    char digits[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char decades[9][8] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char teens[9][11] = {"eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "eighteen", "nineteen"};
    
    if(n > 0 && n < 100)
    {
    	if(n % 10 == 0)
    	{
        	printf("%s", decades[n/10 - 1]);
    	}
    	else
    	{
        	if(n < 10)
        	{
            	printf("%s\n", digits[n - 1]);
        	}
        	else if(n < 20)
        	{
            	printf("%s\n", teens[n%10 - 1]);
        	}
        	else
        	{
            	printf("%s - %s\n", decades[n/10 - 1], digits[n%10 - 1]);
        	}
    	}
    }
    else
    {
    	printf("Invalid Input!");
	}
}
