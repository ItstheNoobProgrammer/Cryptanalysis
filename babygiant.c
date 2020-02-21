#include<stdio.h>
#include<math.h>
int modInverse(int a, int m)
{
a = a%m;
for (int x=1; x<m; x++)
if ((a*x) % m == 1)
return x;
}

int powMod(int a, int b, int n)
{
long long x = 1, y = a;
while (b > 0) {
if (b % 2 == 1)
x = (x * y) % n;
y = (y * y) % n;
b /= 2;
}
return x % n;
}

int search(int arr[], int n, int x)
{
int i;
for (i = 1; i <=n; i++)
if (arr[i] == x)
return i;
return -1;
}
int main()
{
int a,b,p,l,k[100],i,h,t,he,eh,in,pos,s,result;
printf("Enter a:");
scanf("%d",&a);
printf("\nEnter b:");
scanf("%d",&b);
printf("\nEnter p:");
scanf("%d",&p);
l=sqrt(p);
s=b;
for(i=1;i<=l;i++)
{
h=pow(a,i);
t=h%p;
k[i]=t;
}
in=modInverse(a,p);
eh=powMod(in,l,p);

for(i=0;i<=(l);i++)
{
pos = search(k,l,s);
if(pos!=-1)
{
printf("i=%d\tj=%d\tL=%d\n",i,pos,l);
result=pos+(i)*l;
printf("\nresult:%d\t",result);
break;
}
else
s=(s*eh)%p;
}
}
