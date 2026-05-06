#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double payment(int, double);

int main()
{
	//first column - start time
	//second column - rating 1-5
	
	FILE *infile;
	FILE *outfile;outfile = fopen("festival.txt", "w");
	outfile = fopen("festival.txt", "w");
	fprintf(outfile, "Current user: Ava Kosta, AGK115\n");
	fclose(outfile); 
	
	int password = 0; //correct password is 5678
	char choice1;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678){
		printf("\nIncorrect password. Bye!");
		return 0; // stops it from running further
	}
	else{
		printf("\nEnter the letter P for payment or R for ratings: ");
		scanf(" %c", &choice1);
			while (choice1 != 'P' || choice1 != 'R'){ //error check
			printf("\nEnter the letter P for payment or R for ratings: ");
			scanf(" %c", &choice1);
			}
	}	
	
	switch (choice1){
		case 'P':{ //payment
			int ticketNum = 0;
			printf("\nEnter an integer value to correspond to the number of festival tickets you want: ");
			scanf("%d", &ticketNum); 
				while (ticketNum <= 0){ //error check
				printf("\nEnter an integer value to correspond to the number of festival tickets you want: ");
				scanf("%d", &ticketNum); 
				}
				double totalcost = 0.00;
				totalcost = payment(ticketNum, totalcost);
				printf("\nTotal payment is $%10.2lf", totalcost);
			break;
		}
		case 'R':{//ratings
			char filename[50];
			printf("\nEnter a filename for the music festival data: ");
			scanf("%s", &filename);
				while (filename != 'saturday.txt'){ //error check
					printf("\nEnter a filename for the music festival data: ");
					scanf("%s", &filename);
				}
			infile = fopen(filename, "r"); // reads the inputted txt file
			
			int check = 0, i = 0, n = 0;
			double data [100][2];
			while (check != EOF){ //read in
				check = fscanf(infile, "%lf %lf", &data[i][0], &data[i][1]); 
				i++;
			}
			n = i-1;
			fclose(infile);
			double average[100][2];
			
			
			ratings(data, average, n); //calling function 2
			outfile = fopen("festival.txt", "a");
			fprintf(outfile, "\nThe average rating for Shift A is %.2lf and the average rating for Shift B is %lf", average[0][0], average[0][1]); 
			fclose(outfile);
			
			
			
			break;
		}

}
	
	return 0;
}

double payment(int ticketNum, double totalcost){ //function 1

	totalcost = ticketNum*33+(1/5)*(ticketNum*33);
	return totalcost;
}

void ratings(double data[][2], double average[][2], int n,){
	char Times[100];
	double sumA = 0, sumB = 0;
	double countA = 0, countB = 0;
	for (int j = 0; j < n; j++){
		if (data[j][0] >= 3 && data[j][0] < 7){
			times[j] = 'A';
		}
		else if (data[j][0] > 7){
			times[j] = 'B';
		}
	}
	printf("\n\nShift\tRating");
	for (int ii = 0; ii < n; ii++){
	printf("\n%c\t%lf", times[ii], data[ii][1]);
	
	if (times[ii] == 'A'){
		countA++;
		sumA = sumA + data[ii][1];
	}
	
	if (times[ii] == 'A'){
		countA++;
		sumA = sumA + data[ii][1];
	}
	
}
	average[0][0] = sumA /countA;
	
	
	
	
}

