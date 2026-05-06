#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Proto-zone-a
double Payment(int);
void Ratings(float[][2], int, float[2]);

int main()
{
	FILE * fp; // Creating file and printing to it
	fp = fopen("festival.txt","w");
	fprintf(fp,"\"Current user: Owen Rick, ofr9\"");
	fclose(fp);
	
	int pword;
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d",&pword); 
	
	if (pword != 5678) 	// incorrect password
	{
		printf("\nIncorrect password. Bye!");
		return 0;
	}
	else 
	{
		char correct;
		do {	// Error checking to make sure its a P or R entered
		printf("\nEnter P for payment or R for ratings: ");
		scanf(" %c",&correct);
		} while (correct != 'P' && correct != 'R');
		
		switch (correct)
		{
			case 'P':	// Payment Section
			{
			int tickets;
				do {
				printf("How many tickets do you want to purchase? ");
				scanf("%d",&tickets);
				} while (tickets <=0);
				
			double Total;
			Total = Payment(tickets);	// Calling payment 
			
			printf("\nTotal payment is $%-10.2lf",Total);
			break;
			}
			case 'R':	// Ratings section
			{
			char filename[50];
			FILE * fread;
			
			do {void Ratings(float array, int idx, float avgshift)
			printf("\nPlease enter a filename: ");	// Loading in file
			scanf("%s",&filename);
			fread = fopen(filename,"r");
			} while (fread == NULL);
			
			float array[50][2];
			int idx = 0;
			while (check != EOF)	// Reading data with EOF
			{
				check = fscanf(fread,"%d %d", &array[idx][0],&array[idx][1]);
				idx++;
			}
			fclose(fread);
			
			float avgshift[2];
			Ratings(array[][2], idx, avgshift[2]);
			
			FILE * fp2;
			fp2 = fopen("festival.txt","a");
			fprintf("\nThe average rating for Shift A is %f and the average rating for shift B is %f.",
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

// Function Junction 
double Payment(int tickets)
{
	double Total = tickets * 33 + (1/5)*(tickets*33);
	return Total;
}

void Ratings(float array, int idx, float avgshift)
{
	char Times[idx];
	int countA,countB;
	for (int i = 0; i<idx; i++)
	{
		if (array[i][0] < 7)
		{
			Times[i] = 'A';
			countA++;
		}
		else
		{
			Times[i] = 'B';
			countB++;
		}
	}
	
	printf("\nShift\tRating\n"); // Displaying everything
	for (i = 0; i<idx; i++)
	{
		printf(" %c\t%f",Times[i],array[i][1]);
	}
	
	double sumA = 0.0,sumB = 0.0;
	for (i = 0; i<idx; i++)
	{
		if Times[i] = 'A'
		{
			sumA = sumA + array[i][1];
		}
		else
		{
			sumB = sumB + array[i][1];
		}
	}
	
	avgshift[0] = sumA/countA;
	avgshift[1] = sumB/countB;
}
