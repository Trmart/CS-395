/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w17
 * Date: 4/8/2022
 * File : w17.c
 * Compile: gcc -Wall -Wextra w17.c -o w17.exe
 * Run: ./w17.exe
 * 
 * This program implements the coin collecting
 * robot  algorithm
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>

void init_board(char* argv[], int numRows, int numCols, char inputBoard[numRows][numCols]);
void print_input_board(int numRows, int numCols, char inputBoard[numRows][numCols]); 
void print_solution_board(int numRows, int numCols, int solutionBoard[numRows][numCols]);
void coin_collecting_robot(int numRows, int numCols, char inputBoard[numCols][numRows], int solutionBoard[numRows][numCols]); 
int find_max(int numOne, int numTwo);

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
      printf("Error. Not Enough Arguments Entered. Process Termination");
      return -1;
   }

   int numRows = atoi(argv[1]);
   int numCols = atoi(argv[2]);

   if((argc - 3) < (numRows * numCols))
   {
      printf("Error. Not Enough Elements Entered For Board. Process Termination");
      return -1;
   }

   char inputBoard[numRows][numCols];
   int solutionBoard[numRows][numCols];

   init_board(argv, numRows, numCols, inputBoard); 
   print_input_board(numRows,numCols, inputBoard);
   coin_collecting_robot(numRows, numCols, inputBoard, solutionBoard);
   print_solution_board(numRows, numCols, solutionBoard);

   return 0;
}

//initializes the input board 
void init_board(char* argv[], int numRows, int numCols, char inputBoard[numRows][numCols])
{
   int cellCount = 3;
   int i, j;

   for(i = 0; i < numRows; ++i)
   {
      for(j = 0; j < numCols; ++j)
      {
         inputBoard[i][j] = *argv[cellCount++];
      }
   }
}

//coin collecting robot algorithm
void coin_collecting_robot(int numRows, int numCols, char inputBoard[numRows][numCols], int solutionBoard[numRows][numCols])
{
   int i, j;
   const int charConversion = 48;
   int initialX = 0;
   solutionBoard[0][0] = inputBoard[0][0] - charConversion;

   for (j = 1; j < numCols; ++j)
   {
      if ((inputBoard[0][j] != 'X') && (initialX == 0))
      {
         solutionBoard[0][j] = solutionBoard[0][j - 1] + (inputBoard[0][j] - charConversion);
      }
      else
      {
         solutionBoard[0][j] = 0;
         inputBoard[0][j] = 'X';
         initialX = 1;
      }
   }

   initialX = 0;

   for (i = 1; i < numRows; ++i)
   {
      if ((inputBoard[i][0] != 'X') && (initialX == 0))
      {
         solutionBoard[i][0] = solutionBoard[i - 1][0] + (inputBoard[i][0] - charConversion);
      }
      else
      {
         solutionBoard[i][0] = 0;
         inputBoard[i][0] = 'X';
         initialX = 1;
      }
      for (j = 1; j < numCols; ++j)
      {
         if ((inputBoard[i - 1][j] == 'X') && (inputBoard[i][j - 1] == 'X'))
         {
            inputBoard[i][j] = 'X';
         }
         if ((j != numCols - 1) && (inputBoard[i + 1][j] == 'X') && (inputBoard[i][j + 1] == 'X'))
         {
            inputBoard[i][j] = 'X';
         }
         if (inputBoard[i][j] != 'X')
         {
            solutionBoard[i][j] = find_max(solutionBoard[i - 1][j] + (inputBoard[i][j] - charConversion), solutionBoard[i][j - 1] + (inputBoard[i][j] - charConversion));
         }
         else
         {
            solutionBoard[i][j] = 0;
         }
      }
   }
}

//prints solution board
void print_solution_board(int numRows, int numCols, int solutionBoard[numRows][numCols])
{
   int i, j;

   printf("Coin Collecting Table:\n");

   for(i = 0; i < numRows; ++i)
   {
      for(j = 0; j < numCols; ++j)
      {
         printf("%d\t", solutionBoard[i][j]);
      }
      printf("\n");
   }

   printf("\nThe optimal path with this board is: %d\n", solutionBoard[numRows - 1][numCols - 1]);
}

