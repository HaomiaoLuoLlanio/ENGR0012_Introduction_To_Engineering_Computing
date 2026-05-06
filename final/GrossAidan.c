#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


double Payment(int, double);
void Ratings(int, char, int);

int main()
{
	char filename[100]; //Here we create a placeholder character that stroes what the user types
	do {
		printf("Please enter the file you would like to work on: ");
		fscanf("%s", filename); //This scans what the user wrote and puts it on filename. We dont need an & since this is a %s
		FILE*fp = fopen(filename, "a");
		if (filename == 'festival.txt') {
		FILE*fp = fopen("festival.txt", "a");
		fprintf(fp, "Current user: Aidan Gross, adg236\n");
		fclose(fp);
	}		
	} while (fp == NULL)
	
	int password;
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	fscanf("%d", &password);
	if (password != 5678) {
		printf("Incorrect password. Bye!\n");
		return 0;
	}
	
	char user_choice = 'j'; //Here we make user choice equal the character j to allow us into the loop
	
	while (user_choice != 'P' && user_choice != 'p' && user_choice != 'R' && user_choice != 'r') {
	printf("Please enter the letter P for payment or the letter R for ratings: ");
	fscanf("%c", &user_choice);
	if (user_choice != 'P' && user_choice != 'p' && user_choice != 'R' && user_choice != 'r') {
		printf("You have not selected a valid option!\n");
	}
	}
	
	switch (user_choice) { //Here we user user_choice for the switch case because it is either R or P
		
		case 'p':
		case 'P': {
		int user_integer;
		while (user_integer <= 0) {
			printf("Please enter an integer number to correspond with how many tickets you want: ");
			fscanf("%d", &user_integer);
			if (user_integer <= 0) {
				printf("You have entered an invalid integer!\n");
			}
		}
		double total_payment = 0;
		double Payment(int user_integer, double total_payment);
		
		printf("Total payment is $%10.2lf\n", total_payment); //This prints out the total payment coming straight from the variable total_payment. We have 10.2 for a field width of 10 and a decimal precision of 2
		
		break;	
		}
		
		case 'r':
		case 'R': {
			
		FILE*fp = NULL;
		char user_file;

		while (FILE*fp == NULL) {
		printf("Please enter the text file named saturday.txt: ");
		fscanf("%s", user_file);
		FILE*fp = fopen(user_file, "r");
		if (FILE*fp == NULL) {
			printf("You have entered the incorrect file name!\n");
		}
		}
		
		double arr[][];
		int rows = 0;
		
		while (fscanf(fp, "%lf" "%lf", arr[rows][0], arr[rows][1]) != EOF) {
			rows++;
		}
		fclose(fp);
		
		void Ratings(int arr[][2], char times[][1], int rows);
		
		fp = fopen("festival.txt", "a");
		fprintf(fp, "The average rating for Shift A is %lf and the average rating for Shift B is %lf.", , );
		fclose(fp);
		break;
		}
		
		default {
			break;
		}
		
	}
	
	return 0;
}

double Payment(int user_integer, double total_payment) {
	total_payment = user_integer*33 + 0.2*user_integer;
	return total_payment;
}

void Ratings(int arr[][2], char times[][1], int rows) {
	for (int i=0; i<rows; i++) {
		if (arr[i][0] >= 3 && arr[i][3] < 7){
			char times[i][0] = 'A';
		}
		else if (arr[i][0] >= 7) {
			char times[i][0] = 'B';
		}
	}
	
	printf("Shift\tRating");
	for (int i=0; i<rows; i++) {
		printf("%c\t%lf",times[i][0], arr[i][1]);
}

