#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float Payment(int tickets);

VOID Ratings(float Times, float Ratings);

int main()
{
	FILE *file;
	file=fopen("festival.txt" , "w");
	fprintf(file, "Current user: Nirvan Harrell,nih150");
	fcloseall
	
	printf("Music Festival 2026. Enter your 4 digit password:\n");
	float pass;
	scanf("%f", pass);
	if (pass =! 5678){
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	
	
	char user=a;
	do 
		printf("Enter the letter P for payment or the letter R for ratings.\n");
	while (user =! "P" || user =! "R")
		scanf("%c", user);
	
	switch user
	
	case P
	int integer;
	float total;
	printf("Please enter an integer value for how many tickets you want.\n");
	total=Payment(integer);
	printf("Total Payment is $10.2%f", total);
	break;
	
	case R
	printf("Please enter a file name for your music festival data\n");
	char[100] userfile;
	scanf("%99s", userfile);
	file=fopen(userfile, "r");
	float row1[100];
	float row2[100];
	int i=0;
	
	while (fprintf(file, "%f", "%f", row1[i], row2[i])==2){
		i++
	}
	fcloseall
	
	Ratings(row
	
	
	
	return 0;
}

float Payment(int tickets); {
	float total;
	total=tickets*33+tickets*33/5;
	return total;
}

VOID Ratings(float Times, float Ratings); {
	char[100] Times2;
	int i=0;
	while (Times[i]>0) {
	if (Times[i]<7) {
		Times2[i]=A;
	}
	else {
		Times2[i]=B;
	}
	i++;
}
	printf("Shift\tRating\n");
	int i=0;
	while (Times[i]>0); {
		printf("%99s\t%.6f\n", Times2[i], Ratings[i]);
	}
	float aavg;
	float bavg;
	int countA;
	int countB;
	while (Times[i]>0)
	if (Times2==A) {
		aavg=aavg+Ratings[i];
		countA++;
	}
		else {
		bavg=bavg+Ratings[i];
		countB++; }
		aavg=aavg/countA;
		bavg=bavg/countB;
		Times2[98]=aavg;
		Times2[99]=bavg;
	return VOID
}
		
	
