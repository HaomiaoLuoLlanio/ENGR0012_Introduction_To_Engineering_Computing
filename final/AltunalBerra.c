#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes

double = Payment(int);
Ratings(float[][2]);

//Main
int main()
{
	
	//  1
	
	FILE *fp;
	
	fp = fopen("festival.txt","w");
	fprintf(fp,"Curent user: Berra Altunal, bea141");
	fclose(fp);
	
	//  2
	int password;
	printf("Music Festival 202. Enter your 4-digit password:");
	scanf("%d",&password);
	
	// 3
	
	if (password != 5678)
	{
		printf("\nIncorrect password. Bye!");
		return 1;
	}
	
	// 4
	
	char choice;
	
	do
	{
	printf("\nEnter the letter P for payment of the letter R for ratings: ");
	scanf(" %c",&choice);
	} while (choice != 'P' && choice != 'R');
	
	// 5, 6, 7, 8, 9, 10, 11, 12
	
	int tickets;
	double Total;
	
	switch (choice)
	{
		
		case 'P':
			
			do{
			printf("\nEnter the number of festival tickets you would like to purchase: ");
			scanf("%d", &tickets);
			} while (tickets <=0);
			
			// Calling payment function
			Total = Payment(tickets);
			
			printf("Total payment is $%10.2lf", Total);
			
		
		break;
		
			
		
		case 'R':
		
		char filename[50];
		FILE *fp2;
		
		do{
		printf("Enter a filename for your music festival data: ");
		scanf("%s",&filename);
		fp2 = fopen(filename,"r");
		} while (fp2 == NULL);
		
		float data[100][2];
		int i = 0, check;
		
		while (check != EOF)
		{
			check = fscanf(fp2,"%f %f", &data[i][0],&data[i][1]);
			i++;
		}
				
		
		fclose(fp2);
		
		// Call function Ratings
		
		Ratings(float data[][2]);
		
		fopen(fp);
		// ran out of time fprintf();
		
		break;
		
	}
	
	
	return 0;
}

//Function Definitions

// Payment Function
double = Payment(int tickets)
{
	Total = tickets*33+33*tickets/5;
	return Total;
}

// Ratings Function

Ratings(float data[][2])
{
char Times[50], letter;
int i = 0;
float sumA=0, sumB=0, countA=0, countB=0;

printf("\nShift \t Rating\n");

for (i=0;i<rows;i++)
{
	if (data[i][0]>=3 && data[i][0]<3)
	{
		letter = 'A';
		countA++;
		sumA = sumA + data[i][1];
	}
	else
	{
		letter = 'B';
		countB++;
		sumB = sumB + data[i][1];
	}
	printf(" %c \t %f",letter,data[i][1]);
}

float averageA, averageB;

// averageA
	averageA = sumA/countA;
// averageB
	averageB = sumB/countB;

averageA = data[0][2];
averageB = data[1][2];

}

