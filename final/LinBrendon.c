#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Brendon Lin
//Dr. Zhou
//Computer 20, Time: 1pm 4/23/2026

//This is my function prototype area
int Payment(int);
void Ratings (int rows,double arr[][2]);

int main()
{
	FILE *fp;
	fp = fopen("festival.txt","w");	
	fprintf(fp, "Current User: Brendon Lin, brl262");
	fclose(fp);	
	
	int password;	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", password); //password is 5678
	if(password != 5678){
	printf("\nIncorrect password. Bye\n");	
	}	
	else 
	{
		printf("Welcome user\n");	//just a landmark for me to see if I'm in	
		printf("PLease enter P for payment or R for ratings: ");
		char choice;
		scanf(" %c", choice);
		while (choice != 'R' || choice != 'P')
		{
			printf("PLease enter P for payment or R for ratings: ");	
			scanf(" %c", choice);
		}
		switch (choice)
		{
			case 'R': 
			{	
				FILE *fin;
				char filename[50];
				printf("Enter a file name for your music festival data.");
				//saturday.txt
				scanf("%s", filename);
				fin = fopen(filename, "r");
				while (fin == NULL)
				{
					printf("Enter a file name for your music festival data.");
					scanf("%s", filename);
					fin = fopen(filename, "r");
				}
				double arr[20][20]
				int check = 0;
				int idx = 0;
				while(check != EOF) //for EOF or -1
				{
					check = fscanf(fin,"%lf %lf", &arr[idx][0], &arr[idx][1]); //& updates my data within the array
					idx = idx + 1;
				}
				int rows;
				rows = idx - 1; //since idx will be plus 1 on rows, this cancels the inaccuracy.
				fclose(fin); //always close your files after you're done.
				Ratings (int rows,double arr[][2]);
			
			break;	
			}	
			case 'P':
			{
				int tickets;
				printf("please enter the number of tickets you'd like to purchase: ");
				scanf("%d",&tickets);
				if(tickets == 0)
				{
				printf("please enter the number of tickets you'd like to purchase: ");
				scanf("%d",&tickets);	
				}
				int total;
				total = Payment(tickets);
				printf("Total payment is $%10.2d", total);
			break;	
			}
		}
	}	
	return 0;
}

//Function Area
int Payment(int tickets)
{
	int total;
	total = ((tickets* 33) + ((1/5)*tickets*33));
	
	return total;
}

void Ratings (int rows,double arr[][2])
{
	printf("Shift\tRating");
	char Time[rows];
	int numA = 0;
	double sumA=0.0;
	double sumB=0.0;
	double TotalA;
	double TotalB;
	int numB = 0;
	
	for(int i = 0; i < rows; i ++) //this i is independant of the i in main
	{
		if(arr[i][0] >= 3 && arr[i][0] <= 7)
		{
			Time[i] = 'A';
			numA = numA +1;
			sumA = sumA + arr[i][1];
		}
		else
		{
			Time[i] = 'B';
			numB = numB + 1;
			sumB = sumB + arr[i][1];
		}
		printf("\n%c\t\t%lf", Time[i], arr[i][1]);
	}
	TotalA = sumA/numA + 0.0;
	TotalB = sumB/numB + 0.0;
	printf("\nTotal for A is %lf, Total for B is %lf", TotalA, TotalB);
	fopen('festival.txt','a'); //append
	fprintf("The average Total for A is %lf, Total for B is lf", TotalA, TotalB);
	fclose('festival.txt'); //This functions requires no output. All is done here.
}
