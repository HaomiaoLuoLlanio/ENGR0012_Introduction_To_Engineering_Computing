


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float Payment(int);
void Ratings(float[][2], int, float[2]);

int main()
{
	FILE *fpoint = fopen("festival.txt","w");
	fprintf(fpoint, "Current user: Evan Ebarb, eve17");
	fclose(fpoint);
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d",&pass);
	if (pass != 5678){
		printf("Incorrect password. Bye!");
	}
	else{
		char sel;
		do{
		printf("Enter letter P for payment or R for ratings: ");
		scanf(" %c",&sel);
	}while(sel != 'P' && sel != 'R');
	switch (sel){
		case 'P':{
			int tickets;
			do{
			printf("Please enter the number of festival tickets you would like to purchase: ");
			scanf("%d",&tickets);
		}while(tickets < 0);
		//PAYMENT FUNC
		float cost = Payment(tickets);
		printf("Total payment is $%.2f",cost);
		break;
		}
		case 'R':{
			FILE *fp;
			char dataf[50];
			do{
				printf("Please enter the name of the file: ");
				scanf("%s",dataf);
				fp = fopen(dataf,"r");
			}while(fp == NULL);
			float festdata[100][2];
			int i = 0;
			while(fscanf(fp,"%f %f", festdata[i][0], festdata[i][1]) != EOF){
				i++;
			}
			fclose(fp);
			//RATINGS FUNC
			Ratings(festdata, i, avgr);
			FILE *fp2 = fopen(dataf,"a");
			fprintf(fp2,"The average rating for shift A is %f and the average rating for shift B is %f.", avgr[0], avgr[1]);
			
		}
	}
	return 0;
}
float Payment(int tickets){
	float cost = tickets*33.0 + 0.2*(tickets)*33.0;
	return cost;
}

void Ratings(float festdata[][2], int rows, float avgr[2]){
	char Times[rows];
	avgr[0] = 0;
	avgr[1] = 0;
	int rowA = 0, rowB = 0;
	for (int i=0;i<rows;i++){
		if (festdata[i][0] >= 3 && festdata[i][0] <=7){
			Times[i] = 'A';
			avgr[0] += festdata[i][1];
			rowA++;
		}
		else{
			Times[i] = 'B';
			avgr[1] += festdata[i][1];
			rowB++;
		}
	}
	avgr[0] = avgr[0] / rowA;
	avgr[1] = avgr[1] / rowB;
	printf("Shift\tRating");
	for (int i=0;i<rows;i++){
		printf("%c\t%f",Times[i],festdata[i][1]);
	}
}
	
		











