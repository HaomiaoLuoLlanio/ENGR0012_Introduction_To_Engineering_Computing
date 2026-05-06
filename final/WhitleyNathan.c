#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototypes
double payment(int);
int ratings(double[][2],int);

//Main
int main()
{
	FILE *fp=fopen("festival.txt","w");
	fprintf(fp,"Current user: Nathan Whitley, naw198");
	fclose(fp);
	
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d",&pass); //correct is 5678
	if (pass!=5678){
		printf("\nIncorrect password. Bye!");
		return 1; //Ends program
	}
	
	char letter;
	do{
	printf("Enter P for payment or R for ratings: ");
	scanf(" %c",&letter);
	}while(letter!='P' && letter!='R'); //only allows P and R
	
	switch (letter)
	{
		case 'P':
		{
			int tickets;
			do{
			printf("/nEnter an integer value to correspond to the number of tickets you would like to purchase: ");
			scanf("%d",&tickets);
			}while(tickets<=0); //doesn't allow invalid condition, ensuring number is greater than zero
			//calling function payment
			double total=payment(tickets);
			printf("Total payment is $%10.2lf",total);
			break;
		}
		case 'R':
		{
			char filename[50];
			FILE *fp;
			do{
				printf("Enter a filename for your music festival data: "); 
				scanf("%s",filename); //use saturday.txt
				fp=fopen(filename,"r");
			}while(fp==NULL);
			
			int check=0,i=0;
			double data[50][2];
			while (check!=EOF)
			{
				check=fscanf(fp,"%lf %lf",&data[i][0],&data[i][1]);
				i++;
			}
			int rows=i-1;
			fclose(fp);
			
			//call function ratings
			int avg=ratings(data,rows);
			
			FILE *fp=fopen("festival.txt","a");
			fprintf(fp,"\nThe average rating for Shift A is ## and the average rating for Shift B is ##",##,##);
			fclose(fp);
			
			break;
		}
		default:
		{
			break;
		}
	}
	return 0;
}

//Functions
double payment(int tickets)
{
	double total=tickets*33.00+(1/5)*(tickets*33.00);
	return total;
}

void ratings(double data[][2],int rows)
{
	char Times[rows][1];
	
	for (int i=0;i<rows;i++)
	{
		if (data[i][0]<=3 || data[i][0]>7)
		{
			Times[i][0]='A';
		}
		else if (data[i][0]<=7)
		{
			Times[i][0]='B';
		}
	}
	printf("\nShift\tRating\n");
	int sum=0;
	for (i=0;i<rows;i++)
	{
		printf(" %c\t%lf\n",Times[i][0],data[i][1]);
		sum=sum+data[i][1];	
	}
	int avg=sum/rows;
	return avg;
	
	
}




