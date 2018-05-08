#include <stdio.h>
#include <stdlib.h>  

int main() 
{
	double Q = system("Quick");
	double B = system("Bub");

	if (Q - B > 0)
		printf("\nWinner is Bubble sort\n");
	else if (Q - B < 0)
		printf("\nWinner is Quick sort\n");
	else if (Q == B)
		printf("\nDraw\n");
	system("pause\n");
}