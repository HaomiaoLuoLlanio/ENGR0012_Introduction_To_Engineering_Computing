#include <stdio.h>
#include <stdlib.h>

int main()
{
	char pt;
	printf("Which part of HW7 do you want to test? Enter only 1, 3, 4, 5, or 6: \n");
	// For grading purposes to allow partial credit, just put your code of each part inside each case
	scanf(" %c", &pt);

	switch (pt)
	{
	case '1':
	{
		// Part 1

		// Part 2

		break;
	}
	case '3':
	{
		// Part 3

		break;
	}
	case '4':
	{
		// Part 4

		break;
	}
	case '5':
	{
		// Part 5

		break;
	}
	case '6':
	{
		// Part 6

		break;
	}
	default:
		printf("Invalid part selected.\n");
		return 1; // Exit with error
	}
	return 0;
}

// Reflect on your work this week. Underneath your code, in comments, answer Q1-Q3