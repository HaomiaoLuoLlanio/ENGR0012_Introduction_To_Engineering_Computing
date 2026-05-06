#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
//put outside of main with a ;
double Payment(double,double);
void Ratings(int, int, char, char);


int main()
{
	FILE*fp;
	char filename[100];
	
	fp=fopen("festival.txt","w");
	
	char name;
	double loginID;
	printf("Current user: %c, %lf",name,loginID);
	fclose(fp);
	
	//2 enter pass
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d",&password);
	
	while(password!=5678)
	{
		printf("Incorrect password. Bye!");
		return 0;
	}	
	
		char choice;
		printf("Enter P for payment or R for ratings");
		scanf(" %c", &choice);
		
	while(choice!=P && choice !=R)//error checking
	{	printf("Enter P for payment or R for ratings");
		scanf(" %c", &choice);
	}
	
	switch(choice)
	{
		case 'P':
		{
			int tickets;
			printf("enter am integer value to correspond to number of festival tickets you would like to purchase.");
			scanf("%d",tickets);
			
				if(tickets<0)//if lessthan tickets you ask them again to error check
				{
			printf("enter am integer value to correspond to number of festival tickets you would like to purchase.");
			scanf("%d",tickets);
			//add total somewhere here
	double Payment(double tickets,33.00)//total

			printf("Total payment is $%10.2lf",total);
				}
			break;
		}
		
		case 'R':
		{
			FILE*fp2;
			char filename2[][2]; //told there is 2
						
			while(fp2!=EOF)
			{} //proceed if not
			
			fp2=fopen("festival.txt","r");
			printf("The average rating for Shift A is %lf and the average rating for Shift B is %lf",___,__)
			
			
			break;
		}		
		
		default:
		{break;}
	}
		
	}	
		
	return 0;
}

//function for p // L at end is for local
double Payment(double ticknumL,double totalL)
{
		total=(ticknumL*33+(1/5)*ticknumL*33)
		return totalL;
}

//function for ratings
void Ratings(int Times, int Ratings, char A, char B)
{
char Times[][];
char A,B;
int rows;
int i=0; //var for rowa num
	for(i=0;i<rows;i++)
	{
	if(Times=>3 && Times<7)
		{
		A=Times[i][0]; //1st col
		}
	if(Times=>7)
		{
		B=Times[i][1];
		}	
	printf("Shift\tRating\n");
	fscanf(fp2,"Times\tRatings")
	}
	//av of a
	int Aaverage,Baverage;
	if(ShiftA>0)
	{
		Aaverage=sumrating/totalrating
	}
		if(ShiftB>0)
	{
		Baverage=sumrating/totalrating
	}
}

