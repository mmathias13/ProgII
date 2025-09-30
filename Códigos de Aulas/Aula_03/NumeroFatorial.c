#include <stdio.h>

int fatorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
        return n * fatorial(n - 1);
}

int main(int argc, char const *argv[])
{
    int num = 0;
    scanf("%d\n", &num);
    printf("%d\n", fatorial(num));

    return 0;
}
