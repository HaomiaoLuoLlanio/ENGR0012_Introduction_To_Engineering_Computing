
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Payment(int);
char Ratings(time)



int main()
{
	
	FILE*fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Nishma Ghimire, ngs49");
	fclose(fp);
	
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d", &password);
	
	while (password != 5678)
	{
		printf("Incorrect password. Bye!");
		break;
	}
char usr_choice;
	
	if (password == 5678)
	{
		
		
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &usr_choice);
		
		while (usr_choice != 'P' && usr_choice!='R')//error checking that user choice is only P or R
		{
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &usr_choice);			
		}
		
	}
	
	switch (usr_choice)
	{
		case 'P':
		{
			int tickets;
			printf("Enter an integer value to correspond to number of festival tickets: ");
			scanf("%d", &tickets);
			
			while (tickets < 0)//error checking that tickets can't be below 0
			{
			printf("Enter an integer value to correspond to number of festival tickets: ");
			scanf("%d", &tickets);				
			}
			
			float = total;
			total = Payment(tickets);
			printf("Total payment is %10.2lf", total);
				
			break;		
		}
		
		case 'R':
		{
			char file[100];
			printf("Enter a filename for music festival data: ");//Asking user to enter filename
			scanf("%s", file);
			
			while (file == NULL) //If no file name is given, it asks again and again until satisfied
			{
			printf("Enter a filename for music festival data: ");
			scanf("%s", file);					
			}
			
			float data[idx][2];
			check = 0;
			int idx = 0;
			
			FILE *fp;
			fp = fopen("saturday.txt", "r");//opening saturday.txt in order to read
			

			while (check !=EOF)
			{
				check = fscanf(fp, "%lf %lf", &data[idx][0], &data[idx][1]);
				idx = idx +1		
				
			}
			fclose(fp);
			
			Times[idx][1]
			times = Ratings(time);
			break;
		
		}
		
		default:
		{
			break;
		}
		
	}
	
	
	
	
	
	return 0;
}



float Payment(int ticket)
{
	float total;
	total = (ticket)*33+(1/5)*(ticket*33);
return total;
	
	
}


char Ratings(time)
{
	char times[i][j];
	idx = 0;
	float startTime;
	for (i = 0; i<idx; i++)
	{
		startTime=[i][j];
	if (startTime >=3 && startTime<7)
	{
		
		char letter = 'A';
	else
	char letter = 'B';
	

	}
	printf("Shift \t Rating");
	printf("%c %c", times);
	
	float avg;
	return times;
{
	
	
	
}













