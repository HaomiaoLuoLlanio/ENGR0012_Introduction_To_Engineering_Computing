#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double payment(int ticketnum);
void ratings(float saturday[][2],int rows);
int main()
{
	FILE*fp;
	fp=fopen("festival.txt","w");
	fprintf(fp,"Current user: Jesse Njunge,jen158");
	fclose(fp);
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d",&password);
	if (password!=5678)
	{
		printf("Incorrect password.Bye!");
		return 1;
	}
		
		char choice;
	if (password==5678)//setting if statement
	{
		
		printf("\nEnterthe letter P for payment or the letter R for  ratings: ");
		scanf(" %c",&choice);
	}
	
	switch (choice)
	{
		case 'P':
		{
			int ticketnum;
			printf("Enter amount of tickets for purchase: \n");
			scanf("%d",&ticketnum);
			while (ticketnum<0)//error checking
			{
				printf("Enter amount of tickets for purchase: \n");
				scanf("%d",&ticketnum);
			}
			double total = payment(ticketnum);
			printf("Total payment is $$%10.2lf\n",total);
			break;
		}
		case 'R':
		{
			char filename[100];
			printf("Enter filename for festival data: ");
			scanf("%s",filename);
			FILE*point;
			point=fopen(filename,"r");
			while(fp!=NULL)
			{
				printf("Enter filename for festival data: ");
				scanf("%s",filename);
				point=fopen(filename,"r");
			}
			
			float saturday[50][2];
			int check=0;
			int idx=0;
			while(check!=EOF)
			{
				check=fscanf(point," %f %f",&saturday[idx][0],&saturday[idx][1]);
				idx++;
			}
			break;
			fclose(point);
			int rows=idx-1;
			 ratings(saturday,rows);
			
		}
		default:
		{
			break;
		}
	}
	
	
	
	
	
	return 0;
}



double payment(int ticketnum)//Making payment function
{
	double payment;
	payment = (ticketnum+0.0)*(33)+(1/5)*(ticketnum*33);
	return payment;
}


void ratings(float saturday[][2],int rows)//Making ratings function
{
	char Times[rows][2];
	for(int i=0;i<rows;i++)
	{
		if (saturday[i][0]>=3 && saturday[i][0]<=7)
		{
			Times[i][0]='A';
		}
		else if (saturday[i][0]>=7)//seperating times
		{
			Times[i][0]='B';
		}
		}
		printf("Shif\tRating");
		for(int i=0;i<rows;i++)
		{
			printf(" %c/t%f",Times[i][0],saturday[i][2]);
		}
		int Acount;
		int Bcount;
		for (int i=0; i<rows;i++)
		{
			if (Times[i][0]=='A')
			{
				Acount=Acount+1;
			}
			else
				
		}
		
}
	
	
	
	

