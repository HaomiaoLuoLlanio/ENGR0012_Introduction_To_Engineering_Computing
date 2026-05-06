#include <stdlib.h>
#include <stdio.h>
#include <math.h>



double payment( int); // declare before function 
double ratings(double , int );

int main()
{
	FILE *fp;
	
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Zander Perry, zsp15");
	fclose(fp);
	
	int password; 
	printf("Music Fesival 2026: Enter your 4-digit password: ");
	scanf("%d", &password);
	
	
	char choice; // declare outside of loop
	if (password == 5678) // only correct option
	{
		printf("Please enter the letter P for payment or the letter R for ratings: ");
		scanf(" %c", &choice);
		while (choice != 'P' || choice != 'R')
		{
			printf("Please enter the letter P for payment or the letter R for ratings: ");
			scanf(" %c", &choice);
		}
		
	}
	else 
	{
		printf("Incorrect password. Bye!");
		return 0; // return to end program
	}
	
	int tickets;
	
	switch (choice)
	{
	
	case 'P':
	{
		printf("Please enter the number of tickets you would like to purchase(greater than 0): ");
		scanf("%d", &tickets);
		while (tickets<1)
		{
			printf("Please enter the number of tickets you would like to purchase(greater than 0): ");
		scanf("%d", &tickets);
		}
		double price = 0;
		price = payment(tickets); // Payment function
		printf("Total payment is $%10.2lf", price);
		break;
	}
	case 'R':
	{
		FILE *fp; 
		char filename[50]; 
		printf("Please enter a filename for music data: ");
		scanf("%s", filename);
		fp = fopen(filename, "r"); // 2 rows, x cols
		while (fp == NULL)
		{
			printf("Please enter a filename for music data: ");
			scanf("%s", filename);
		}
		
		int check = 0;
		float data[2][50];
		int idx = 0; 
		while (check != EOF) 
		{
			check = fprintf(fp, "%lf, %lf", data[0][idx], data[1][idx]);
			idx = idx+1;
		}
		check = check-1; // decrease since it counts one extra
		fclose(fp); 
		double average; 
		average = ratings(data, check); // function call
		FILE *fp;
		fp= fopen("festival.txt", "a");
		fprintf(fp, "The average rating for Shift A is %lf, and the average rating for Shift B is %lf", average, average);
		fclose(fp);
		break;
	}
	default:
	{
		break;
	}
	
	
	}
	
	return 0;
}


double payment(int tix)
{
	double total = 0; // declare this inside function
	total = tix*33.0 + (1/5)*tix*33.0;
	return total; // return value
}


double ratings(double data[2], int cols)
{
	char times[1][cols]; 
	for (i=0; i<cols; i++)
	{
		if (data[0][i] >=3 && data[0][i] <7)
		{
			times[0][i] = 'A';
		}
		else 
		{
			times[0][i] = 'B';
			
		}
		
	}
	
	printf("Shift \t Rating\n");
	int totalrating = 0;
	double average; 
	for (i=0;i<cols;i++)
	{
		printf(" %c\t%lf", times[0][i], data[1][i]);
		totalrating = totalrating+ data[1][i]; 
		
	}
	
	average = totalrating+0.0/cols; 
	return average; 
}






