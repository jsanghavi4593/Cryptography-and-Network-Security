#include<stdio.h>
#include<conio.h>
#include<string.h>

void cipher(int i,int c);
int findMin();
void makeArray(int,int);

char arr[22][22],darr[22][22],emessage[111],retmessage[111],key[55];
char temp[55],temp2[55];
int k=0;

int main()
{
	char *message,*dmessage;

	int i,j,klen,emlen,flag=0;
	int r,c,index,min,rows;
	clrscr();

	printf("\nEnter the Key: ");
	fflush(stdin);
	gets(key);

	printf("Enter the Message: ");
	fflush(stdin);
	gets(message);

	strcpy(temp,key);
	klen=strlen(key);

	k=0;
	for(i=0; ;i++)
	{
		if(flag==1)
		break;

		for(j=0;key[j]!=NULL;j++)
		{
			if(message[k]==NULL)
			{
				flag=1;
				arr[i][j]='-';
			}

			else
			{
				arr[i][j]=message[k++];
			}
		}
	}

	r=i;
	c=j;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}

	k=0;

	for(i=0;i<klen;i++)
	{
		index=findMin();
		cipher(index,r);
	}

	emessage[k]='\0';
	printf("\nEncrypted message is: ");
	for(i=0;emessage[i]!=NULL;i++)
	printf("%c",emessage[i]);
	printf("\n");

	emlen=strlen(emessage);

	strcpy(temp,key);

	rows=emlen/klen;
	rows;
	j=0;

	for(i=0,k=1;emessage[i]!=NULL;i++,k++)
	{
		temp2[j++]=emessage[i];
		if((k%rows)==0)
		{
			temp2[j]='\0';
			index=findMin();
			makeArray(index,rows);
			j=0;
		}
	}

	printf("\nArray Retrieved is:\n");

	k=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%c ",darr[i][j]);
			retmessage[k++]=darr[i][j];
		}
		printf("\n");
	}
	retmessage[k]='\0';

	printf("\nMessage retrieved is: ");

	for(i=0;retmessage[i]!=NULL;i++)
	printf("%c",retmessage[i]);
	printf("\n");

	getch();
	return(0);
}

void cipher(int i,int r)
{
	int j;
	for(j=0;j<r;j++)
	{
		{
			emessage[k++]=arr[j][i];
		}
	}
}

void makeArray(int col,int row)
{
	int i,j;

	for(i=0;i<row;i++)
	{
		darr[i][col]=temp2[i];
	}
}

int findMin()
{
	int i,j,min,index;

	min=temp[0];
	index=0;
	for(j=0;temp[j]!=NULL;j++)
	{
		if(temp[j]<min)
		{
			min=temp[j];
			index=j;
		}
	}

	temp[index]=123;
	return(index);
}