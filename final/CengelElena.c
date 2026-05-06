
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 double payment(int);

int main()
{
	// 1) creating and printing to a file
	FILE* Pointer;
	
	Pointer = fopen("festival.txt", "w");
	
	fprintf(Pointer, "Current user: Elena Cengel, emc409");
	
	fclose(Pointer);
	
	// 2) get password
	
	
	int password;
	
	scanf("Music Festival 2026. Enter your 4-didgit password: %d", &password);
	
	// 3) check if password is incorrect
	
	if (password!=5678){
		printf("Incorrect password. Bye!");
	}
	
	// 4) password correct
	
	char choice;
	do{
		scanf("Please enter P for payment or R for ratings %c", &choice);
	}
	while(choice!='P'|| choice!='R');
	
	// 5) switch case
	
	switch (choice){
		
		// 6
		case('P'):
		int ticketNum;
		
		do{
			scanf("Please enter number of tickets you want: %d", &ticketNum);
		}
		while(ticketNum<=0);
		
		// 7)
		double total;
		 total = payment(ticketNum);
		 // 8)
		 
		printf("Total payment is $  %lf10.2", total);
		
		
		break;
		
		// 9
		case('R'):
		 
		 FILE* file;
		 char filename[15];
		 
		 
		 do{
			 scanf("Enter filename %s",filename); 
			 file= fopen(filename, "r");
		 }
		 while(file==NULL);
		 
		 
		 // 10)
		 float data[][1];
		 int check;
		 int i=0;
		 
		
		 
		 while (1){
			 for(int j=0;j<2; j++){
			 
			 check = fscanf(file, "%f", &data[i][j]);
			 
		 if(check==EOF){
			 break; 
		  }
		  i++;
		  
	  }
  
	}  
		 
		  
	     }
		
		
		return 0;
	}
	
	// payment function
	
	double payment(int numTickets){
		double total;
		total = (numTickets*33)+ 1.0/5*(numTickets*33);
		return total;
		
		
	// rating function
	
	
	}
	
	
	
	


