
#include <stdio.h>
#include <stdlib.h>


double calculateTickets(int numTickets);
void processBands(float times[], float ratings[], int size, double averages[]);

int main() {
	
	printf("gia babilon, gjb70");
	
    FILE *fp;
    char filename[50];
    float times[MAX], ratings[MAX];
    int count = 0;

    fp = fopen("festival.txt", "w"); //trying to open test but i got confused about this part so i made it something else idk
    if (fp == NULL) {
		printf("Error creating file.\n");
        return 1;
    }
    fprintf(fp, "Concert Data Log\n");
    fclose(fp);
    
    //open user file
    printf("Enter input filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return 1;
    }
    
    //EOF
    while (fscanf(fp, "%f % f", &times[count], &ratings[count]) != EOF) {
        count++;
    }
    
    fclose(fp);
    
    //create password
    int password;
    printf("Enter 4-digit passcode: ");
    scanf("%d", password);

    if (pass != 5678) {
        return 0; // stop if program wrong
    }
    
    
    int choice;
    printf("\n1. Buy Tickets\n2. Analyze Bands Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
		
        case 1 {
            int num;
            printf("How many tickets? ");
            scanf("%d", &num);
            
            double total = calculateTickets(num);
            
            printf("Total cost: %10.2lf\n", total);
            break;
        }
        
        case 2 {
            // reopen file
            fp = fopen("output.txt", "a");
            if (fp == NULL) {
                printf("Error opening file.\n");
                return 1;
            }
            
            double averages[2];
            
            processBands(times, ratings, count, averages);
            
            fprintf(fp, "Averages -> A: %.2lf B: %.2lf\n",
            averages[0], averages[1]);
            
            fclose(fp);
            
            printf("Average Group A: %.2lf\n", average[0]);
            printf("Average Group B: %.2lf\n", averages[1]);
            break;
        }

        default:
            printf("Invalid choice.\n")
    }

    return 0;
}


//calc ticket $
double calculateTickets(int numTicets) {
    double price = 25.0; 
    return numTickets * price;
}


//process bands
void processBands(float times[], float ratings[], int size, double averages[]) {
    char groups[MAX]; 

    double sumA = 0, sumB = 0;
    int countA = 0, countB = 0;

    printf("\nGroup  Rating\n");

    for (int i = 0; i < size; i++) {

        if (times[i] <= 7.0) {
            groups[i] = 'A';
            sumA += ratings[i];
            countA++;
        } else {
            groups[i] = 'B';
            sumB += ratings[i];
            countB++;
        }

        printf("  %c     %.2f\n", groups[i], ratings[i]);
    }

    // compute averages
    if (countA > 0)
        averages[0] = sumA / countA;
    else
        averages[0] = 0;

    if (countB > 0)
        averages[1] = sumB / countB;
    else
        averages[1] = 0;
}
