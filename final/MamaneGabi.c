#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double Payment(int, double);
void Ratings(float[][2], int ,double[2]);
 
int main()
{
	//1
	
	FILE *fout;
	fout = fopen(fout,"festival.txt","w");
	fprintf(fout, "Current user: Gabi, gcm62\n");
	fclose(fout);
	
	//2
	int pw;
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &pw);
	
	char PorR;
	
	if(pw != 5678){
		printf("Incorrect password. Bye!\n");
	} else{
		do{
		printf("Please enter P for payment or R for ratings: \n");
		scanf(" %c", &PorR);
	}while(PorR != 'R' && PorR != 'P');
	}
	
	switch(PorR){
		case 'P':{
		int tix;
		//error checking
		do{
		printf("Please enter an integer value for the number of festival tickets you would like to purchase: \n");
		scanf("%d", &tix);
	}while(tix<=0);
	//end error checking
	double totalP;
		totalP = Payment(tix,totalP); //call function
		printf("Total payment is $%10.2lf\n", totalP);
		break;
	}
		case 'R':{
			FILE* fp;
			char filename[50];
			do{
		printf("Please enter a file name for yotu festival data: \n")
		scanf("%s", &filename);
		fp = fopen(fp,filename,"r");//use "saturday.txt" file
	}while(fp == NULL);
	
	float RatingsA[][2];
	int check = 0;
	int idx = 0;
		while(check != EOF){
			check = fscanf(fp, "%f %f", RatingsA[idx][0], RatingsA[idx][1]);
			idx = idx+1;
		}
		fclose(fp);
		idx = idx-1;//correct for extra
		double AVG[2];
		Ratings(RatingsA[][2],idx, AVG[2]);
		FILE *Fpoint;
		Fpoint = fopen(Fpoint, "festival.txt", "a");
		fprintf("The average rating for Shift A is %lf and the average rating for Shift B is %lf\n", AVG[0], AVG[1]);
		fclose(Fpoint);
		
		break;
	}
	}
	
	
	
	
	
	return 0;
}


double Payment(int tix, double totalP){
	totalP = (tix*33) + (1/5)*(tix*33);

	return totalP;
}
void Ratings(float RatingsA[][2], int idx,double AVG[2]){
	char Times[idx];
	int ShiftA=0, ShiftB=0, ShiftAi=0, ShiftBi=0;
	for(int i = 0; i<idx;i++){

		if (RatingsA[i][0]<7){
			Times[i] = 'A';
			ShiftA = ShiftA+ RatingsA[i][0];
			ShiftAi = ShiftAi+1;
		}else if (RatingsA[i][1]>=7){
			Times[i] = 'B';
			ShiftB = ShiftB+ RatingsA[i][0];
			ShiftBi = ShiftBi+1;
		}
		printf("Shift\tRating");
		for(int i = 0; i<idx;i++){
			printf("%c\t%lf", Times[i], RatingsA[i][0]);
		}
	}
	
	//calc AVG
	AVG[0] = ShiftA/ShiftAi;
	AVG[1] = ShiftB/ShiftBi;
	
	
}











