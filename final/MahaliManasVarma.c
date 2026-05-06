#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

//Function prototype
double Payment(int);
double Ratings(float);

int main()
{
	//1)
	FILE *fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Manas, MAM1819");
	fclose(fp);
	
	//2)
	int password;
	char choice;
	int tickets;
	char filename;
	int rows = 0;
	float data[][1];
	
	
	printf("Music festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	//3)
	if(password != 5678)
	{
		printf("Incorrect password");
	}
	//4)
	else
	{
		printf("type 'P' for payment or 'R' for ratings");
		scanf(" %c", &choice);
		while (choice != 'P' && choice != 'R')
		{
		printf("type 'P' for payment or 'R' for ratings");
		scanf(" %c", &choice);	
		}
		//5)
		switch (choice)
		{
		/*6)*/	case 'P':
			{
				printf("how many tickets would you like to buy? ");
				scanf("%d", &tickets);
				while (tickets <= 0)
				{
					printf("how many tickets would you like to buy? ");
					scanf("%d", &tickets);
				}
				
				/*7)*/ double Total_pay = Payment(tickets);
				/*8*/ printf("Total payment is $%10.2d", Total_pay);
				break;
			}
			
			case 'R':
			{
				//9
				printf("Enter the filename: ");
				scanf("%s", &filename);
				
				//10)
				while (filename == NULL)
				{
					printf("Enter the filename: ");
					scanf("%s", &filename);
				}
				FILE*fpr = fopen(filename, "r");
				while (fscanf("&f, %f", &data[rows][0], &data[rows][1]) == 2)
				{
					rows++;
				}
				
				//11) 
				float Total_rat = Ratings(data[][1]);
				
				//12)
				FILE * fp = fopen("festival.txt", "a");
				fprintf(fp, "The average rating for SHift A is %f and the avergae rating for Shift B is %f", Total_rat);
				fclose(fp);
			}
		}
		
	}
	return 0;
}

//Function Creation
double Payment(int tickets)
{
	double Total = tickets*33+.25*tickets*33;
	return Total;
}

double Ratings(float data[][1])
{
	for(int i = 0; data[i][0] > 3 && data[i][0] < 10; i++)
	{
		
	}
	
	
	
	
}
