#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <cmath>
#define QUEENNO 8

/**
All function declarations used in the program.
*/
void PlaceQueen(int, int*);
int canBePlaced(int, int, int*);
void ShowChessBoard(int*);

/**
Main function from which the actual logic to place queen is called.
*/
void main()
{
	int x[QUEENNO], i;

	printf("The 8 queens problem");
	// Function call to place a queen, takes 0 as the first argument and an empty array
	PlaceQueen(0, x);
	printf("End");
	getchar();
	getchar();
}

/**
Place queen function which takes the empty array as input.
*/
void PlaceQueen(int k, int *x)
{
	int i;
	char ch;

	for (i = 0; i < 8; i++)
	{
		if (canBePlaced(k, i, x)) // For each iteration checks if the queen can be placed in a particular position.
		{
			x[k] = i;
			if (k == 7)
			{
				ShowChessBoard(x); // Call ShowChessBoard function, which shows the position of each queen in the board.
				printf("\n\n Want to see more?[n->stop, any-> continue]: ");
				scanf_s("%c", &ch);
				if (ch == 'n' || ch == 'N'){
					printf("Exit Program!!");
					break;
				}
			}
			if (k < 7)
				PlaceQueen(k + 1, x);
		}
	}

}

/**
Function to check if a queen can be placed in a particular position
*/
int canBePlaced(int k, int i, int *x)
{
	int j;
	for (j = 0; j < k; j++)
	{
		// Condition to check if a queen's position is valid.
		if ((abs(j - k) == abs(x[j] - i)) || (x[j] == i))
			return 0;
	}
	return 1;
}

/**
Function to show the board with queens in their respective position.
*/
void ShowChessBoard(int *x)
{

	int i, j;
	printf(" \n----------------------------------------------\n ");
	printf(" ");
	for (i = 0; i < 8; i++)
	{
		printf(" %d ", (i + 1));
		printf(" ");
	}
	for (i = 0; i < 8; i++)
	{
		printf(" \n \n %d ", (i + 1));
		for (j = 0; j < 8; j++)
		{
			if (j == x[i])
				printf(" Q ");
			else
				printf(" . ");
			printf(" ");
		}
		printf(" ");
	}
	printf(" \n---------------------------------------------- ");
}