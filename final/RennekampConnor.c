#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// PROTOTYPES
double Payment(int);
void Ratings(float[][2], int, double[2]);

int main()
{
	FILE *fp;
	fp = fopen("festival.txt","w");
	
	fprintf(fp, "Connor Rennekamp, cjr183\n");
	fclose(fp);
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	
	if (password != 5678){ // Ending program if the password is wrong
		printf("Incorrect password. Bye!");
		return 1;
	}
	else{
		char usr_opt;
		printf("\nEnter a P for payment or R for ratings: ");
		scanf(" %c", &usr_opt);
		
		while (usr_opt != 'P' && usr_opt != 'R'){
			printf("\nInvalid input. Enter a P for payment or R for ratings: ");
			scanf(" %c", &usr_opt);
		}
		
		switch (usr_opt){
			
			case 'P':{
				
				int ticket_num;
				printf("Please enter how many tickets you would like: ");
				scanf("%d", &ticket_num);
				
				while (ticket_num < 0){
					printf("Invalid input. Please enter how many tickets you would like: ");
					scanf("%d", &ticket_num);
				}
				
				double cost;
				cost = Payment(ticket_num);
				
				printf("Total payment: $%10.2lf\n", cost);
				
				break;
			}
			case 'R':{
				
				char filename[50];
				FILE *fpoint;
				
				printf("Enter the name of your file: ");
				scanf("%s", filename);
				fpoint = fopen(filename, "r");
				
				while (fpoint == NULL){
					printf("Enter the name of your file: ");
					scanf("%s", filename);
					fpoint = fopen(filename, "r");
				}
				
				float data[1000][2];
				int count = 0;
				int value = 0;
				
				while (value != -1){ // Checking the length of file. If value is -1, noting was scanned.
					value = fscanf(fpoint, "%f %f", &data[count][0], &data[count][1]);
					count = count + 1;
				}
				
				int rows = count - 1;
				double res[2];
				
				Ratings(data, rows, res);
				
				fp = fopen("festival.txt","a");
				fprintf(fp, "The average rating for shift A is %lf and the average rating for shift B is %lf\n", res[0], res[1]);
				fclose(fp);
				break;
			}
			default:{
				break;
			}
		}
	}
	
	
	return 0;
}

// FUNCITONS:


double Payment(int n){
	
	double total;
	
	total = n*33.0 + ((1/5)*n*33); // Calculating total
	
	return total;
}


void Ratings(float data[][2], int size, double res[2]){ // using a matrix to return the two designated values
	char times[size];
	
	for (int i=0; i<size; i++){
		if (data[i][0] >= 3 && data[i][0] < 7){
			times[i] = 'A';
		}
		else{
			times[i] = 'B';
		}
	}
	
	printf("Shift\tRating\n");
	for (int i=0; i<size; i++){
		printf("%c\t%f\n", times[i], data[i][1]);
	}
	
	int sum_A = 0;
	int count_A = 0;
	int sum_B = 0;
	int count_B = 0;
	
	for (int i=0; i<size; i++){ // calculating sum of each rating based off of whether they are A or B
		if (times[i] == 'A'){
			sum_A = sum_A + data[i][1];
			count_A = count_A + 1;
		}
		else{
			sum_B = sum_B + data[i][1];
			count_B = count_B + 1;
		}
	}
	
	double avg_A = (sum_A*1.00)/count_A;
	double avg_B = (sum_B*1.00)/count_B;
	
	res[0] = avg_A;
	res[1] = avg_B;
	
	return;
}

