#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main() {
	int password[4], tix;
	char task[1], filename[30];
	File *fp = 
	printf("Current user: Sam, ska77 \n");// displaying the curreent user
	fclose(fp);
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("&d", password); //scanning the input response
	if (password != 5678 ){ //errorchecking response
		printf("Incorrect password. Bye!");
		else printf ("Enter P for payment or R for ratings: \n");
		scanf("&s", task);	
}
	switch (task) { // switch case to let user view rating and payment info
	
	case 1: P
	printf("Please enter an integer value for the number of tickets you would like to purchase\n");
	scanf("&d", tix);
	while (tix <= 0) {
		printf("Please enter an integer value for the number of tickets you would like to purchase\n");
		scanf("&d", tix);
	}
	printf("Total payment is $%10.2d/n", )
	break
	case 2: R
	File *fp;
	
	printf("Enter a filename for your music festival data!\n");
	scanf("&s", filename2);
	while (filename == NULL) { //errorchecking the filenamee against null
		printf("Enter a filename for your music festival!\n");
		scanf("&s", filename2);
	}
	float filename2[][2];
	int check = 0;
	int idx = 0; 
	while (check != EOF) { //errorchecking against EOF so it knows when its reached the end
	check = fscanf("%d %d", &filename2[idx][1], &filename2[idx][2]);
	idx = idx + 1;
	fp = fopen(
}
	fp = fopen(filename, "a", "The average rating for Shift A is %d and the average rating for Shift B is %d")
	fclose(fP);
	break
	

}	
	
	
	return 0;
}
