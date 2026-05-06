
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double payment(int);
void Ratings(float[][2], int);

int main()
{
	//1
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Anthony Watkins, ANW361");
	fclose(fp);
	//2
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:" );
	scanf(" %d", &password);
	//3
	if(password != 5678){
		printf("\nIncorrect password. Bye!");
		return 1;
	}
	//4
	char usrchoice1;
	printf("\nEnter P for payment or R for ratings:" );
	scanf(" %c", &usrchoice1);
	while(usrchoice1 != 'P' && usrchoice1 != 'R'){
	printf("\nEnter P for payment or R for ratings:" );
	scanf(" %c", &usrchoice1);		
	}
	//5
	switch (usrchoice1){
		
		case 'P':
		//6
		{
		int tickets;
		printf("How many festival tickets would you like to purchase?" );
		scanf(" %d", &tickets);
		
		while(tickets<0){
			printf("How many festival tickets would you like to purchase?" );
			scanf(" %d", &tickets);
		}
		//7
		
		double cost = payment(tickets);
		//8
		printf("Total payment is $%10.2lf\n", cost);
		//Call pay function
		}
		
		
		case 'R':
		{
			FILE *POINTER;
			char filename[20];
			int i = 0;
			int check;
			int rows = 0;
			float FestData[50][2];
			//10
			printf("Please enter name for music festival data: ");
			scanf("%19s", filename);
			POINTER =fopen(filename, "r"); 
			while (POINTER == NULL){
				printf("Please enter name for music festival data: ");
				scanf("%19s", filename);
				POINTER =fopen(filename, "w"); 
			}
			while(1){
			check = fscanf(POINTER, "%f" "%f", &FestData[i][0], &FestData[i][1]);
			if (check == EOF){
			rows = i;	
			break;	
			}
			i++;		
			}
			Ratings(FestData, rows);
			fp=fopen(filename, "a"); 
			fprintf(fp, "The average rating for Shift A is %f and the average rating for Shift B is %f", AAvg, AAvg);
			fclose(fp);
			
			 
			
			
			
		}
		
		
	}
		
	
	return 0;
}


double payment(int tickets){
	double cost = 0;
	
	cost = (tickets * 33) + (1/5) * (tickets * 33);
	return cost;
}


void Ratings(float FestData[][2], int rows){
	char times[rows];
	printf("Shift\tRating\n");
	for (int i=0; i<rows; i++){
		if (FestData[i][0] >=3 && FestData[i][0] < 7){
		times[i] = 'A';
		}
		else if (FestData[i][0] >=7){
		times[i] = 'B';
		}
	printf("%c\t%f",	times[i], FestData[i][1]);
}
	float shiftAsum = 0;
	float shiftAnum = 0;
	float shiftBsum = 0;
	float shiftBnum = 0;

	for (int i=0; i<rows; i++){
		if (times[i] == 'A'){
			shiftAsum = shiftAsum + FestData[i][1];
			shiftAnum++;
		}
		else{
			shiftBsum = shiftBsum + FestData[i][1];
			shiftBnum++;	
		}
	
	}
	float AAvg = shiftAsum/shiftAnum;
	float BAvg = shiftBsum/shiftBnum;
}

