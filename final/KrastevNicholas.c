#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double Payment (int);

int main()
{
	//variables
	int password;
	char choice;
	int numTickets;
	char filename[100];
	double total;
	double data[100][2];
	int idx = 0;
	int check;
	
	//create and open file
	FILE * fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Nicholas Krastev, npk53");
	
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);
	
	if (password<5678 || password>5678)
	{
		printf("Incorrect password. Bye!");
	}
	
	printf("Enter P for payment or R for rating: \n");
	scanf(" %c", &choice);
		
	if (choice != 'p' || choice != 'r')
	{
		printf("Enter P for payment or R for rating: \n");
		scanf(" %c", &choice);
	}
	
	
	switch (choice)
	{
		case 'P':
		{
			
			printf("How many festival tickets would you like to buy?\n");
			scanf("%d", &numTickets);
			//Error checking
			while(numTickets<0)
			{
				printf("How many festival tickets would you like to buy?\n");
				scanf("%d", &numTickets);
			}
			//function call
			total = Payment(numTickets);
			printf("Total payment is $%10.2lf", total);
			break;
		}
		case 'R':
		{
			printf("Enter a filename for your music festival data: \n");
			scanf("%s", filename);
			FILE*fout;
			fout = fopen(filename, "r");
			//error checking
			while (fout == NULL)
			{
				printf("Enter a filename for your music festival data: \n");
				scanf("%s", filename);
				fout = fopen(filename, "r");
			}
			while (data[idx][2] != EOF)
			{
				
				
			}
			break;
		}
		default: 
		{
			break;
		}
	}
	
	
	
	return 0;
}

double Payment (int ticket)
{
	double Total;
	Total = (ticket*33) + ((1/5)*(ticket*33));
	return Total;
}

void ratings (int times[][], int shiftA, int shiftB)
{
	
}
