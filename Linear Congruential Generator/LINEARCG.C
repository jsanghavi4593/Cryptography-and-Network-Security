#include<stdio.h>
#include<conio.h>

void main()
{
	int Xo,X1;
	int a,c,m;
	int i,n;
	int array[20];
	clrscr();

	printf("\nEnter the Seed Value Xo: ");
	scanf("%d",&Xo);

	printf("Enter the Modulus m: ");
	scanf("%d",&m);

	printf("Enter the Constant Multiplier a: ");
	scanf("%d",&a);

	printf("Enter the Increment c: ");
	scanf("%d",&c);


	printf("\nHow many random numbers you want to generate: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		X1 = (a * Xo + c) % m;
		array[i] = X1;
		Xo = X1;

	}

	printf("\nThe Generated Random Numbers are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}

	getch();
}