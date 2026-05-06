#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
double Payment(float tix);
float Ratings(float arr[100][2], int count, int op);

int main(void)
{
	// Opens or creates the Festival file
	FILE *festival = fopen("festival.txt", "w");
	fprintf(festival, "Current user: Ignacio Castillo, ixc4");
	fclose(festival);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);
	if (password != 5678)
	{
		printf("Incorrect Password. Bye!");
		return 1;
	}
	
	char choice;
	printf("\nEnter P for payment or R for ratings:\n");
	scanf(" %c", &choice);
	
	while (choice != 'P' && choice != 'R')
	{
		printf("\nEnter P for payment or R for ratings:\n");
		scanf(" %c", &choice);
	}
	
	switch (choice)
	{
		case 'P':
		{
			float tix;
			printf("\nHow many tickets would you like to purchase?:\n");
			scanf("%f", &tix);
			while (tix < 0)
			{
			printf("\nHow many tickets would you like to purchase?:\n");
			scanf("%f", &tix);
			}
			
			double tot = Payment(tix);
			
			printf("Total payment is $%10.2lf", tot);
			break;
		}
		case 'R':	
		{
			FILE *current;
			char name[50];
			printf("\nPlease enter a filename:\n");
			scanf("%s", name);
			current = fopen(name, "r");
			
			while (current == NULL)
			{
				printf("\nPlease enter a filename:\n");
				scanf("%s", name);
				current = fopen(name, "r");
			}
			
			float ratings[100][2];
			int counter = 0, temp = 0;
			while (temp != EOF)
			{
				temp = fscanf(current, "%f %f", &ratings[counter][0], &ratings[counter][1]);
				counter++; 
			}
			
			counter = counter - 1;
			fclose(current);
			
			float averages[2];
			averages[0] = Ratings(ratings, counter, 1);
			averages[1] = Ratings(ratings, counter, 2);
			FILE *new = fopen("festival.txt", "a");
			fprintf(new, "The average rating for Shift A is %.2f and the average rating for Shift B is %.2f", averages[0], averages[1]);
			break;
		}
		default:
		{
			printf("Somehow managed to break the code");
			return 2;
		}
	}
	
	return 0;
}

// Functions
double Payment(float tix)
{
	double tot;
	tot = tix * 33.00 + ((1/5)*tix*33.00);
	return tot;
}

float Ratings(float arr[100][2], int count, int op)
{
	int countA = 0, countB = 0;
	float totA = 0, totB = 0;
	if (op == 1)
	{
		printf("Shift\tRating\n");
		(int i = 0; i < count; i++)
		{
			if (arr[i][0] < 7 && arr[i][0] > 3)
			{
				printf("A\t%f\n", arr[i][1]);
				countA++;
				totA = totA + arr[i][1];
			}
			else if (arr[i][0] >= 7)
			{
				printf("B\t%f\n", arr[i][1]);
				countB++;
				totB = totB + arr[i][1];
			}
		}
	}
	
	float avg;
	if (op == 1)
	{
		avg = totA/countA;
		return avg;
	}
	else if (op == 2)
	{
		avg = totB/countB;
		return avg;
	}
	else
	{
		return 0;
	}
}
