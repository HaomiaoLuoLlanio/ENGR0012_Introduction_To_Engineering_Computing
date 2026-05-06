
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float Payment(int numt);
void Ratings(char Times[], data[][0], rows)
int main()
{
	
	//creating file pointer labeled fp
	FILE*fp;
	fp = fopen("festival.txt","a");
	fprintf(fp, "Current user: Olivia Mazuca, ogm27");
	fclose(fp);
	
	
	int password;
	char ratings; 
	int numt;
	printf("Music Festival 2026. Enter your 4-digit password: \n");
	scanf("%d", &password);
	if (password != 5678)
	{
	printf("Incorrect password. Bye!");
	}
	else 
	{
		printf("Enter the letter P or R for ratings: \n");
		scanf(" %c", &ratings); 
		//error checking user for r or p
		while (ratings!='P' && ratings!='R')
		{
		printf("Enter the letter P or R for ratings: \n");
		scanf(" %c", &ratings);
		}
	}
	char filename[100];
	FILE *fi;
	float totalm;
	float data[][2];
	int idx = 0;
	int check = 0;
	int rows; 
	char Times[50];
	switch (ratings)
	{
		//Making case r
		case 'R':
		{
			printf("Enter a filename for festival data: \n");
			scanf("%s",filename);
			fi = fopen(filename, "r");
			while (fi == NULL)
			{
			printf("Enter a filename for festival data: \n");
			scanf("%s",filename);
			fi = fopen(filename, "r");
			// error checking till End of file
			while (check != EOF)
			{
				check = fscanf(fi, "%f %f", data[idx][0], data[idx][1]);
				idx = idx+1; 
			}
			fclose(fi);
			rows = idx-1;
			Ratings(Times[50],data[][3],rows);
			}
			break;
		}
		//case p for payment
		case 'P':
		{
			printf("Enter an integer value for number of tickets you want to buy: \n");
			scanf("%d", &numt);
			while (numt<0)
			{
			printf("Enter an integer value for number of tickets you want to buy: \n");
			scanf("%d", &numt);
			//calling payment function
			totalm = Payment(numt); 
			}
			printf("Total payment is $%10.2f\n", totalm);
			break;
		}
		
		
		
		
	}
	
	
	return 0;
}

float Payment(int numt)
{
	float total; 
	total = (numt)*33+(1/5)*(numt*33);
	return total;

	
}

//no outputs for rating function
void Ratings(char Times[], data[][0], rows)
{
	float avga; 
	float avgb;
	for(int i = 0; i<rows; i++)
	{
		for(int j= 0; j<3; j++)
		{
			if (data[i][0]>=3|| data[i][0]<7)
			{
				Times[j]='A'
			avga = Times[j]/j;
			}
			
			else
			{
				Times[j] = 'B';
		avgb = Times[j]/j
		}
		
	}
	for(int i = 0; i<rows; i++)
	{
		for(int j= 0; j<3; j++)
		{
			printf("Shift\tRating\n");
			printf("%c\t%f\n", &Times[j], &data[i][j]);
		}
		print("\n");
	}

}





