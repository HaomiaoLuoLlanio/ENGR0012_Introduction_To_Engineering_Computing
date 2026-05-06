#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// function prototypes

double Payment(int);
double Ratings(double, int);



int main()
{
	
	FILE *outputfile;
	
	outputfile = fopen("festival.txt", "w");
	fprintf(outputfile, "\nCurrent User: Andrew Hutjens, amh648");
	fclose(outputfile);
	
	int password =5678;
	char letter;
	
	printf("\nMusic Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	if(password != 5678)
	{
		printf("\nIncorrect password. Bye!");
	}
	else
	{
		do
		{
			printf("\nplease enter the letter P for payment or the letter R for ratings");
			scanf("%c", &letter);
		}while(letter !='P' || letter != 'R');
	switch(letter) // this is my switch case
	{
		case 'P':
		{
			int tickets;
			do{
			printf("\nhow many tickets would you like to purchase: ");
			scanf("%d", &tickets);
			}while(tickets>0);
			total = Payment(tickets);
			printf("\nTotal payment is $%10.2lf", total);
			break;
		}
		case 'R'
		{
			char filename[100];
			FILE * fptr;
			do{
				printf("\nplease enter a filename: ");
				scanf("%s", filename);
				fptr = fopen(filename, "r");
			}while(fptr == NULL);
			
			double arr[100][2];
			int w=0, check;
			
			while(1)
			{
				check = fscanf(fptr, "%lf %lf", &arr[w][0], &arr[w][1]);
				if(check == EOF)
				{
					break;
				}
				w++;
			}
			fclose(fptr);
			average = Ratings(arr,w);
			printf(" the average rating is idk");
			outputfile = fopen("festival.txt", "w");
			fprintf("the average rating for shift A is %lf, and the average for shift B is %lf", average, average);
			fclose(outputfile);
			break;
		}
		
		default:
		{
		}
	}
	
	}
	
	return 0;
}

double Payment(int tickets) //payment function
{
	double total;
	total = (tickets*33) + (1/5)*(tickets*33);
	return total;
}

double Ratings(double arr, int w) //ratings function
{
	char times[100][2];
	for(int i=0, i<w; i++)
	{
		//for(int j=0; j<2; j++); maybe i needed this 
		if(i>3 && i<7)
		{
			i = 'A';
		}
		else
		{
			i = 'B';
		}
	}
	printf("\nShift\tRating");
	printf("%c\t%c", arr[i][0], arr[0][1]);
	double average;
	average = times[w][1]
	return average;
}



// C was a wicked langauge to learn
// i did enjoy Gavin tho
// i need to pass this course
// please with the kindess in your heaert give me a 70
// a 70 woudl save lives















