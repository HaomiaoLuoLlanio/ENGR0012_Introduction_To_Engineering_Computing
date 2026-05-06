#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Isaac B. Geer
// April 23, 2026

// Prototypes:
double Payment(int);
void Ratings(float[][2], int, double);

int main(){
	
	// Variable List:
	int password, tickets = 0, rows = 0, check = 0;
	char letter, filename[50];
	double cost, average[2];
	float arr[50][2];
	
	// Main:
	FILE *fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Isaac B. Geer, ibg12");
	fclose(fp);
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678){
		printf("Incorrect password. Bye!");}
	else {
		while (letter != 'P' && letter != 'R'){
			printf("Enter the letter 'P' for payment or the letter 'R' for ratings: ");
			scanf(" %c", &letter);}
		
		switch (letter){
			case 'P':{
				while (tickets <= 0){
					printf("Enter how many tickets you would like: ");
					scanf("%d", &tickets);}
				cost = Payment(tickets);
				printf("Total payment is $%10.2lf", cost);
			break;}
			
			case 'R':{
				FILE *fp = NULL;
				while (fp == NULL){
					printf("Enter filename for music festival data: ");
					scanf("%s", filename);
					fp = fopen(filename, "r");}
				while (check != EOF){
					check = fscanf(fp, "%f %f", &arr[rows][0], &arr[rows][1]);
					rows++;}
				fclose(fp);
				
				Ratings(arr[][2], rows, average[2]);
				fp = fopen("festival.txt", "a");
				fprintf(fp, "\nThe average rating for Shift A is %lf and the average rating for Shift B is %lf.", average[0], average[1]);
				fclose(fp);
			break;}
		}
	}
	
return 0;}
	
// Function List:
double Payment(int num){
	double total;
	total = (num * 33) + ((1/5) * (num * 33));
return total;}

void Ratings(float arr[][2], int rows, double average[2]){
	char Times[50];
	double sumA, sumB;
	int countA, countB;
	
	for (int i=0; i<rows; i++){
		if (arr[i][0] < 7){
			Times[i] = 'A';
			sumA = arr[i][0] + sumA;
			countA++;}
		else {
			Times[i] = 'B';
			sumB = arr[i][0] + sumB;
			countB++;}}
			
	printf("\nShift\tRating");
	for (int i=0; i<rows; i++){
		printf("\n%c\t%f", Times[i], arr[i][1]);}
	average[0] = sumA / countA;
	average[1] = sumB / countB;
}
