#include <bits/stdc++.h>
using namespace std;

void primeFactors(long long int n)
{
while (n % 2 == 0)
{
cout << 2 << " ";
n = n/2;
}

for (long long int i = 3; i <= sqrt(n); i = i + 2)
{
while (n % i == 0)
{
cout << i << " ";
n = n/i;
}
}

if (n > 2)
cout << n << " ";
}


int main()
{
long long int n;
printf("Enter n");
scanf("%lld",&n);
primeFactors(n);
return 0;
}
