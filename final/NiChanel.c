#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Payment(int tickets)
double Ratings(int[][2]=,int)
int main()
{
	FILE *fp=fopen("festival.txt","w");
	fprintf(fp,"Current user: Chanel Ni, chn160");
	fclose(fp);
	int password;
	printf("Music Festival 2026. Enter 4 digit-password:");
	scanf("%s",password);
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");
	}else if (password = 5678)
	{
		char letter;
		printf("Enter the letter P for payment or the R for ratings:");
		scanf(" %c",&letter);
		while (letter != 'P' && letter != 'R')
		{
			printf("Enter the letter P for payment or the R for ratings:");
			scanf(" %c",&letter);
		}
		switch (letter)
		{
			case 'P':
			{
				int tickets;
				printf("Enter an integer value for the # of tickets you would like to buy:");
				scanf("%d",&tickets);
				while (tickets<=0)
				{
					printf("Enter an integer value for the # of tickets you would like to buy:");
					scanf("%d",&tickets);
				}
				int tickets;
				tickets1=Payment(tickets);
				printf("Total payment is $%10.2lf",total);
				break;
			}
			case 'R':
			{
				FILE *reader;
				char filename[100];
				printf("Enter a filename:\n");
				scanf("%s",filename);
				reader=fopen(filename,"r");
				while (reader == NULL)
				{
					printf("Enter a filename:\n");
					scanf("%s",filename);
					reader=fopen(filename,"r");
				}
				int status=0;
				int count=0;
				while (status != EOF)
				{
					status=fscanf(reader,"%d",data[count][2]);
					count++;
				}
				int rows;
				rows=count-1;
				fclose(reader);
				int average[][];
				average=Ratings(data,rows);
				FILE *append=fopen("festival.txt","a")
				fprintf(append,"The average rating for Shift A is %d and the average rating for Shift B is %d.",average[1][1],average[2][1]);
				fclose(append);
			}
	}
	return 0;
}
	int Payment(int tickets)
	{
		total=(tickets)*33+(1/5)*(tickets*33);
		return tickets;
	}
	double Ratings(data[][2],int rows)
	{
		char Times[][];
		int countA=0;
		int countB=0;
		double sumratingsA,sumratingsB;
		for (int i=0;i<rows;i++)
		{
			if (data[i][1]>=3 && data[i][1]<7)
			{
				Times[i][1]=A;
				countA++;
				sumratingsA=sumratingsA+data[i][2];
			}else if (data[i][1]>=7)
			{
				Times[i][1]=B;
				countB++;
				sumratingsB=sumratingsA+data[i][2];
			}
			sumratingsA=sumratings+data[i][2];
			printf("Shift\tTab\n");
			printf("%c\n",Times[i][1]);
			printf("%lf\n",data[i][2]);
		}
		int averageA,averageB;
		averageA=sumratingsA/countA;
		averageB=sumratingsB/countB;
		int average[2][1];
		average[1][1]=averageA;
		average[2][1]=averageB;
		return average;
	}

