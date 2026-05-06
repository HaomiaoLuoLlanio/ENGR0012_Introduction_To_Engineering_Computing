

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ratings(int)



int main()
{
	FILE *pointer;
	pointer = fopen(festival.txt,"w");
	fprintf(pointer,"Curremt user: Aliya Cottrill, alc689");
	fclose(festival.txt);
	
	printf("Music Festival 2026. Enter your 4-digit password:/n");
	int passward[4];
	scanf("%d",&passward[0]);
	scanf("%d",&passward[1]);
	scanf("%d",&passward[2]);
	scanf("%d",&passward[3]);
	
	if (passward[0] != 5 || passward[1] != 6 || passward[2] != 7 || passward[3] != 8)
	{
		//program ends if the incorect passward is entered
	}
	else
{
	printf("\nEnter the letter P for payment or the Letter R for ratings.\n");
	char choice;
	scanf(" %c", &choice);
	
	while (choice != 'P' || choice != 'R')
	{
		printf("Invalid choice, please enter P or R");
		scanf(" %c", &choice);
	}
	
	switch (choice)
	case 'P':
	{
		printf("\nHow many tickets would you like to purchase?\n");
		int tickets;
		scanf("%d",tickets);
		while (tickets <= 0)
		{
			printf("Please enter a number greater than 0\n");
			scanf("%d",tickets);
		}
		double cost;
		cost = payment(tickets);
		printf("total payment is $%2lf\n",cost);
		break;
	}
	case 'R':
	{
		char file[50];
		scanf("%s",file);
		check = fopen(file,"r");
		if (check == NULL)
		{
			printf("File not found, enter a different file name\n");
			check = fopen(file,"r");
		}
		double data[50][2]
		int full;
		i=0;
		while (full != EOF)
		{
		full = fscanf(check,"%lf %lf",data[i][0],data[i][2];
		i=i+1;
		}
		fclose(file);
		break;
	}
}
	return 0;
}




double payment(int tickets)
{
	double cost;
	cost=1/5;
	cost=cost*tickets;
	cost=cost+33;
	return cost;
}

void ratings(double data[][2])
{
	char times[50]
	j=1;
	while()
	{
		if(data[j][0]>=3 && data[j][0]<7)
		{
			printf(" %c",times[j]);
			j=j+1
		}
	}
}





