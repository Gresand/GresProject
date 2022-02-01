#include <stdio.h>

//---1---
int dectobin(int n)
{
        if ( n >= 2 )
        {
            dectobin( n/2 );
        }
        printf("%d", n % 2);
}

//---2---
double degree(double a, long b)
{
    if(b == 0) return 1.0;
    if(b < 0) return 1.0 / (a * degree (1.0 / a, b + 1));
    return a * degree(a, b - 1);
}

//---3---
double degree2(double x, long n)
{
    if(n == 0) return 1;
    if(n < 0) return degree2 ( 1 / x, -n);
    if(n % 2) return x * degree2 (x, n - 1);
    return degree2(x * x, n / 2);
}

//---4---
void theking()
{
    int n=4,m=5;
    int w[n][m];
    int minmap[n][m];
    int i,j;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            minmap[i][j]=1;
        }
    }

    minmap[0][3]=0;
    minmap[2][2]=0;

    for(j=0;j<m;++j) {
        if(minmap[0][j]==1) {
            w[0][j] = 1;
        }
        else
        {
            while(j<m) {
                w[0][j] = 0;
                j++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if(minmap[i][0]==1) {
            w[i][0] = 1;
        }
        else
        {
            while(i<m) {
                w[i][0]=0;
                i++;
            }

        }
    }

    for(i=1;i<n;++i) {
        for(j=1;j<m;++j)
            if(minmap[i][j]==1) {
                w[i][j] = w[i][j - 1] + w[i - 1][j];
            }
        else
            {
            w[i][j]=0;
            }
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            printf (" %d", w[i][j]," ");
        }
        printf("\n");
    }

    printf("\n");

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            printf (" %d", minmap[i][j]," ");
        }
        printf("\n");
    }
}

int main() {

    //---1---
    int d;
    printf("n =  ");
    scanf("%d", &d);
    printf(" (Dec) = ");
    dectobin( d );
    printf(" (Bin)\n");

    //---2---
    double a;
    long b;
    while (scanf ("%lf %ld", &a, &b) == 2) {
        printf("%5.5lf\n", degree (a, b));
    }

    //---3---
    while (scanf ("%lf %ld", &a, &b) == 2) {
        printf("%5.5lf\n", degree2 (a, b));
    }
    theking();
    return 0;
}
