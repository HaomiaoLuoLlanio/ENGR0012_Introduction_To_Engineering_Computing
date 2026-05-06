#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Payment(int a);
int Ratings(int start, int end);


int main()
{
	
	
	FILE *fp;
	
	fp = fopen("festival.txt", "r");
	
	printf("Current user: Kayla Ngo, kan248");
	
	fclose(fp);

	
	int password = 0;
	
	
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!"); // Ends program here if incorrect.
	}
	else
	{
		char opt;
		do // continues to ask until P or R is entered
		{
		printf("Enter the letter P for payment and R for ratings:");
		scanf(" %c", &opt);
		
		} while (opt != 'P' && opt != 'R');
		
		
		switch (opt) //Switches between payment or ratings
		{
			case 'P': 
				int tickets = 0; 
				do
				{
				printf("Enter an integer value to correspond to the number of festival tickets you would like to purchase: ");
				scanf("%d", &tickets);
				
				} while (tickets <=0);
				// CALL FUNCTION PAYMENT #7
				
				int Total = Payment(tickets);
			
				printf("The total payment is $%10.2d\n");
					break;
				
			case 'R':
			
			FILE *fp;
			float filename[][2];
			
			fp = fopen(filename[][2], "r");
			int n=0;
			int col1[], col2[];
			
			while(fscanf("%lf %lf", &col1[n], &col2[n]) != EOF)
			{
				fprintf("%lf %lf", col1[n], col2[n]);
			}
			
			fclose(fp);
			
			// CALL FUNCTION RATINGS #11
			int Ratings(col1[], col2[]);
			
			// reopen festival text
			FILE *fp;
	
			fp = fopen("festival.txt", "r");
	
			printf("The average rating for Shift A is ");
			
			
			
				break;
			
		}
	}
	
	
	return 0;
}

//////////////////////////////////////////////////////////////////////

int Payment(int a) 
{
	double tot = 0;
	
	tot = a*33+(1/5)*a*33;
	
	return tot; //returns the total amount to the variable Total in main
}

int Ratings(int start, int end)
{
	char Times[][];
	if (times[start][end];
	
	
	printf("\n\nShift\tRating\n");
	printf(" %c\t%lf", Shift, Rating);
	
	
	
}















