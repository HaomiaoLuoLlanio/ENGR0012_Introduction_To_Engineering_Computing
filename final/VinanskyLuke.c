#include <studio.h>
#include <studlib.h>
#include <math.h>

int payment(float)

int main(){
char file[100];
int ps;
char letter;
float tickets;


FILE *fp 

file=fopen(fp,"w");// the w means we can write over the rile and whatever is on it
fprintf("Current user:Luke Vinansky,LMV63");
fclose(fp);

printf("Music Festival 2026. Enter your 4-digit password");
scanf("%d",&ps);
if(ps != 5678){
	printf("Incorrect password. Bye!");
}
while(ps == 5678){
	
	printf("Enter P for payment or R for ratings");
	scanf(" %c", &letter);
	while (letter != 'P' && letter != 'R'){
		printf("Enter P for payment or R for ratings");
	scanf(" %c", &letter);
}
switch (letter)


case 'P':
{
	printf("Please enter the number of festival tickets you would like to purchase");
	scanf("%d", &tickets);
	while (tickets <= 0){// makes sure that tickets are greater then 0
		printf("Please enter the number of festival tickets you would like to purchase");
	scanf("%d", &tickets);
	}
	total=payment;
	printf("Total Payment is $$10.2%d", total);
	
break;	
}


case 'R';
{
	
	FILE *rf
	printf("Please enter a filename: ");
	fscanf("%d",&rf);
	while (rf == NULL){// NULL error checks for us
	printf("ERROR: Please enter a filename: ");
	fscanf("%d",&rf);
	}
	int status;
	float a_matrix[][] = fopen(fp,"r");
	while(staus != EOF){
	
		for( int i = 0, i > rows, i++){	
		for ( int j =, j > colms, i++){
			a_matrix[i][j]++
		}
	}
}
status = status-1	
fclose(rf);


fopen(fp,"a");
fprintf(fp, "The average rating for Shift A %d and Shift B is %d", );
fclose(fp)
break;	
}
	
}

return 0;
}


int payment(float tickets){
	total = tickets*33 + 1/5 *(tickets *33);
return total;// returns total back to function	
}

void ratings{
int	times[8] ={3, 4, 5, 6, 7, 8, 9, 10};
int i;
char shift;
	if(times[i] == 3, times[i] == 4, times[i] == 5, times[i] == 6, times[i] == 7){// makes sure that it only checks 3-7
		
		shift = "shift A";
		
	}
	else{
	
	shift = "shift B"
}
}
