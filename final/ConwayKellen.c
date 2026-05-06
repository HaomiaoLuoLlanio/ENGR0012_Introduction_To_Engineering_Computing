#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int Payment(int);
void Ratings( *float, int);
int main() {
	int pass, tickets, total, rows;
	char choice;
	FILE *Pointer;
	Pointer = fopen("festival.txt","w");
	fprintf(Pointer,"Current User: Kellen Conway, krc216");
	fclose(Pointer);

	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d",&pass);
	
	if (pass != 5678) {
		printf("\nIncorrect password. Bye!");
		
		}
	printf("\nEnter a P for payment or an R for ratings!");
	do {
		scanf(" %c",&choice);
		}
	while (choice != 'P' && choice != 'R');
	
	switch (choice) {
		case 'P': {
			printf("\nEnter the number of tickets you wish to purchase: ");
			do {
				scanf(" %d",&tickets);
				}
			while (tickets<1);
			// payment function
			total = Payment(tickets);
			printf("Total payment is $%10d", total);
			break;
			}
		case 'R': {
			FILE *Pointer;
			float check = 0, arrayX[200];
			int i=0;
			//char filename[50];
			//do {
				//scanf("%s",&filename);
				
				//}
			//while (filename[50] == "saturday.txt");
			Pointer = fopen("saturday.txt","r");
			
			while(1) {
				check = fscanf(Pointer,"%f",&arrayX[i]);
				printf("%f",check);
				if (check == EOF) {
					printf("%f",check);
					break;
					}
				printf("%f",arrayX[i]);
				rows++;
				i++;
				}
			fclose(Pointer);
			}
		default: {
			
			
			
			
			
			}	
			
		}
	
	
	return 0;
}

int Payment(int tickets) {
	int total;
	total = (tickets*33) + (1/5)*(tickets)*(33);
	return total;
	}

void Ratings(float *arrayX[200], int rows) {
	int i;
	char Times[200];
	printf("Shift\tRatings");
	for (i=0;i<=rows;i++) {
		
		if (*arrayX[i] < 7) {
			Times[i] = 'A';
			}
		else {
			Times[i] = 'B';
			}
		printf("%c\t%f", Times[i], );
		}
	}




