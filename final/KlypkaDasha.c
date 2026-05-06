#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//prototype
double Payment(int);
void Ratings (double [][2], int);


int main(int argc, char **argv)
{
	//new file
	FILE*fp;
	fp = fopen("festival.txt", "w");
	
	fprintf(fp, "Currecnt user: Dasha Klypka, Dak426");
	fclose(fp);
	
	//password
	int pasw;
	printf("Music Festival 2026. Enter you 4-digit password: "); //5678
	scanf("%d", &pasw);
	if (pasw != 5678){
		printf("Incorrect password. Bye!");
	}
	
	//payment
	char choice;
	printf("\nEnter the letter P for payment or R for ratings: ");
	scanf(" %c", &choice);
	
	while(choice != 'P' && choice != 'R'){
		printf("\nInvalid. Enter the letter P for payment or R for ratings: ");
		scanf(" %c", &choice);
	}
	
	switch(choice){
		case 'P':{
			int numt;
			printf("\nEnter number of tickets: ");
			scanf("%d", &numt);
			while(numt == 0){
				printf("\nInvalid. Enter number of tickets: ");
				scanf("%d", &numt);	
			}
			double total; //total of payment
				total = Payment(numt);
				printf("\nTotal payment is $%10.2lf", total);
				break;
		}
		case 'R': {
			char filename[100];
			printf("\nEnter file name for music festival data: ");
			scanf("%s", filename);
			
			FILE*fp2;
			fp2 = fopen(filename, "r");
			
			while(fp2 == NULL){
				printf("\nInvalid. Enter file name for music festival data: ");
				scanf("%s", filename);
			}
			
			double data[][];
			int idx = 0;
			int rows =0;
			while (fp != EOF){
				data[idx][0]= fcanf(fp2, "%lf", filename[idx][0]);
				data[idx][1]= fcanf(fp2, "%lf", filename[idx][1]);  
				idx++;
			}
			rows = idx + 1;
			fclose(fp2);
			
			ratingRatings(rows);
			
		}
	}
	
	
	
	
	
	return 0;
}

//f1
double Payment(int numt){
	double total=0;
	total = numt*33 + (0.0) + (1/5)*numt*33;
	return total;
}

//f2
int Ratings (double data[][2], int rows){
	char Times[];
	for (int i=0; i<rows; i++){
		for (int j=0; j<2; j++){
			//shift A
			if ((data[i][j] >= 3) || ((data[i][j] >= 3) && (data[i][j] <= 7) ){
			Times[i][0] = 'A';
			}
			if ((data[i][j] >= 7) ){
			Times[i][0] = 'B';
			}
		}
		printf("Shift\t""Rating");
		for (int i=0; i<rows; i++){
		for (int j=0; j<2; j++){
			printf(Times[i][j]);
			}
		}
	}
	
	
}








