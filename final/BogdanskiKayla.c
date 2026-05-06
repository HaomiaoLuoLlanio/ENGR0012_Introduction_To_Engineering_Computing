#include <stdlib.h>
#include <stdio.h>
#include <math.h>


	//function declaration
	void Payment(int);
	int Ratings();
	
	


int main()
{
	//Part 1 creating and writing file 
	
	FILE*fp = fopen("festival.txt", "w");
	
	while (fp != EOF)
	{
	printf("Curent user:Kayla Bogdanski,KRB252");
	}
	fclose(fp);
	
	// Part 2 asking user to enter password
	
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:/n");
	scanf("%d", &password);
	
	
	//Part 3 error check loop invalid case
	if (password != 5678)
	{
		printf("Incorrect password. Bye!\n");
		/////////
	else
	
	}
	
	
	//Part 4 valid case
	char = P;
	char = R;
	char option;
	If (password == 5678)
	{
		printf("Please enter the letter P for payement or the letter R for Ratings:\n ");
		scanf(" c", &option);
	}
	
	
	//Part 5 and 6 switch case
	
		switch()
			case P:
			{
				int = ticket_number;
				printf("Please enter an integer value for number of tickets you would like to purchase:\n ");
				scanf("%d", ticket_number);
				
				if (ticket_number <= 0)
				{
					/////how to run again
				}
				
				//need to call function payment
				Payment();
				
				//Display Total Payment
				printf("Total Payment is %% %.2lf\n", total);
			}
			
			
			case R:
			{
				//Part 9//
				filename[50];
				FILE*fpp = fopen(filename, "r");
				fprintf("Please enter filename for music festival data: \n");
				fscanf("%s" filename);
				
			valid = "saturday.txt";
				if (filename != valid)
				{
					printf("Invalid file: please retry a different file. \n")
					return 1;
				}
				
				//Part 10//
				
				int rows;
				int arr[rows][2];
				while (fpp != EOF)
				{
					fprintf(fpp, "saturday.txt", "r");
					/////
					
					
				}
				
				fclose(fpp);
				
				//Part 11// call function
				Ratings();
				
				
				//Part 12//
				FILE*fp;
				fopen = (fp,"festival.txt", "a");
				printf("The average rating for Shift A is %.1lf and the average for shift B is %.2lf", shifta, shiftb);
				
				fclose(fp);
				
				
			}
	
	return 0;
}


		//function workspace - tasks
	//fucntion 1 payment 
	//PArt 7 and 8//
		void Payment(int total)
		{
			int G = ticket_number;
		double	total = (G)*33 + (1/5)*(G*33);
			
			return total;
		}
		
		
	//fucntion 2 ratings
		int Ratings();
		{
			char times[][];
			//ran out of time
			
			
			printf("Shift \t Rating");
			printf(""
		}
		
		
		
		
		
		
		
		
