// Joshua Schroll Wood, Zhou 4pm 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//payment
float Payment(int n){
	return (float)((n*30)+((1/5)*n*30));
}

void Rating (double arr[][2], int rows){
	for (int i = 0; i < rows; i++){
		printf("%lf\n",arr[i][1]);
	}
}


int main()
{
	//1
	FILE *file;
	file = fopen("festival.txt","w");
	fprintf(file,"Current user: Joshua Schroll Wood, JPS274");
	fclose(file);
	//2 
	int pass;
	printf("Music Festival 2026. Enter you 4 digit password\n");
	scanf("%d",&pass);
	//3
	if (pass != 5678){
		printf("incorrect password. bye!\n");
		return 0;
	}
	//4 
	char choice;
	float cost;
	char filename[50];
	int i = 0;
	double arr[50][2];
	printf("Enter P for payment or R for ratings: ");
	scanf(" %c",&choice);
	while (choice != 'P' && choice != 'R'){
		printf("Enter P for payment or R for ratings: ");
		scanf(" %c",&choice);
	}
	//5
	switch (choice){
		case 'P':
		//6
		int tick;
		printf("How many tickets:");
		scanf("%d",&tick);
		while (tick <= 0){
			printf("How many tickets:");
			scanf("%d",&tick);
		}
		cost = Payment(tick);
		printf("Total payment is $%10.2f",cost);
		break;
		case 'R':
		//10
		printf("Enter filename: ");
		scanf("%s",filename);
		//while (filename != ){
		//	printf("Enter filename: ");
		//	scanf("%s",filename);	
		//}
		file = fopen(filename,"r");
		while(fscanf(file,"%lf %lf", &arr[i][0], &arr[i][1]) == 2){
			i++;
		}
		Rating(arr,i);
		fclose(file);
		break;
		default:; 
	
}
	return 0;
}

