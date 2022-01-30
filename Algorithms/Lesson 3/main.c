#include <stdio.h>
#include <stdbool.h>

bool isprime(int n)
{
    if (n>1)
    {
        for (int i=2;i<n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    return false;
}

int main() {
    int n;
    printf("Input a number: ");
    scanf_s("%d", &n);
    if (isprime(n))
    {
        printf("This number is simple");
    }
    else
    {
        printf("This number is not simple");
    }
}
