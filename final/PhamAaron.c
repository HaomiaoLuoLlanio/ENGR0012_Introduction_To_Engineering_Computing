#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
double payment(int tickets);
float ratings(float data[][2]);
int main()
{
	FILE*fp = fopen("festival.txt","w");
	fprintf(fp, "Current User: Aaron Pham,ajp370");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	if (password != 5678) //checks to see if user entered the correct password
	{
		printf("\nIncorrect password. Bye!");
		return 1; //immediately ends program upon entering wrong password
	}
	
	char usrChoice;
	if (password == 5678) 
	{
		printf("\nPlease enter the letter P for payment, or the letter R for ratings: ");
		scanf(" %c", &usrChoice);
		while (usrChoice != 'P' && usrChoice != 'R')
		{
			printf("\nPlease enter the letter P for payment, or the letter R for ratings: ");
		scanf(" %c", &usrChoice);
		}
	}
	
	int ticketNum;
	
	switch (usrChoice)
	{
		case 'P':
		{
			printf("\nHow many tickets would you like to purchase? ");
			scanf("%d",&ticketNum);
			while(ticketNum < 0)
			{
				printf("\nHow many tickets would you like to purchase? ");
				scanf("%d",&ticketNum);
			}
			
			double paymentMain;
			paymentMain = payment(ticketNum);
			printf("Total payment is %10.2lf",paymentMain);
			break;
		}
		case 'R':
		{
			FILE*fp1;
			char filename[50];
			printf("Please enter a filename for festival data: ");
			scanf("%s",&filename);
			while (fp1 == NULL)
			{
				printf("Please enter a filename for festival data: ");
				scanf("%s",&filename);
			}
			fp1 = fopen(filename,"r");
			float satData[100][2];
			int check = 0;
			int idx = 0;
			while(check != EOF)
			{
				check = fscanf(fp1, "%f" "%f", &satData[idx][0], &satData[idx][1]);
				idx++;
			}
			fclose(fp);
			ratings(satData);
			
			float averageAmain = ratings(satData);
			float averageBmain = ratings(satData);
			FILE*fp4 = fopen("festival.txt","a");
			fprintf(fp4, "The average rating for shift A is %f, and the average rating for shift B is %f", averageAmain, averageBmain);
			fclose(fp4);
			break;
		}
		default:
		{
			break;
		}
	}
	

return 0;
}

double payment(int tickets)
{
	double cost = (tickets+0.0)*33;
	double fees = cost*(1/5);
	double total = cost + fees;
	return total;
}

float ratings(float data[][2])
{
	FILE*fp3;
	fp3 = fopen("saturday.txt","r");
	float satData1[100][2];
	int check = 0;
	int idx = 0;
	while(check != EOF)
	{
		check = fscanf(fp3, "%f" "%f", &satData1[idx][0], &satData1[idx][1]);
		idx++;
	}
	fclose(fp3);
	int rows = idx - 1;
	char times[rows];
	for (int i =0; i<rows;i++)
	{
		if (satData1[rows][0] > 3 || satData1[rows][0] <7)
		{
			times[i] = 'A';
		}
		else
		{
			times[i] = 'B';
		}
	}
	printf("\nShift\tRating");
	for (int i=0; i<rows; i++)
	{
		printf("%c\t%f", times[i], satData1[i][1]);
	}
	float sumA;
	float sumB;
	int aTotal;
	int bTotal;
	for (int i=0; i<rows; i++)
	{
		if (times[1] == 'A') //checks the shift assignment before adding to the sum
		{
		sumA = sumA + satData1[i][1];
		aTotal++;
		}
		else
		{
			sumB = sumB + satData1[i][1];
			bTotal++;
		}
	}
	float averageA = sumA / (aTotal+0.0);
	float averageB = sumB / (bTotal+0.0);
	
	return averageA;
	return averageB;
	
	
	
}
