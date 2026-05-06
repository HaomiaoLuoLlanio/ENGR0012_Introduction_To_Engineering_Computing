#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double Payment(int);
void Ratings(float, int );
int main()
{
	
	// 1. write a file and close
	FILE *fp;
	fp = fopen("festival.txt","w");
	fprintf(fp, "Current user: Sneha Mahadevan, snm132");
	fclose(fp);
	
	//2. ask user for password
	printf("Music Festival 2026. Enter your 4-digit password: ");
	int password;
	scanf("%d",&password);
	if (password == 5678) // 4. correct password 
	{
		char PR;  // choose payment or ratings and error check
		do
		{
			printf("\nEnter the letter P for payment or the letter R for ratings: ");
			scanf(" %c", &PR);
		} while (PR != 'P' && PR != 'R');
		
		// 5. switch case for P or R
		switch (PR)
		{
			case 'P':
			{
				int ticketnum;  // 6. ask number of tickets and error check
				printf("\nEnter an integer value corresponding to the number of festival tickets you would like to buy: ");
				scanf("%d", &ticketnum);
				while (ticketnum <= 0)
				{
					printf("\nEnter a value greater than zero: ");
					scanf("%d", &ticketnum);
				}
				
				double total = Payment(ticketnum);  // 7. call Payment function
				printf("\nTotal payment is $%10.2lf", total); // 8. display total payment				
				
				break;
			}
			case 'R':
			{
				char filename[50];
				printf("\nEnter a filename for your music festival data: ");
				scanf("%s",filename);
				
				// 9. enter filename for data and error check
				FILE *fp;
				fp = fopen(filename, "r");
				while (fp == NULL)
				{
					printf("\nEnter a filename for your music festival data: ");
					scanf("%s",filename);
					fp = fopen(filename, "r");
				}
				
				// 10. read data into array
				float data[100][2];
				int rows = 0;
				for (int i=0; i<=EOF; i++)
				{
					fscanf(fp,"%f %f", data[i][0], data[i][1]);
					rows++;
				}
				
				// printf("\n%d rows",rows);	
				rows = 20;
				
				void Ratings(float data[rows][2]; // call Ratiings function
				
				FILE *fp;
				fp = fopen
				
				break;
			}
		}
		
	}
	else // 3. incorrect password
	{
		printf("\nIncorrect password. Bye!");
	}
	
	
	return 0;
}



////////// Functions

double Payment(int ticketnum)
{
	int total;
	total = ticketnum*33 + (1/5)*(ticketnum*33);
	return total;
}



void Ratings(float data[rows][2], int rows)
{
	char Times[rows];
		printf("\nShift\tRating");
	for (i=0; i<rows; i++)
	{
		if (data[rows][0] >= 3 && < 7)
		{
			Times[rows] = 'A';
			printf("\n%c",Times[rows]);
		}
		else if (data[rows][0] >=7)
		{
			Times[rows] = 'B';
			printf("\n%c",Times[rows]);
		}
		else
		{
		}
	}

}
	
