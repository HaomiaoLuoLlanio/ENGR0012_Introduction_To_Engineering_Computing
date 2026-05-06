#include <stdlib.h>
#include <math.h>
#include <stdio.h>
//function setups
int Payment(int ticket);
int Ratings(int Times[], int b[], int rows);


//the main function
int main()
{
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Finn Jensen, frj19");
	fclose(fp);
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);
	if(password != 5678)
	{
		printf("Inncorrect password. Bye!");
		return 1;
		
	}
	
	char input;
	while(1)
	{
		if(input != 'P' || input != 'R')
		{
			printf("Please enter the letter P for payment or the letter R for ratings\n");
			scanf("%c", &input);
		}
		if(input == 'P' || input == 'R')
		{
			break; //ensures that user types P or R
		}
	}
	switch(input)
	{
		//creates switch case with input
		case 'P':
		{
			int ticket =0;
			while(ticket<1)
			{
				printf("Please enter an integer value for the number of festival tickets you would like to purchase\n");
				scanf("%d", &ticket);
				int total = Payment(ticket);
				printf("Total payment is $$ %10.2d",total);
			}
		}
		case 'R':
		{
			FILE *fj;
			float filename;
			fj = fopen("filename", "r");
			while(fj == NULL && fopen != "saturday.txt")
			//checks for the right file
			{
				printf("Please enter a file name for music festival data\n");
				scanf("%f", &filename);
			}
			int rows;
			int max =100;
			float a[max], b[max];
			while(rows<max && fscanf(fp, "%f %f", &a, &b)==2)
			{
				//creates the number of rows
				rows++;
			}
			fclose(fj);
			average = Ratings(a,b, rows);
			FILE *fi
			fi = fopen("festival.txt" "a");
			fprintf(%d", average);
			fclose(fi);
			
		}
		
	}
		
	
	
	return 0;
}



//functions
int Ratings(int a[], int b[], int rows)
{
	char Times[rows];
	int average;
	printf("Shift \t Rating");
	for(int i=0; i<rows; i++)
	{
		if(a<7)
		{
			Times[i] = 'A';
			average[0]= average[0] + b[i];
		}
		if(a>=7)
		{
			Times[i] = 'B';
			average[1]= average[1] + b[i];
		}
		printf("%c \t %d", Times[i], b[i]);
		
	}
	average[0] = average[0]/rows;
	average[1] = average[1]/rows;
	return(average);
	
}

int Payment(int ticket)
{
	int total;
	total = ticket*33 + 1/5 *ticket*33;
	return(total);
}
