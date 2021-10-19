#include <stdio.h>
#include <string.h>


 char fib[20000] = "0";
    char A[10000] = "0";
    char B[10000] = "1";

int char_int(const char *p, int k)
{
    if (k < strlen(p))
        return p[strlen(p) - k - 1] - 48;
    return 0;
}
   
int main()
{
    int n;
    printf("enter n: \n");
    scanf("%d", &n);
    if (n == 0)
        printf("%s", A);
    else if (n == 1)
        printf("%s", B);
    else
    {
        for (int j = 2; j <= n; j++)
        {
            int i, lA = strlen(A), lB = strlen(B), z, sum, carry = 0;
            z = lA > lB ? lA : lB;
            for (i = 0; i < z; i++)
            {
                int num1 = char_int(A, i);
                int num2 = char_int(B, i);
                sum = num1 + num2 + carry;
                carry = 0;
                if (sum > 9)
                {
                    carry = 1;
                    sum =sum- 10;
                }
                fib[i] = sum + 48;
            }
            if (carry)
                fib[i++] = carry + 48;

            for (i = 0; i < strlen(fib) / 2; i++)
            {
                char t = fib[i];
                fib[i] = fib[strlen(fib) - i - 1];
                fib[strlen(fib) - i - 1] = t;
            }
            for (int i = 0; B[i] != '\0'; i++)
                A[i] = B[i];
            for (int i = 0; fib[i] != '\0'; i++)
                B[i] = fib[i];
        }
    }
    printf("Fibonacci number \n");
    printf("%s", fib);
}