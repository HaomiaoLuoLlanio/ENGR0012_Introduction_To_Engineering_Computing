#include <math.h>
#include <stdlib.h>
#include <stdio.h>

////////PROTOTYPE
float = payment(int);
void ratings(int ,int );

int main()
{
FILE *start = fopen("festival.txt","w");
fprintf(start,"Current user: Pun Suwannachin, pus24");
fclose(start);

///NUMBER 2 &3////
int password;
printf("Music Festival 2026. enter your 4-digit password: \n");
scanf("%d",&password);

if(password != 5678)
{
	printf("Incorrect password. Bye!");
}

///Number 4////////
char choice;
printf("Please enter (P) for Payment pr (R) for ratings: \n");
scanf(" %c",&choice);
while(choice != 'R' && choice != 'P')
{
	printf("Please enter (P) for Payment pr (R) for ratings: \n");
scanf(" %c",&choice);
}

////NUMBER 5////////
int ticknum;
int check = 0;
int idx = 0;
char filename[100];

int data[30][2];

switch(choice)
{
	case 'P':
	printf("Please enter how many tickets you would like to purchase: \n");
	scanf("%d",&ticknum);
	while(ticknum<=0)
	{
	printf("Please enter how many tickets you would like to purchase: \n");
	scanf("%d",&ticknum);
	}
	float total = payment(ticknum);
	
	printf("Total payemnt is $%10.2lf"),total);
	break;
	
	case 'R':
	FILE *fp = fopen(filename);
	printf("Please enter the a file anme for the music festical:  \n");
	scanf("%s",&filename);
	while (filename == NULL)
	{
	printf("Please enter the a file anme for the music festical:  \n");
	scanf("%s",&filename);
	}
	
	while(filename!=EOF)
	{
		fscanf(fp,"%d %d",&data[idx][1],&data[idx][1]);
		idx++;
	}
	ratings(idx,int data[30][2]);
	fclose(fp);
	
	
	////NUMBER 12
	FILE *file = fopen("festval.txt","w");
	fprintf(file,"The average rating for Shift A is  and the average shift for b is .");
	break;
	
	
}

	return 0;
}

/////PAYMENT FUNCTION////////////////
void total = payment(int ticknum)
{
	float total;
	total = (ticknum*33)+((1/5)*(ticknum*33);
	
	return(total);
}

////Ratings FUNCTION////

void ratings(int idx,int data[30][2])
{
	float average;
	char Times;
	////NUMBER 11
	for(int i = 0;i<idx;i++)
	{
		for(int j = 0;j<idx;j++)
	{
		if(data[i][j]>3 && data[i][j]<7)
		{
			Times = 'A';
		}
		else 
		{
			Times = 'B';
		}
	}
	}
	printf("Shift\tRating\n");
	
	average = A/B;
	return(average);
}












