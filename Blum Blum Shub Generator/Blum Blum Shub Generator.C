#include<stdio.h>
#include<conio.h>

void main()
{
	int Xo,X1;
	int p,q;
	int i,n;
	int array[20];
	clrscr();

	printf("\nEnter the Seed Value Xo: ");
	scanf("%d",&Xo);

	printf("Enter the value of p: ");
	scanf("%d",&p);

	printf("Enter the value of q: ");
	scanf("%d",&q);

	printf("\nHow many random numbers you want to generate: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		X1 = (Xo * Xo) % (p*q);
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