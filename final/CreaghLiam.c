#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Liam Creagh LTC38 Zhou's 12pm

//Function Prototypes
int = Payment(int);
double, double = Ratings(int, int [][1]);


int main()
{
	FILE *fp;
	fp = fopen("festival.txt", "w"); //used w to tell the file i am writing stuff into it
	fprintf(fp, "Current User: Liam Creagh, LTC38");
	while (fp==NULL)
	{
	fp = fopen("festival.txt", "a");
	fprintf(fp, "Current User: Liam Creagh, LTC38");
}
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your four digit password: \n\n\n"); //skipped three lines because of sample display
	scanf("%d", password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");
	}
	
	if (password == 5678)
	{
		char choice;
		printf("Enter P for payment or the letter R for ratings: \n\n");
		scanf(" %c", choice);
		while ( choice != P || choice != R)
		{
			printf("Enter P for payment or the letter R for ratings: ");
			scanf(" %c", choice); //need a space for character scan
		}
		switch (choice) //falls into one of two categories based on user choice
		
		case 'P': 
		{
			int tickets;
			printf("Enter the number of tickets you would like to purchase: ");
			scanf("%d", tickets);
			total_cost = Payment(int tickets);
			printf("Total payment is $%10.2d", total_cost);
			break;
		}
		case 'R': 
		{
			FILE *fp2
			
			printf("Enter a file name for your music festival data: \n")
			scanf("%s", filename);
			fp2 = fopen("saturday.txt", "r");
			while (fp2 == NULL)
			{
				printf("Enter a file name for your music festival data: ")
				scanf("%s", filename);
				fp2 = fopen("saturday.txt", "r");
			}
			int check = 0;
			int idx = 0;
			int arr[][2];
			int rows = 0;
			while (check != EOF)
			{
				check = fscanf(fp2, "%d" "lf", arr[idx][0], arr[idx][1]);
				idx ++; 
			}
			rows = idx - 1; //displays unknown number of rows achieved from the file
			fclose(fp2)
			ratingA, ratingB = Ratings(int rows)
			fp = fopen("festival.txt", "w");
			fprintf(fp, "The average rating for Shift A is %lf and the average rating for shift B is %lf", ratingA, ratingB); //displays values found from ratings function
			break;
		}
		default: 
		{
			
			break;
		}
	}
	
	
	
	return 0;
}


//Function Section

int = Payment(int tickets)
{
	int total_cost;
	total_cost = (tickets*33) + (0.2*tickets*33);
	return total_cost;
}

double, double = Ratings(int rows, int arr[][1])
{
	char times[][];
	for (i = 0; i < rows; i++)
	{
		if (time > 3 || time < 7)
		{
			arr[0][0] = [A][1]
		}
		else if ( time > 7)
		{
			arr[0][0] = [B][1]
		}
		printf("Shift"\t"Rating");
		printf(" %c"\t" %c", times[0][0], times[1][0]);
		int avg_rating_A;
		int avg_rating_B;
		avg_rating_A = times[rows][0] / rows;
		avg_rating_B = times[rows][1] / rows;
	}
	
	return avg_rating_A, avg_rating_B;
	
}





