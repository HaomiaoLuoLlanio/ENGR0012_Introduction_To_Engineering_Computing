#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//declare funcs at top
void Payment(int tix1, float total1);
void Ratings(double sat[][2], int rows);

int main()
{
	FILE *mainfile1 = fopen("festival.txt", "w");
	fprintf(mainfile1, "Current user: Sean Gillin, seg248");
	fclose(mainfile1);
	
	printf("Music festival 2026, enter 4 digit password: \n");
	int password[4];
	for(int i=0;i<4;i++)//scans to all 4 parts of password array
	{
		scanf("%d", password[i]);
	}
	
	char ques1;
	if(password[0]==5 && password[1]==6 && password[2]==7 && password[3]==8)//specific password
	{
		printf("Enter P for payment or R for ratings");
		scanf(" %c", &ques1);
		while(ques1 != 'P' && ques1 != 'R')
		{
			printf("Enter P for payment or R for ratings");
			scanf(" %c", &ques1);
		}
	}
	else
	{
		printf("Incorrect password");
	}
	int tix;
	float total;
	char filename[20];
	switch(ques1)
	{
		case 'P': 
		printf("please enter number of tickets");
		scanf("%d", &tix);
		while(tix <1)
		{
			printf("please enter number of tickets");
			scanf("%d", &tix);
		}
		Payment(tix, total);//calls payment function
		printf("total payment is $%lf10.2", total);
		break;
		
		case 'R': 
		printf("enter a file name for music data");
		scanf("%s", &filename);
		while(fopen(filname) == NULL)
		{
			printf("enter a file name for music data");
			scanf("%s", &filename);
		}
		FILE rfile* = fopen(filename, "r");
		float ratings[2][50];
		while(fscanf("filename") != EOF)//should scan till end of file 
		{
			for(int i2=0;i2<2;i2++)
			{
				for(int j2=0;j2<50;j2++)
				{
					fscanf("filename" "%lf", &ratings[i2][j2]);
				}
		}
		char shift;
		Ratings(shift, ratings[2][50]);
		mainfile1 = fopenf("festival.txt", "a");
		fprintf(mainfile1, "The avg rating for shift a is %lf and for shift a %lf", 
		break;
		
		
	}
	return 0;
}
void Payment(int tix1, float total1)
{
	total1 = tix1 *3 + 0.2*(tix1 *3);
}
Ratings(char shift1, float ratings1[2][50])
{
	char Times[50];
	for(int i=0)
	{
		
	}
}
