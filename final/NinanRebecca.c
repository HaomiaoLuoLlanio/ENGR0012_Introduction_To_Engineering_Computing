#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//function prototype 
double Payment (int);
()Ratings();

int main()
{
	
	
	
	//main

//1.
FILE *fp
int pass; 
char choice; 
double total;
fp=fopen("festival.txt", "a"); 
printf("current user: Rebecca Ninan, RMN59"); 
fclose(fp); 

//2.

printf("Music Festival 2026. Enter your 4-digit password"); 
scanf("%d", &pass); 
//3. 
if (pass!=5678){
printf("Incorrect password. Bye!");	
else 
//4.
do{ 
	printf("Please enter the letter P for payment or R for ratings"); 
	scanf(" %c", &choice);
	
}while (choice!=R || choice !=P); 

//5-
switch (choice){

case P: 
int tick; 
do{
printf("How many tickets would you like to buy?"); 
scanf("%d", &tick); 
}while(tick<=0);
total=Payment(tick);
printf("total payment is $$%lf", total); 
break; 

case R: 
char filename[50];
do{
printf("Please enter a file name for your music festival data"); 
scanf("%s", &filename);
FILE *pointer
pointer=fopen(filename, "r"); 	
}while(pointer==NULL);

int check;
int i; 
int rows;
int arr[50][2];
while (check!=EOF)
check=fscanf(pointer, "%d %d", &arr[i][0], &arr[i][1]);
i++;
}
rows=i-1;
fclose(pointer);

()Ratings();

break; 

otherwise: 

break;
}
	return 0;
}


	
	//function declaration
	
double Payment(int tick){
double total; 
total= tick*33+1/5*(tick*33)
return total;
}
	
	
()Ratings(int arr[i][2]){
char times[50];
for (i=0;i<50;i++){
	if (arr[i][0]>=3 && arr[i][0]<=7){
		times[i]='A'
	
	if else (arr[i][0]>=7)
	times[i]='B'
	


	
}
}	
	for(i=0;i<50;i++){
		printf("Shift \t Ratings %c \t %d", times[i], arr[i][1]); 
		
	}
	
	printf("\n"); 
	 
	 int count=0; 
	 double total=0;
	 double sum; 
	for(i=0;i<50;i++){
	if(	arr[i][0]>=3 && arr[i][0]<=7){
		
		count=count+1;
		total=i;
	if else ()
		
	}
}

