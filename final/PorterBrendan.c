#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Protypes
double payment(int); // establiushes the function

int Ratings(double[][], int);

int main()
{
	FILE *fpointer
	fpointer=fopen("festival.txt",'w');
	
	fprintf(fpointer,"Current user: Brendan Porter, bmp136\n");
	
	fclose(fpointer);
	
	int password;
	
	printf("Music festival 2026. Enter your 4-digit password\n");
	scanf("%d", &password);
	
	if (password != 5678){
		printf("Incorrect password. Bye!");
	}
	else{
		char pay_rate;
		printf("Enter P for payment of R for ratings\n");
		scanf(" %c", &pay_rate);
		while (pay_rate != 'P' && pat_rate != 'R'){
			printf("Enter P for payment of R for ratings\n");
			scanf(" %c", &pay_rate);
		}
		
	switch (pay_rate){
	
	case 'P':{
		int tickets_num;
		printf("How many tickets would you like\n");
		scanf("%d", &tickets_num);
		
		while (tickets_num<=0){
			printf("How many tickets would you like\n");
			scanf("%d", &tickets_num);
		}
		
		double payment(tickets_num); //calls to function and returns a double variable
		
		printf("Total paymenbt is $$%10.2lf\n",cost);
		break;
	}
	
	case 'R':{
		FILE *fp
		char filename[50];
		
		printf("Enter a filename for your music festival data")
		scanf(" %c", &filename);
		
		fp=fopen(filename, 'r');
		
		while (fp==NULL){
			printf("Enter a filename for your music festival data")
			scanf(" %c", &filename);
		}
		
		int check;
		double music_data[100][2];
		int row=0;
		
		while (check!=EOF){
			check=fscanf(fp, "%lf %lf", musi_data[row][0], music_data[row][1]);
			row=row+1;
		}
		
		fclose(fp);
		
		int Ratings(double music_data[][2], int rows);
		
		break;
	}
	}
}
	
	
	return 0;
}

//Functions

double payment(int tickets_num){
	double cost=0;
	cost=tickets_num*33+1/5*(tickets_num*33);
	return(cost);
}

int Ratings(double music[][2], int rows){
	char times[]
	
	for (int i=0;i<rows;i++){
		if (music[i][0]>=3 && music[i][0]<7){
			times[i]='A';
		}
		else if (music[i][0]>=7){
			times[i]='B';
		}
	}
	printf("Shift\t Rating");
	for (int j=0;j<rows;j++){
		printf("%c\t %c", times[j], music[j][1]);
	}
	
	for (int i=0;i<rows,i++){
		int total;
		total=total+music[rows][i];
		int avg;
		avg=total/rows;
	}
	return(avg);
}







