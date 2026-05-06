#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *festive;
	festive = fopen("festival.txt", "w");
	fprintf(festive, "Current user: Tudor Albu, tna17");
	fclose(festive);
	int password;
	char choice;
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);	
if (password == 5678) {
		printf("Enter letter P for payment or letter R for ratings: \n");
	scanf("%c", &choice);
	while (choice != 'P' || choice != 'R') {
	printf("Enter letter P for payment or letter R for ratings: \n");
	scanf("%c", &choice);
	}
}
else
	{
		printf("Incorrect password. Bye!\n");
		return 1;
	}
	int purchase;
	float result;	
	FILE fp*
	char filename[50];
	float array[][2]
	int check, idx;
	switch (choice){
		case 'P':
		printf("Enter how many tickets you would like to purchase: \n");
		scanf("%d", &purchase);
		while(purchase<0){
		printf("Enter how many tickets you would like to purchase: \n");
		scanf("%d", &purchase);	
		}
		result = payment(purchase);
		printf("Total payment is $%10.2f\n");
	    break;
		case'R':
		printf("Please enter a file name for music festival data: \n");
		scanf("%s",filename);
		fp=fopen(filename, "r");
		while(fp == NULL){
			printf("Please enter a file name for music festival data: \n");
		scanf("%s",filename);
		fp=fopen(filename, "r");
	}
	while(check != EOF){
		
		break;
		
	}

	
	
	return 0;
}
float payment(tickets){
	float total;
	total = (tickets+(0.0)*33)+(0.2*tickets+(0.0)*33);
	return total;
}
