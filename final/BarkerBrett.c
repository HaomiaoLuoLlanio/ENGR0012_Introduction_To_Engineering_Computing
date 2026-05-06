

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float payment(int num);
//char ratings(char Times);
int main()
{
	//file creation 1
	FILE *fp;
	fp=fopen("festival.txt","w");
	fprintf(fp,"current user: Brett Barker, BDB89");
	fclose(fp);
	//password 2
	int password;
	int truepass=5678;
	char choice;
	int pvalue;
	
	printf("Music Festival 2026. Enter your 4-digit password:\n");
	scanf("%d",&password);
	//see if password is right
	if(password==truepass){
		printf("Enter the letter P for payment or the letter R for ratings: \n");
		scanf(" %c", &choice);
		switch (choice){
			//p choice
			case 'P':
				printf("Enter an integer value to correspond to the number of festival tickets you would like to purchase: \n");
				scanf("%d",&pvalue);
				while (pvalue<=0){
						printf("Invalid, try again: ");
						scanf("%d",&pvalue);
				}
				float payment(int pvalue);
				
			break;
			//r choice
			case 'R':
				FILE *fnew;
				char filename[50];
				printf("Enter a file name for your music festival data: \n");
				scanf("%s",filename);
				fnew=fopen(filename,"r");
				while (1){
					if(fnew ==NULL){
						printf("Invalid, try again");
						scanf("%s",filename);
						fnew=fopen(filename,"r");
					}else{
						break;
					}
				//float a[50], b[50];
				//while fread(fnew,"%d %d", float a[n], float b[n], int n ){
				//	n++;
				}
			break;
			
			//char ratings(char Times);
			
		}
		
		
		
	}else{
		printf("Incorrect password. Bye!\n");
	}
	
	
	return 0;
}
//payment function
float payment(int num)
{
	float total;
	total = num*33 + (1/5) * num*33;
	printf("Total payment is $%lf",total);
	return total;
}
//ratings function
//char ratings(char Times)
//{
	
//	for (int i; i=0;i++){
//		if(Times[i] >3 && Times[i]<7){
//			Times[i]='A'
//		}else{
//			Times[i]='B'
//		}
		
//	}
	
//	return Times[50];
//}
