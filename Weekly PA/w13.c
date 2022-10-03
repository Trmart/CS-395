/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w13
 * Date: 4/7/2022
 * File : w13.c
 * Compile: gcc -Wall -Wextra w13.c -o w13.exe
 * Run: ./w13.exe
 * 
 * This program implements the russian pesant 
 * multiplication algorithm 
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>

void russianPeasantMultiplication(int x, int y, int sum);
void print(int x, int y, int sum); 

int main(int argc, char *argv[])
{
   if(argc < 3 || argc > 3)
   {
      printf("Incorrect number of input values given. Can only accept 2 input values. Process Terminated\n"); 
      exit(1);
   }

   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   russianPeasantMultiplication(x,y,0); 

   return 0; 
}

//Russian Peasant Multiplication Algorithm
void russianPeasantMultiplication(int x, int y, int sum)
{
   if((x%2) != 0)
   {
      sum = sum + y; 
   }
   print(x,y,sum);

   if(x != 1)
   {
      x = x/2;
      y = y*2; 
      russianPeasantMultiplication(x,y,sum); 
   }

}

// print function to output the proper formatting wanted 
void print(int x, int y, int sum)
{
   printf("%6d %6d", x , y);

   if((x%2) != 0)
   {
      printf(" %6d", y); 
   }

   if(x == 1)
   {
      printf("\n"); 
      printf("%20s\n", "------");
      printf("%20d\n",sum); 
   }

   else
   {
      printf("\n"); 
   }
}
