/* 4. Write a program that takes a positive integer n and returns the number of positive integers less than or equal to n that are divisible by exactly one of 4, 6 and 10.
      Sample Input: Enter a positive integer: 20
      Sample Output: 6

      Explanation: {4,6,8,10,12,16,18,20} - {12, 20} */

#include <stdio.h>
int main()
{
    int n, cnt, div4, div6, div10, div12, div20, div30, div60;

    printf ("Enter Number  : ");
    scanf("%d", &n);

    div10 = n / 10;
    div6  = n / 6;
    div4  = n / 4;

    div12 = n / 12;
    div20 = n / 20;
    div30 = n / 30;

    div60 = n / 60;

    cnt = (div10 + div6 + div4) - 2*(div12 + div20 + div30) + div60;
    printf("%d \n", cnt);
    return 0;
}
