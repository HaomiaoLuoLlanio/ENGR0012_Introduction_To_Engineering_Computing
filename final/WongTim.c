//Included Libs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Name: Tim Wong
//Student ID: 4858152
//I hope who ever grades this has a great summer break! :)

//Prototypes 

double Payment(int );
void Ratings (float [][2], int);



int main()
{
	FILE *f;
	f = fopen("festival.txt","w");
	fprintf(f,"Current user: Tim, TiW144");
	fclose(f);
	
	//correct is 5678
	int mp;
	printf("\nMusic Festival 2026. Enter your 4-digit password: " );
	scanf("%d", &mp);
	
	if(mp!=5678){
		printf("Incorrect password. Bye!");
		return 0;
		}
		
	char choice;
		do{
		printf("\n Please enter P for payment or R for ratings " );
		scanf(" %c", &choice);
		}while(choice!='R'&& choice!='P' );
		
		
		switch(choice){
			
		case 'R':{
		char filename[50];
		FILE *fp;
		//for checking saturday.txt
		do{
		printf("\n Please enter a filename: " );
		scanf(" %s", filename);
		fp = fopen(filename,"r");
		}while(fp==NULL );
			
		float data[100][2];
		
		int check;
		int counter;
		while(check!=EOF){
		check=fscanf(fp, "%f %f",&data[counter][0],&data[counter][1]);
		counter++;
			}
		int rows= counter-1;
		fclose(fp);
		
		//11 call Ratings 
		Ratings(data, rows);
			
			
			
		break;
	}
		case 'P':{
		int tickets;
		double main_total=0.0;
		do{
		printf("\nHow many tickets would you like to purchase? " );
		scanf("%d", &tickets);
		}while(tickets<=0 );
		//7 call payment
		main_total= Payment(tickets);
		printf("Total payment is %10.2lf", main_total);
		break;
	}
	default:{
		break;}
	}
	return 0;
}


//Functions

double Payment(int tic){
	double total = (tic+0.0)*33 + (1/5)*((tic+0.0)*33);
	return total;
	}

void Ratings (float arr[][2], int rows){
	char Times[rows];
	
	for(int i=0; i<rows;i++){
	if(arr[i][0]>=3 && arr[i][0]<7){
		Times[i]='A';
		}
	else{
		Times[i]='B';
		}
	
}
	printf("Shift \t Rating\n");
	for(int i=0; i<rows;i++){
		printf("%c\t%f\n",Times[i],arr[i][1]);
		
		}
		float Sum_a=0.0;
		int counter_a=0;
		float Sum_b=0.0;
		int counter_b=0;
		for(int i=0; i<rows;i++){
			if (Times[i]=='A'){
				Sum_a=Sum_a+arr[i][1];
				counter_a++;
				}
				else{
				Sum_b=Sum_b+arr[i][1];
				counter_b++;
				}
			
			
			}
			
			float average_a= Sum_a/counter_a;
			float average_b= Sum_b/counter_b;

	}
















