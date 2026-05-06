#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Payment Function

double Payment(int Tickets)
{
	double Total = Tickets * 33 + 0.2 * Tickets * 33;
	return Total;
}

// Ratings Function

void Ratings(double data[100][2], int elements);
{
	char Times[];
	
	for (int j = 0; j < elements; j++)
	{
		if (data[j][0] < 7)
		{
			Times[j] = 'A';
		}
		else
		{
			Times[j] = 'B';
		}
		
		printf("Shift\tRating\n\n");
		
		for (int k = 0; k < elements; k++);
		{
			printf("%s\t%lf", Times[k], data[k][1]);
		}
		
	}
	
	
}





int main(int argc, char **argv)
{
	int password;
	char choice;
	double Tickets = 0;
	double TicketCost;
	char FileName[50];
	double data[100][2];
	
	FILE *fp = fopen("festival.txt", "w");
	
	fprintf(fp, "Current User: Kade Collins, KWC23");
	
	fclose(fp);
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password == 5678)
	{
		while (choice != 'P' && choice != 'R')
		{
			printf("Please enter the letter P for payment or the letter R for ratings: ");
			scanf("%s", &choice);
		}
		
		switch (choice)
		{
			case 'P':
			
				while (Tickets < 1)
				{
					printf("\nPlease enter the number of Festival Tickets you would like to purchase: ");
					scanf("%lf", &Tickets);
					TicketCost = Payment(Tickets);
					printf("\nTotal Payment Amount: $%10.2lf", TicketCost);
				}
				
			break;
			
			case 'R':
			
					while (FileName != 'saturday.txt')
					{
						printf("Please Enter a File Name: ");
						scanf("%s", FileName);
					}
					
					FILE *pf = fopen(FileName, "r");
					
					for (int i = 0; fscanf(pf, "%lf\t%lf\n", &data[i][0], &data[i][1]) != EOF; i++)
					{
						printf("%lf\t%lf\n", &data[i][0], &data[i][1]);
						elements++
					}
					
					fclose(pf);
					
					Ratings(Data, elements);
					
					
			
			break;
			
			default:
			break;
		}
		
		
	}
	else
	{
		printf("\n\nIncorrect password. Bye!");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

