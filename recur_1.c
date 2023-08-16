#include <stdio.h>
int i = 1;
void multable(int n)
{
    if (i <= 10)
    {
        printf("\n%d*%d=%d", n, i, n * i);
        i++;
        multable(n);
    }
}
void main()
{
    multable(5);
}