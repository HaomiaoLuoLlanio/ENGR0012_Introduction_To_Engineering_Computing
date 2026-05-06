#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int Ratings(void);
int payment(int);


int main()
{

FILE *festival;
fopen("festival.txt", "a");
fprintf("Current user: Owen Mucho, owm22");
fclose(festival);
int password;
printf("Music Festival 2026. Enter your 4-digit password:");
scanf(" %d", &password);
if (password == 5678) {
/////////////////////////////////////////////////////////
	//rest of main inside here
do {
	char letter;
	printf("enter P for payment or R fot ratings");
	scanf(" %c", &letter);
	
	
} while(letter !=P || letter != R);
	switch(letter) {
		case: P
			do {
				int number
				int cost
				printf("Enter an integer value for number of tickets you want);
				scanf(" %d", &number);
				cost = payment(number);
				printf("Total payment is $$%20.2lf", cost);
				break;
			} while(number <1);
		case: R
			do {
				checkprintf("enter file name for their music festval data");
				scanf("%s", file);
				do = fopen(file, "r");
			} while (do == NULL);
			int check;
			int count;
			float array[300][2];
			for (i=0; i<300; i++) {
			check = fscanf(file, "%lf %lf", &array[i][0], &array[i][1]);
				if (check == EOF) {
					
					break;
				}
				else {
				}
			count++;
			}
			count = count - 1;
			fclose(file);
			Ratings()
			fopen(festival.txt, "a");
			fprintf("The average rating for Shift A is %d and the average rating for Shift B is %d", );
			fclose(festival);
		default:
			break;
		}
	
	
	
	
/////////////////////////////////////////////////////////
}
else {
	printf("Incorrect Password. Bye!");
}
	return 0;
}

////functions/////////////////////////////////////////////
	
int payment(int num) {
	int money;
	money = 33 + (33/5)*num;
	return money;
}
	
int Ratings(void) {
char Times[][2]
for (i=0; i<300; i++) {
	
	
	
	
}
	
	
	
	
	
	
	
	
	

