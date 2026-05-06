#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double payment(int);
double ratings(double [][2],int);

int main()
{
	int password;
	char sw;
	FILE *fp;
	fp = fopen("festival.txt", "c");
	fprintf(fp, "Current user: Owen Chase, oac22");
	fclose(fp);
	printf("Music Festival 2026. Enter your 4-diget password: ");
	scanf("%d", &password);
	
	
	//error check if password is correct
	if (password == 5678){
		printf("enter P for payment, or R for rattings");
		scanf(" %c", &sw);
		while (sw != P && sw != R){
			printf("enter P for payment, or R for rattings");
			scanf(" %c", &sw);
		}
		switch (sw){
			case 'P':
			{
				int tic;
				double total;
				printf("how many tickets?")
				scanf("%d", tic);
				total = payemnt(tic);
				printf("your total is $%10.2lf", total);
				break;
			}
			case 'R':
			{
				char filename[50];
				FILE *fo;
				printf("enter the file name");
				scanf("s", &filename);
				fo = fopen(filename, "R");
				//error check for proper file
				while (fo != NULL){
					printf("enter the file name");
					scanf("s", &filename);
					fo = fopen(filename, "R");
				}
				int check = 0, idx = 0;
				double arr[][2];
				//counting rows, and making the array
				while (check != EOF){
					check = fscanf(fo, "%lf %lf", arr[idx][0], arr[idx][1]);
					idx++;
				}
				fclose(fo);
				int rows = idx-1;
				
				avga,avgb = ratings(arr, rows);
				fp = fopen("festival.txt", "a");
				fprintf(fp, "the average rating for shift A is %lf and the average rating for B is %lf.", avga,avgb);
				fclose(fp);
				
				
				break;
			}
		}
		
		
	}
	else{
		printf("incorrect password. Bye!");
	}
	
	
}
//payment function for P switch case
double payment(int tic)
{
	double total= 0;
	total = (tic+0.0)*33 +(1/5)*(tic+0.0)*33;
	return total;
} 



//ratings function for R switch case
double ratings(double arr[][2],int rows){
	char time[];
	
	for (int i = 0, i<rows, i++){
		if (arr[i][0] > 3 && arr[i][0] <7){
			time[i] = "A";
		}
		if (arr[i][0] > 7){
			time[i] = "B";
		}
	}
	printf("shift \t Rating");
	
	for (int i = 0, i<rows, i++){
			printf(" %c \t %10.2lf", time[i], arr[i][1]);
		}
	//average rating in shifts
	double avga, avgb;
	int totala=0, totalb=0, counta = 0, countb = 0;
	for (int i = 0, i<rows, i++){
		if (time[i] == 'A'){
			totala = (totala + time[i]);
			counta++
		}
		if (time[i] == 'B'{
			totalb = totalb + time[i];
			countb++
		}
		avga = (totala+0.0)/counta;
		avgb = (totalb+0.0)/countb;
		return (avga,avgb);
	}
}






