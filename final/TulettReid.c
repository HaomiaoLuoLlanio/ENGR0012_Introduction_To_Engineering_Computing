#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double payment(int);
void ratings(float[][2], int);

int main()
{
	// open a file and add your name Q1
	FILE *fp;
	fp = ("festival.txt", "w");
	
	fprintf(fp, "Current user: Reid Tulett, ret117");
	
	fclose(fp);
	
	
	// insert password Q2
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);
	
	
	char pr, filename[50];
	int tickets, checker = 0, idx, count;
	double cost;
	float arr[100][2], avgs[1][2];
	
	if (password == 5678)
	{
		printf("Please enter /'P/' for payment or /'R/' for ratings:\n");
		scanf(" %c", &pr);
		
		while (pr != 'P' || pr != 'R')
		{
			printf("Please enter /'P/' for payment or /'R/' for ratings:\n");
			scanf(" %c", &pr);
			
			switch (pr)
			{
				case 'P':
				{
					printf("Please enter the number of tickets you would like to purchace:\n");
					scanf("%d", &tickets);
					
					while (tickets <= 0)
					{
						printf("Please enter the number of tickets you would like to purchace:\n");
						scanf("%d", &tickets);
					}
					
					cost = payment(tickets);
					printf("Total payment is $%10.2lf\n", cost);
					
					break;
				}
				case 'R':
				{
					FILE *fp;
					printf("Please enter a filename:\n");
					scanf("%s", filename);
					fp = fopen(filename, "r");
					
					while (fp == NULL)
					{
						printf("Please enter a filename:\n");
						scanf("%s", filename);
						fp = fopen(filename, "r");	
					}
					
					while (checker == EOF)
					{
						fscanf(fp, "%f %f", &arr[idx][0], &arr[idx][1]);
						idx = idx + 1;
					}
					
					fclose(fp);
					count = idx - 1;
					
					// ratings function
					ratings(arr, count);
					
					fp = fopen("festival.txt", "a");
					
					fprintf(fp, "The average rating for Shift A is %f and the average rating for Shift B is %f\n", avgs[0][0], avgs[0][1]);
					
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
	else
	{
		printf("Incorrect password. Bye!\n");
		return 1;
	}
	
	
	return 0;
}

// payment function
double payment(int num)
{
	double total;
	
	total = num*33 + (1/5)*(num*33);
	
	return total;
}

// ratings function
void ratings(float data[][2], int rows)
{
	char times[50][2];
	float ratings_1, ratings_2, avg_1, avg_2;
	float avgs[1][2];
	int count_1, count_2;
	
	for (int i=0; i<rows; i++)
	{
		if (data[i][0] >= 3 && data[i][0] < 7)
		{
			times[i][0] = 'A';
			ratings_1 = ratings_1 + data[i][1];
			count_1 = count_1 + 1;
		}
		else if (data[i][0] >= 7)
		{
			times[i][0] = 'B';
			ratings_2 = ratings_2 + data[i][1];
			count_2 = count_2 + 1;
		}
	}
	
	printf("Shift\tRating");
	for (int j=0; j<rows; j++)
	{
		printf("%c\t%f", times[j][0], data[j][1]);
	}
	
	avg_1 = ratings_1 / count_1;
	avg_2 = ratings_2 / count_2;
	
	avgs[0][0] = avg_1;
	avgs[0][1] = avg_2;
}

