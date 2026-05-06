
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double paymentFunc(int tickets);

int main()
{
	FILE*fp_write;
do{	
fp_write=fopen("festival.txt","w");

if(fp_write==NULL){
	printf("invalud, please try again");
}
else{
	fprintf(fp_write,"current user; Olivia Gray, ocg26");
}
}while (fp_write==NULL);

fclose(fp_write);

int password;

printf("music festival 2026. enter your four digit passord");
scanf("%d",&password);

if(password!=5678){
	printf("incorrect passowrd, bye!");
	return 1;
}

else{
	char usr_choice;
	do{
		
	printf("please enter P for payment or R for ratings");
	scanf(" %c", &usr_choice);
	
	if(usr_choice!='P'||usr_choice!='R'){
		printf("invalid, please try again");
	}
}while(usr_choice!='P'||usr_choice!='R');

switch (usr_choice){
	case 'P':
	{
		int tix_num;
		printf("please enter the number of tickets you would like");
		scanf("%d",&tix_num);
		
		if(tix_num<0){
			printf("invalid, please re-enter");
			scanf("%d",&tix_num);
		}
		double total=paymentFunc(tix_num);
		
		printf("total payment is $%10.2f");
		break;
	}

	return 0;
}
}
}

//-----------FUNCTIONS--------------

double paymentFunc(int tickets){
	double total=(tickets*33)+(1/5)*(tickets*33);
	return total;
}



