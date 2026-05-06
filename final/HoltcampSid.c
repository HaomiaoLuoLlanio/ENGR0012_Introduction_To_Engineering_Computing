// Sid Holtcamp
// sih93
// Zhou 4pm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int Payment(int tickets);
float Ratings(float festivalData[][2], int count, char shift);

int main() {
	// opening new file festival.txt for the first time
	FILE *festival = fopen("festival.txt","w");
	fprintf(festival,"Current user: Siddharth Holtcamp, sih93");
	fclose(festival);
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	int password;
	scanf(" %d", &password);
	
	// ending program if incorrect password is entered
	if (password != 5678) {
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	printf("Enter P for payment or R for ratings: ");
	char opt;
	scanf(" %c", &opt);
	while (opt != 'P' && opt != 'R') {
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c", &opt);
	}
	
	// if else branch for user chosen option
	if (opt == 'P') {
		printf("Enter an integer for the number of tickets you would like to buy: ");
		int tickets;
		scanf(" %d", &tickets);
		while (tickets <= 0) {
			printf("Enter an integer for the number of tickets you would like to buy: ");
			scanf(" %d", &tickets);
		}
		printf("Total payment is $%10.2d",Payment(tickets));
	}
	
	else {
		// prompting user to enter filename to check through festival data
		printf("Enter filename for music festival data: ");
		char filename[50];
		scanf(" %s",filename);
		FILE *data = fopen(filename,"r");
		while (data == NULL) {
			printf("Enter filename for music festival data: ");
			scanf("%s",filename);
			data = fopen(filename,"r");
		}
		
		int count = 0;
		float temp1;
		float temp2;
		// counting how many rows are seen
		while (fscanf(data,"%f %f",&temp1,&temp2) == 2) {
			count++;
		}
		float festivalData[count][2];
		for (int i = 0; i < count; i++) {
			fscanf(data,"%f %f",&festivalData[i][0],&festivalData[i][1]);
		}
		fopen("festival.txt","a");
		fprintf(festival,"\nThe average rating for Shift A is %f and the average rating for Shift B is %f.",Ratings(festivalData,count,'A'),Ratings(festivalData,count,'B'));
		fclose(festival);
	}
	
	return 0;
}

int Payment(int tickets) {
	return (tickets)*(33)+(1/5)*(tickets*33);
}

float Ratings(float festivalData[][2], int count, char shift) {
	char Times[count];
	for (int i = 0; i < count; i++) {
		if (festivalData[i][0] >= 3 && festivalData[i][0] < 7) {
			Times[i] = 'A';
		}
		else {
			Times[i] = 'B';
		}
	}
	printf("Shift\tRating");
	float sumA = 0;
	float sumB = 0;
	for (int i = 0; i < count; i++) {
		printf("\n%c\t%f",Times[i],festivalData[i][1]);
		if (Times[i] == 'A') {
			sumA += festivalData[i][1];
		}
		else {
			sumB += festivalData[i][1];
		}
	}
	if (shift == 'A') {
		return (float) sumA/count;
	}
	else {
		return (float) sumB/count;
	}
	
}
