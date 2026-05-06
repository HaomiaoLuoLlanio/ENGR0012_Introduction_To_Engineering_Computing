

#include <stdlib.h>
#include <math.h>
#include <strng.h>//don't think this is correct but i can't remember it
#include <stdio.h>

int main()
{
	int password=5678, tickets,total,average
	float choice
	char P, R, filename[50], rows, Times={
	// creating festival.txt
	do
	{
	FILE *pointer;
	printf("Current user: Elise Pham, elp214");
	scanf(pointer, festival.txt, "w");//i forget the order
	fopen( %s, "festival.txt", "w" ); //trying to make the pointer open the file and write to the new one
}
	while pointer==NULL;
	{
	}
	close; //close the file always
	
	
	
	// music fest password
	printf("Music Festival 2026. Enter your 4-digit password:");
	scanf("%s", password);
	if password==5678;
	{
		printf("please enter P for payment, or R for ratings");
		scanf("%s", "choice");//not sure if choice variable needs quotes
		while (1);//indefinite error checking
		
	}
	else
	{
		printf("Incorrect password. Bye!"\n);
		break; //"the program should not do anything else"
	}
	
	//switchcase
	switch choice;
{
	case P;
	{
		printf("please enter the number of tickets you want to purchase."\n);
		scanf(%d, tickets);
		while (1);
		{
			tickets>=0;
		}
		Payment();//calling payment function
		printf("Total payment is $", %d, total\n); //display payment
	case R;
	FILE *pointer2;
	printf(pointer2,%s, "saturday.txt");
	scanf(%s, filename);
	fopen(pointer2, filename, "r");//read, not write
	filename==EOF //this isn't right but i know EOF equals something i can't remember
	close;
	//there needs to be a while loop here with i++ and rows=i for the Ratings function to be accurate
	while
	i++
	rows=filename[1]
	rows=i //just putting this for as many points possible
	Ratings()
	printf("the average rating for shift A is", %d, "and the average rating for shift B is", %d, avgA, avgB);
	
	return 0;
}

total=Payment(); //payment function
{
	total=tickets*33+0.2*tickets*33;
	return total;
}
Ratings();
{
	for (i=0, rows=i, i++);
	{if filename[1]==;//from 3 to 10 pm, idk how to say that
	{Times=A;
	}
	else
	{Times=B;
		
}
}
printf("Shift\n" "Rating\n");
printf("%c", Times[50]);
avgA=//all times A/n;
avgB=// all times B/n;
average=avgA+avgB;
//cannot return multiple
return average;
}
