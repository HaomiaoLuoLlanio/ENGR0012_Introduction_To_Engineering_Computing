
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double Payment(int);
void Ratings(double[][2], int);


int main()
{
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Nico Comunale, njc134");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");
		return 1; //ending program here
	}
	
	char choice;
	printf("enter P for payment or R for ratings: ");
	scanf(" %c", &choice);
	
	while (choice != 'P' && choice != 'R') //Error checking
	{
	printf("enter P for payment or R for ratings: ");
	scanf(" %c", &choice);
	}
	
	switch (choice)
	{
	case 'P':
	{
		int tickets;
		printf("Enter a ineger value for how many tickets you would like to purchase: ");
		scanf("%d", &tickets);
		
		while (tickets < 1)
		{
		printf("Enter a ineger value for how many tickets you would like to purchase: ");
		scanf("%d", &tickets);
		}
		double total_main;
		total_main = Payment(tickets);
		
		printf("Total payment is $%10.2lf", total_main);
		break;
	}
	case 'R':
	{
		char filname[100];
		printf("Enter a file name for your music festival data: ");
		scanf("%s", &filename);
		
		FILE *fp2
		fp2 = fopen(filename, "r");
		
		while (filename == NULL) //error checking
		{
		printf("Enter a file name for your music festival data: ");
		scanf("%s", &filename);
		fp2 = fopen(filename, "r");
		}
		
		double arr[][2];
		int idx;
		for (i=1;i<100;i++)
		{
			if (arr[i][2] == EOF)
			{
				idx = idx + 1;
			}
		}
		int rows;
		rows = idx - 1;
		fclose(fp2);
		break;
	}
}

	average = Ratings(arr[][2],rows)

	printf("Enter a file name for your music festival data: ");
	scanf("%s", &filename);
	fp2 = fopen(filename, "w");
	
	fprintf(fp2, "The average rating for Shift A is %lf and the average raiting for Shift B is %lf", average, average);
	fclose(fp2);
	
	


	return 0;
}

double Payment(int ticks) 
{
	double total;
	total = (ticks*33 + (1/5)*(ticks*33)); //equation
	return total;
}

double Ratings(double sat[][2], int rows)
{
	char times;
	
	for (i=1;i<100;i++) //changing letter for specific time
	{
		if (sat[i][1] < 7)
		{
		times = 'A';
		}
		else
		{
		times = 'B';
		}
	}
printf("Shift\tRating"); //showing raiting and shift time
for (i=1;i<100;i++)
	{
		if (sat[i][1] < 7)
		{
		times = 'A';
		}
		else
		{
		times = 'B';
		}
		printf("%c\t%lf", times[i], sat[i][1]);
	}

return average;
}

