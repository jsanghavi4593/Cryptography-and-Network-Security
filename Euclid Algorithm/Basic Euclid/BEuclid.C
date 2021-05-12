#include<stdio.h>
#include<conio.h>

long int gcd(int a, int b)
{
	if(a==0)
	{
		return b;
	}

	return gcd (b%a, a);
}

void main()
{
	 long int a,b;
	 clrscr();

	 printf("\nEnter the value of a and b: ");
	 scanf("%ld %ld",&a,&b);

	 printf("\nGCD (%ld,%ld) = %ld", a, b, gcd(a, b));
	 getch();
}