#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double payment(int tickets);
void Ratings(int numbands, float arr[numbands][2], double avgs[2]);

int main(){
int correctPass = 5678;

//prints user data
FILE *writer = fopen("festival.txt", "w");
fprintf(writer, "Current user: Benjamin See, bss104");
fclose(writer);

//checks for an inital password
printf("Music festival 2026. Enter your 4-digit password: ");
int password;
scanf("%d", &password);
if(password!= correctPass){
	printf("Incorrect password. Bye!");
	return 1;
}


char choice;

//error checks user choice
do{
printf("\nenter P for payment or R for ratings: ");
scanf(" %c", &choice);
}while(choice!='R' && choice !='P');


switch(choice){
	case 'R':{
		
		//gets the file name from the user and opens it
		FILE *reader;
		char fname[100];
		do{
			printf("\nPlease enter a file name: ");
			scanf("%s", fname);
			reader = fopen(fname, "r");
		}while(reader==NULL);
		
		//reads in the data to an array
		float arr[9999][2];
		int idx=0;
		int check;
		while(1){
			check = fscanf(reader, "%f %f", &arr[idx][0], &arr[idx][1]);
			if(check==EOF){
				break;
			}
			idx++;
		}
		
		fclose(reader);
		
		double avgs[2];
		Ratings(idx, arr, avgs);
		
		FILE* writernew = fopen("festival.txt", "a");
		fprintf(writernew, "\nThe average rating for Shift A is %lf and the average rating for Shift B is %lf", avgs[0], avgs[1]);
		fclose(writernew);
		
		break;
	}
	case 'P':{
		int tickets;
		
		do{
			//asks user for num tickets and error checks
			printf("\nplease enter an integer value of festival tickets to purchase: ");
			scanf("%d", &tickets);
		}while(tickets<1);
		
		double total = payment(tickets);
		
		printf("Total payment is $%-10.2lf", total);
		break;
	}
	
	
}

return 0;
}

//returns total payment due
double payment(int tickets){
	return 1.0*tickets*33 + .2*tickets*33;
}

void Ratings(int numbands, float arr[numbands][2], double avgs[2]){
	int totalRatingA = 0;
	int totalRatingB = 0;
	int numB = 0;
	int numA = 0;
	char Times[numbands];

	//looping through the bands info to label them in shifts and calculate the average
	for(int i=0; i<numbands; i++){
		
		if(arr[i][0] <7){
			Times[i] = 'A';
			totalRatingA+=arr[i][1];
			numA++;
		}
		else{
			totalRatingB+=arr[i][1];
			Times[i] = 'B';
			numB++;
		}
	}
	
	printf("Shift\tRating\n");
	for(int i = 0; i<numbands; i++){
		printf("%c\t%f\n", Times[i], arr[i][1]);
	}
	
	//calculating and returning values
	 avgs[0] = 1.0*totalRatingA/numA;
	 avgs[1] = 1.0*totalRatingB/numB;
	 
	
}
