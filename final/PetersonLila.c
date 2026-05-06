#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double Payment(double); //function prototype
void Ratings(float[][2], int, float[2]);






int main()
{
	
	FILE*fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current User: Lila Peterson, lgp47");
	fclose(fp);
	
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!"); //check is correct password
		
	}
	else //if password is correct
	{
		char payrat;
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &payrat);
		
		while (payrat != 'P' && payrat != 'R')
		{
			printf("Enter P for payment or R for ratings: ");
			scanf(" %c", &payrat);
		}
		
		switch (payrat) //distinguish between pay or rating
		{
		
		case 'P':
		{
			double tickets;
			printf("\nHow many tickets would you like to purchase: ");
			scanf("%lf", &tickets);
			
			while (tickets <= 0)
			{
				printf("\nHow many tickets would you like to purchase: ");
				scanf("%lf", &tickets);
				
			}
			
			double cost;
			cost = Payment(tickets);
			
			printf("\nTotal Payment is $%10.2lf", cost);
			
			
			
		break;
		}
		case 'R':
		{
			
			char filename[100];
			printf("\nEnter a filename for your data: ");
			scanf("%s", filename);
			
			FILE*fp;
			fp = fopen(filename, "r");
			
			while (fp == NULL)
			{
				printf("\nEnter a filename for your data: ");
			scanf("%s", filename);
				fp = fopen(filename, "r");
			}
			
			float data[200][2];
			int i = 0;
			
			while(fscanf(fp, "%f %f", &data[i][0], &data[i][1]) != EOF)
			{
					i = i+1;
			}
			
			int rows = i;
			fclose(fp);
			
			float average[2];
			Ratings(data,rows,average);
			
			FILE*pointer;
			pointer=fopen("festival.txt", "a");
			
			fprintf(pointer, "The average rating for Shift A is %f and the average rating for Shift B is %f", average[0], average[1]);
			fclose(fp);
			
			
			break;
		}
		default:
		{
			break;
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}


double Payment(double tickets) 
{
	double cost = 0;
	
	cost = (tickets*(33.00))+((1/5)*(tickets*(33.00)));
	
	return cost; // return cost to main
	
}


void Ratings( float data[][2], int rows, float average[2]) //data is returned to main through arrays
{
	
	char Times[100];
	
	for(int i = 0; i < rows; i++)
	{
		if (data[i][0] >= 3 && data[i][0] < 7)
		{
			Times[i]='A';
		}
		else if (data[i][0] >= 7)
		{
			Times[i]='B';
			
		}
	}
		
		printf("\nShift\tRating");
		for (int i = 0; i < rows; i++)
		{
			
			printf("\n%c\t%f", Times[i], data[i][1]);
		}
		
		float Aavg = 0;
		float Acount = 0;
		float Bavg = 0;
		float Bcount = 0;
		for (int i = 0; i < rows; i++)
		{
			
			if (Times[i] == 'A')
			{
				
				Aavg = Aavg + data[i][1];
				Acount = Acount + 1;
				
			}
			else
			{
				
				Bavg = Bavg + data[i][1];
				Bcount = Bcount + 1;
				
			}
			
		}
		
		Aavg = Aavg/Acount;
		Bavg = Bavg/Bcount;
	
	
	average[0] = Aavg;
	average[1] = Bavg;
	
	
	
	
}













