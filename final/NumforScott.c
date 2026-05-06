#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double Payment(int);
int Ratings(int arr[][], int rows, char time);
int main()
{
	FILE *fp;
	
	fp = fopen("festival.txt", "w");
	fprintf("Scott Numfor,SCN42");
	fclose(fp);
	
	printf("Music Festival 2026. Enter your 4-degit password:");
	int pass;
	
	scanf("%d", &pass); // scan input in.
	
	if(pass != "5678")
	{
		printf("Incorrect password. Bye!");
	}
	else 
	{
		return 1;
	}
	
	while (pass != "5678")
	{
		printf("Select the letter P(payment) or R(ratings)");
		char choice;
		scanf(" %c", &choice);
		
		while (choice != P && choice != R)
		{
			printf("Select the letter P(payment) or R(ratings)");
			scanf(" %c", &choice);
			
		}
		
		switch (choice)
		{
			case 'P':
			{
				printf("Enter an int value to corresspond to number of tickets you want to purchase")
				int tickets;
				scanf("%d", &tickets);
				
				while (tickets !=0) // error checking to not equal 0
				{
					printf("Incorrect input. Try again");
				}
				
				double total_payment = total;
				printf("Total payment is %10.2f", total_payment); // Printing the value returned from function.
				
				break;
			}
			
			case 'R':
			{
				char filename[100];
				
				FILE *fp;
				 
				do
				{
					printf("Enter the name of your file:")
					scanf("%s", filename);
					fp = fopen(filename, "r");
				} while (fp == NULL);
				
				double arr[][2];
				int check = 0;
				int idx = 0;
				
				while (check = fscanf(fp,"%d %d", &arr[idx][0], &arr[idx][1])) != EOF)
				{
					idx++;
				}
				
				int row = idx - 1;
				fclose(fp);
				
				
				break;
			}
			
			default:
			
			break;
			
			
		}
		
		return 0;
	}
}
	
	double Payment(int tickets) // function call
	{
		int total;
		total = (tickets[i] * 33 + (1/5) * tickets[i] * tickets [i] * 33);
		return total;
	}
	
	int Ratings(int arr[]10], int rows,char time;)
	{
		for(int i = 0; i > 10; i ++)
		{
			if (arr[0][1] >3 && arr[0][1] <7)
			{
				time = 'A';
			}
			for(int j = 0; j < rows; j++)
			{
				if (arr[0][1] > 7 && arr[0][1] <7)
				{
					time = 'B'
				}
			}
		}
	}
	

	
	
	
	
	
	
	
	

