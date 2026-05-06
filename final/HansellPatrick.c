#include <stdio.h>
#include <std.lib>
#include <math.h>
#include <string.h>

int Payment(int);
void Ratings(int[][2], int, float, float);

int main()
{
	int pass;
	char choice;
	int tickets;
	int array[100][2];
	int rows = 0;
	char Filename[50];
	float avgA;
	float avgB;
	
	FILE* Pointer
	Pointer = fopen("festival.txt", "w");
	fprintf(Pointer, "Current user: Patrick Hansell, pdh29\n\n");
	fclose(Pointer);
	
	prinf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &pass);
	
	if(pass != 5678)
	{
		printf("Incorrect password. Bye!\n");
	}
	else
	{
		do
		{
			
		printf("Enter P for payment or R for ratings: \n");
		scanf("%c", &choice);
		
		}while(choice != 'P' && choice != 'R');
		
		switch (choice)
		{
			case 'P':
			
			do
			{
				
			printf("Number of festival tickets you would like to purchase: \n");
			scanf("%d", &tickets);
			
			}while(tickets < 0);
			
			int Total = Payment(tickets);
			
			printf("Total payment is $%10.2d\n", Total);
			
			break;
			
			case 'R':
			
			FILE* Pointer2;
			
			do
			{
				
			prinf("Filename: ");
			scanf("%s", Filename);
			
			Pointer = fopen(Filename, "r");
			
			}while(Filename == NULL); //ensures a correct file is entered (Filename != null)
			
			int check;
			while(1)
			{
				check = fscanf(Pointer2, "%d %d", &array[rows][0], &array[rows][1];
				
				if(check == EOF)
				{break;}
				
				rows++; //put rows below because we do not want to count when check = -1 as a row
				
			}
			
			fclose(Pointer2);
			
			Ratings(array, rows, avgA, avgB);
			
			Pointer = fopen("festival.txt", "a");
			fprintf(Pointer, "The average rating for Shift A is %f and the average rating for Shift B is %f.", avgA, avgB);
			fclose(Pointer);
			
			break;
			
		}
			
		
	}
	
	
	return 0;
}

int Payment(int t)
{
	int Total;
	
	Total = (t) * 33 + (1/5) * (t);
	return Total;
	
}

void Ratings(int array[][2], int rows, float avgA, float avgB)
{
	char times[50];
	float sumA = 0;
	float sumB = 0;
	int countA = 0;
	int countB = 0;
	
	for(int i = 0; i < rows; i++)
	{
		if(array[i][2] >= 3 && array[i][2] < 7)
		{
			times[i] = 'A';
			countA++; //collects the amount of As
			sumA = sumA + array[i][2]; //collects the sum of ratings that are As
			
		}
		else 
		{
			times[i] = 'B';
			countB++ //exact same idea here
			sumB = sumB + array[i][2];
		}
	}
	
	printf("Shift\tRating\n");
	
	for(i = 0; i < rows; i++)
	{
		printf("%d\t%8.6d\n", times[i], array[i][2]);
	}
	
	avgA = (float)sumA / countA; //no double returns, so we must declare variables in main
	avgB = (float)sumB / countB;
	
	
}

