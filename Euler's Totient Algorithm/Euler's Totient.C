#include<stdio.h>
#include<conio.h>

int phi(int n) 
{ 
	int p, result = n;

	for (p = 2; p * p <= n; ++p)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
				n /= p;
			result -= result / p;
		}
	}

	if (n > 1)
		result -= result / n;
	return result;
}

void main()
{
	int n, x;
	clrscr();

	printf("Enter the value of x: ");
	scanf("%d",&x);
	printf("\n");

	for (n = 1; n <= x; n++)
	{
		printf("phi(%d) = %d\n", n, phi(n));
	}

	getch();
}