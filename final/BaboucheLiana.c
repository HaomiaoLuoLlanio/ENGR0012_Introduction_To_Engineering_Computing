
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function prototypes
float payment(int);
void ratings(float [50][2], int);

int main()
{
	FILE *fp = fopen("festival.txt","w"); // created this file
	fprintf(fp,"Current user: Liana Babouche, ltb57");
	fclose(fp);
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	int password;
	scanf("%d", &password);
	char choice;
	
	if (password == 5678)
	{
		do {
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &choice);
		} while (choice != 'P' && choice != 'R');
	}
	else
	{
	printf("\nIncorrect password. Bye!");
	return 0;
	}
	
	switch (choice)
	{
		case 'P':
		{
			int numticket;
			do {
			printf("\nEnter number of tickets you would like to purchase: ");
			scanf("%d", &numticket);
			} while (numticket <= 0); 
			// function Payment here
			float total = payment(numticket);
			printf("\nTotal payment is $%10.2f", total);
			
			break;
		}
		case 'R':
		{
			printf("\nEnter a file name for your music festival data: ");
			char filename[50];
			scanf("%s", &filename);
			FILE *ratefile = fopen(filename,"r");
			
			if (ratefile == NULL) // error checking to make sure the file can open
			{
				printf("\nEnter a file name for your music festival data: ");
				scanf("%s", &filename);
				FILE *ratefile = fopen(filename,"r");
			}
			
			float arr[50][2];
			int check = 0;
			int i = 0;
			int rows = 0;
			
			while (check != EOF) // reading all the values and raising index until end of file
			{
				check = fscanf(ratefile, "%f %f", arr[i][1], arr[i][2]);
				i++;
				rows = rows + 1;
			}
			fclose(ratefile);
			void ratings(float arr[50][2], int rows);
			fopen(ratefile,"a");
			fprintf(ratefile,"\nThe average rating for Shift A is %f and the average rating for Shift B is %f.",avgA,avgB);
			fclose(ratefile)
			
			break;
		}
	}
	
	return 0;
}


// functions

float payment(int numticket)
{
	float totalcost = numticket*33 + (1/5) * (numticket*33);
	return totalcost;
}

void ratings(float arr[50][2], int rows) // for this function, i did not know how to return two values, both avgA and avgB to the main
{
	char times[rows];
	for (int i = 0; i < rows; i++)
	{
		if (arr[i][1] >= 3 && arr[i][1] < 7)
		{
			times[i] = 'A';
		}
		else 
		{
			times[i] = 'B';
		}
	}
	
	printf("\nShift\tRating");
	float sumA = 0;
	float avgA;
	int countA = 0;
	
	float sumB = 0;
	float avgB;
	int countB = 0;
	
	for (int i = 0; i<rows;i++) // I used the same for loop to both display values and find the averages
	{
		printf("%c\t%f",times[i],arr[i][1]);
		printf("\n");
		
		if (times[i] == 'A')
		{
			sumA = sumA + arr[i][1];
			countA++;
		}
		
		if (times[i] == 'B')
		{
			sumB = sumB + arr[i][1];
			countB++;
		}
		
	}
	avgA = sumA/countA;
	avgB = sumB/countB;
	
	
}



