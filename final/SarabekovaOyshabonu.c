#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//function prototypes 
double Payment(int);
void Ratings(double[][2], int, double[2])

int main() {
	// created a new file
	FILE *fout = fopen("festival.txt", "w");
	fprintf(fout, "Current user: Aisha Sarabekova, oys6");
	// closed file
	fclose(fout);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	char choice;
	if(password != 5678) {
		printf("Incorrect password. Bye!");
		return 1;
	}
	else {
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &choice);
		while(choice != 'R' || choice != 'P') {
			printf("Enter P for payment or R for ratings: ");
			scanf(" %c", &choice);
		}
		switch(choice) {
			case 'P': {
				int num_tickets;
				printf("Enter an integer value (for number of tickets): ");
				scanf("%d", &num_tickets);
				while(num_tickets < 0) { //invalid condition
					printf("Enter an integer value (for number of tickets): ");
					scanf("%d", &num_tickets);
				}
				double total;
				total = Payment(num_tickets);
				printf("Total payment is $%.2lf", total);
				break;
			}
			
			case 'R': {
				char filename[50];
				FILE *fp;
				printf("Enter a filename: ");
				scanf("%s", filename);
				fp = fopen(filename, "r");
				while(fp == NULL) {
					printf("Enter a filename: ");
					scanf("%s", filename);
					fp = fopen(filename, "r");
				}
				double matrix[100][2];
				int check = 0;
				int idx = 0;
				while(check != EOF) {
					check = fscanf(fp, "%lf %lf", &matrix[idx][0], &matrix[idx][1]);
					idx = idx + 1;
				}
				int rows;
				rows = idx - 1;
				fclose(fp);
				double average[2];
				Ratings(matrix, rows, average);
				printf("The average rating for Shift A is %lf and the average rating for Shift B is %lf", average[0], average[1]);
				break;
			}
			
			default: {
				break;
			}
		}
	}
	


	return 0;
}

// Payment function
double Payment(int tickets) {
	double tot; 
	tot = (tickets)*33.00+(1.0/5)*(tickets*33.00);
	return tot;
}

// Ratings function
void Ratings(double matrix[][2], int rs, double average[2]) {
	char Times[];
	double sumA = 0.0;
	double sumB = 0.0;
	for(int i = 0; i < rs; i++) {
		if(matrix[i][0] >= 3 && matrix[i][0] < 7) {
			Times[i] = 'A'; // shift A
			sumA = sumA + matrix[i][1];
		}
		else if(matrix[i][0] >= 7) {
			Times[i] = 'B'; // shift B
			sumB = sumB + matrix[i][1];
		}
	}
	printf("Shift\tRating");
	for(int i = 0; i < rs; i++) {
		printf("%c\t%lf", Times[i], matrix[i][1]);
	}
	double averageA; 
	double averageB;
	averageA = sumA/rs;
	averageB = sumB/rs;
	double average[2] = {averageA, averageB};
	
	
}
