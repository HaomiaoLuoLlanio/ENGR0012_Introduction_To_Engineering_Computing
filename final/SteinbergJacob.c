#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


double Payment(int);
int main()
{
	//1
	FILE *fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current User: Jake Steinberg, jws189");
	fclose(fp);
	
	//2
	int password;
	printf("Music Festical 2026. Enter your 4-digit password: ");
	scanf(" %d", &password);
	//3
	if(password != 5678){
		printf("Inccorrect password. Bye!");
	}
	//4
	char usrChoice = 'R';
//	do{
//	printf("Type P to chose print or R for ratings: ");
//	scanf(" %c", &usrChoice);
//	}while(usrChoice != 'R' || usrChoice != 'P');
		
	//5
	switch(usrChoice){
		case 'P':{
			//6
			int tickets;
			double cost;
			do{
			printf("How many tickets would you like to purchase: ");
			scanf(" %d", &tickets);
			}while(tickets < 0);
			//7
			cost = Payment(tickets);
			//8
			printf("Total payment is $%10.2lf", cost);
			break;
		}
		case 'R':{
			//9
			char filename[20];
			printf("Enter a filename for your festival data: ");
			scanf(" %c", &filename[20]);
			while(filename[20] != 'saturday.txt'){
			printf("Enter a filename for your festival data: ");
			scanf(" %c", &filename[20]);
			}
			
			//10
			int data[][2];
			int rows=0;
			FILE *fp2;
			fp2 = fopen(filename[20], "r");
			while(rows != EOF){
				rows++;
			}
			fclose(fp2);
			//11
			
			//12
			fp = fopen("festival.txt", "a");
			fprintf("The average rating for shift A is %lf and the average rating for shift B is %lf", , )
			fclose(fp)
			
			break;
		}
		default:{
			break;
		}
	}
	
	return 0;
}


double Payment(int numTickets){
	int total;
	total = numTickets*33 + .2*numTickets*33;
	return total;
}

double Ratings(){
	//A
	int rows;
	int Times[rows][2];
	
	//B
	printf("Shift\tRating\n");
	for
	
	
	//C
	
	
}
