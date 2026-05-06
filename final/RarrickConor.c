

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Allows you do perform math functions
#include <string.h>

double Payment(int );   // Have to declaire functions above main 

int main(int argc, char **argv)
{
	FILE *festival.txt
	
	fopen(festival.txt, "w");
	
	if (festival.txt != NULL)  // If file does not exist it = NULL
	{
		printf("Current user: Conor Rarrick, crr150.\n");
		fclose(festival.txt);  // closes the file 
		
		int password;
		printf("Music Festival 2026. Enter your 4-digit password: ");
		scanf("%d", &password);
		
		if (password !=5678)
		{
			printf("\nIncorrect password. Bye!\n");
		}
		else 
		{
			char letter;
			printf("Enter the letter P for payment or R for ratings.\n");
			scanf( " %c", &letter);
			
		while (letter != 'P' && letter != 'R')
		{
			printf("Enter the letter P for payment or R for ratings.\n");
			scanf( " %c", &letter);
		
		}
	
	int num;
	
	switch (letter)
	{
		case 'P':
		printf("Enter an interger value for the number of tickets you would like to purchase: ");
			scanf( "%d", &num);
			
			while (num<0)
			{
			printf("Enter an interger value for the number of tickets you would like to purchase: ");
			scanf( "%d", &num);	
			}
	
	double t_cost;
	
	t_cost = Payment(num);
	
	printf("Total payment is $%10.2lf\n", t_cost);
	
	break;
	
	case 'R':
	
	FILE *fp
	char filename[50];
	
	printf("Enter a filename for your music festival data: \n");
	scanf("%s", &filename);
	fp=fopen(filename);
	
	while (fp == NULL) // Allows for error checking 
	{
		printf("Enter a filename for your music festival data: \n");
	scanf("%s", &filename);
	fp=fopen(filename);
		
	}
	
	float data1[][2];
	int check = 0;
	int idx = 0;
	while {check !=-1)
		{
			
			check = fscanf(fp, "%f %f", data1[idx][0], data1[idx][1]);
			idx = idx +1;
			
			
		}
	fclose(fp);
	int rows = idx-1;
	
	
	
	break;
	
	
	
	}
}
	
	return 0;
}


double Payment(int tickets)
{
	double cost;
	
	cost = (tickets*33) + ((1/5)*(tickets*33));
	
	return cost;
	
}

void Ratings(int rs, float data[][2])
{
	char Times[50];
	
	
	
}
