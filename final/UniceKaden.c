#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Payment(int );
void ratings(float [][2], int );
int main()
{
FILE *fp;
fp = fopen("festival.txt","w");   // opens new file and overwrites data if it already exists
fprintf(fp,"Current user: Kaden Unice, kau44");
fclose(fp); 

char choice;
int pw;
printf("Music Festival 2026. Enter your 4-digit password: ");
scanf("%d",&pw);
if (pw != 5678)
{
	printf("incorrect password. Bye!\n");
	return 0; 
}
else 
{
printf("Enter the letter P for payment or letter R for ratings: ");	
scanf(" %c",&choice);
while( choice != 'P' && choice != 'R' ) 
{
printf("Enter the letter P for payment or letter R for ratings: ");	
scanf(" %c",&choice);
}
}

switch (choice){
case 'P': 
{
int tix; 
printf("Please enter how many festival tickets you would like to buy: "); 
scanf("%d",&tix);
while(tix<1) // if user enters tix number below 1 they are asked again 
{
printf("Please enter how many festival tickets you would like to buy: "); 
scanf("%d",&tix);
}
int cost = Payment(tix); 
	
break;
}
case 'R': 
{
char filename[100];
FILE *fptr;	
printf("enter a file name for your musical festival data: ");
scanf("%s",filename);
fptr = fopen(filename,"r"); 

while( fopen(filename,"r") == NULL) {
printf("enter a file name for your musical festival data: ");
scanf("%s",filename);
fptr = fopen(filename,"r"); 
}

float rate[100][2];
int check=1;
int i=0;

while( check != EOF) {
fscanf(fptr,"%f %f", &rate[i][0], &rate[i][1]);
i++;
}
int rows = i-1; 
fclose(fptr); 
ratings(rate,rows); 


break; 
}
default: 
{
	
break; 
}
}
	return 0;  
}

int Payment(int num)
{
double total; 
total = num * 33 + 0.2 * num * 33; // calculates payment using formula
return total; 
}

void ratings(float array[][2], int rows)
{
char Times[rows]; 
float ratingA, ratingB;
int a=0, b=0;

for(int i=1;i<rows;i++)
{
if ( array[i][0] >= 3.0 && array[i][0] <= 7.0 )
{
Times[i] = 'A';
ratingA = ratingA + array[i][1];
a=a+1;
}
else
{
Times[i] = 'B';
ratingB = ratingB + array[i][1];
b=b+1;
}
printf("Shift\tRating\n");
printf("%c\t%f",Times[i],array[i][1]);
float avga, avgb; 
avga = ratingA / a;
avgb = ratingB / b; 


}
	
	
}



