#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Payment(numTic);

int main()
{
	char choice;
	int numTic;
	double payment = 0.0;
	char filename[100];
	float data[100][2];
	int rows = 0;
	double sumA = 0.0;
	double sumB = 0.0;
	
	FILE*out;
	FILE*fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Tanner Brosius, teb113");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");
		return 0;
	}
	else
	{	
		do
		{
			printf("Enter the letter P for payment or R for ratings: \n");
			scanf(" %c", &choice);
		
			if (choice != 'P' && choice != 'R')
			{
				printf("Invalid option, try again.");
			}
		} while (choice != 'P' && choice != 'R');
	}
	
	switch (choice)
	{
	case 'P':
		{
			do
			{
				printf("Enter the number of tickets you want to buy: \n");
				scanf("%d", &numTic);
				
				if (numTic < 0)
				{
					printf("Invalid number, try again.");
				}
			} while (numTic < 0);
			
			payment = Payment(numTic);
			printf("Total payment is $%10.2lf", payment);
			
		}
	case 'R':
		{
			do
			{
				printf("Enter file name: \n");
				scanf("%s", filename);
				out = fopen(filename, "r");
				
				if (out == NULL)
				{
					printf("Invalid file, try again.");
				}
			} while (out == NULL);
			
			while (fscanf(out, "%f %f", &data[rows][0], &data[rows][1]) != EOF)
			{
				rows = rows + 1;
			}
			fclose(out);
			
		}
	default:
		{
		}
	}
		
	return 0;
}

int Payment(numTic)
{
	double total;
	
	total = numTic * 33 + ((1/5) * (numTic * 33));
	return total;
}

void Ratings(float data[100][2], int rows)
{
	char Times[100][2];
	
	for (int i = 0; i<rows; i++);
	{
		if (data[i][0] >= 3 && data[i][0] < 7)
		{
			Times[i][0] = 'A';
		}
		else (data[i][0] >= 7)
		{
			Times[i][0] = 'B';
		}
	}
	printf("\nShift\tRating\n");
	for (int i = 0; i<rows; i++);
	{
		printf("%c\t%f\n", Times[i][0], data[i][1]);
	}
	
	for (int i = 0; i<rows; i++);
	{
		if (Times[i][0] == 'A')
		{
			sumA = sumA + Times[i][0];
		}
		else
		{
			sumB = sumB + Times[i][0];
		}
	}
	avgA = sumA / rows;
	avgB = sumB / rows;
	
}
