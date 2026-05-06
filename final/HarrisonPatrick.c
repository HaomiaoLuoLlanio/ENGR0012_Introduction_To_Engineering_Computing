#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double payment(int tickets);

int main()
{
	double total;
	char letter;
	char filename[30];
	int rows = 0;
	int idx;
	
	FILE* fp;
	fp = fopen("festival.txt","t");
	if (fp != NULL)
	{
	fprintf(fp,"Current user: Patrick Harrison, pjh90@pitt.edu\n");
	fclose(fp);
	}
	int pass;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &pass);
	if (pass != 5678)
	{
		printf("Incorrect password. Bye!\n");
	}
	else if (pass == 5678)
	{
		do{
			printf("Enter a letter P for payment or the letter R for ratings:\n");
			scanf(" %c", &letter);
		}while(letter != 'P' && letter != 'R');
	}
	switch (letter)
	{
		case 'P':
		{
			int numtic;
			do{
			printf("Enter and integer value for the # of ticets you would like to purchase:\n");
			scanf("%d", &numtic);
		}while(numtic > 0);
		total = payment(numtic);
		printf("Total payment is $%10.2lf\n", total);
		}
		case 'R':
		{
			do{
			printf("Enter a filename for your music festival data:\n");
			scanf("%s", filename);
		}while(filename != "saturday.txt");
		int check;
		float data[][2];
		fp = fopen(filename,"r");
		while(check != EOF)
		{
			fscanf(fp,"%d %lf", data[rows][i]);
			rows = rows + 1;
			idx = idx + 1;
		}
		
		fclose(fp);
		fp 
		}
	}
	
	return 0;
}

double payment(int tickets)
{
	double x;
	x = tickets*33 + (1/5)*(tickets*33);
	return x;
}



