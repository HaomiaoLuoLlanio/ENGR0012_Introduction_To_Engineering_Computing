#include <stdio.h>

double Payment(int);

void Ratings(double[100][2], int, double[2]);

int main()
{
	FILE *fp1;
	fp1 = fopen("festival.txt", "w");
	fprintf(fp1, "Current user: Kyle Schaller, kms582");
	fclose(fp1);
	int pass;
	printf("\nMusic Festival 2026. Enter your 4-digit password: ");
	scanf("%d", &pass);
	if(pass != 5678){ 
		printf("\nIncorrect password. Bye!");
		return 1;// If they enter the wrong password, stop the code.
		}
	char opt;
	int tickets;
	double total;
	double mat[100][2];
	do{
		printf("\nEnter a P for payment or R for ratings: ");
		scanf(" %c", &opt);
	}while(opt != 'P' && opt != 'R');// Error check user inputs
	
	switch(opt){
		
		
		case 'P':
		do{
			printf("\nEnter how many tickets you would like to purchase: ");
			scanf("%d", &tickets);}while(tickets < 0);
		total = Payment(tickets);
		printf("\nTotal payment is $%10.2lf", total);	
		break;
		case 'R':
		char filename[100];
		FILE *fp2;
		do {
			printf("\nPlease enter a filename: ");
			scanf("%s", filename);
			fp2 = fopen(filename, "r");} while(fp2 == NULL);// If the file is empty, prompt the user again for a new filename.

		int inc = 0;
		int check;
		do {
			check = fscanf(fp2, "%lf %lf", &mat[inc][0], &mat[inc][1]); // Print the results to the file and use the check variable to see if we have reached the end of the file.
			inc++;
			}while (check != EOF);
			fclose(fp2);
		int rows = inc -1;
		double avgResults[2];
		Ratings(mat, rows, avgResults);
		FILE *fp3;
	fp3 = fopen("festival.txt", "a");
	fprintf(fp3, "\nThe average rating for Shift A is %lf and the average rating for Shift B is %lf.", avgResults[0], avgResults[1]);
		fclose(fp3);
		break;
}
	
	
	
	
	return 0;}


double Payment(int tickets){
	double total;
	int first;
	first = 33 * tickets;
	double second;
	second = first * .2; // the second half of the formula is just the first half of the formula times (1/5), so i calculate that here 
	total = first + second; 
	return total;
	}

void Ratings(double mat[100][2], int rows, double avgResults[2]){
	char Times[rows];
	// sumX and numX are used to store the variables needed to calculate the average at the end
	double sumA;
	int numA;
	double sumB;
	int numB;
	for (int i = 0; i < rows; i++){
		if (mat[i][0] < 7){
			Times[i] = 'A';
			numA++; // since we know this index is part of shift A, add 1 to the number of bands in shift A
			sumA = sumA + mat[i][1]; // add this rating to the total rating of bands in shift A as well.
			}
			else{
				Times[i] = 'B';
				numB++;
				sumB = sumB + mat[i][1];
				}
	}
	printf("\nShift\tRating");
	for (int i = 0; i < rows; i++){
		printf("\n%c\t%lf",Times[i], mat[i][1]);}
	avgResults[0] = sumA/numA; // using an array to return two values from this function.
	avgResults[1] = sumB/numB;
	
	
	
	
}
