#include<bits/stdc++.h>
using namespace std;

void FermatFactors(long long int n)
{
if(n <= 0)
{
cout << "[" << n << "]";
return;
}
if((n & 1) == 0)
{
cout << "[" << n / 2.0 << "," << 2 << "]";
return;
}

long long int a = ceil(sqrt(n)) ;
if(a * a == n)
{
cout << "[" << a << "," << a << "]";
return;
}
long long int b;
while(true)
{
long long int b1 = a * a - n ;
b = (long long int)sqrt(b1) ;

if(b * b == b1)
break;
else
a += 1;
}
cout << "[" << (a - b) << "," << (a + b) << "]" ;
return;
}

int main()
{
long long int n;
printf("Enter a number\n");
scanf("%lld",&n);
FermatFactors(n);
return 0;
}
