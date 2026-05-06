#include <stdio.h>
#include <stdlib.h>
#include <math.h.>
#include <string.h>

double payment(int);
void ratings (float[][2], int, int, int)

int main()
{
	FILE *outfile *infile; //specifying placeholders for files
	outfile = fopen("festival.txt", "w");
	fprintf(outfile, "Current user: Sriram Rajkumar, srr193");
	fclose(outfile);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!!");
	}
	else
	{
		char enter; 
		printf("Enter P for payment or R for ratings\n");
		scanf(" %c", &enter);
		
		while (enter != 'P' && enter != 'R')
		{
			printf("Enter P for payment or R for ratings\n");
			scanf(" %c", &enter);
		}
		
		switch(char)
		{
			case 'P':
			{
				int tickets;
				double cost;
				printf("Enter an integer value of the number of tickets you would like to purhcase\n");
				scanf("%d", &tickets);
				cost = payment(tickets);
				printf("Total payment is $%10.2lf", cost)
			}
			
			case 'R':
			{
				char filename[50];
				printf("Enter a filename: \n", )
				scanf("%s", filename);
				infile = fopen(filename, "r");
				
				while (infile == NULL)
				{
					printf("\nEnter a filename for your music festival data: ");
					scanf("%s", fileName);
					festData = fopen(fileName, "r");
				}
				
				int check = 0;
				float arr[100][2]; 
				int i = 0;
				
				while (check != EOF) //scanning into arr from infile
				{
					check = fscanf(infile, "%lf %lf", &arr[i][0], &arr[i][1]);
					i++;
				}
				
				int count = i - 1;
				
				fclose(infile);
				
				int averageA, averageB;
				
				ratings(float arr, int count, int averageA, int averageB);
				
				outfile = fopen("festival.txt", "a"); //appending to otufile
				
				fprintf(outfile, "The average rating for Shift A is %d and the average rating for Shift B is %d", averageA, averageB);
				
			}
		}
	 }	
	return 0;
}

double payment(int tickets)
{
	double total = (double)(tickets*33) + 1/5*(tickets*33);
	return total;
}

void ratings (float arr[][2], int count, int averageA, int averageB) // rating function obtain a display output
{
	char times[100];
	
	for (int i = 0; i < count; i++)
	{
		if(arr[i][0] >= 3.0 && arr[i][0] <= 7.0)
		{
			times[i] = 'A';
		}
		else if (arr[i][0] >= 7.0)
		{
			times[i] = 'B';
		}
	}
	
	printf("Shift\tRating\n");
	
	for (int i = 0; i < count; i++)
	{
		printf("%c\t%.6lf\n", times[i], arr[i][1]);
	}
	
	int countA, countB;
	int sumA, sumB;
	
	for (int i = 0; i < count; i++) //Looping to connect a shift vakue to a ratings value
	{
		if (times[i] == 'A')
		{
			sumA = sumA + arr[i][2];
			countA++;
		}
		else if (times[i] == 'B')
		{
			sumB = sumB + arr[i][2];
			countB++;
		}
		
	}
	
	averageA = sumA/countA;
	averageB = sumB/countB;
	
}


