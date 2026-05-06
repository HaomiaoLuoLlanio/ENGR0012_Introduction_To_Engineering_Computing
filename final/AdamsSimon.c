#include <stdlib.h>
#include <math.h>
#include <stdio.h>
// Function prototypes
double Payment(int);
void Ratings(int,float [][2])
int main(int argc, char **argv)
{
	// File to write name of user
	FILE *fp = fopen("festival.txt", "w");
	fprintf(fp,"Current user: Simon Adams, sja111");
	fclose(fp);
	// Password and error checking for correct password from user
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &pass);
	if(pass != 5678){
		printf("Incorrect password.Bye!");
		return(1);
	}
	char choice;
	printf("Enter the letter P for payment or the letter R for ratings.\n");
	scanf(" %c", &choice);
	while (choice != 'P' && choice != 'R'){
	printf("Enter the letter P for payment or the letter R for ratings.\n");
	scanf(" %c", &choice);
}
int tickets;
// Overall switch case for choice P or R
	switch (choice){
		case 'P':
		{
			printf("Enter the number of tickets you would like to buy");
			scanf("%d", &tickets);
			while(tickets<=0){
			printf("Enter the number of tickets you would like to buy");
			scanf("%d", &tickets);
			double cost;
			cost = Payment(tickets);
			printf("Total payment is $10.2%lf\n", cost);
		}
			break;
		}
		case 'R':
		{
			char filename[100];
			FILE *fp;
			printf("Enter a valid file name for music festival data\n");
			scanf("%s", filename);
			fp = fopen(filename, "r");
			while(fp == NULL){
			printf("Enter a valid file name for music festival data\n");
			scanf("%s", filename);
			fp = fopen(filename, "r");
		}
		float data[100][2];
		int idx =0;
		int valid = 2;
		while (valid != EOF){
			valid = fscanf(fp, "%f %f", &data[idx][0], &data[idx][1]);
			idx = idx +1;
		}
		int rows = idx -1;
		fclose(fp);
		Ratings(rows, data);
		FILE *fp = fopen("festival.txt", "a");
		float averageA =3;
		float averageB =2;
		fprintf(fp, "The average rating for Shift A is %f and the average rating for shift B is %f", averageA, averageB);
		fclose(fp);
		
		
		
			break;
		}
}
	return 0;
}
// Payment function
double Payment(int tick){
	double Total = (tick+0.0)*33+((tick+0.0)*33)/5;
	return(Total);
}
// Ratings function
void Ratings(int rs,float data[][2]){
	char Times[rs];
	for(int i=0;i<rs;i++){
		if(data[i][0]>= 3 && data[i][0] < 7){
			Times[i] = 'A';
		}
		else if (data[i][1]>=7){
			Times[i] = 'B';
		}
	}
	printf("Shift\tRating\n");
	for (int j=0;j<rs;j++){
		printf("%c\t%f", Times[j], data[j][1]);
	}
		float average;
		float sum = 0;
		for(int k=0;k<rs;k++){
			sum = sum + data[k][1];
		}
		average = sum/rs;
	}
			

