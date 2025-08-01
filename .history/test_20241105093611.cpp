#include <iostream>
using namespace std;
int main()
{
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    int max = ar[0], smax = ar[0];
    
    for(int i=0; i<10; i++)
    {
        if(ar[i] > smax)
        {
            if(ar[i] > max)
            {
                max = ar[i];
            }
            else
            {
                smax = ar[i];
            }
        }
    }
    cout << smax;
    return 0;
}