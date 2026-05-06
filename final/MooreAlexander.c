#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double payment(int);

int main()
{
	FILE*fp;
	fp = fopen("Fistival.txt"); // 'w' to overwrite if something is already in the file
	fprintf(fp,"Current user: Alexander Moore, AIM111\n", 'w');
	fclose(fp); // closes file
	
	int passwrd;
	printf("Music festival 2026. Enter your 4-digit password: ");
	scanf("%d", &passwrd);
	
	if (passwrd == 5678)
	{
		char usr_choice;
		printf("enter P for payment or R for ratings");
		scanf(" %c", &usr_choice);
		
		while(usr_choice != 'P' && usr_choice != 'R') // loops untill P or R is choosen
		{
			printf("enter P for payment or R for ratings:");
			scanf(" %c", &usr_choice);
		}
	}
	else
	{
		printf("Incorrect password. Bye!");
		return 0; // ends program if invalid password is used
	}
	
	switch(usr_choice)
	{
		case: 'P'
		{
			int tickets;
			printf("How many tickets would you like to buy?: ");
			scanf("%d", &tickets);
			
			while(tickets < 0)
			{
				printf("How many tickets would you like to buy?: ");
				scanf("%d", &tickets);
			}
			
			double amount;
			amount = payment(tickets);
			printf("Total payment is $10.2lf", payment);
			
			break;
		}
		case: 'R'
		{
			FILE*fp2;
			char filename[50]
			
			printf("Enter filename: ");
			scanf("%s", filename);
			fp = fopen("filename",'r')
			
			while(filename == NULL)
			{
				printf("Enter filename: ");
				scanf("%s", filename);
				fp = fopen("filename",'r')
			}
			
			float data[][2];
			int check;
			int idx;
			
			while(check != EOF) // scans till end of file
			{
				check = fscanf(fp2, "%f %f", &data[][0], &data[][1]);
				idx++
			}
			int rows = idx - 1; 
			fclose(fp2); // closes file
			
			rating(data[][2], rows);
			
			FILE*fp;
			fp = fopen("Fistival.txt");
			
			break;
		}
		default:
		{
			break;
		}
	}
		
	
	
	return 0;
}


double payment(int numT)
{
	double total;
	
	total = numT * 33 +(1/5) * (numT * 33);
	
	return total;
}

void rating(float arr[][2], int rs)
{
	char times[][2];
	printf("Shift\tRating\n");
	
	for(int i = 0; i < rs; i++)
	{
		if(arr[i][2] > 3 && arr[i][2] < 7)
		{
			times[i][2] = 'A'
		}
		else
		{
			times[i][2] = 'B'
		}
		printf(" %c %f\n", times[i][2], arr[i][2]);
	}
	
	float aveA;
	float aveB;
	
	for(int i = 0; i < rs; i++)
	{
	
	
	
}
