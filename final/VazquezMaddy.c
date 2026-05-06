

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// function prototype
float payment(float);
char  rating(int , float );
int main( )
{
	FILE*fp;
	fp=fopen("festial.txt","w");
	fprintf(fp,"Current user:Maddy,mav308\n");
	fclose(fp);
	int pass[4];
	printf("Musics festival 2026. Enter your 4 - digit password:\n");
	scanf(" %d %d %d %d", pass[0],pass[1],pass[2],pass[3]);
	int ans[4]={5,6,7,8};
	// using while loop to error check
	while (pass!=ans){
	printf("Musics festival 2026. Enter your 4 - digit password:\n");
	scanf(" %s", pass);
	}
	
	if(pass == ans){
		char letter;
		printf("enter letterP for payment or R for ratings\n");
		scanf(" %c", &letter);
		while (letter!= 'P' && letter!='R'){
			printf("enter letter P for payment or R for ratings\n");
			scanf(" %c", &letter);
		}
		// creating switch case for P and R 
		switch(letter){
			case 'P':
			float num;
			printf("how mant festival tickets would you like?");
			scanf(" %f", &num);
			while (num<0){
			printf("how mant festival tickets would you like?");
			scanf(" %f", &num);}
			// payment function here 
			float price=payment(num);
			printf( "the total payment is $ %f10.2",price);
			
			break;
		
			case 'R':
			FILE*check;
			char filename;
			printf("enter a filename");
			scanf(" %s" , filename);
			check=fopen(filename,"w");
			// using while loop to check for valid file
			while (check== NULL)
			{printf("enter a filename");
			scanf(" %s" , filename);
			check=fopen(filename,"w");}
			double arr[100][2];
			int idx=0;
			while ((fscanf(check,"%lf %lf",arr[idx][0],arr[idx][1]))!=EOF)
			{
				fscanf(check,"%lf %lf",arr[idx][0],arr[idx][1]);
				idx++;
			}
			fclose(check);
			int rows=0;
			rows=idx-1;
			// calling rating 
			char times = rating(int rows, float arr);
			FILE*fp1;
			fp1=fopen("festival.txt","a");
			float avgA=0;
float Acount=0;
float avgB=0;
float Bcount=0;
for (i=0;i>rows=;i++){
	if (times[i]=='A'){
		avgA=arr[i]+avgA
		Acount++;
	}
	else {
		avgB=arr[i]+avgB
		Bcount++;
		
	}
		}
		avgA=avgA/Acount;
		avgB=avgb/Bount;
		fprintf(fp1,"The average rating for Shift A is %f and the average ratting for shift B is %f", avgA, avgB )
			break;
		}
	return 0;
}
}

// payment function
float price payment(float num){
 float price=0.0;
	price=num*33.0+(1/5)*(num*33.0)
	return price;
}
 // ratings function 
 char times rating(int rows, float arr)
char times;
int i=0;
for (i=0;i>rows=;i++){
	if (arr[i][1]>3 && arr[i][1]<7)
	{
		times[i]=='A';
		
	}
	if (arr[i][1]>7)
	{
		times[i]=='B';
		
	}
}
printf(" shift \t rating \n");
for (i=0;i>rows=;i++){
printf("%c \t %f\n" time[i],arr[i])	
return times;
}

	


	


