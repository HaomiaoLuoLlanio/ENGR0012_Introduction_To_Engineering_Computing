#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Payment(int tickets);
float Ratings(int arr[100][2], int count);

int main()
{
	FILE*fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Aiden Davern, agd110");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit passowrd: \n");
	scanf("%d", password);
	
	while(password != 5678)
	{
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	char choice;
	printf("enter the letter P for payment ot the letter R for ratings: ");
	scanf(" %c", &choice);
	while(choice != 'P' || choice != 'R')
	{
		printf("enter the letter P for payment ot the letter R for ratings: ");
		scanf(" %c", &choice);
	}
	
	switch(choice)
	{
		case 'P':
		{
			int tickets;
			printf("Enter an integer value for number of festival tickets: ");
			scanf("%d", tickets);
			while(tickets < 0)
			{
				printf("Enter an integer value for number of festival tickets: ");
				scanf("%d", tickets);
			}
			
			int total = Payment(tickets);
			printf("Total payment is $%10.2d", total);
			
			break;
		}
		case 'R':
		{
			char fname[50];
			printf("enter a filename for music festical data: ");
			scanf("%s", fname);
			FILE *out = fopen(fname, "r");
			while(out == NULL)
			{
				printf("enter a filename for music festical data: ");
				scanf("%s", fname);
				out = fopen(fname, "r");
			}
			int idx = 0;
			int data[100][2];
			while(fscanf(out, "%d %d", &data[idx][0], &data[idx][1]) != EOF)
			{
				idx++;
			}
			
			
			fclose(out);
			float avga = Ratings(arr[100][2], count);
			fopen(out, "a");
			fprintf(out, "The average rating for shidt A is %f and the average rating for shift B is ##", avga);
			fclose(out);
			
			break;
		}
		default:
		{
			break;
		}
	}
	
	return 0;
}
int Payment(int tickets)
{
	int total;
	total = tickets*33 + (1/5)*(tickets*33);
	return total;
}

float Ratings(int arr[100][2], int count)
{
	char times[100][1];
	printf("\nShift\tRating");
	for(int i=0;i<count;i++)
	{
		if(arr[i][0]>= 3 && arr[i][0] < 7)
		{
			times[i] = 'A';
		}
		if(arr[i][0] > 7)
		{
			times[i] = 'B';
		}
		printf("%c\t%f", times[i], arr[i][1]);
	}
	return avga;
	
	
}
