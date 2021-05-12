#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
	int d;
	int x;
	int y;
} 	EE;

EE extended_euclid(int a, int b)
{
	EE ee1, ee2, ee3;
	if (b == 0)
	{
		ee1.d = a;
		ee1.x = 1;
		ee1.y = 0;
		return ee1;
	}
	else
	{
		ee2 = extended_euclid(b, a % b);
		ee3.d = ee2.d;
		ee3.x = ee2.y;
		ee3.y = ee2.x - floor(a / b) * ee2.y;
		return ee3;
	}
}

int modulo(int x, int N)
{
	 return (x % N + N) % N;
}

void decimal_to_binary(int op1, int aOp[])
{
	 int result, i = 0;
	 do
	 {
		  result = op1 % 2;
		  op1 /= 2;
		  aOp[i] = result;
		  i++;
	 }
	 while(op1 > 0);
}

int modular_exponentiation(int a, int b, int n)
{
	int *bb;
	int count = 0, c = 0, d = 1, i;

	count = (int) (log(b)/log(2)) + 1;

	bb = (int *) malloc(sizeof(int*) * count);
	decimal_to_binary(b, bb);

	for (i = count - 1; i >= 0; i--)
	{
		c = 2 * c;
		d = (d*d) % n;

		if (bb[i] == 1)
		{
			c = c + 1;
			d = (d*a) % n;
		}
	}

	return d;
}

int get_d(int e, int phi)
{
	EE ee;
	ee = extended_euclid(e, phi);
	return modulo(ee.x, phi);
}

void main(int argc, char* argv[])
{
	int p, q, phi, n, e, d, m, c;
	clrscr();

	printf("\n");
	printf("Enter the value of p: ");
	scanf("%d", &p);
	printf("Enter the value of q: ");
	scanf("%d", &q);

	n = p*q;
	phi = (p - 1) * (q - 1);

	printf("Enter the value of e: ");
	scanf("%d", &e);

	d = get_d(e, phi);

	printf("\nd = %d",d);
	printf("Public Key : (%d, %d)\n", e, n);
	printf("Private Key: (%d, %d)\n", d, n);
	printf("\nEnter message to encrypt: ");
	scanf("%d", &m);

	c = modular_exponentiation(m, e, n);
	printf("\nThe Encrypted message is: %d\n", c);
	m = modular_exponentiation(c, d, n);
	printf("The Decrypted message is: %d\n", m);

	getch();
}