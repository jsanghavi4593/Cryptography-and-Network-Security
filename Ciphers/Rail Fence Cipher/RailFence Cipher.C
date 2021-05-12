#include<stdio.h>
#include<conio.h>
#include<string.h>

void encryptMsg(char msg[], int key)
{
	int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
	char railMatrix[10][100];

	for(i = 0; i < key; ++i)
		for(j = 0; j < msgLen; ++j)
			railMatrix[i][j] = '\n';

	for(i = 0; i < msgLen; ++i)
	{
		railMatrix[row][col++] = msg[i];

		if(row == 0 || row == key-1)
			k= k * (-1);

		row = row + k;
	}

	printf("\nEncrypted Message: ");

	for(i = 0; i < key; ++i)
		for(j = 0; j < msgLen; ++j)
			if(railMatrix[i][j] != '\n')
				printf("%c", railMatrix[i][j]);
}

void decryptMsg(char enMsg[], int key)
{
	int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
	char railMatrix[10][100];

	for(i = 0; i < key; ++i)
		for(j = 0; j < msgLen; ++j)
			railMatrix[i][j] = '\n';

	for(i = 0; i < msgLen; ++i)
	{
		railMatrix[row][col++] = '*';

		if(row == 0 || row == key-1)
			k= k * (-1);

		row = row + k;
	}

	for(i = 0; i < key; ++i)
		for(j = 0; j < msgLen; ++j)
			if(railMatrix[i][j] == '*')
				railMatrix[i][j] = enMsg[m++];

	row = col = 0;
	k = -1;

	printf("\nDecrypted Message: ");

	for(i = 0; i < msgLen; ++i)
	{
		printf("%c", railMatrix[row][col++]);

		if(row == 0 || row == key-1)
			k= k * (-1);

		row = row + k;
	}
}

void main()
{
	 char msg[100];
	 char enMsg[100];
	 int key;
	 clrscr();

	 printf("\nEnter the Message: ");
	 scanf("%s",&msg);
	 printf("Enter the value of Key: ");
	 scanf("%d",&key);

	 printf("\nOriginal Message: %s", msg);

	 encryptMsg(msg, key);
	 printf("\n");

	 printf("\nEnter the Encrypted Message: ");
	 scanf("%s",&enMsg);
	 encryptMsg(msg, key);
	 decryptMsg(enMsg, key);
	 printf("\n");

	 getch();
}