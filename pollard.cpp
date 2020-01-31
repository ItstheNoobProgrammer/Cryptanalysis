#include<bits/stdc++.h>
using namespace std;
long long int prevn;

long long int gcd(long long int a, long long int b) {
if (b == 0)
return a;
return gcd(b, a % b);
}

long long int modular_pow(long long int base, int exponent,
long long int modulus)
{
long long int result = 1;
while (exponent > 0)
{
if (exponent & 1)
result = (result * base) % modulus;
exponent = exponent >> 1;
base = (base * base) % modulus;
}
return result;
}

long long int PollardRho(long long int n)
{
if(prevn==n){
printf("One of the divisor for %lld is 1",n);
exit(0);
}else{
srand (time(NULL));
if (n==1) return n;
else if (n % 2 == 0) return 2;
else
{
long long int x = (rand()%(n-2))+2;
long long int y = x;
long long int c = (rand()%(n-1))+1;
long long int d = 1;
printf("x = %lld\t\t\t y = %lld\t\t\t gcd = %lld\n",x,y,d);
while (d==1)
{
x = (modular_pow(x, 2, n) + c + n)%n;
y = (modular_pow(y, 2, n) + c + n)%n;
y = (modular_pow(y, 2, n) + c + n)%n;

d = gcd(abs(x-y), n);
printf("x = %lld\t\t\t y = %lld\t\t\t gcd = %lld\n",x,y,d);
if (d==n){
prevn = n;

return PollardRho(n);}
}
return d;
}}}

int main()
{
long long int n;
printf("Enter a number\n");
scanf("%lld",&n);
//PollardRho(n);
printf("One of the divisors for %lld is %lld.",
n, PollardRho(n));
return 0;
}
