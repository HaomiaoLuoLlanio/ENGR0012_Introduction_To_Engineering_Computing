#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes
double Payments(int);
void Ratings(float);

//Main Program

int main(){


FILE * fp;
fp = fopen("festival.txt","w");
fprintf(fp,"Current user: Mick Kuhl, mwk61");
fclose(fp);

int password;
printf("Music Festival 2026. Enter your 4-digit password: ");
scanf("%d",&password);

if(password == 5678){
	printf("\nIncorrect password. Bye!");
	scanf("%d",&password);
}
else{
	char choice;
	do{
	printf("Enter the letter P for payment or the letter R for ratings: ");
	scanf(" %c",&choice);
	} while(choice != 'P' || choice != 'R');

switch (choice){
	case ('P'):{
		int tickets;
		do{
		printf("\nEnter how many festival tickets you would like to purchase: ");
		scanf("%d",&tickets);
	} while (tickets <= 0);
	
// 7. Call function Payment
	double Total;
	Total = Payments(tickets);
	printf("\nTotal payment is $%10.2lf",Total);
		break;
	}
	
	case ('R'):{
	
	char filename[100];
	printf("\nEnter a file name for your music festival data: ");
	scanf("%s",filename);
	
//Error check filename
	while(filename == NULL)
	{
	printf("\nEnter a file name for your music festival data: ");
	scanf("%s",filename);
	}
	
	FILE * fp2;
	fp2 = fopen(filename,"r");
	
	int check;
	float arr[50][2];
	int idx=0, rows;
	
	while (check != EOF)
	{
	check = fscanf(fp2, arr[idx][2]);
	idx = idx + 1;
	}
	rows = idx - 1;
	
// 11. Call function Ratings
void Ratings(arr[][0],arr[][1]);
		printf("The average rating for Shift A is %d and the average rating for Shift B is %d.",A_avg,B_avg);
		fclose(fp2);
		break;
	}
	
	default:
	
	break;
}

}

	return 0;
}


//Function Declarations

double Payments(int tickets)
{
	double Total;
	Total = tickets*33 + (0.2)*tickets*33;
	return Total;
}

void Ratings(arr[][2])
{
	char Times[50][2];
	
	for (int i=0;i<EOF;i++)
	{
		if (arr[i][0] >= 3 && arr[i][0] < 7)
		{
			Times[i][0] = 'A';
		}
		else
		{
			Times[i][0] = 'B';
		}
	}
	
	printf("\nShift\tRating\n");
	for (int r=0;r<EOF;r++)
	{
		printf("%c\t%lf",Times[r][0],arr[r][1]);
	}
// Shift A average
int A_avg;
	while(Times[i][0] == 'A'){
	A_avg = Times[i][0]/i;
}
// Shift B average
int B_avg;
	while(Times[i][0] == 'B'){
	B_avg = Times[i][0]/i;
}
}
