#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Payment(int);
void Ratings(float[][2], int, float[2]);


int main()
{
	// Part 1:
	FILE *fest = fopen("festival.txt", "w");
	fprintf(fest, "Current user: Jishnu Dass, jid126");
	fclose(fest);
	
	// Part 2:
	int password;
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);

	// Part 3:
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");		
		
	} else 
	{
		// Part 4:
		char choice;
		
		do
		{
			printf("Enter P for payment or R for ratings: ");
			scanf(" %c", &choice);
		} while (choice != 'P' && choice != 'R');
		
		// Part 5:
		switch (choice)
		{
			case 'P':
			{
				// Part 6:
				int tix;
				do
				{
					printf("Please enter an integer value greater than 0 for how many tickets you would like to purchase: ");
					scanf("%d", &tix);
				} while (tix <= 0);
				
				// Part 7:
				double cost = Payment(tix);
				
				// Part 8:
				printf("Total payment is $%-10.2lf", cost);				
				
				
				
				break;
			}
			case 'R':
			{
				// Part 9:
				FILE *RatingFile;
				char fileName[20];
				
				do
				{
					
					printf("Please enter a valid file name for the music fest data: ");
					scanf("%s", fileName);
					
					RatingFile = fopen(fileName, "r");
					
				} while (RatingFile == NULL);
				
				// Part 10:
				int check = 0, idx = 0;
				float data[50][2];
				
				while (check != EOF)
				{
					check = fscanf(RatingFile, "%f %f", &data[idx][0], &data[idx][1]);
					idx++;
					
				}
				
				fclose(RatingFile);
				int count = idx - 1;
				
				// Part 11:
				float resArr[2];
				
				Ratings(data, count, resArr);
				
				// Part 12:
				FILE *fest2 = fopen("festival.txt", "a");
				
				fprintf(fest2, "\nThe average rating for shift A is %f and the average rating for shift B is %f", resArr[0], resArr[1]);
				
				fclose(fest2);
				
					
				break;
			}
			
		}
		
	}






return 0;
}

double Payment(int num)
{
	double total = num * 33 + .2 * num * 33;
	return total;
}

void Ratings(float data[][2], int count, float avgRatings[2])
{
	char Times[count];
	float ratingsA = 0, ratingsB = 0;
	int bandsA = 0, bandsB = 0;
	
	
	
	printf("\nShift\tRating");
	
	for (int i = 0; i < count; i++)
	{
		if (data[i][0] >= 3 && data[i][0] < 7)
		{
			Times[i] = 'A';
			ratingsA = ratingsA + data[i][1];
			bandsA++;
		} else
		{
			Times[i] = 'B';
			ratingsB = ratingsB + data[i][1];
			bandsB++;
		}
		
		printf("\n%c\t%f", Times[i], data[i][1]);
				
		avgRatings[0] = ratingsA / bandsA;
		avgRatings[1] = ratingsB / bandsB;
	
		
		
		
	}
	
}












