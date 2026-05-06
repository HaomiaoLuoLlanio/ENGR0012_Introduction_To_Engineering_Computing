#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// Function Prototypes
double Payment(int);
void Ratings(int, double [][2]);

int main()
{
	FILE *file;
	file = fopen("festival.txt", "w");
	fprintf(file, "Current user: Hayden Nebel, hen42\n");
	fclose(file);
	printf("Music Festival 2026. Enter your 4-digit password: ");
	int password;
	scanf("%d", &password);
	if (password != 5678)
	{
		return 1;
	}
	else
	{
		char choice;
		printf("\nEnter P for payment of R for ratings: ");
		scanf(" %c", &choice);
		while (choice != 'P' && choice != 'R')
		{
			printf(" would you like to pay or check the ratings?: ");
			scanf(" %c", &choice);
		}
		switch (choice)
		{
			case 'P':
			{
				int tickets;
				printf("\nHow many festival tickets would you like? ");
				scanf("%d", &tickets);
				while (tickets <=0)
				{
					printf("\nNot Valid. How many festival tickets would you like? ");
					scanf("%d", &tickets);
				}
				// Call Payment function
				double amount = Payment(tickets);
				// display total amount
				printf("\nTotal payment is $$10.2lf", amount);
				break;
			}
			case 'R':
			{
				char filename[100];
				printf("\nEnter a file name for your music festival data: ");
				scanf("%s", &filename[100]);
				FILE *fp;
				fp = fopen(filename[100] , "r");
				while (fp == NULL)
				{
					printf("\nNot Valid. Enter a file name for your music festival data: ");
					scanf("%s", &filename[100]);
				}
				
				// Find Size of File
				int value=0, i = 0;
				double array[100][2];
				while (value != EOF)
				{
					value = scanf(fp, "%d %d", &array[i][0], &array[i][1] );
					i++;
				}
				
				int idx;
				idx = i-1;
				
				// Call Ratings function
				void Ratings(idx, array[][2])
				// Reopen festival.txt
				fopen("festival.txt" , "a");
				
				
				
				fclose("festival.txt");
				
				break;
			}
			default:
			{
				break;
			}
		}
	}
	
	
	
	
	return 0;
}

// Function Creation
double Payment(int num)
{
	double total;
	total = num*33 + (1/5) * num*33;
	
	return total;
}

// Ratings Function
void Ratings(int count, double festival[][2])
{
	int Times[] = {};
	char letter[] = {};
	double ratings[] = {};
	printf("Shift\tRating\n");
	for (int i=0; i<count; i++)
	{
		ratings[i] = festival[i][1];
		Times[i] = festival[i][0];
		if (Times[i] >= 3 && Times[i] < 7)
		{
			letter[i] = 'A';
		}
		else
		{
			letter[i] = 'B';
		}
	}
	for (int i=0; i<count; i++)
	{
		for (int j=0; j<2; j++)
		{
			printf(" %c\t%lf", letter[i], ratings[i]);
		}
		printf("\n");
	}
	double avgA, avgB, sumA, sumB;
	
	for (int i=0; i<count; i++)
	{
		// Calculate average
	}
}
