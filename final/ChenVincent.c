#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function prototypes
	// 1. payment
	float Payment(int);

	// 2. ratings
	void Ratings(float[][2], int, float[]);

// main
int main()
{
	// create festival.txt & write
	FILE* festival = fopen("festival.txt", "w");
	
	// print statement to festival.txt
	fprintf(festival, "Current user: Vincent Chen, vic161");
	
	// close file
	fclose(festival);
	
	// input password
	int password;
	
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);
	
	// wrong password
	if (password != 5678){
		printf("\nIncorrect password. Bye!");
		return 1;
	}
	
	// white space
	printf("\n\n");
	
	// enter P for payment or R for ratings
	char option;
	do{
	printf("Enter P for payment or R for ratings: \n");
	scanf(" %c", &option);
	}while(option != 'P' && option != 'R');
	
	// switch case
	switch (option){
		case 'P':{
			// white space
			printf("\n");
			
			// purchase tickets
			int tickets;
			do{
			printf("How many tickets would you like to purchase? (>0) : \n");
			scanf("%d", &tickets);
			}while(tickets <= 0);
			
			// call payment function
			float total = Payment(tickets);
			
			// display total
			printf("Total payment if $%10.2f", total);
			
			break;
		}
		case 'R':{
			// white space
			printf("\n");
			
			// ask for filename
			char filename[1000];
			FILE* saturday;
			
			do{
				printf("Enter file name:\n");
				scanf("%s", filename);
				saturday = fopen(filename, "r");
			}while(saturday == NULL);
			
			// white space
			printf("\n");			
			
			// read file
			int check = 0, idx = 0;
			float data[1000][2];
			
			while ((check = fscanf(saturday, "%f %f", &data[idx][0], &data[idx][1])) != EOF){
				idx++;
			}
			
			// calculate rows
			int rows = idx - 1;
			
			// result matrix for ratings function
			float result[2];
			
			// call ratings runction
			Ratings(data, rows, result);
			
			// reopen festival.txt & append
			FILE* reopen = fopen("festival.txt", "a");
			fprintf(reopen, "\nThe average rating for Shift A is %f and the average rating for Shift B is %f.", result[0], result[1]);
			
			// close file
			fclose(reopen);
		
			
			break;
		}
	}
	
	return 0;
}



// functions
	// 1. payment
	float Payment(int num){
		// calculate payment
		float payment = num * 33.0 + (num*33)/5.0;
		
		// return payment
		return payment;
	}

	// 2. ratings
	void Ratings(float data[][2], int rows, float avg[]){
		// find times of band
		char Times[1000];
		
		// counts & sums
		int countA = 0, countB = 0;
		int sumA = 0, sumB = 0;
		
		// find start times
		for (int i = 0; i < rows; i++){
			if (data[i][0] >= 3 && data[i][0] <= 7){
				Times[i] = 'A'; // Shift A
				
				// count A
				countA++;
				
				// sum A
				sumA = sumA + data[i][1];
			}
			else{
				Times[i] = 'B'; //  Shift B
				
				// count B
				countB++;
				
				// sum B
				sumB = sumB + data[i][1];		
			}
		}
		
		// print stuff
		printf("\nShift\tRating\n");
		for (int i = 0; i < rows; i++){
			printf("%c\t%f\n", Times[i], data[i][1]);
		}
		
		// calculate averages for A & B
		float avgA = sumA*1.0/countA;
		float avgB = sumB*1.0/countB;
		
		// return to array
		avg[0] = avgA;
		avg[1] = avgB;
	}
