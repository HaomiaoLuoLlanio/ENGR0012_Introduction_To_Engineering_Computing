#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float paymentfunc(int,int);

int main()
{
	FILE *fp; //unfinished due to time constraints, attempt at creating a writable filr
	fp=fopen('festival.txt',"w");
	fprintf(fp,"Ben Moore, bem239");
	fclose(fp);
	
	int pass;
	char pr;
	int tick;
	float total=0;
	int times[2]={0,0}
	printf("Music Festival 2026. Please enter your 4-digit password: "); //error checks password
	scanf("%d",&pass);
	while (pass!=5678){
		printf("\nIncorrect password. Please try again: ");
		scanf("%d",&pass);
	}
	
	printf("\nPlease enter P for payment or R for ratings: "); //enter for ratings, w/ error check
	scanf(" %c", &pr);
	
	while (pr!='P' && pr!='R'){
		printf("\nInvalid input. Please try again: ");
		scanf(" %c", &pr);
	}
	switch (pr){
		
		case 'P':
		printf("\nPlease enter how many tickets you would like to purchase: ");
		scanf("%d",&tick);
		while (tick<=0){
			printf("\nInvalid number of tickets. Please try again: ");
			scanf("%d",&tick);
		
		}
			total=paymentfunc(tick, total);
			printf("Total Payment is $%10.2f",total);
		break;
		case 'R':
			FILE*newfile;
			char filename[100];
			printf("\nPlease enter filename: ");
			scanf("%s",filename);
			newfile=fopen(filename,"r")
			while (filename!='saturday.txt'){
				printf("Incorrect file. Please try again: ");
				scanf("%s",filename);
				newfile=fopen(filename,"r")
			}
			for (int i=0;i<EOF;i++){
			while (fscanf(newfile, "%d %lf",timrs[0],times[1])) {//unfinished due to time constraints, attempting to read end of file
				if (EOF==
			}
		}
		ratingsfunc()
		break;
	}
	return 0;
}

float paymentfunc(int numtick, int payment){
	payment=(numtick*33)+(0.2*33*numtick);
	return payment;
}

void ratingsfunc(char shift, int times){//unfinished function ratings
	if (times>=3 && times<7){
		shift='A';
	}else{
		shift='B';
	}
	printf("\nShift\tRating\n%c\t%d",shift,times)
	
}
