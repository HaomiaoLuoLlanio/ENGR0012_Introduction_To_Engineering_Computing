#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float Payment(int);

int main()
{
	FILE *festival = fopen("festival.txt", "w");
	fprintf(festival, "Current user: Luke Peralta, LAP269");
	fclose(festival); // Printing to file
	
	printf("\nMuisc Festival 2026. Enter your 4-digit password:");
	int usrpass;
	scanf("%d", &usrpass);
	
	if (usrpass == 5678)
	{
		
		char usrchoice;
		do{
			printf("\nEnter P for payment or R for ratings: ");
			scanf("%c", &usrchoice);
		} while(usrchoice != 'P' && usrchoice != 'R');
		
		switch (usrchoice){
		
		case 'P':
		
		printf("\nEnter how many festival tickets you would like to purchase as a positive integer: ");
		int usrtickets;
		scanf("%d", &usrtickets);
		
		while (usrtickets < 1)
		{
		printf("\nEnter a positive integer");
		scanf("%d", &usrtickets);
		}
		float total;
		total = Payment(usrtickets);
		printf("\nTotal payment is $%10.2lf", total);
		break;
		
		case 'R':
		FILE *fp;
		char usrfilename[100];
		do{
		printf("\nEnter a file name for your music festival data : ");
		scanf("%s", &usrfilename);
		fp = fopen(usrfilename, "r");
	} while(fopen(usrfilename, "r") == 0);
	
	int t = 0;
	ratings[t][2];

	while (fscanf(fp, %d %d, &ratings[t][0], &ratings[t][1]) != EOF)
	{t++}
		
	
	
	
	}
		
		
	}
	else 
	{
		printf("Incorrect password. Bye!");
	}
	return 0;
	}

	float Payment(int usrtickets)
	{
		float total;
		total = usrtickets*33+0.2*usrtickets*33;
		return total;
	}
	
	
	void Ratings(filename)
	int v;
	char Times[v]
	
	FILE *fp = fopen(filename, "r");
	
	while 
	
