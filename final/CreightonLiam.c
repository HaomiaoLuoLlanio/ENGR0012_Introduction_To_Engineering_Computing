#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double Rating(char [][])
void Payment (ticketnum, int )


int main()
{
	FILE*fp=fopen("festival.txt","w"); //this is how you write into a file
	fprintf(fp,"\"Current user: Liam Creighton, LIC269\"\n");
	fclose(fp);
	
	printf("Music Fest 2026. Enter your 4-digit password: ", password);
	scanf("%d",password);
	if(password!=5678){
		printf("Incorrect password. Bye!");
		return 1;
	}
	
	printf("Please enter the letter P for payment of the letter R for ratings: ");
	scanf("% c",&choice);
	
	char choice;
	while (choice!=P||choice!=R){ //error checking to make sure that the choice is either P or R
	printf("Please enter the letter P for payment of the letter R for ratings: ");
	scanf("%c",choice)
}
	
	switch ()
	{
		case P:
		{
			printf("Please enter the amount of tickets you would like: ");
			scanf("%d", ticketnum);
			if(ticketnum<=0){
			printf("Please enter the amount of tickets you would like: ");
			scanf("%d", ticketnum)	
			}
			printf("Total payment is \$10.2lf", ticketnum)
			break;
		}
		
		case R:
		{
			printf("Please enter a file name: ");
			scanf("%s", filename);
			if(filename==NULL){ //this is the error checking used to make sure the file exists
			printf("please enter number of tickets");
			scanf("%d", filename);	
		}
		int rows=0
		int count=0
		FILE*filename=fopen("??","r"); // this is how you read into a file
		for(int i=0; i<rows; i++){
			for(int j=0;j<rows;j++){
				fprintf(filename,"");
				
				
			}
		}
		Ratings(Times[][])
			break;
		}
		
		default:
		
	}
FILE*fp=fopen("festival.txt","a"); //this is how you amend an already existing file
fprintf("The average rating for Shift A is %lf and the average rating for Shift B is %lf.", shiftA, shiftB);
fclose(fp); 
	return 0;
}



void Payment (ticketnum, int Total){
Total=ticketnum*$33+(1/5)*(ticketnum*$33)	
}

double Rating(char Times[][]){
	for(int i=0; i<rows;i++){ //this has the code go through the data through the fisrt and second coloumns
		for(int j=0; j<rows; j++){
			if(data[i][0]<=3 && data[i][0]>7){
				data[i][0]='A'
		}
	if(data[i][0]<=7){
		data[i][0]='B'
		}
	}
	printf("Shift\tRating\n%lf\t%lf",Times,ratings);
	
	
}
