#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Ratings(float[100][2], int);
double payment(int);
int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("festival.txt","w"); //opens festival text file
	fprintf(fp,"Current user: Maxwell Harder, MAH974");
	fclose(fp);
	int password;	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &password);
	if(password != 5678){
		printf("Incorrect password. Bye!");
		return 1;
	}
	char let;
	printf("Enter P for payment or R for ratings: ");
	scanf(" %c", &let);
	while(let != 'P' && let != 'R'){
		printf("Enter P for payment or R for ratings: ");
	scanf(" %c", &let);
}

switch (let){
	case 'P':
	{
		int tix;
		printf("How many tickets are you ordering? ");
		scanf("%d", &tix);
		while(tix<=0){
			printf("How many tickets are you ordering? "); //checks to make sure that tickets is a value graeter than 0
		scanf("%d", &tix);
	}
	printf("Total payent is $%.2lf", payment(tix)); //Correctly displays price of tickets
	
	break;
	}
	case 'R':
	{
		FILE *fp2;
		char fileName[50];
	printf("Enter a file name: ");
	scanf(" %s", &fileName[50]);
	fp2 = fopen(fileName, "r");
	while(fp2 != NULL){
		printf("Enter a file name: ");
	scanf(" %s", &fileName[50]);
	fp2 = fopen(fileName, "r");
	}
	float data[100][2];
	int rows;
	while(fscanf(fp2,"%f %f", &data[rows][0],&data[rows][1])!=EOF){ //Gets number of rows in file using EOF
		rows++;
	}
	fclose(fp2);
	Ratings(data, rows);
	
	
	break;	
	}
}
	fclose(fp);
	return 0;
}

double payment(int ticks){
	int total = ticks * 33 + (1/5) * (ticks*33); 
	
	return total;
}

void Ratings(float arr[100][2], int rows){
	char Times[rows];
	for (int i = 0; i<rows; i++){
		if(arr[i][1] >=3 && arr[i][1] <7){
			Times[i]='A';
		}else{
			Times[i] = 'B';
		}		
	}
	printf("Shift\tRating\n");
	for(int j = 0; j<rows; j++){
		printf("%c\t%lf\n",Times[j], arr[j][1]);
	}
}


