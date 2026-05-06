#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// prototypes
float payment(float)
void ratings(char, float)

float main() {
	FILE *(fp);
	fp = fopen("festival.txt", "w");
	fprintf("Current User: Henry Leopold, hpl13\n", 'w');
	int x = 5678;
	int y = 0;
	scanf("Music Festival 2026. Enter your 4-digit password: &d/n", y);
	if (y != x) {
		printf("Incorrect password. Bye!/n");
	}
	else {
		char pass;
		scanf("please enter P for payment or R for ratings: %s\n", pass);
		while (pass != P || pass != R) {
			scanf("please enter P for payment or R for ratings: %s\n", pass);
		}
		switch (pass) {
			case P {
				float t = 0.0;
				printf("Please enter the number of festival tickets you wish to purchase: %lf\n", t);
				while (t <=0) {
					printf("Please enter the number of festival tickets you wish to purchase: %lf\n", t);
				}
				float p = 0.0;
				payment(t, p);
				printf("Total payment is $%.2lf10\n", p);
				break;
			}
			case R {
				char filename;
				printf("Please enter a filename for the music festival data: \n%s\n", filename);
				while (filename != "saturday.txt") {
					printf("Please enter a filename for the music festival data: \n%s\n", filename);
				}
				fopen = ("saturday.txt", 'r');
				// EOF
				fclose = ("saturday.txt");
				float shiftA = 0.0;
				float shiftB = 0.0;
				char testAB;
				char Times[][] = 
				// Ratings fucntion
				fopen = "saturday.txt"
				printf("The average rating for Shift A is %lf and the average rating for Shift B is %lf", shiftA, shiftB);
				fclose = ("saturday.txt");
				break
			}
		}
	}
	return 0;
}




float payment(float t, float p) {
	p = (t*33)+(.2*(t*33));
	return p;
}

void ratings(Times, shiftA, shiftB, testAB) {
	for (int i = 0; i <= Times[EOF]; i++) {
		for (int j = 0; j <= Times[i][EOF]; j++) {
			if (Times[i] =
		}
	}
}
