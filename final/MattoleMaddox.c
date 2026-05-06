#include <stdio.h>

void Ratings(float data[][2], int n)
{
	char times[100];
	double countA = 0;
	double rateA = 0;
	double countB = 0;
	double rateB = 0;
	for (int i = 0; i < n; i++){
		if (data[i][0] >= 3 && data[i][0] < 7){
			times[i] = 'A';
			countA++;
			rateA += data[i][1];
		}
		else{
			times[i] = 'B';
			countB++;
			rateB += data[i][1];
		}
	}
	printf("Shift\tRating");
	for (int i = 0; i < n; i++){
		printf("%c\t%f",times[i], data[i][1]);
	}
	double avgA = rateA/countA;
	double avgB = rateB/countB;
}
	
	

double payment(double tix)
{
	double total = ((tix *33) + ((tix*33)/5));
	return total;
}

int main()
{
	FILE*fp1;
	fp1 = fopen("festival.txt","w");
	fprintf(fp1,"Current user: Maddox Mattole, mam1839\n");
	fclose(fp1);
	
	int pass, x =0, y = 0;
	char choice;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pass);
	
	if (pass != 5678){
		printf("\nIncorrect password. Bye!\n");
	}
	else {
		while (x == 0){
			printf("Enter P for payment or R for ratings: ");
			scanf(" %c", &choice);
			if (choice == 'P'){
				x = 1;
				break;
			}
			else if (choice == 'R'){
				x = 1;
				break;
			}
			else if (x == 0){
				printf("\nEnter P or R.\n");
			}
		}
	}
	double tix;
	char filename[50];
	FILE*fp = NULL;
	switch (choice){
		case 'P': {
			while (y == 0){
				printf("How many tickets would you like?: \n");
				scanf("%lf", &tix);
				if (tix > 0){
					y = 1;
					break;
				}
				else{
					printf("Enter a non-negative value.\n");
				}
			}
			double total = payment(tix);
			printf("Total payment is %10.2lf\n", total);
		}
		case 'R': {
			while (fp == NULL){
				printf("Enter a filename: \n");
				scanf("%s", filename);
				fp = fopen(filename, "r");
				if (fp == NULL){
					printf("File does not exist.\n");
				}
			}
			float data[100][2];
			int n = 0;
			while (fscanf(fp,"%f %f", &data[n][0], &data[n][1]) == 2){
				n++;
			}
			Ratings(data,n);
		}
	}
	
		
	
			
			
	
	
			
		
	
			
	
	
	return 0;
}

