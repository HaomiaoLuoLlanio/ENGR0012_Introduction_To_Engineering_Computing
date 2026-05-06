#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	FILE *"festival.txt" = fopen("festival.txt", w);
	
	fprintf("festival.txt", "Current user: Madison Kovacs, MMK202\n");
	fclose("festival.txt");
	
	int password;
	scanf("Music Festival 2026. Enter your 4-digit password: %d\n", password);
	
	if (password != 5678)
	{
		printf("Incorrect password. Bye!");
	}
	else
	
	char inp
	scanf("Enter P for payment or R for ratings: %ch", inp);
	
	if (inp != "P" | inp != "R")
	{
		scanf("Enter P for payment or R for ratings: %ch", inp);
	}
	else
	//make switch case
	switch inp
	{//case p
		case "P"
		{
			int numtix
			scanf("Enter an integer value corresponding to the number of festival tickets you would like to purchase: %d", numtix);
			
			if (numtix <= 0);
			{
			scanf("Enter an integer value corresponding to the number of festival tickets you would like to purchase: %d", numtix);
			}
			else
			float total;
			total = payment(numtix);
			printf("Total payment is $$.2%f", total);
			
			break
		}
		//case r
		case "R"
		{
			char FILE filename;
			scanf("Enter a file name for the music festival data: %ch", filename);
			
			if (filename != "saturday.txt")
			{
				scanf("Enter a file name for the music festival data: %ch", filename);
			}
			else
			
			fopen(filename, r);
			
			float array[rows][cols];
			array[cols] = filename[0,2];
			array[rows] = filename[0,100];
			
			ratings(array[][]);
			
			fopen("festival.txt", w);
			fprintf("festival.txt", "The average rating for shift a is %d and the average rating for shift B is %d", avA, avB);
			fclose("festival.txt");
			
			
			
		
		break
		}
		
	}
	
	return 0;
}
//making payment function
function payment(numtix);
{
	float total;
	total = numtix*33+(1/5)*(numtix*33);
	return total;
}
//making ratings function
function ratings(array[][]);
{
	char times[];
	int i;
	
	for (i == 0, i++);
	{
		if (array[i][1]>=3 && array[i][1] < 7)
		{
			times[i] = "A";
		}
		elseif (array[i][1] >= 7)
		{
			times[i] = "B";
		}
		
		printf("Shift"\t"Rating"\n%ch", times[]);
		int avA
		avA= times[A]/times[cols];
		int avB
		avB=times[B]/times[cols];
		
	}
	
	return avA, avB;
}






