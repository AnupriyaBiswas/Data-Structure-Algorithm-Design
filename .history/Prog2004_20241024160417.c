/*4. Write a program that takes three integers and checks whether the sum of any two is greater than the third.*/

#include <stdio.h>
int main()
{
    int n1, n2, n3;

    printf ("Enter First  Number  : ");
    scanf("%d", &n1);
    printf ("Enter Second Number  : ");
    scanf("%d", &n2);
    printf ("Enter Third  Number  : ");
    scanf("%d", &n3);

    if(n1 == n2+n3)
    {
        printf("First Number is Equal to the Summation of Second and Third.\n");
    }
    else if(n2 == n1+n3)
    {
        printf("Second Number is Equal to the Summation of First and Third.\n");
    }
    else if(n3 == n1+n2)
    {
        printf("Third Number is Equal to the Summation of Second and First.\n");
    }
    else
    {}

    return 0;
}