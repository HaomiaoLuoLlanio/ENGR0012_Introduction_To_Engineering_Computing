#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double payment(double tickets);
void ratings(double festdata[][2],int rowcount);

int main(){
FILE *nameInput;

nameInput = fopen("festival.txt","w");
fprintf(nameInput,"George Bunovich, 4851544");
fclose(nameInput);

int password;

	
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%d",&password);

char choice;

if(password == 5678){
	do{
		printf("Enter the letter P for payment or the letter R for ratings.");
		scanf(" %c",&choice);
	}while(choice != 'R' && choice != 'P');
	
}else{
	printf("Inccorect password. Bye!");
	return 0; 
}
	
	double tickets; 
	
	
	switch(choice){
		case 'P':{
			do{
				printf("Enter the amount of tickets you would like to buy: ");
				scanf("%lf",&tickets);
			}while(tickets <= 0);
			double totalprice = payment(tickets);
			printf("Total payment is $%10.2lf",totalprice);
			break;
		}
		case 'R': {
			FILE *textdata;
			printf("Enter a filename for your music festival data: ");
			textdata = fopen("saturday.txt","r");
			
			double festdata[50][2];
			int rowcount;
			
			while(fscanf(textdata, "%lf %lf", &festdata[rowcount][0], &festdata[rowcount][1]) != EOF){
				rowcount++;
			}
				fclose(textdata);
				
			
			
			
			
		}
	
}







	return 0;
}


double payment(double tickets){
	double total;
	total = tickets* 33 + (1/5) * (tickets * 33);
	return total;
}

void ratings(double festdata[][2],int rowcount){
	char Times[100];
	
	for(int i = 0;i<rowcount;i++){
		if(festdata[i][0]> 3 && festdata[i][0] < 7){
			Times[i] = "A";
		}
		else{
			Times[i] = "B";
		}
		printf("Shift\tRating");
		printf("%c\t%lf",Times[i],festdata[i][1]);
		
	
	
}
















