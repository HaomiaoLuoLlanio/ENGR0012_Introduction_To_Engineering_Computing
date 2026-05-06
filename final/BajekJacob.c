#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



double Payment(int, int);
void Ratings(char[][], char[], int, int, int);

int main()
{
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp ,"Current user: Jacob Bajek, JAB1039\n");
	fclose(fp);
	
	
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", pass);
	
	if (pass != 5678)
	{
		printf("Incorrect password. Bye!\n");
		return 1;
	}
	
	char PR;
	printf("Enter P for payment or R for Ratings: ");
	scanf(" %ch", PR);
	
	while (PR != P && PR != R)
	{
		printf("Enter P for payment or R for Ratings: ");
		scanf(" %ch", PR);
	}
	
	
	int tcount;
	double pay;
	char filename[100];
	float arr[50][2];
	double avgA;
	double avgB;
	
	switch (PR)
	case P:
	{
		printf("How many tickets: ")
		scanf("%d", tcount);
		
		while (tcount <= 0)
		{
		printf("How many tickets: ")
		scanf("%d", tcount);			
		}
		
		pay = Payment(tcount, p);	// calling function Payment
		
		printf("Total payment is $%10.2lf", pay);
		break;
	}
	
	case R:
	{
		printf("Please enter a filename: ");
		scanf("%s", &filename);
		
		while (filename == NULL)
		{
			printf("Please enter a filename: ");
			scanf("%s", &filename);			
		}
		
		FILE *f2;		
		f2 = fopen(filename, "r");				// opens filename as a read
		
		while (int j = 0, j =! EOF, j++)
		{
			scanf("%lf %lf", &arr[
		}
		
		
		
		fclose(filename);
		
		Ratings()					//calls function Ratings
		
		
		FILE *f3;
		f3 = fopen("festival.txt", "a");
		fprintf = (f3, "The average rating for Shift A is ##, and the average rating for Shift B is ##", avgA, avgB);
		
		fclose(f3);
		
		break;
	}
	default:
	{
		break;
	}
	
	
	return 0;
}


double Payment(int t, double p)
{
	p = (t+0.00)*33 + (1/5)*((t+0.00)*33);
}


void Ratings(char Times[][], char array[], int rows, int aA, int aB)
{
	while (int i = 0, i<rows, i++)
	{
		Times[1][i] = 
	}
	
	Times[1][1] = 'Shift';
	Times[1][2] = 'Rating';
	
}



