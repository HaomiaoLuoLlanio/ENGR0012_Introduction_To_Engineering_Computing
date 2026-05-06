#include <math.h>
#include <stdlib.h>
#include <stdio.h>


double Payment(int);
void Rating(double[][2],int,double[2]);
// Let c know my functions




int main()
{
	FILE*fp;
	fp=fopen("festival.txt","w");
	fprintf(fp,"Isaac Gourley, ISG106\n");
	fclose(fp);
	int password,tickets;
	double tprice;
	char choice;
	// All of my first variables
	printf(" Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d",&password);
	
	if(password!= 5678){//  Check the password
	printf("Incorrect password. Bye!\n");
	return(1);
	}
	
	else{
	do{
	printf("Please choose ratings(R) or payment(P)");
	scanf(" %c",&choice);
	}while(choice!='P' && choice!= 'R');	
	
	switch(choice){
	
	case 'P':{
	do{
	printf("How many tickets do you want?\n");
	scanf("%d",&tickets);
	}while(tickets<=0);
	tprice=Payment(tickets);
	printf("Total payment is $%10.2lf\n",tprice);
	break;}
	
	case 'R':{
	char filename[50];
	double data[50][2];
	int i=0;
	FILE* f1;
	do{
	printf("Please enter you filename:\n");
	scanf("%s",filename);
	f1=fopen(filename,"r");
	}while(f1==NULL);
	int check;
	do{
	check=fscanf(f1,"%lf %lf",&data[i][0],&data[i][1]);
	i++;
	}while(check!= -1);
	int count=i-1;
	double avg[2];
	Rating(data,count,avg);
	FILE*f2;
	f2=fopen("festival.txt","a");
	fprintf(f2,"The average rating for Shift A is %lf and the average rating for Shift B is %lf",avg[0],avg[1]);
	fclose(f2);
	break;}
	
	default:{
	
	break;}
	
	}
	}
	return 0;
}

double Payment(int t){
double total;
total= t*33+((1/5)*(t*33));
return(total);
	}

void Rating(double arr[][2],int rows,double avgarr[2])// Pass in the array I want to change
{
char Times[rows];// Function varable for shifts
for(int i=0;i<rows;i++){

if(arr[i][0]>3 && arr[i][0]<7){
Times[i]='A';
}
else{
Times[i]='B';
}
}

printf("Shift\tRating\n");
for(int i=0;i<rows;i++){
printf("%c\t%lf\n",Times[i],arr[i][1]);
}
int count1=0,count2=0;
double max1=0,max2=0;

for(int i=0;i<rows;i++){
if(Times[i]=='A'){
count1=count1+1;
max1=max1+arr[i][1];
}
else{
count2=count2+1;
max2=max2+arr[i][1];
}

}
avgarr[0]=max1/count1;
avgarr[1]=max2/count2;

}








