
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//prototype

float paymentFunction(int tix);
float ratingsFunction(int arr[][0],int arr[][1],int rows);

int main()
{
	// declare variables
	int correct;
	int tix;
	char choice;
	float arr[100][2];
	int rows=0;
	float total;
	// open and close file after printing
	FILE *fp;
	fp = fopen("festival.txt","w");
	fprinf(fp,"Current user: Jasmine Park, jjp190");
	fclose(fp);
	printf("Music Festival 2026. Enter your 4 digit password: \n");
	scanf("%d",&correct);
	if (correct == 5678)
	{
		printf("Please enter P for payment or R for ratings\n");
		scanf("%c",&choice);
		while (choice != 'P' || choice != 'R')
		{
		printf("Invalid. Please enter P for payment or R for ratings");
		scanf("%c",&choice);
		}
		switch (choice)
		{
			case 'P':
			printf("Please enter the number of tickets you want to buy: \n");
			scanf("%d",&tix);
			// call function
			total = paymentFunction(tix);
			printf("Total payment is &-10.2f",total);
			break;
			case 'R':
			char filename[100];
			// open file ask user and error check
			FILE *pointer;
			printf("Enter filename for your data: \n");
			scanf("%99s",filename);
			pointer = fopen(filename,"r");
			while (pointer == NULL)
			{
			printf("Enter filename for your data: \n");
			scanf("%99s",filename);
			pointer = fopen(filename,"r");
			}
			while (fscanf(pointer,"%d %d", &arr[rows][0],&arr[rows][1])!=EOF)
			{
				rows++;
			}
			fclose(pointer);
			// call function
			avg = ratingsFunction(arr[][0], arr[][1], rows);
			pointer = fopen(filename,"w");
			printf(pointer,"THE average rating for Shift A is %f and the average rating for shift B is %f", avgA,avgB);
			
			
			break;
		}
	}
	else
	{
		printf("Incorrect password.Bye!");
	}
	
	
	return 0;
}

//function

float paymentFunction(int tix)
{
	int total;
	total = tix*33+(1/5)*33;
	return total;
}

float ratingsFunction(int arr[][0],int arr[][1],int rows);
{
	char times[100];
	for (int i=0;i<rows;i++)
	{
		if (arr[i][0]>= 3 && arr[i][0]<7)
		{
			times[i] = 'A';
		}
		else if (arr[i][0]>=7)
		{
			times[i]= 'B';
		}
	}
	
	
printf("Shift\tRating\n");
for (i=0;i<rows,i++){
printf("%c\t",times[i]);
printf("%lf",arr[i][1]);
}
float avgA,avgB;
for (int j=0;j<i;j++)
{
	if (times[j] == 'A')
	{
		avgA = j/i;
		
	}
	return avgA;
	else
	{
		avgB = j/i;
	}
	return avgB;
}

}
