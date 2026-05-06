
#include <stdio.lib>
#include <stdio.h>


double Payment(int);
double[] Ratings(float, int);

int main()
{
	
	FILE *file1;
	file1  = fopen("festival.txt", 'w');
	fprintf(file1, "Current user: Maya Schlaufman, mas1809\n");
	fclose(file1);
	
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	int pw
	scanf("%d", &pw);
	if (pw == 5678){ // program only runs if password is correct
		char choice;
		printf("Enter P for payment or R for ratings\n");
		scanf(" %c", choice);
		while (choice != 'R' && choice != 'P'){
			printf("Enter P for payment or R for ratings\n");
			scanf(" %c", choice);
		}
		
		switch (choice){
			case 'P':{
				int tickets;
				printf("How many tickets?\n");
				scanf("%d", &tickets);
				while(tickets<0){
					printf("How many tickets?\n");
					scanf("%d", &tickets);
				}
				double total = Payment(tickets);
				printf("Total payment is $%10.2lf", total);
				break;
			}
			case 'R':{
				char filename[50];
				int check;
				FILE *file2;
				printf("Enter file name for music festival data: \n");
				scanf(" %s", &filename);
				
				file2 = fopen(filename, "r");

				while (file2 == NULL){
					printf("Enter file name for music festival data: \n");
					scanf(" %s", &filename);
					
					file2 = fopen(filename, "r");
				}
				float arr[][2];
				int index = 0;
				while(check != EOF){
					fscanf(file2, "%f %f", arr[index][0], arr[index][1]); //scan in file
					index++;
				}
				int n = index-1;
				fclose(file2);
				double arr2[] = Ratings(arr, n); //keep ratings for both as one variable
				file1 = fopen("festival.txt", 'a');
				fprintf(file1, "The average rating for Shift A is %lf and the average rating for shift B is %lf\n",arr2[0], arr2[1]);
				fclose(file1);
				break;
			}
			
			
		}
		
		
	}else{ //only part that runs if pw  is incorrect
		printf("Bye!");
	}
	
	

	
	return 0;
}



double Payment(int tickets){
	double total = tickets*33 + (1/5)*tickets*33;
	return total;
}


double[] Ratings(float arr[n][2], int n){
	char times[];
	printf("Shift\tRating\n");
	for(int i=0; i<n; i++){
		if(arr[i][0] <7 && arr[i][0] >3){ //Assign A or B, and print to file
			times[i] = 'A';
		}else if(arr[i][0] >= 7){
			times[i] = 'B';
		}
		printf("%c\t%f\n", times[i], arr[i][1]);
	}
	sumA = 0;
	sumB = 0;
	int A;
	int B;
	for(int i=0; i<n; i++){//find sums for each and how many of A and B there are
		if(times[i] == 'A'){
			sumA += arr[i][1];
			A++; 
		}
		if(times[i] == 'B'){
			sumB += arr[i][1];
			B++;
		}
	}
	double avgs[2] = {sumA/A, sumB/B}; //assign array as average of a and average of b
	
	return avgs[];
}











