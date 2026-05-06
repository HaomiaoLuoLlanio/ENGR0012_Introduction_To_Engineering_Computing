#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double payment(int)//function prototype
float [2] ratings(float [][2], int)

int main()
{
FILE *fp;
fp =fopen("festival.txt","w");
fprintf(fp,"Current User: Jack Glover,jag684");
fclose(fp);
int password;
printf("Music Festival 2026. Enter yoyr 4-digit password: ");
scanf("%d", &password);
if (password != 5678)
{
	printf("Incorrect password. Bye!");
}
else
{
	char choice;
	printf("Enter the letter P for payment or R for ratings\n");
	scanf(" %c", &choice);
	if (choice != 'P' && choice != 'R')
	{
		printf("Enter the letter P for payment or R for ratings: ");
		scanf(" %c", &choice);
	}
	switch (choice)//switch case for options from user input
	{
		case 'P':
		{
			int tickets;
			printf("Enter an integer value that corresponds to the number of festival tickets you would like to purhase: ");
			scanf("%d", &tickets);
			if (tickets <=0)
			{
				printf("Enter an integer value that corresponds to the number of festival tickets you would like to purhase: ");
				scanf("%d", &tickets);
				float total;
				total = payment(tickets);
				printf("Total payment is $%10.2lf", total);
			}
			break;
		}
		case 'R':
		{
			char filename[50];
			printf("\nPlease enter a filename for the musical festival data: ");
			scanf("%s", filename);
			FILE *fop;
			fop = fopen(filename, "r");
			if (filename == NULL)
			{
			printf("\nPlease enter a filename for the musical festival data: ");
			scanf("%s", filename);
			FILE *fop;
			fop = fopen(filename, "r");	//calls function
			}
			int i =0;
			float data[50][2];
			while(1)
			{
				fscanf(fop, "%lf %lf", data[i][0], data[i][1]);
				if (EOF == 0)//ends when at the end of file
				{
					break;
				}
				i=i+1;
				
			}
			int rows = i-1;
			fclose(fop);
			
			avg[2] = ratings(data[][2], rows)
			FILE *foop;
			foop = fopen("festival.txt", "a");
			fprintf(foop, "The average rating for SHift A is %lf and the average rating for Shift B is %lf", avg[0], avg[1]);
			
			break;
		}
		default:
		{
			break;
		}
		
		
		
	}
}



return 0;
}


float payment(int tickets)
{
	float total;
	total = (tickets+0.0)*33;
	total = total+ total/5;
	return total;
	
}
float avg[2] ratings(float data[][2], int rows)
{
	char Times[50]
	for (int ii=0; ii<rows; ii++)
	{
		if (data[ii][0]>=3 && data[ii][0]<7)
		{
			Times[ii] = 'A';
		}
		else
		{
			Times[ii] = 'B';
		}
	}
	
	printf("Shift\tRating");
	for (int ii=0; ii<rows; ii++)
	{
		printf("%c\t%.6lf\n", Times[ii], data[ii][0]);
	}
	double avgB;
	double avgA;
	int countA=0;
	int countB=0;
	for (int ii=0; ii<rows; ii++)
	{
		if (data[ii][0]>=3 && data[ii][0]<7)
		{
			avgA = avgA + data[ii][0];
			countA = countA+1;
		}
		else
		{
			avgB = avgB + data[ii][0];
			countB = countB+1;
		}
	}
	avgA = avgA/countA;
	avgB = avgB/countB;
	float avg[2] = {avgA, avgB};
	return avg[2];
}
