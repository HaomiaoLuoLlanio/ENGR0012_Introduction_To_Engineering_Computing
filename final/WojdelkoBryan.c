#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Payment(int tickets);
void Ratings(float data [][COLS], int rows, double *avgA, double *avgB);

int main()
{
	FILE *fp;
	char name[] = "your name"
	char id[] = "yourID";
	
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: %s, %s\n", name, id);
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password !=5678)
	{
		printf("Incorrect password. Bye!")
	}
	
	
	char choice;
	do
	{
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &choice);
		choice = toupper(choice);
	}while (choice != 'P' && choice != 'R');
	
	if (choice == 'P')
	{
		printf("Enter the number of tickets: ");
		scanf("%d", &tickets);
		
		total = payment(tickets);
		printf("Total payment is %10.2f\n", total);
	}
	else if(choice == 'R')
	{
		while(1)
		{printf("Enter file name: ");
			scanf("%s", filename);
			
			file = fopen(filename, "r");
			
			if (file != NULL)
			break;
			
			printf("Error opening file. Try again");
		}
		while (fscanf(file, "%f %f", &data[rows][0], &data[rows][1]) == 2){
			
		}
	return 0;
}