//prints the sent in input board 
void print_input_board(int numRows, int numCols, char inputBoard[numRows][numCols])
{
   int i, j;

   printf("Board Input:\n");
   for (i = 0; i < numRows; ++i)
   {
      for (j = 0; j < numCols; ++j)
      {
         printf("%c\t", inputBoard[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

//finds the max of two sent in integers. Returns max value
int find_max(int numOne, int numTwo)
{
   return numOne > numTwo ? numOne : numTwo;
}

// Modified Robot Coin Collecting

// Consider this algorithm:

// //Applies dynamic programming to compute the largest number of
// //coins a robot can collect on an n × m board by starting at (1, 1)
// //and moving right and down from upper left to down right corner
// //Input: Matrix C[1..n, 1..m] whose elements are equal to 1 and 0
// //for cells with and without a coin, respectively
// //Output: Largest number of coins the robot can bring to cell (n, m)
// RobotCoinCollection(C[1..n, 1..m])
//    F[1, 1]←C[1, 1]; 
//    for j ←2 to m do 
//       F[1, j]←F[1, j − 1]+ C[1, j]
//    for i ←2 to n do
//       F[i, 1]←F[i − 1, 1]+ C[i, 1]
//       for j ←2 to m do
//          F[i, j ]←max(F [i − 1, j], F[i, j − 1]) + C[i, j ]
//    return F[n, m]

// Modify this algorithm so some cells on the board (indecated by and 'X' are inaccessible for the robot.

// The input should be command line arguements in the format Columns Rows <Cell content>*
// 0 indicates the cell is empty. 1 indicates the cell has a coin in it. X indicates the cell is inexcessable.

// for example
// ./robotCoin 5 6 0 X 0 1 0 0 1 0 0 X 1 0 0 1 0 X 1 0 0 0 0 1 0 1 X X X 0 1 0

// Should produce this output:
// Board Inputed:
// 0       X       0       1       0       0
// 1       0       0       X       1       0
// 0       1       0       X       1       0
// 0       0       0       1       0       1
// X       X       X       0       1       0

// Coin Collecting Table:
// 0       0       0       0       0       0
// 1       1       1       0       0       0
// 1       2       2       0       0       0
// 1       2       2       3       3       4
// 0       0       0       3       4       4

// The optimal path with this board is: 4

// Note: When you print the board, follow each value with a tab:
//    printf("%d\t", board[i][j]);

///w17.exe 20 15 0 1 1 1 0 1 0 1 0 0 0 1 1 0 1 0 1 X 0 1 1 0 X X 1 0 1 X 0 1 1 0 X 1 0 1 1 1 1 0 0 0 1 0 1 X 0 0 0 X 0 0 1 0 1 1 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 X 0 0 0 1 1 0 0 0 0 1 X 0 0 0 0 0 0 0 X 0 1 0 0 0 0 0 0 1 0 1 X 0 0 0 0 0 0 0 X 0 0 0 1 1 1 0 0 0 0 1 0 0 0 1 X X 0 0 X X 0 0 0 0 0 1 0 1 0 0 1 1 1 1 1 1 0 0 1 0 0 1 0 X 1 0 1 0 0 0 0 0 0 0 1 1 0 0 1 1 0 X 0 0 0 1 0 0 0 1 X X 1 0 0 1 1 0 0 1 X 0 0 1 1 1 0 0 0 1 0 X 1 1 1 0 0 0 0 1 0 0 1 0 X 0 0 0 0 0 0 0 0 1 0 0 1 0 X 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 1 1 X 0 0 0 0 0 1 0 1 1 0 X 0 0 0 1 1 1 X 0 0 1 0 0 0 1 0 X 0 0 0 1 1 1 0 0 0 0 0 1 0 0 0 1 0 0 0 1 1 0