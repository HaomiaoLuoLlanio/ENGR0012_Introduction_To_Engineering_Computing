#include <stdio.h>

float payment (int numTickets){
	float price;
	price = (numTickets*33) + (1/5)*(numTickets*33);
	return price;
}

void ratings(int rows, float festival[2][rows]){
	char times[rows];
	int acount, asum, asum, bcount, bsum;
	float aratings[rows], bratings[rows];
	for(int i=0; i<rows; i++){
		if(festival[0][i] < 7){
			times[i] = 'A';
			asum = asum + festival[1][i];
			aratings[acount] = festival[1][i];
			acount++;
			
		} else if (festival [0][i] > 7){
			times[i] = 'B';
			bsum = bsum + festival[1][i];
			bratings[acount] = festival[1][i];
			bcount++;
		}
		printf("Shift\tRating");
		for (int i=0; i<rows; i++){
			printf("%c" times[i];
		}
	}
	
}

int main(){
	
	FILE*meow = fopen("festival.txt", "w");
	fprintf(meow, "Current user: Eduardo Romero, DDR42");
	fclose(meow);
	
	char pass[4];
	printf("Music Festival 2026. Enter your 4-digit passoword: ");
	scanf(" %s", pass);
	if(pass[0] == '5' && pass[1] == '6' && pass[2] == '7' && pass[3] == '8'){
		char prchoice;
		while(prchoice != 'P' && prchoice != 'R'){
			printf("Press P to view payments and press R to view ratings: ");
			scanf(" %c", &prchoice);
		}
		
		switch (prchoice){
			case 'P':{
				int tickets = 0;
				float price;
				while(tickets <= 0){
				printf("Enter the number of tickets you would like to purchase: ");
				scanf("%d", &tickets);
				price = payment(tickets);
				printf("Total payment is $%10.2f", price);
				break;
				}	
			}
			case 'R':{
				char filename[100];
				printf("Please enter a file name: ");
				scanf("%s", filename);
				FILE*meow2 = fopen(filename, "r");
				while (meow2 == NULL){
					printf("Please enter a file name: ");
					scanf("%s", filename);
					meow2 = fopen(filename, "r");
				}
				int rows = 0;
				float thing1, thing2;
				while(fscanf(meow2, "%f %f", &thing1, &thing2) != EOF){
					rows++;
				}
				float fratings[2][rows];
				for (int i=0; i<rows; i++){
					fscanf(meow2, "%f %f", &fratings[0][i], &fratings[1][i]);
					printf("%f %f\n", fratings[0][i], fratings[1][i]);
				}
				ratings(rows, fratings);
			}
				
			
		}
		
		
	} else{
		printf("Incorrect password. Bye!");
	}
	
	
	return 0;
}

