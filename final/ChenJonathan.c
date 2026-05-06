#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototype
double payment(int number);
double rating(double Times[][2]);
int main()
{
	FILE *festival.txt;
	printf("Current user: Jonathan Chen, dac514.\n");
	fclose(festival.txt);
	// variables that need to be used in the main function
	int password, tickets;
	double money;
	char letter;
	char filename;
	double arr[][2];
	// use do-while loop to check the password and the letter they enter is valid
	do{
		printf("Music Festival 2026. Enter your 4-digit password: \n");
		scanf("%d", &password);
		do
		{
			printf("Please enter the Letter P for payment or the letter R for ratings.\n");
			scanf(" %c", &letter);
		}while(letter != 'P' && letter != 'R')
	}while (password != 5678)
	{
		printf("Incorrect passowrd. Bye!\n");
	}
	switch (letter)
	{
		case 'P':
		{
			printf("Please enter an number for festival ticket you would like to purchase: \n");
			scanf("%d", &tickets);
			while (tickets = 0);
			{
				printf("Please enter an number for festival ticket you would like to purchase: \n");
				scanf("%d", &tickets);
			}
			printf("Total payment is $$%10.2lf.\n");
			break;
		}
		case 'R':
		{
			FILE *fp
			fp = fopen(filename, 'r');
			printf("Please enter the file name: \n");
			scanf(" %c", &filename);
			while (fp == NULL)
			{
				fp = fopen(filename, 'r');
				printf("Please enter the file name: \n");
				scanf(" %c", &filename);
			}
			int idx, rows
			while (arr[][2] == EOF)
			{
				printf("%d %d", arr[idx][0], arr[idx][1]);
				idx++;
			}
			fclose(fp);
			rows = idx - 1;
			double averageA, averageB;
			FILE *festival.txt;
			festival.txt = fopen("festival.txt",'w');
			printf("Thea average rating for Shift A is %lf, and the average rating for Shift B is %lf.\n", averageA, averageB);
			break;
		}
		default:
		{
			break;
		}
	return 0;
}






// function payment
double payment(int number)
{
	double Total = 0.0;
	Total = number*33+(1/5)*(number*33);
	return money;
}

// function rating
void rating(double Times[][2])
{
	int i, j;
	for (i=0; i>=3 && i<7,j=0,j++)
	{
		Times[j][2]=A;
	}
	for (i=0; i>=7,j=0;j++)
	{
		Times[j][2]=B;
	}
	printf("Shift\tRating.\n");
	printf("%lf\t%lf", Times[j][0],Times[j][1]);
	double avgA, avgB;
	avgA = ;
	avgB = ;
	retunr 1;
}
