#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prtotype
double Payment(int);
void(int, double[2], int[][2])



int main()
{
	FILE * fp;
	fp = fopen("festival.txt","w");
	fprintf(fp,"Current user: Austin Michael, ajm659");
	fclose(fp);
	
	int password;
	
	printf("Music Festival 2026. Enter you 4 digit password: ");
	scanf("%d", &password);
	
	if(password == 5678) // password attempt 
	{
		char choice;
		
		printf("Choose P for payment or R for ratings");
		scanf(" %c", &choice);
		
		while(choice != 'R' && choice!= 'P') //choic checking 
		{
			printf("Choose P for payment or R for ratings");
			scanf(" %c", &choice);
		}
		
		switch (choice)
		{
			case 'P':
			{
				int tickets;
				printf("How many tickets would you like: ");
				scanf("%d", &tickets);
				
				while(tickets<0)
				{
					printf("How many tickets would you like: ");
					scanf("%d", &tickets);
				
				}
				
				double total = Payment(tickets);
				
				printf("Total payment is $%10.2lf", total);
				
			}
			
			case 'R':
			{
				FILE * fp;
				char filename[50]; // file check 
				
				printf("Please enter a filename: ");
				scanf(" %c", &filename[50]);
				fp = fopen(filename, "r");
				
				while(fp == NULL)
				{
					printf("Please enter a filename: ");
					scanf(" %c", &filename[50]);
					fp = fopen(filename, "r");
				}
				
				int data[100][2];
				int check=0;
				int row=0;
				int times[2];
				while(check != EOF)
				{
					check = fscanf(fp,"%d %d", &data[row][0], &data[row][1]); // scan file 
					row = row +1;
				}
				row = row-1; // rows - 1
				
				fclose(fp);
				
				
			}
			
			void(row, times[2], data[][2]);
			
			FILE * fp;
			
			fp = fopen("festival.txt",'a'); // appened file 
			fprintf(fp, " The averge rating Shift A is %lf and shift B is %lf", times[0],times[1]);
			
		}
		
		
		
	}
	else
	{
		printf("Incorrect password. Bye!");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

// Functions

double Payment(int tickets)
{
	double total;
	
	total = (tickets*33) + (1/5) *(tickets * 33);
	
	return total;
}

void(int row, double times[2], int data[][2])
{
	
	int countA
	int countB
	double rateA
	double rateB
	
	for (i = 0; i < row; i++)
	{
		if(data[i][0] >= 3 && data[i][0]<7);
		{
			times[0]='A';
			times[1]= data[i][0];
			rateA= rateA + data[i][0];
			countA++
		}
		else
		{
			times[0]='B';
			times[1]= data[i][0];
			countB++
			rateB= rateB + data[i][0];
		}
		
		
	}
	
	printf(" Shift/t Rating");
	
	
	
	for (i = 0; i < row; i++)
	{
		printf(" %c /t %d", times[0] ,times[1]);
	}
	
	times[0]= rateA/countA;
	times[1]= rateB/countB
	
	return times[2];
}









