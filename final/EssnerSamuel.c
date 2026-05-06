#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Payment(int);
double Ratings(double[][2], int);
int main()
{
	FILE *fout;
	fout = "festival.txt";
	fout = fopen(festival.txt, "w");
	fprintf(fout, "Current use: Samuel Essner, swe46");
	fclose(fout);
	
	int password = 0;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect pawwsord. Bye!");
	}
	
	char choice; 
	printf("Enter P or R: ");
	scanf(" %c", &choice);
	
	while (choice != 'P' && choice != 'R')
	{
		printf("Enter P or R: ");
		scanf(" %c", &choice);
	}
	
	switch (choice)
	{
	case 'P':
		int numTickets;
		printf("Enter the number of tickets to buy: ");
		scanf("%d", &numTickets);
		
		while (numTickets < 1)
		{
			printf("Enter the number of tickets to buy: ");
			scanf("%d", &numTickets);
		}
		
		double price;
		price = Payment(numTickets);
		
		printf("Total payment is $$ 10.2lf", price);
		
		
		
		break;
	
	case 'R':
	
	char filename[100];
		FILE *fp;
		printf("Enter a filename for music festival data: ");
		scanf(" %s", filename);
		fp = fopen(filename, "w");
		
		while (fp == NULL)
		{
			printf("Enter a filename for music festival data: ");
			scanf(" %s", filename);
			fp = fopen(filename, "w");
		}
		
		double data[100][2];
		int check; 
		int idx;
		int rows;
		while (check != EOF)
		{
		check = fscanf(fp, "%lf %lf", &data[idx][0], &data[idx][1]);
		idx = idx + 1;
		}
		rows = idx - 1;

	double AvgR;
	AvgR = Ratings(data, rows);
	
	FILE *fout;
	fout = "festival.txt";
	fout = fopen(festival.txt, "a");
	fprintf(fout, "The average raing for is: %lf", AvgR);
	fclose(fout);
	
	
	break;
	
	
	
	default:
	break;
}

	return 0;
}

double Payment(int tickets)
{
	int total = (tickets + 0.0)*33 + (1/5)*(tickets*33);
	return total;
	
}


double Ratings(double dataR[][2], int rowsR)
{
	char times[rowsR];
	
	for (int i = 0; i<rowsR; i++)
	{
		if (dataR[i][0] >= 3 && dataR[i][0] <= 7)
		{
		times[i] = 'A'; 
	}
	else 
	{
	times[i] = 'B';
	}
	}
	printf("Shift\tRating");
	
	for (int i = 0; i<rowsR; i++)
	{
	printf(" %c\t%lf", times[i], dataR[i][1]);
}

double avg;
double ratingsum;
for (int i = 0; i<rowsR; i++)
{
	ratingsum = ratingsum + dataR[i][1];
}

avg = ratingsum/rowsR;

return avg;
}
