
#include <stdio.h>
#include <stdlib.h>

float Payment(int);
float Ratings(float[2][100]);
int main()
{
	
	//Q1
	FILE *fp = fopen("festival.txt","w");
	fprintf(fp,"Current user: Ethan Smith, ems647");
	fclose(fp);
	
	
	//Q2
	printf("Music Festival 2026. Enter your 4-digit password:");
	int password;
	scanf("%d", &password);
	
	
	//Q3
	if(password != 5678)
	{
		printf("Incorrect password. Bye!");
		return 0;
	}
	
	
	//Q4
	char payRate;
	do
	{
		printf("Enter P for payment or R for ratings");
		scanf(" %c", &payRate);
	}
	while(payRate != 'P' || payRate != 'R');
	
	
	//Q5
	
	switch(payRate)
	{
		case 'P':
		
			//Q6, 7, 8
			int tickets;
			do
			{
				printf("Enter the number of tickets you would like");
				scanf("%d",&tickets);
			}
			while(tickets<=0);
			float pay = Payment(tickets);
			printf("Total payment is $%10.2f",pay);
			
		break;
		case 'R':
			//Q9
			char fname[50];
			FILE *pointer;
			do
			{
				printf("Enter a valid filename");
				scanf("%s", fname);
				pointer = fopen(fname,"r");
			}
			while(pointer == NULL);
			
			
			//Q10
			float data[2][100];
			int i;
			while(fscanf(pointer,"%f %f", &data[0][i], &data[1][i]) != EOF)
			{
				i++;
			}
			
			
			//Q11
			float average = Ratings(data);
			printf("The average rating for Shift A is %f and the average rating for shift B is %f" , average, average);
			
	
		break;
	
	
		default:
	}
	
	return 0;
}


//RATINGS FNCT
float Ratings(float data[2][100])
{
	
	//A
	char Times[100];
	char length;
	for(int i = 0;i<100;i++){
		if(data[0][i] >= 3 && data[0][i]<7)
		{
			Times[i] = 'A';
		}
		else if(data[0][i] >=7)
		{
			Times[i] = 'B';
		}
		
		if(data[0][i] ==0 && data[1][i] ==0)
		{
			length = i-1;
		}
	}
	
	//B
	printf("Shift\tRating");
	
	for(int i = 0; i<length;i++)
	{
		printf("%c\t%f",Times[i],data[1][i]);
	}
	
	
	//C
	float sum[2];
	float average[2];
	for(int i = 0; i<length;i++)
	{
		if(Times[i] == 'A')
		{
			sum[0] += data[1][i];
		}
		if(Times[i] == 'B')
		{
			sum[1] += data[1][i];
		}
	}
	average[0] = sum[0] / (length);
	average[1] = sum[1] / (length);
	return average[0];
	
	
}
float Payment(int tickets)
{
	float pay = (tickets+0.0)*33 + (0.2) * tickets * 33 ;
	return pay;
}
