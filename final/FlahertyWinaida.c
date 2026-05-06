#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//small section for functions below:
double Payment(int);
void Ratings(float [][2],int,float [2]){


int main(){
	FILE*ft;
	//Question 1
	ft = fopen("festival.txt","w");
	fprintf(ft, "Current User: Winaida Flaherty, wmf25\n");
	fclose(ft);
	
	//Question 2
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d",&password);
	
	//Question 3
	if(password != 5678){
		printf("Incorrect password. Bye!\n");
		return 1; //returning 1 ensures that the program ends without going onto next steps.
	}
	
	//Question 4
	char opt1;
	do{
	printf("Enter P for payment or R for ratings\n");
	scanf(" %c", &opt1);
	} while(opt1 != 'P' || opt1 != 'R'); //note: only P and R are accepted, not p or r.
	
	//Question 5
		//Below is the resting place of all variables
	int ticket, check, rows,i;
	double total;
	char fn[100];
	float arr[100][2],avg[2];
	FILE*fp;
	FILE*ft2;
	
	switch (opt1){
		case 'P':
		//Question 6
		printf("Enter the number of tickets you wish to purchase:\n");
		scanf(" %d", &ticket);
		
		//Question 7
		total = Payment(ticket);
		
		//Question 8
		printf("Total payment is %10.2lf\n",total);
		break;
		case 'R':
		
		//Question 9
		printf("Enter a file name for music festival data:\n");
		scanf("%s",fn);
		fp = fopen(fn, "r");
		
		while (fp == NULL){ //make sure that the file is actually a file and not not a file using the pointer.
		printf("Enter a file name for music festival data:\n");
		scanf("%s",fn);
		fp = fopen(fn, "r");
		}
		
		//Question 10
		while (check != EOF){
		check = fscanf(fp, "%f %f", arr[i][0],arr[i][1]);
		i++;
		}
		rows = i-1;
		fclose(fp);
		
		//Question 11
		Ratings(arr[][2], rows, avg[2]);
		
		//Question 12
		ft2 = fopen("festival.txt","a");
		fprintf(ft2, "The average rating for Shift A is %f and the average rating for Shift B is %f\n",avg[0],avg[1]);
		fclose(ft2);
		
		
	}
	
	
	return 0;
}


//Here lies the functions.
double Payment(int num){
	double tot;
	tot = num*33.0+0.2*num*33.0;
	return tot;
}

void Ratings(float rat[][2],int rows, float avg[2]){
	//A
	char Times[rows];
	float sumA = 0, sumB = 0, countA =0, countB=0;
	for (int i=0;i<rows,i++){ 
		if (rat[i][0] > 3 && rat[i][0] < 7){
			Times[i] = 'A';
			sumA = rat[i][1] +sumA;
			countA = countA +1;
			}
		else{
			Times[i] = 'B';
			sumB = rat[i][1] +sumB;
			countB = countB +1;
			}
		}
	
	//B
	printf("Shift\tRating\n");
	for (int j=0;j<rows,j++){ 
			printf("%c\t%f\n",Times[j],rat[j][1]);
		}
	
	//C
	avg[0] = sumA/countA;
	avg[1] = sumB/countB;
	
}
