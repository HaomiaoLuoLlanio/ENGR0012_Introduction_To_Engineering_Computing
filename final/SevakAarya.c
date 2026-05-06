#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double totalfunction(int,double);//function prototype//

int main(){
	
	FILE*pointer;
	pointer=fopen("festival.txt","w"); //creating file//
	fprintf(pointer, "Current user: Aarya Sevak, AES397"); //printing to file//
	fclose(pointer);
	int check=0;
	int password[100];      //all variabless i used are declared here even if in loops//
	int tickets;
	double data0[][2];
	int idx=0;
	int row;
	double total;
	char filename[100];
	printf("\nMusic festival 2026, Enter your 4 digit password:");
	scanf(" %d", &password);
	char option;
	if (password!=5678){
		printf("\nIncorrect password.Bye!");
	else{
		printf("enter P for payement or R for rating");
		scanf(" %c", &option);
		while (option!='P' && 'R'){
			printf("enter P for payement or R for rating");
			scanf(" %c", &option);}
		switch(option){
			case 'P':{
				printf("enter number of festival tickets:");
				scanf(" %d",&tickets);
				while (tickets <=0){
					printf("enter number of festival tickets:");
					scanf(" %d",&tickets);}
				atotal=double totalfunction(int tickets, double total);//calling function and assigning variables//
				printf("Total payment is $ %10.2lf",atotal);
			}
			case 'R':{
				printf("Enter a filename:");
				scanf(" %s", filename);
				FILE*pt;
				pt=fopen(filename, "r");
				while (pt==NULL){
					printf("Enter a filename:");
					scanf(" %s", filename);}
				while (pt!=EOF){
					fscanf(pt, "%lf %lf", data[idx][0],data[idx][1]);
					idx=idx+1
					row=idx-1;}
					char func;
					func=char ratings()
					printf("Shift A is and the aveage rating is shift b");
				
					
				
					
					
				
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
double totalfunction(int numtickets){
	double totalamount=numtickets*33+(0.2)*(numtickets*33);//function and math right here//
	return totalamount;

	
char ratings (char times[][],int data[][],int j,int new rows)
	{ if ( data[j][0] >3 || data[j][0] <7){
		time[j][0]='A';
		j++;}
	else{ time[j][0]='B';}
	
