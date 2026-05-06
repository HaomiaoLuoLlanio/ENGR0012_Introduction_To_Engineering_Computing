


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//functions above main dont need to be called at top
float Payment(int ticketnum){
	float total;
	total = (ticketnum * 33) + ((1/5)*ticketnum*33);
	return total;
}


// tried to use empty data data[][] to initialize but its weird with float i think?
void Ratings(int count, float data[100][2]){
	char Times[100];
	int i = 0;
	float sumA;
	float sumB;
	int Acount = 0;
	int Bcount = 0;
	
	for (i = 0; i < count; i++){
		if(data[i][0] >= 3 && data[i][0] <= 7){
			Times[i] = 'A';
			sumA = sumA + data[i][0];
			Acount++;
		}
		else if( data[i][0] >= 7){
			Times[i] = 'A';
			sumB = sumB + data[i][0];
			Bcount++;
		}
			
	}
	
	
	
	printf("Shift\tRating");
	for (i = 0; i < count; i++){
		printf("%c\t%f", Times[i], data[i][0]);
	}
	
	printf("Avg rating for Shift A is %f and for Shift B is %f, sumA/Acount, sumB/Bcount);
}

int main(int argc, char **argv)
{
	
	//variables
	FILE *fp;
	int password = 5678;
	int pass;
	char choice;
	int ticketnum;
	float payment;
	char filename[100];
	float data[100][2];
	int count = 0;
	
	//part 1 opening and closing the file w fprintf
	
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Gideon Dayo, goi7");
	fclose(fp);
	
	
	
	printf("Music Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pass);
	
	if(pass != password){
		printf("Incorrect password. Bye!");
		return 1;
	}
	 
	 
	 //part 4 checking user for input
	printf("Enter the letter P for payment or R for ratings: ");
	scanf(" %c", &choice);
	
	while(choice != 'R' && choice != 'P'){
		printf("Wrong character you may only enter a P or an R");
		scanf(" %c", &choice);
	}
	
	switch(choice){
	
	case 'R':
	printf("Enter a filename for music festival data");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	
	if (fp == NULL){
		printf("Enter a correct filename for music festival data");
	scanf("%s", filename);
	}
	//not sure if EOF is working i think it should be bolded but i use Vscode so i dont know
	while (check != EOF){
		check = fscanf(fp, "%f %f", data[count][0], data[count][1]);
		count++;
	}
	
	fclose(fp);
	
	Ratings(count, data[100][2]);
	
	
	
	
	
	break;
	
	
	case 'P':
	printf("Enter an integer value for the number of festival tickets you want");
	scanf("%d", &ticketnum);
	
	while(ticketnum < 0){
		printf("Enter a positive integer value for the number of festival tickets you want");
		scanf("%d", &ticketnum);
		
		payment = Payment(ticketnum);
		
		printf("Total payment is $%10.2f", payment);
	}
	
	break;
}
	return 0;
}

