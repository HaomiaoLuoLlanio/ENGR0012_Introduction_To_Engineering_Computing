
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//F Prototypes

total Payment(char);
void Ratings();

int main()
{
	
	FILE *festival;
	
	//#1
	festival = fopen("festival.txt", "w");
	fprintf(festival, "Current User: Beatrice Oguku, bno16");
	
	fclose(festival);
	
	//#2
	
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pass);
	
	
	if(pass != 5678)
	{
		printf("Incorrect password. Bye!");
		return 0;
	if else (pass == 5678)
	{
		char result
		printf("Enter the letter 'P' for payment or 'R' for ratings");
		scanf(" %c", &result);
		i++	// COME BACK FOR ERROR CHECKING SECTION	
}
}

//#5 & 6
switch (result)
{
	case 'P'
	{
		int numoftickets;
		printf("Enter the number of festival tickets you want to purchase:");
		scanf("%d", &numoftickets);
		
		if (numoftickets==0){
			printf("Please enter a new value.");
		}
		else {
			
		}
		// MAKE A LOOP FOR ERROR CHECKING
		
	}
	
	case 'R'
	{
		ratings();
}

// #7 & 8
payment();
printf("Total payment is: %10.2d", &payment);

// #9

char filename[50];

printf("Enter the file name for music festival data: ");
do{
	scanf("%s", filename);
	
} while (filename==NULL);


//#10

int matrix[x][y];


// FUNCTIONS			

//figure out if you putint for this
total Payment(char result)
{
	int total;
	total = numoftickets * 33 + ((1/5)*numoftickets);
}
	
void Ratings()

int i, j;
char Times[i][j];

FILE *numbers

numbers = fopen("saturday.txt", "r");
fscanf(numbers, "%d", &i);

if (Times[i]>=3 && Times[i]<7)
{
		printf("A")
		
		if else (Times[i]>7{
			printf("B")
	}
}

printf("Shift /t Rating");
printf("%s", &Times[i][j]);

	
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

