#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

float Payment (int);
void Ratings(double[], double[], double[2], int);

int main()
{
	FILE *Pointer;
	Pointer = fopen("festival.txt","w");
	fprintf(Pointer,"Current user: Chris Clineff, cjc331"); //Prints out my user info to document
	fclose(Pointer);
	
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf(" %d",&pass);
	if (pass != 5678)
	{
		printf("\nIncorrect password. Bye!"); //states output and ends the program, as everything else is inside the else loop
	}
	else
	{
		char check;
		do{
		printf("\n\nEnter P for payment or R for Ratings\n");
		scanf(" %c",&check);
		}while (check != 'P' && check != 'R');
		
		FILE *reader;  //instantiates a new file pointer variable for the next sequence
		
		switch (check)
		{
			case ('P'):
			int tickets;
			printf("\n\nPlease enter integer value for number of festival tickets they would like to purchase.");
			do{
			scanf("%d",&tickets);
			}while(tickets <= 0);
			
			float total;
			total = Payment(tickets);
			
			printf("Total payment is $10.2%f",total);
			
			break;
			case ('R'):
			char filename[50]; //creates a filename array to contain the file name from user
			do{
			printf("\nEnter file name:\n");
			scanf(" %s",filename);
			reader = fopen(filename,"r");
			}while (reader == NULL);
			
			double ratings[100];
			double times[100];
			double checker;
			int count = 0;
			
			while(1)
			{
				checker = fscanf(reader,"%lf",&times[count]);
				if (checker == EOF)
				{			
					break;
				}
				fscanf(reader,"%lf",&ratings[count]);  //reads in the 2nd column from Saturday.txt document
				count++;			
			}
			fclose(reader);
			
			double edit[2];
			Ratings(times,ratings,edit,count);
			
			Pointer = fopen("festival.txt","a");
			fprintf(Pointer,"\n\nThe average rating for Shift A is %f and the average rating for Shift B is %f",edit[0],edit[1]);		
			break;
			default:			
		}
	}
	
	
	
	return 0;
}

float Payment(int tickets)
{
	float total;
	float ticket = tickets;
	total = ticket*33.0 + 0.2*(ticket*33.0);
	return total;
}

void Ratings(double times[], double ratings[], double edit[2], int count)
{
	char Times[count];
	int A = 0;
	int B = 0;
	float Asum = 0;
	float Bsum = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (times[i] >= 3 && times[i] < 7)
		{
			Times[i] = 'A';
			A++;
			Asum = Asum + ratings[i];
		}
		else
		{
			Times[i] = 'B';
			B++;
			Bsum = Bsum + ratings[i];
		}
	}
	printf("\nShift\tRating\n");
	for (int x = 0; x < count; x++)
	{
		printf("%c\t%f\n",Times[x],ratings[x]);
	}
	edit[0] = Asum / A;
	edit[1] = Bsum / B;
}
