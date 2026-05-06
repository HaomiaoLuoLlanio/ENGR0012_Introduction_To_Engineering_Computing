#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function prototypes
double Payment(double);
void Ratings(int, float[][2], float[])


int main()
{
	// Creating and writing in the file
	FILE * pointer;
	pointer = fopen("festival.txt", "w");
	fprintf(pointer,"Current user: Ava Barzen, alb923");
	fclose(pointer);
	
	// Asking the user for the passcode
	printf("Music Festival 2026. Enter your 4-digit password: ");
	int password;
	scanf("%d", &password);
	if (password != 5678) // If the password is wrong print and then leave the loop
	{
		printf("Incorrect password. Bye!");
	}
	else if (password == 5678)// If the password is correct do this section of the loop
	{
		printf("What would you like to do? Enter P for Payment or R for Ratings: ");
		char choice;
		scanf(" %c", &choice);
		// Error checking for either R or P indefinitely
		while(choice != 'R' && choice != 'P')
		{
			printf("What would you like to do? Enter P for Payment or R for Ratings: ");
			scanf(" %c", &choice);	
		}
		
		switch(choice)
		{
			case 'P':
			{
				printf("Please enter an interger value for the number of tickets you would like to buy: ");
				double tickets;
				scanf("%lf", &tickets);
				while(tickets < 0) // Error checking number of tickets
				{
					printf("Please enter an interger value for the number of tickets you would like to buy: ");
					scanf("%lf", &tickets);	
				}
				// Calling the Payment function
				double total = Payment(tickets);
				
				// Displaying the total recieved from the function	
				printf("Total payment is $%10.2lf", total);	
				break;
			}
			case 'R':
			{
				// Getting the file name from the user
				printf("Please enter the name of your music festival data file: ");
				char filename[50];
				scanf("%s", &filename);
				FILE * pointer2;
				pointer2 = fopen(filename, "r");
				while(pointer2 == NULL) // Error checking the file name
				{
					printf("Please enter the name of your music festival data file: ");
					scanf("%s", &filename);
					FILE * pointer2;
					pointer2 = fopen(filename, "r");	
				}
				float array[][2];
				int check;
				int var;
				int count = 0;
				while (1) // Checking for the end of file
				{
					check = fscanf(pointer2, "%lf", &var );
					if (check == EOF)
					{
						break;
					}
					count = count + 1;
				}
				int rows = count/2;
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						fscanf(pointer2, "%f",array[i][j]);
					}
				}
				float average[2];
				// Calling the Ratings function
				Ratings(rows, array[][2], average[])
				pointer2 = fopen("festival.txt", "a");
				fprintf(pointer2, "The average rating for Shift A is %f and the average rating for Stift B is %f", average[1], average[2]);
				fclose(pointer2);
				
				break;
			}
		}
		
		
		
		
	}
	
	
	return 0;
}

// Functions
// Payment function
double Payment(double tickets)
{
	double total = 0;
	total = (tickets*33) + ((1/5)*tickets*33);
	return total;
}

//Ratings function
void Ratings(int rows, float array[][2], float average[])
{
	char Times[rows];
	for int i = 0; i < rows; i++)
	{
		if (array[i][0] >= 3 && array[i][0] < 7)
		{
			Times[i] = 'A';
		}
		else if (array[i][0] >= 7)
			{
				Times[i] = 'B';
			}
	}

	printf("Shift \t Rating");
	float sumA = 0, countA = 0;
	float sumB = 0, countB = 0;
	for (int i = 0; i < rows; i++)
	{
		printf(" %c\t%f\n", Times[i], array[i][1);
		if(Times[i] == 'A')
		{
			sumA = sumA + array[i][1];
			countA = countA + 1;
		}
		else if (Times[i] == 'B')
		{
			sumB = sumB + array[i][1];
			countB = countB + 1;
		}
	}
	float average[2]
	average[1] = sumA/countA;
	average[2] = sumB/countB;
	return;
}
}




