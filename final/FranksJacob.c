#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Function Signatures
double Payment(int);
void Ratings(int, double [][2], float[2]);


int main() {
	//Declare Variables
	FILE *fileWriter = fopen("festival.txt", "w");
	int password;
	char choice;
	
	//Print user info to file
	fprintf(fileWriter, "Current user: Jacob Franks, jrf209\n");
	fclose(fileWriter);	//Close file and save contents
	
	//Prompt user for password
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);	//5678
	
	if(password != 5678) {	//Close program on incorrect password
		printf("\n\nIncorrect password. Bye!\n");
		return 0;
	}
	
	// If user correct, continue to ask for payment/ratings
	do {
		printf("\n\nWelcome, user!\nPlease enter P for payment or R for ratings: ");
		scanf(" %c", &choice);
	} while(choice != 'P' && choice != 'R');	//Ensure user provides valid input
	
	switch(choice) {
		case 'P': {
			//Declare relevant variables
			int tix;
			double total;
			
			//Ask user for amnt of tickets to purchase and save val
			do {
				printf("\nHow many tickets would you like to purchase?\n");
				scanf("%d", &tix);
			} while(tix <= 0);
			//Call Payment to calculate total cost
			total = Payment(tix);
			
			//Display total payment amount
			printf("\nTotal payment is $%10.2lf\n", total);
			break;
		}
		case 'R': {
			//Declare relevant variables
			FILE *filePointer;
			int check, len = 0;
			char filename[20];
			float avg[2];
			double festivalData[25][2];
			
			//Request filename
			do {
				printf("\nPlease enter the name for your festival data file: ");
				scanf("%s", &filename);
				
				filePointer = fopen(filename, "r");
			} while(filePointer == NULL);
			
			//Read in data
			do {
				check = fscanf(filePointer, "%lf\t%lf", &festivalData[len][0], &festivalData[len][1]);
				len++;
			} while(check != EOF);
			len--;	//Adjust array length to fit
			fclose(filePointer);	//close filepointer
			
			//Call Ratings to calculate average ratings
			Ratings(len, festivalData, avg);
			
			//Append results to file
			fileWriter = fopen("festival.txt", "a");
			fprintf(fileWriter, "The average rating for Shift A is %2f and the average rating for Shift B is %2f\n", avg[0], avg[1]);
			fclose(fileWriter);	//Close fileWriter and save changes
			break;
		}
	}
	
	
	return 0;
}


//Function Prototypes
double Payment(int tix) {
	//Declare variable and carry out value calculation
	double total = (tix * 33.00) + (0.2 * tix * 33.00);
	
	//Return total cost
	return total;
}

void Ratings(int acts, double schedule[][2], float avg[2]) {
	char Times[25];
	
	//Assign shift for each act based on performance time
	for(int i = 0; i < acts; i++) {
		if(schedule[i][0] < 7) {
			Times[i] = 'A';
		}
		else {
			Times[i] = 'B';
		}
	}
	
	//Display Heading
	printf("\nShift\tRating\n");
	for(int i = 0; i < acts; i++) {
		printf("%c\t%lf\n", Times[i], schedule[i][1]);
	}
	
	//Sum averages
	avg[0] = 0;
	int actsA = 0, actsB = 0;
	avg[1] = 0;
	
	for(int i = 0; i < acts; i++) {
		if(Times[i] == 'A') {
			avg[0] += schedule[i][1];
			actsA++;
		}
		else {
			avg[1] += schedule[i][1];
			actsB++;
		}
	}
	
	//Finalize Averages for Each Shift
	avg[0] /= actsA;
	avg[1] /= actsB;

	return;
}
