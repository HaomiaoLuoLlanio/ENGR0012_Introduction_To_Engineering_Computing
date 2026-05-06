
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//----------PROTOTYPESS-----------//
double payment(int);
void ratings(int, int);

int main();
{
	//----------------MAIN------------//

//1.
FILE *fp = fopen("festival.txt", "w"); //USE W TO WRITE IN FILE

fprintf(fp,"Matthew Heineman, mah941");

if(fp == NULL)
{
printf("Error opening file\n");	
return 1;
}
fclose(fp);  //MAKE SURE TO CLOSE THE FILE

//2.
int password;
int validpassword = 5678;

printf("Music Festival 2026. Enter your 4 digit password: ");
scanf("%d", &password);  //MAKE SURE TO USE & TO SAVE ADDRESS


//3.
if(!=validpassword)
{
printf("Incorrect password bye!");	
return 0;
}



//4.
char choice;
if(password == validpassword)
{
printf("Enter P for payment or a R for rating: ");
scanf(" %c", &choice);
if(choice != 'P' || choice != 'R')
{
printf("Error, enter a valid number: ");	
}(while(choice != 'P' || choice != 'R');	
}


//5.
switch(choice):
{
case 'P':  //MAKE SURE TO USE : INSTEAD OF ;
{
int numtickets;
printf("Enter the number of tickets you would like: ");
scanf("%d", &numtickets);

if(numtickets < 0)
{
printf("Error: Enter a value greater thn zero: ");	
}while(numtickets < 0);
	
total = payment(numtickets);	

//8. 
printf("Total payment is $%10.2lf\n", total);	
break;
}



case 'R':
{
FILE *fp2;
char filename[50];

do
{
printf("Enter a filename for festival music data: ");
scanf("%s", filename);
fp2 = fopen(filename, "r"); //USE R TO READ FILE
}while( fp2 == NULL);


int data[100][2];
int rows = 0;
while(fscanf(fp2, "%d %d", &data[rows][0], &data[rows][1]) != EOF)
{
rows++;
}
fclose(fp2);

ratings(data, rows);	

printf("The average rating for shift A is %lf and the average for shift B is %lf.\n", AvergaeA, AverageB);
	
break;	
}



default:
{
break;
}
}
	
	return 0;
}

//-------FUNCTIONS-----------//

//----------Payment Function-----------//
double payment(int a);
{
total = a*33 + (1/5);

return (double)total;	
}

//----------Ratings Function-----------//
//A.
void ratings(int data[][2], int rows)
{
int time[100];
char shift;

printf("Shit\tRating\n");

for(int i = 0; i < rows; i++)
{
if(time[i] >= 3 && time[i] <= 7)
{
shift = 'A';
printf(" %c\n", shift);	
}
else
{
shift = 'B';
printf(" %c\n", shift);	
}	
}

//C.
for(int i = 0; i < rows; i++)
{
	
if(time[i] >= 3 && time[i] <= 7)
{
shift = 'A';
double AverageA;
int total;

for(int j = 0; j < rows; j++);
{
totaldata = data[j][1]+=;
total++;

AverageA = totaldata / total;
reutrn (double)AverageA;
}

}
else
{
shift = 'B';	
double AverageB;
int total;

for(int j = 0; j < rows; j++);
{
totaldata = data[j][1]+=;
total++;

AverageB = totaldata / total;
reutrn (double)AverageB;
}

}


}
