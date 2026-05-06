#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
double Payment(int );
void Ratings(int , double [][2]);

//Main
int main()
{
	FILE *fp;
	fp = fopen("festival.txt","w");
	fprintf(fp,"Current user: Ava Brinkerhoff, afb87");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d",&password);
	if (password!=5678)
	{
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	char selection;
	printf("Enter the letter P for payment or R for ratings: ");
	scanf(" %c",&selection);
	//Error checking
	while(selection!='P'&&selection!='R')
	{
		printf("Enter the letter P for payment or R for ratings: ");
		scanf(" %c",&selection);
	}
	
	int tickets;
	double cost;
	switch(selection)
	{
		case 'P':
		{
			printf("Enter an integer value for the number of tickets you would like to purchase: ");
			scanf("%d",&tickets);
			//Error checking
			while(tickets<0)
			{
				printf("Enter an integer value for the number of tickets you would like to purchase: ");
				scanf("%d",&tickets);
			}
			
			cost = Payment(tickets);
			printf("Total payment is $%.2lf",cost);
			break;
		}
		case 'R':
		{
			FILE *filenew;
			char filename[100];
			printf("Enter a file name for music festival data: ");
			scanf("%s",filename);
			filenew=fopen(filename,"r");
			//Error checking
			while(filenew==NULL)
			{
				printf("Enter a file name for music festival data: ");
				scanf("%s",filename);
				filenew=fopen(filename,"r");
			}
			
			double data[100][2];
			int idx,rows;
			for(idx=0;idx<=EOF;idx++)
			{
				fscanf(filenew,"%f %f",data[idx][0],data[idx][1]);
			}
			rows=idx-1;
			fclose(filenew);
			
			Ratings(rows,data[rows][2]);
			break;
		}
	}
	

return 0;	
}


//Functions

//Payment function for amount of tickets
double Payment(int num)
{
	double total;
	total = (num*33)+(1/5)*(num*33);
	return total;
}

//Ratings function
void Ratings(int row, double dataset[][2])
{
	char Times;
	float avg;
	printf("Shift\tRating");
	for(int i=0;i<=row+1;i++)
	{
		if(dataset[i][0]>=3&&dataset[i][0]<7)
		{
			Times='A';
		}
		if(dataset[i][0]>=7)
		{
			Times='B';
		}
		printf("%c\t%f",Times,dataset[i][1]);
	}
	return;
}



