#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double payment(int);
double ratings(double [][2], int )

int main()
{
	FILE *fp;
	fp=fopen("festival.txt", "w");
	fprintf(fp, "Current user: Nathan Freed, nrf57");
	fclose(fp);
	
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pass);
	if (pass==5678)
	{
		char mode;
		printf("Enter P for payment or R for ratings ");
		scanf(" %c", &mode);
		while(mode!='P' && mode!='R')
		{
			printf("Enter P for payment or R for ratings ");
			scanf(" %c", &mode);
		}
		switch(mode)
		{
			case 'P':
			{
				int tickets;
				printf("How many tickets would you like to buy? ");
				scanf("%d", &tickets);
				while(tickets<=0)
				{
					printf("How many tickets would you like to buy? ");
					scanf("%d", &tickets);
				}
				double tot;
				tot=payment(tickets);
				printf("Total payment is $%10.2lf", tot);
				break;
			}
			case 'R':
			{
				FILE *fp2;
				char fname[50];
				printf("Enter a file name for your festival data: ");
				scanf("%s", fname);
				fp2=fopen(fname, "r");
				//while(fp2==NULL)
				//{
					//printf("Enter a file name for your festival data: ");
					//scanf("%s", fname);
					//fp2=fopen(fname, "r");
				//}
				double data[50][2];
				int choice;
				int idx;
				while(choice!=EOF) //checks for EOF
				{
					choice=fscanf(fp2, "%lf %lf", &data[idx][0], &data[idx][1]);
					idx++;
				}
				int rows=idx-1;
				fclose(fp2);
				double ratings(double data[][2], int rows)
				break;
			}
			default:
		}
	}
	else
	{
		printf("Incorect password. Bye!");
	}
	return 0;
}

double payment(int tick)
{
	int total=tick*33+0.2*tick*33;
	return total;
}

double ratings(double arr[][2], int rs)
{
	char Times[50];
	for(int i=0;i<rs;i++)
	{
		if(arr[i][0]>=3 && arr[i][0]<7)
		{
			Times[i]='A';
		}
		else
		{
			Times[i]='B';
		}
	}
	printf("Shift\tRating");
	for(int i=0;i<rs;i++)
	{
		printf("%c\t%lf", Times[i], arr[i][1]);
	}
	double avgA;
	double avgB;
	double sumA;
	double sumB;
	int countA=0;
	int countB=0;
	for(int i=0;i<rs;i++)
	{
		if (Times[i]=='A')
		{
			sumA=sumA+arr[i][1];
			cou
		}
		else
		{
			sumB=sumB+arr[i][1];
		}
	}
	avgA=sumA/countA;
	avgB=sumB/countB;
	return avgA;
	return avgB;
}
