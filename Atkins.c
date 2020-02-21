#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int AtkinsandBernstein(int num)
{
if (num > 2)
printf("2\t");
if (num > 3)
printf("3\t");
bool sieve[num];
for (int i = 0; i < num; i++)
sieve[i] = false;
for (int a = 1; a * a < num; a++)
{
for (int b = 1; b * b < num; b++)
{
int n = (4 * a* a) + (b * b);
if (n <= num && (n % 12 == 1 || n % 12 == 5))
sieve[n] = true;
n = (3 * a * a) + (b * b);
if (n <= num && n % 12 == 7)
sieve[n] = true;
n = (3 * a * a) - (b * b);
if (a > b && n <= num && n % 12 == 11)
sieve[n] = true;
}
}
for (int x = 5; x < num; x++)
if (sieve[x])
printf("%d\t",x);
printf("\n");
}

int main(void)
{
int n;
printf("Enter the Number\n");
scanf("%d",&n);
AtkinsandBernstein(n);
return 0;
}
