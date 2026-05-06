

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int payment(int t);
int main()
{
	
	
	FILE* fs = fopen("festival.txt", "w");
	fprintf(fs, "Current user: Emanuel DiNatale, ejd126");
	fclose(fs);
	int cp;
	char c;
	int totalc;
	int tickets;
	char filename[20];
	printf("Music Festival 2026.  Enter your 4-digit password:");
	scanf(" %d", &cp);
	if (cp != 5678){
		printf("Incorrect password.  Bye!");
	}
	else
	{
		printf("Enter the letter P for payment or the letter R for ratings: ");
		scanf(" %c", &c);
	}
	//while (error check)
	
	switch (c){
		
		case 'P':{
			printf("How many tickets would you like to purchase?: ");
			scanf(" %d", &tickets);
		totalc = payment(tickets);
			printf("Total payment is $%d", totalc);
			
		}
		
		case 'R':{
			printf("Enter a file name: ");
			scanf(" %c", filename);
			
		}
	}
	
	return 0;
}

int payment(int t){
	int total;
	total = t*33 + (1/5)*t;
	return total;
}
