#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double Payment(int);
void Ratings(double [][2], int)

int main(){
	FILE *fp1;
	fp1 = fopen("festival.txt", "w");
	fprintf(fp1, "Current user: Xander Magiera, xrm1");
	fclose(fp1);
	int password;
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d", &password);

	if (password!=5678){
		printf("Incorrect password. Bye!\n");
		return 1;
	}
	else{
	char usrInput;
		printf("Please enter P for payment or R for ratings.\n");
		scanf(" %c", &usrInput);
		while (usrInput != 'P' && usrInput != 'R'){
		printf("Please enter P for payment or R for ratings.\n");
		scanf(" %c", &usrInput);
		}
				switch(usrInput){
			case 'P':
			int tickets;
			printf("Enter an integer value corresponding to how many tickets you'd like to purchase: \n");
			scanf("%d", &tickets);
			while(tickets<0){
			printf("Enter an integer value corresponding to how many tickets you'd like to purchase: \n");
			scanf("%d", &tickets);
			double totalmoney;
			totalmoney = Payment(tickets);
			printf("Total payment is $%10.2lf", totalmoney);
			}
			
			break;
			
			case 'R':
			char filename[50];
			FILE *fp2;
			printf("Enter file name: \n");
			scanf("%s", &filename);
			fp2 = fopen(filename, "r");
			while(fp2 == NULL){
			printf("Enter file name: \n");
			scanf("%s", &filename);
			fp2 = fopen(filename, "r");
				}
			int check = 0;
			int idx = 0;
			double arr[][2];
			while(check != EOF){
					fscanf(fp2, "%lf %lf", &arr[idx][0], &arr[idx][1]);
				}
				fclose(fp2);
				int rows = idx-1;
				Ratings(arr, rows);
				
			break;
		}
	}

	
	
	
	return 0;
}



double Payment(int ntickets){
	double total = ntickets+0.0*3+ntickets+0.0*33*1/5;
	return total;
}

void Ratings(double arr2[][2], int rws){
	char Times[rws][1];
	for(i = 0; i<rws; i++){
		
		}
	
}
