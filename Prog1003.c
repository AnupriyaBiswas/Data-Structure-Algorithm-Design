/* 3. Write a program that reads in the coordinates of the vertices of a quadrilateral on the two-dimensional plane in clockwise order 
      and prints 1, if it is regular (all sides are equal) else prints 0. */

#include <stdio.h>
#include <math.h>
int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4, d1, d2, d3, d4;
    printf ("Enter First  x - coordinate : ");
    scanf("%d", &x1);
    printf ("Enter First  y - coordinate : ");
    scanf("%d", &y1);

    printf ("Enter Second x - coordinate : ");
    scanf("%d", &x2);
    printf ("Enter Second y - coordinate : ");
    scanf("%d", &y2);

    printf ("Enter Third  x - coordinate : ");
    scanf("%d", &x3);
    printf ("Enter Third  y - coordinate : ");
    scanf("%d", &y3);

    printf ("Enter Fourth x - coordinate : ");
    scanf("%d", &x4);
    printf ("Enter Fourth y - coordinate : ");
    scanf("%d", &y4);

    d1 = pow((y1 - y2), 2) + pow((x1 - x2), 2);
    d2 = pow((y2 - y3), 2) + pow((x2 - x3), 2);
    d1 = pow((y3 - y4), 2) + pow((x3 - x4), 2);
    d2 = pow((y4 - y1), 2) + pow((x4 - x1), 2);

    if (d1 == d2 == d3 == d4)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
