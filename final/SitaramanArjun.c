#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

double Payment(int tics);
void Ratings(float arr[][2], int rows, char arr2[], float ratingAvg[2]);

int main()
{
	FILE*festival;
	festival = fopen("festival.txt", "w");
	fprintf(festival, "Current user: Arjun Sitaraman, ANS1094");
	fclose(festival);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	if (password != 5678) {
		return 1; //return 1 ends the code
	}
	
	char payOrRate;
	printf("\nEnter the letter P for payment or the letter R for ratings: ");
	scanf(" %c", &payOrRate);
	while (payOrRate != 'P' && payOrRate != 'R') {
		printf("\nEnter the letter P for payment or the letter R for ratings: ");
		scanf(" %c", &payOrRate);
	}
	
	switch (payOrRate) {
		case 'P': {
			int tickets;
			printf("\nHow many festival tickets do you want to purchace: ");
			scanf("%d", &tickets);
			while (tickets <= 0) {
				printf("\nHow many festival tickets do you want to purchace: ");
				scanf("%d", &tickets);
			}
			double price = Payment(tickets);
			printf("Total payment is $%10.2lf", price);
			break;
		}
		case 'R': {
			FILE*festData;
			char fileName[50];
			printf("\nEnter a filename for your music festival data: ");
			scanf("%s", fileName);
			festData = fopen(fileName, "r");
			while (festData == NULL) { //If the file doesn't exist you enter the loop
				printf("\nEnter a filename for your music festival data: ");
				scanf("%s", fileName);
				festData = fopen(fileName, "r");
			}
			float fileData[50][2];
			int check = 0;
			int i = 0;
			while (check != EOF) { //If there is no more data to read then you exit this loop
				check = fscanf(festData, "%f %f", &fileData[i][0], &fileData[i][1]);
				i++;
			}
			fclose(festData);
			int totalRows = i-1;
			char Slots[totalRows];
			float AverageRating[2];
			Ratings(fileData, totalRows, Slots, AverageRating);
			
			FILE*festival;
			festival = fopen("festival.txt", "a");
			fprintf(festival, "\nThe average rating for Shift A is %f and the average rating for Shift b is %f", AverageRating[0], AverageRating[1]);
			break;
		}
		default: { //Nothing needed for default because with error checking 'C' or 'P' must be chosen
			break;
		}
	}
	
	return 0;
}

double Payment(int tics) {
	double cost = tics*33+0.2*(tics*33);
	return cost;
}

void Ratings(float arr[][2], int rows, char arr2[], float ratingAvg[2]) { //rows tells when to end loops, ratingAvg stores the average ratings calculated
	float ARatingTotal = 0;
	int ASlots = 0;
	float BRatingTotal = 0;
	int BSlots = 0;
	for (int i = 0; i<rows; i++) {
		if (arr[i][0] < 7) {
			arr2[i] = 'A';
			ARatingTotal = ARatingTotal + arr[i][1];
			ASlots++;
		}
		else {
			arr2[i] = 'B';
			BRatingTotal = BRatingTotal + arr[i][1];
			BSlots++;
		}
	}
	printf("Shift\tRating");
	for (int i = 0; i<rows; i++) {
		printf("\n %c\t%f", arr2[i], arr[i][1]);
	}
	float AAverage = ARatingTotal/ASlots;
	float BAverage = BRatingTotal/BSlots;
	ratingAvg[0] = AAverage;
	ratingAvg[1] = BAverage;
}







