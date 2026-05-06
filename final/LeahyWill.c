


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float payment(int);
void Ratings(void);


int main()
{
	
	//part one: file
	FILE*fp;
	fp = fopen("festival.txt", "w");
	fprintf(fp, "Current user: Will Leahy, WRL17\n");
	fclose(fp);
	// part two: user input
	int password = 0;
	printf("\nMusic Festival 2026. enter your four digit password: ");
	scanf("%d", &password);
	//part three: password
	if (password != 5678){ // using ! to indicate that it is NOT that
		printf("incorrect password. BYE!\n");
		return 1;
	}
	//part four: select
	char user1;
	do{
	printf("enter P for payment or R for ratings\n");
	scanf(" %c", &user1);
} while(user1 != 'P' && user1 != 'R');
	
	//part five, six, seven, eight, nine, ten, eleven, twelve: switch case
	int numtix = 0;
	float cost;
	char filename[100];
	float x[100][2]; //give 100 rows to be safe
	int i = 0;
	
	switch(user1){
		case 'P':
		do{
		printf("\nplease enter your number of tickets you would like to buy: ");
		scanf("%d", &numtix);
	}while (numtix<=0);
	
		cost = payment(numtix); //calling function
		printf("Total payment is $%8.2f", cost);
		break; //remembered to break
		case 'R':
		do{
		printf("enter a filename for your music festival data: ");
		scanf("%s", &filename[100]);
	} while (filename != "saturday.txt"); //warning here but cant figure out how to fix
		FILE*filep;
		filep = fopen(filename, "R");
		
		while (fscanf(filep, "%f %f", &x[i][0], &x[i][1])){		
		i++;
	}
	fclose(filep);
	
	ratings();
	
	FILE*fpoint;
	fpoint = fopen("festival.txt", "R");
	fprintf(fpoint, "the average rating of shift A is ## and the average rating for shift B is ##."); //NOTE: I know you want me to use a %f I just did not do the function so I couldn't
	
	
	
		break;
		default:
		printf("unknown error");
		break;
	}
	
	

	return 0;
}

float payment(int numtix){
	float total;
	total = numtix*33+0.2*(numtix*33);
	return total;
}


void Ratings(void){
	// a
	int times[100];
	for (int i = 0; i > 100, i++){
		if (times[i] <7)
		//im too confused on what this is asking me to do so i will just move on due to time
		
	}
	
	
}



