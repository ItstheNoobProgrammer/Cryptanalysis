 #include<stdio.h>

int gcdExtended(int a, int b, int *x, int *y)
{

    int p, q ;
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;

      int gcd = gcdExtended(b%a, a, &x1, &y1);


    *x = y1 - (b/a) * x1;
    *y = x1;
    p = *x ;
    q = *y ;
    //printf(" %d %d", p, q);
    //printf("\n");

    if(p < 0)
        p = p + 26;
    if(q < 0)
        q = q + 26;
    //printf("\n %d %d\n", p, q);


    return p;
}


int main()
{
	char m[50], c[50], d[50];
	int p, q, i, x, y;

	printf("Enter the plaintext: ");
	scanf("%s", m);
	//printf("\n%s\n", m);

	printf("Enter the keys: ");
	scanf("%d %d", &p, &q);

	for(i = 0; m[i]!='\0'; i++)
	{
		m[i] = m[i] % 65;
		c[i] = 65 + (p*m[i]+q)%26;
	}
    c[i]= '\0';

	printf("\n%s\n", c);

	//DECRYPTION
	int inv = gcdExtended(p, 26, &x, &y);

	for(i = 0; c[i]!= '\0'; i++)
	{
		c[i] = c[i]%65;
		d[i] = 65 + (inv * (c[i] - q))%26;
		if(d[i]< 'A')
			d[i] = d[i] + 26;
	}
    d[i]= '\0';
	printf("\n%s\n", d);


//CRYPTANALYSIS

int e, h, f, g, l, j;

e = m[0] % 65;
h = m[1] % 65;
f = c[0] % 65;
g = c[1] % 65;

l = f -g;
if(l < 0)
	l = l + 26;
j = e -h;
if(j < 0)
	j = j + 26;

printf(" \n%d %d", l, j);

inv =  gcdExtended(j, 26, &x, &y);
int k1 = (l * inv ) %26 ;

int k2 = f - e * k1;
while(k2 < 0)
	k2 = k2 + 26;

printf("\nkeys are : %d %d", k1,k2);

}
