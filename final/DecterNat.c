#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Prototypes

double Payment(int);
float Ratings(float, int);

//Main

int main()
{

//Part 1

FILE *ffest
ffest = fopen("festival.txt", "w");
fprintf(ffest, "Current user: Nathaniel Decter, nmd131");
fclose(ffest);

//Part 2

int usr_pass = 0;
printf("Music Festival 2026. Enter your 4 digit password: ");
scanf("%d", &usr_pass);

//Part 3 and 4 Error check password and decision

if (usr_pass != 5678)
{
	printf("\n\nIncorrect password. Bye!");
	return 1;
}
else
{
	char usr_choice; 
	printf("\n\nWould you like to make a payment (P) or leave a rating (R)? ");
	scanf(" %c", &usr_choice);
	while (usr_choice != 'R' || usr_choice != 'P')
	{
		printf("\n\nWould you like to make a payment (P) or leave a rating (R)? ");
		scanf(" %c", &usr_choice);
	}
}

// Part 5-

switch (usr_choice)
{
	case ('P'):
	{
		int tickets = 0;
		printf("\n\nPlease enter an integer value number of festival tickets you would like to purchase: ");
		scanf("%d", &tickets);
		while (tickest < 0)
		{
			printf("\n\nPlease enter an integer value number of festival tickets you would like to purchase: ");
			scanf("%d", &tickets);
		}
		
		//Payment function 
		
		double Total_payment = Payment(tickets);
		
		printf("Your total is: $%10.2lf", Total_payment);
		
		break;
	}
	case ('R'):
	{
		char filename[100];
		FILE *fdata
		float data[][2]
		printf("Please enter a file name for your music festival data: ");
		scanf("%s", filename);
		fdata = fopen(filename, "r");
		while (fdata == NULL)
		{
			printf("Please enter a file name for your music festival data: ");
			scanf("%s", filename);
			fdata = fopen(filename, "r");
		}
		int check = 0;
		int i = 0;
		while (check != EOF)
		{
			check = fscanf(fdata, "%f %f", data[i][0], data[i][1]);
			i++;
		}
		fclose(fdata);
		
		//Ratings Function
		
		float Avgs[2] =Ratings(data, i);
		FILE *fp;
		fp = fopen("festival.txt", "a");
		fprintf(fp, "\n\n");
		fprintf(fp,"The average rating for Shift A is %f and the average rating for shift B is %f", Avgs[0], Avgs[1]);
		fclose(fp);
		
		break;
	}
	default:
	{
		//No necessary input
	}
	
}





return 0;
}

//Functions

double Payment(int func_tickets)
{
	double Total = 0;
	
	Total = (func_tickets * 33) + (1 / 5) * (func_tickets * 33);
	
	return Total;
}

Ratings(float func_data, int length)
{
	char Times[];
	for (idx = 0; idx < length; idx++)
	{
		if (func_data[idx] > 3 && func_data[idx] < 7)
		{
			Times[idx] = 'A'
		}
		else if (func_data > 7)
		{
			Times[idx] = 'B'
		}
	}
	
	printf("\n\nShitf\tRating\n");
	for (idx = 0; idx < length; idx++)
	{
		printf("%c\t%f\n", Times[idx], func_data[i][1]);
	}
	
	int A_count = 0;
	int B_ count = 0;
	float A_rating_sum = 0;
	float B_rating_sum = 0;

	for (idx = 0; idx < length; idx++);
	{
		if (Times[idx] == 'A')
		{
			A_count = A_count + 1;
			A_rating_sum = A_rating_sum + func_data[idx][1];
		}
		else if (Times[idx] == 'B')
		{
			B_count = B_count + 1;
			B_rating_sum = B_rating_sum + func_data[idx][1];
		}
	}
	float Bavg = B_rating_sum / B_count;
	float Aavg = A_rating_sum / A_count;
	float avgs[2] = {Aavg, Bavg};
	return avgs[2];
	
}







