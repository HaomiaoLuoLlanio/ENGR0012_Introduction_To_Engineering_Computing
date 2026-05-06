#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int Payment(int pvalue);

int main()
{
	FILE*ptr;
	FILE*ptr2
	ptr=fopen("festival.txt","w");
	fprintf(ptr,"Current user: Reuben Kuriakose, rnk39.");
	
	int code, q, pvalue, total, count, idx;
	char resp, fname[50];
	int mat[][2];
	
	fprintf("Music Festival 2026. Enter your 4-digit password: ");
	fscan("%d",&code);
	fclose("festival.txt.");
	
	if (code!=5678){
		printf("\nIncorrect password. Bye!");
		else{
			do{
				printf("\nP for payment or R for ratings: ");
				scanf(" %c", &resp);
				if (resp != "P" || resp != "R"){
						q = 0;
					}else {
						q = 1;
					}
				}while(q!=1);
			
			switch(resp){
				
				case "P"
					do{
					printf("\n\nEnter a valid amount of tickets you want to purchase: ");
					scanf("%d",pvalue);
					if (pvalue<=0){
						q = 0;
					}else{
						q =1;
					}
				}while(q!=0);
				
				total = Payment(pvalue);
				printf("\nThe total payment is $$%10.2d",total);
				break;
				
				case "R"
				do{
				printf("\n\nEnter a file name for your music fesitval data: ");
				scanf("%s",fname);
				ptr2=fopen(fname,"r");
				if (ptr2==NULL){
					q=0;
				}else{
					q=1;
				}
				
				while(count!=EOF){
					count=fscanf(ptr2,"%d %d", mat[idx][0], mat[idx][1]);
					idx++;
				}
				mat[idx+1][0] = NULL;
				mat[idx+1][1] = NULL;
				idx=idx-1;
				fclose(ptr2);
				
				
				Ratings
				
				
				
			}while(q==0);
				break;
			}
			
		}
	
	int Payment(int pvalue){
		int total;
		total = (pvalue*33) + (0.2*(pvalue)*33);
		return total;
	}
	
	int AVGShiftA int AVGShiftB(){
		FILE*ptr;
		int idx, count,i, Times[][2], waste[];
		ptr=fopen("saturday.txt","r");
		
		while(count!=EOF){
					count=fscanf(ptr,"%d %d", Times[idx][0], waste[idx]);
					idx++;
				}
			Times[idx+1][0] = NULL;
			Times[idx+1][1] = NULL;
			
		for(i=0;i<=idx;i++){
			if (Times[idx][1]>7 && Times[idx][1]<3){
				Times[idx][i] == "A";
			}
		}
			
		printf("\n\nShift\tRating");
		for(i=0;i<=idx;i++){
			printf("%d\t%c",Times[i][1]. Times[i][2];
		}
				
		
		
		
		return AVGShiftA, AVGShiftB;
	}
	
	
	return 0;
}

