/* 1. You are given a 2D  array of size n x n where all the elements are distinct integers between 1 and n^2, and every integer appears exactly once. 
	  Starting from any cell in this matrix you can move up, down, left and right in a non-wrap around fashion and without leaving the matrix. 
	  Path in a matrix is a sequence of cells based on the four moves. 
	  Starting from any cell, a maximum length path is defined as the largest sequence of cells such that the values in the cells 
	  along the path are in increasing order with an increment of one encountered in each move. 
      As an example, consider the following 3 x 3 matrix:
      |2|5|1|
      |3|6|9|
      |4|7|8| Starting from (R0, C1) the longest path is 5 -> 6 -> 7 -> 8 -> 9 with length 5
      Write a program to find the number of cells and moves starting from a given cell that would give the longest path. 
*/

#include <stdio.h>
#include <string.h>
int main()
{
    int n, i, j, sr, sc, now, right, left, up, down, k, min;
    char minpos[6];

    printf ("Enter Length : ");
    scanf("%d", &n);
    printf("\n");

    int arr[n][n];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter Number : ");
            scanf("%d", &arr[i][j]);
        }
    }


    printf("\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Enter Starting Row    : ");
    scanf("%d", &sr);
    printf("Enter Starting Column : ");
    scanf("%d", &sc);

    k = 1;
    while(k == 1)
    {
        now = arr[sr][sc];
        if(sc + 1 == n)
            right = 0;
        else
            right = arr[sr][sc+1];

        if(sc - 1 == -1)
            left = 0;
        else
            left = arr[sr][sc-1];

        if(sr + 1 == n)
            down = 0;
        else
            down = arr[sr+1][sc];

        if(sr - 1 == -1)
            up = 0;
        else
            up = arr[sr-1][sc];

        
        //printf("%d, %d, %d, %d, %d.",now, left, right, up, down);

        min = 1000;
        strcpy(minpos, "now");

        if(right>now)
        {
            min = right;
            strcpy(minpos, "right");
        }
        if(left>now)
        {
            min = left;
            strcpy(minpos, "left");
        }
        if(down>now)
        {
            min = down;
            strcpy(minpos, "down");
        }
        if(up>now)
        {
            min = up;
            strcpy(minpos, "up");
        }
        //printf("preprint - %s",minpos);
        if(strcmp(minpos, "now") == 0)
        {
            break;
        }
        else
        {
            printf("%s ",minpos);
            if(strcmp(minpos, "right") == 0)
                sc++;
            else if(strcmp(minpos, "left") == 0)
                sc--;
            else if(strcmp(minpos, "up") == 0)
                sr--;
            else
            {
                sr++;
            }
        }
    }
    return 0;
}
