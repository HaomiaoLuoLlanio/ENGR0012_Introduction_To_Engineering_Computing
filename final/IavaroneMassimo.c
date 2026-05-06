#include <stdlib.h>
#include <stdio.h>
#include <math.h>




double Payment(int tix);
void Ratings (double data[][1],int rows);


int main(){
	
	FILE*Cptr;
	double tot;
	char pOr;
	int password; //holds the music festival password
	Cptr=fopen("festival.txt","w");
	fprintf(Cptr,"Current User: [Massimo Iavarone], [MDI34]\n");
	fclose(Cptr);
	
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d",&password);
	
	if (password!=5678)
	{
		printf("Incorrect password. Bye!\n");
	}
	do{
	printf("Enter payment (P) or rating (R): \n");
	scanf(" %c",&pOr);
}
while(pOr!='P'&&pOr!='R');//error checking if equal to P or R than continue
	int tix;
	switch(pOr)
	{
		case'P':
		{
			do{
			printf("How many tickets would you like: \n");
			scanf("%d",&tix);
			
			tot=Payment(tix);
			printf("Total payment is $%10.2lf\n",tot);

		}
		while(tix<=0);
			break;
		}
		
		case'R':
		{
			char filename[300]; //array for user to enter filename
			FILE*rdPt;
			
			do{
			printf("Enter a filename for your festival data: \n");
			scanf("%s",filename);
			rdPt=fopen(filename,"r");
		}
		while(rdPt==NULL);
			double data[300][1];
			int check=0;
			int idx=0;
			int rows;
			do{
				check=fscanf(rdPt,"%lf %lf", &data[idx][0],&data[idx][1]);
				idx=idx+1;
			}
			while(check!=EOF);
			rows=idx-1;// number of rows in the file
			void Ratings (data,rows);
			
			FILE*reOP;
			
			reOP=fopen("festival.txt","a"); //appending to file not rewriting
			fprintf("The average rating for shift A is %lf and the average for Shift B is %lf\n",data[1][0],data[2][0]);
			fclose(reOP);//closes file

			break;
		}
		
		
	}
	
	
	return 0;
}





//functions

double Payment(int tix)
{
	
	double total;
	
	total=(tix*33)+(.2*tix*33);
	
	return total; //returns the total calculated to the main
	
	
	
}



void Ratings (data[][1],rows)
{
	
	char Times[][];
	
	for(int i=0;i<rows;i++){
		if(data[i][0]==3){
			Times[i][0]='A';
			
			else {
			for(int i=0;i<rows;i++){ //looping through read in file if between 3 and 7 assign shift B
		(data[i][0]>3&&data[i][1]<7){
			Times[i][0]='B';
		}
	}
}	
	
	for (int i=0;i<rows;i++){
		for(intj=0;j<2;j++){
			printf("Shift\tRating\n");
			printf("%c\t%lf\n",Times[i][j],data[i][0]);
			
		}
	}
	
}
