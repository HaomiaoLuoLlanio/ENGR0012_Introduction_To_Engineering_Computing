#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//function prototypes
double Payment(int tickets, double price);
void  Ratings(double data[][2], double ratings);

int main()
{
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp,"Current user: Jansen Sarisky, JRS529\n");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);
	
	if (password != 5678) //error checking the password to see if it matches
	{
		printf("Incorrect password. Bye!\n");
	}
	
if (password == 5678)
{
	char inp;
	printf("Please enter the letter P for payment or the letter R for ratings\n");
	scanf(" %c", &inp);
	while (inp != 'P' && inp != 'R')
	{
		printf("Please enter the letter P for payment or the letter R for ratings\n");
		scanf(" %c", &inp);
	}
	
	switch (inp)
	{
		case 'P':
		{
			int tickets; 
			printf("Please enter the number of tickets you want: \n");
			scanf("%d", &tickets);
			while (tickets < 0) //error checking that the number of tickets is greater than 0
			{
				printf("Please enter the number of tickets you want: \n");
				scanf("%d", &tickets);	
			}
			double total = Payment(tickets, 33.0);
			printf("Total payment is: $%10.2lf\n", total); //printds with $ 10 char and 2 decimal
		break;	
		}
		case 'R':
		{
			FILE *fp2;
			char filename[100];
			
			printf("Enter a filename for the music festival data\n");
			scanf("%s", filename);
			fp2 = fopen(filename, "r");
			
			while (fp2 == NULL) //error checking file 
			{
				printf("Enter a filename for the music festival data\n");
				scanf("%s", filename);
				fp2 = fopen(filename, "r");
			}
			
			double data[100][2];
			int idx = 0;
			int check = 0;
			
			for(int i = 0; i < idx; i++)
			{
				
				while (check != EOF) //reading until end of file 
				{
					check = fscanf(fp2, "%lf %lf", data[idx]);
					if(check != EOF)
					idx++;
				}
			}
			fclose(fp2);
			int idx = rows;
			Ratings(time, ratings);
		break; 	
		}
		
		
	}	
}
	
	return 0;
}

//fuction for payment 
double Payment(int tickets, double price)
{
int total;
total = tickets * price + (1/5) * (tickets * price);
return total;
	
}

//fucntion for ratings
 void Ratings(double data[][2], double ratings)
 {
	char times[100];
	int sumA, sumB;
	int countA, countB;
	printf("Shift\tRatings\n");
	for (int i = 0; i < rows; i++)
	{
		if (data[i][0] >= 3 || data[i][0] <= 7)
		{
			times[i] = 'A';
			sumA = sumA + ratings;
			countA++;
			
		}
		else if (data[i][0] > 7)
		{
			times[i] = 'B';
			sumB = sumB + ratings;
			countB++;
			
		}
		printf(" %c\t%.2lf\n",times[i],data[i][1]);
	}

	
	
}
