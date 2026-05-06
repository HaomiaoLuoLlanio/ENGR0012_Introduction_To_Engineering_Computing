#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Payment(int);
int Ratings();


int main()
{
	FILE *fest;
	
	
	fclose(fest);
	
	int Password;
	printf("Mustic Festival 2026. Enter your 4-digit password: ");
	scanf(" %d",&Password);
	if(Password != 5678)
	{
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	char opt;
	printf("Enter P for payment or R for ratings: ");
	scanf(" %c", &opt);
	
	while(opt != 'P' && opt != 'R')
	{
		printf("Enter payment or ratings (P or R): ");
		scanf(" %c", &opt);
	}
	
	switch(opt)
	{
		case('P'):
		{
			int tickets;
			printf("How many festival tickets would you like to purchase? ");
			scanf(" %d",&tickets);
			while(tickets<=0)
			{
				printf("How many festival tickets would you like to purchase? ");
				scanf(" %d",&tickets);
			}
			double Total;
			Total = Payment(tickets);
			printf("Total payment is $%10.2lf.", Total);
			break;
		}
		case('R'):
		{
			FILE *fp;
			char filename[100];
			printf("Enter file name for music festival: ");
			scanf(" %s",filename);
			
			fp = fopen(filename,"r");
			while(filename == NULL)
			{
				printf("Enter file name for music festival: ");
				scanf(" %s",filename);
			}
			
			float array[100][2];
			int check = 0;
			int idx = 0;
			int col = 0;
			for(check == EOF)
			{
				for(col=0;col<2;col++)
				{
					array[idx][col] = fscanf(fp,"%lf %lf");
					idx = idx + 1;
					check++;
				}
			}
			fclose(fp);
			int r;
			
			r = Ratings();
			
			printf("");
			
			
			break;
		}
		default:
		{
			break;
		}
		
	}
	
	
	return 0;
}

double Payment(int x)
{
	double Total;
	Total = (x * 33) + ((1/5) * x);
	return Total;
}

int Ratings()
{
	char Times[100];
	double RatingA[100];
	double RatingB[100];
	double Aavg = 0;
	double Bavg = 0;
	
	for(int i=0;i++)
	{
		Aavg = Aavg + RatingA[i];
	}
	for()
	{
		
	}
	return 0;
}

