#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


float payment(int numtix){ //function to calculate tot. cost for person based on how many tix they want
	float total = 0;
	total = numtix*33 + (1/5)*(numtix*33);
	return total;
	
}


float Ratings(char Times[], float col1[]){
	for (int i = 0; i<row; i++) {
		if (col1[i] >=3 && col1[i] <7){
			Times[i] = 'A';
		}
		else if (cols1[i] >= 7) {
			Times[i] = 'B';
		}
		
		
	}
	
}

int main() {
	
	FILE *fp;
	char festival[100]; //creating a file and then closing it
	fp = fopen(festival, "w");	
	fclose(fp);
	
	printf("Current User: Amani Sterling, ars816.");
	
	int pw;
	char choice;
	int CORRECT = 5678;
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pw);
		if (pw != CORRECT) {
			printf("Incorrect password. Bye!\n");
			return 1; //return 1 should cause break in program and nothing else will run
		}
		else if (pw == CORRECT) {
			do //do function to error check that person inputs either P or R
			{
				printf("Please enter P for payment or R for ratings: ");
				scanf(" %c", &choice);
					if (choice != 'P' || choice != 'R') {
						printf("Please choose P or R.\n");
					}
			} while (choice != 'P' || choice != 'R');
			
				switch (choice)
				{
					case 1:
					int numtix;
					
					do { //do function to error check that person selects + number of tickets they would like to buy
						printf("Please enter an integer value corresponding to the number of festival tickets you'd like to purchase: ");				
						scanf("%d", &numtix);
							if (numtix < 0) { 
								printf("Number greater than 0.\n");
							}
					} while (numtix < 0);
						
					float cost = payment(numtix);
					
					printf("Total payment is $%10.2lf", cost);
	
						break;
					case 2: 
					float col1[100];
					float col2[100];
					int rows;
					FILE *nfp;
					
					while (fscanf(nfp, "%f %f", &col1[100], &col2[100]) == 2){ // scanning through to end of file to determine number of rows 
						rows++;
					}
					
					char Times[rows];
					
					
					
					fopen(festival);
					
					float Ratings(char Times[], col1[])
					fprintf("The average rating for Shift A is ## and the average rating for shift B is ##", ?, ?);
					
				
						break;
						
					
					
					
					
				
				}
				
			
		}
		}
	
	
	return 0;
}

