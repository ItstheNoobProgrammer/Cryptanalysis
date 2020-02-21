#include <stdbool.h>
#include<stdio.h>
#include<string.h>
void SieveOfEratosthenes(int n)
{
bool prime[n+1];
memset(prime, true, sizeof(prime));
for (int p=2; p*p<=n; p++)
{
if (prime[p] == true)
{
for (int i=p*p; i<=n; i += p)
prime[i] = false;
}
}
for (int p=2; p<=n; p++)
if (prime[p])
printf("%d\t",p);
}
int main()
{
int n;
printf("\nEnter the value of n:");
scanf("%d",&n);
printf("\nThe prime numbers less than or equal to %d are:\n",n);
SieveOfEratosthenes(n);
return 0;
}
