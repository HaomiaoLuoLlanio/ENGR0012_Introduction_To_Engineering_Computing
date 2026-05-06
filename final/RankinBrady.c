#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Payment(int);
int Ratings(int);

int main()
{
	FILE*fp;
	fp=fopen("festival.txt","w"); //Writes over the file that we have
	fprintf(fp,"Current user: Brady Rankin, ber122");
	fclose(fp);
	
	int password=0;
	char usr_choice;
	printf("Music festival 2026. Enter your 4 digit password:");
	scanf("%d",&password);
	
	if (password!=5678){ //Puts user in a loop where they cant leave
		printf("Incorrect password, Bye!");
	}
	else { //Used for the rest of the function
		printf("Please enter P for payment or R for Ratings: ");
		scanf(" %c", &usr_choice); 
		
		while (usr_choice!= 'P' && usr_choice != 'R') {
		printf("Please enter P for payment or R for Ratings: ");
		scanf(" %c", &usr_choice);
	}
		
		switch (usr_choice) {
			case 'P':
			int tickets=0;
			int Total=0;
			printf("Please enter a number of tickets you want to purchase");
			scanf("%d",&tickets);
			while (tickets<=0) {
				printf("Please enter a number of tickets you want to purchase");
				scanf("%d",&tickets);
			}
				Total=Payment(tickets);
				printf("Total Payment is $%10.2d",Total);
				break;
			
			case 'R': //These cases are where the cose splits ints two
			char filename[50];
			FILE*fest;
			printf("Please enter a filename for the music festival data");
			scanf("%s",&filename);
			fest=fopen(filename,"r");
			while (fest==NULL) { 
			printf("Please enter a filename for the music festival data");
			scanf("%s",&filename);
			}
			int check=0;
			int idx=0;
			while (check!=EOF) {
			check=printf("%d %d",filename[idx][0],filename[idx][1]);
			idx=idx+1;
		}
		rows=idx-1
			
			break;
			
			default:
			
			break;
	}
	
	}
	
 return 0;	
}

int Payment(tickets){
	int total=0;
	total=(tickets*33)+((1/5)*(tickets*33);
	return total; //We want to return this back to the function
}

int Ratings(rows) {
	char times[][0]
	for (int i=0,i<rows,i++)
	if (filename[i][0]<7) {
		time[i][0]=filename[i][0];
	}
	


