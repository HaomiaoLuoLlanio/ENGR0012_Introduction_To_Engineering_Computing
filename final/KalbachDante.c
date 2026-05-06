#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE *fp
	int filename;
	fp = fopen(filename, "w");
	printf("Current user: Dante Kalbach,DAK436\n");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	if (password = 5678)
	{
		char P, R;
		printf("Please enter P for payment or R for ratings: ");
		scanf("%c", &P);
		scanf("%c", &R);
		while (char != 'R' || char != 'P') //error checking to make sure they enter R or P
		{
		printf("Please enter P for payment or R for ratings: ");
		scanf("%c", &P);
		scanf("%c", &R);
		}
		switch (char)
		{
			{
			case 'P':
			int tickets;
			printf("Please enter how many tickets would like to purchase: ");
			scanf("%d",tickets);
			while (tickets < 0)
			{
			printf("Please enter how many tickets would like to purchase: ");
			scanf("%d", &tickets);
			int Pay
			Pay = Payment(tickets); // calling the Payment function and equaling it to the integar Pay
			printf("Total payment is $%10.2lf", Pay);
			}
			break:
			}
			{
			case 'R':
			{
			FILE *fp
			int filename;
			printf("Enter a filename for your music festival data: ");
			scanf("%s", &filename);
			fp = fopen(filename, "r");
			while (fp == NULL)
			{
			printf("Enter a filename for your music festival data: ");
			scanf("%s", &filename);
			fp = fopen(filename, "r");	
			}
			float file[idx][2];
			int count = 0;
			int idx = 0;
			while(fp != EOF) 
			{
				fscanf("%d %d", file[idx][0], file[idx][1]); //trying to use idx as a count for how many rows are in the file by counting up by one during the EOF loop.
				idx = idx + 1;
			}
			fclose(fp)
			int ShiftA_avg
			int ShiftB_avg
			Ratings(ShiftA_avg, ShiftB_avg);
			FILE *fp
			int filename;
			fp = fopen(filename, "w");
			printf("The average rating for Shift A is %lf and the average rating for Shift B is %lf.", ShiftA_avg, ShiftB_avg);
			fclose(fp);
			}
			break;
			}
			{
			default:
			{	
			}
			break;
			}
		}
	}
	else
	{
		printf("Incorrect password. Bye!");
	}

	return 0;
}

void Payment(Tickets)
{
	int Total;
	Total = Tickets * 33 + (1/5) * (Tickets * 33); // Getting total of ticket price
}

void Ratings(ShiftA_avg, ShiftB_avg)
{
	int i = 0;
	char Times[i];
	while (Times[i] < idx, i++)
	{
		if ()
		{
			Times[i] = 'A';
		}
		else
		{
			Times[i] = 'B';
		}
	}
	printf("Shift \t Ratings");
	while (i=0, Times[i] < idx, i++)
	{
		print("%c \t %lf", Times[i], Times[i]);
	}
	ShiftA_avg = Times[i]/idx;
	ShiftB_avg = Times[i]/idx;
}
