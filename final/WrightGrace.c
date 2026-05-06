#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//below tells the code that functions are at the end
double payment(int tickets,double total);
double ratings(char times[][],double sumA, double sumB, double averageA, double averageB);

int main()
{
	
	 int password=0000;
	 char choice;

	 
	FILE*festival;//creating a file*pointer
	festival=fopen("festival.txt","a");
	fprintf("Current user: Grace Wright, gew72");
	fclose("festival.txt");
	
	printf("\nMusic Festival 2026. Enter your 4-digit password: %d",password);
	scanf("%d", &password);
	
	if(password!=5678)//checking password
	{
		printf("\nIncorrect password. Bye!");
	}
	if(password==5678)
	{
		printf("\nPlease enter P for payment or R for ratings:");
		scanf(" %c", &choice);
		
	}
	if (choice!='P' && choice !='R'){
		printf("\nPlease neter P for payment or R for ratings");
	}
	
	int tickets;
	double total;
	float ratings[][];
	int size;
	
	switch(choice){//switch chase for payment or rating choice input by user
		case 'P'
		{
			printf("\nPlease neter a number of tickets you would like to buy: ");
			scanf("%d", &tickets);
			if (tickets==0)
			{
				printf("\nPlease choose an ticket amount not equal to 0");
				total=payment(tickets);
				printf("Total payment is $"%10.2lf",total);
			}
			break;
		}
		case 'R'
		{
			fopen("festival.txt","a");
			while (int=i,i<size,i++){
			if (scanf(festival.txt, "%f", ratings[i][2])!=EOF)
			{
				i++;
			}
		}
			while (int=j,j<size,j++){
			if (scanf(festival.txt, "%f", ratings[i][j])!=EOF)
			{
				j++;
			}
		}
			ratings();
			break;
		}
		
	return 0;
}
double payment(int tickets,int total)//payment fcuntion cacluating how much total cost will be by the user insput
{
	total=tickets*33+(1/5)*(tickets*33)
	
	return total;
}

double ratings(char times[][],double sumA, double sumB, double averageA, double averageB)//function called if user chose option for rating
{
	do 
	{
		times[i][]=='A';
	}while(int i=0, i<EOF, i++);
	
	do 
	{
		times[][j]=='B';
	}while(int j=0, j<EOF, j++);
	
	
	printf("\n Shift\tRating");
	printf("\t%lf",times[][]);
	
	int i=0
	
	//average
	
	while(int i=0, i<size, i++)
	{
		for (times[i][]!=EOF)
		sumA+=sumA;
	}
}
averageA=sumA/size;
printf("%d", averageA);

while(int j=0, j<size, j++)
	{
		for (times[][j]!=EOF)
		sumB+=sumB;
	}
}
averageB=sumB/size;
printf("%d", averageB);


	
	return 0;
}


