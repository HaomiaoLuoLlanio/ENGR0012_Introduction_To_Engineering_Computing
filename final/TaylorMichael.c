
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double payment(int);
//reutrns a double

//the int is becasue thats the variable it requires
void ratings();
int main()
{
	FILE*fp;
	
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Michael Taylor, mtt69");
	fclose(fp);
	
	int password;
	char choice;
	int amount = 0;
	double totalPrice=0;
	
	
	char filename[100];
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d",password);
	if(password!=5678)
	{
		printf("Incorrect password. Bye!");
	}
	else
	{
	printf("enter the letter P for payment or R	for ratings");
	scanf(" %c",choice);
	
	while(choice!='P' || choice!='R')
	{
		printf("enter the letter P for payment or R	for ratings");
	scanf(" %c",&choice);
	}
	
	
	switch(choice)
	{
		case 'R':
		printf("Enter a filename: ");
		scanf("%s",filename);
		FILE*fp2;
		fp2 = fopen(filename,"r");
		while(fp2==NULL)
		{
			printf("Enter a filename: ");
		scanf("%s",filename);
		fp2 = fopen(filename,"r");
		}
		int check;
		float array[100][2];
		int idx=0;
		
		while(check!= EOF)
		{
			check = fscanf(fp2, "%f %f",array[idx][0],array[idx][1]);
			idx = idx+1;
			
		}
		fclose(fp2);
		
		void ratings();
		
		fp = fopen("festival.txt", "w");
	//	fprintf(fp
		
		
		
		
		break;
		
		case 'P':
		printf("how many festival tickets would you like to purchase?");
		scanf("%d",amount);
		while(amount==0)
		{
			printf("how many festival tickets would you like to purchase?");
		scanf("%d",amount);
		}
		totalPrice=payment(amount);
		//function call to a double
		
		printf("Total payment is $ %10.2lf",totalPrice);
		break;
		
		default:
		//just incase the switch doesn't work
		break;
		
	}
	
	
	
	
	
	}
	return 0;
}


//functions


//payment

double payment(int numTickets)
{
	double functionTotalPrice=0;
	
	functionTotalPrice= numTickets*33.00 + ((numTickets*33.00)/5);
	return functionTotalPrice;
}

//ratings

void ratings()
{
	char times[100][1];
	fp2 = fopen("saturday.txt","r");
	int checker=0;
	int rows;
	
	while(checker!= EOF)
		{
			check = fscanf(fp2," %c %c",times[rows][0],times[rows][1]);
			rows = rows+1;
		}
	
	for(int i=0;i<rows;i++)
	//the loop will run unitl there are no more rows
	{
		if(times[i][0]
	}
	
}
