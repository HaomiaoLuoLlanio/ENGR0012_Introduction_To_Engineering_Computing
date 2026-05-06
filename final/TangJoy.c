#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Payment(int)
int Ratings(int)

int main()
{
	//First file
	
	FILE *fp;
	
	fp=fopen("festival.txt","w");
	fprintf(fp,"Current user: Joy Tang, JOT168");
	fclose(fp);
	
	//Input password
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password == 5678)
	{
		//choices
		char choice;
		printf("\nEnter P for payment or R for ratings: ");
		scanf(" %c",&choice);
		
		if (choice!='P' && choice!='R')
		{
			printf("Enter P for payment or R for ratings");
			scanf("%c",&choice);
		}
		//Branch into choices	
		switch (choice)
		{
			case 'P':
			{
				int tickets;
				printf("Enter amount of tickets you want to purchase");
				scanf("%d",tickets);
				if (tickets<=0)
				{
					printf("Enter amount of tickets you want to purchase");
					scanf("%d",tickets);
				}
				double price;
				price=Payment(tickets);
				printf("Total payment is $%10.2lf", price);
					
				
				break;
			}
			case 'R':
			{
				FILE *file;
				printf("Enter a filename for your music festival data");
				scanf("%s",&filename)
				file=fopen("filename","r");
				
				if (file==NULL)
				{
					printf("Enter a filename for your music festival data");
					scanf("%s",&filename)
					file=fopen("filename","r");
				}
				int i=0 j=0;
				int rows=0;
				float arr[][];
				if (file!=EOF)
				{
					for (int i=0; i<10;i++)
					{
						for (int j=0; j<2;j++)
						{
							arr[][]=arr[i][j];
						}
					}
					rows=i-1;		
				}
				
				
					
					
				break;
			}
	}
}
	else 
	{
		printf("Incorrect password. Bye!");
	}
	
	
	
	return 0;
}
//First function

double Payment(int tic)
{
	double total;
	total=tic*33+(1/5)*(tic*33);
	return total;
}

//Second function
int Ratings(int)
{
	int times[100];
}
	
	
	
