/*********************************************
 * Id: mart8517
 * 
 * This program solves 2^n recursively
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
int exponential(int n); 

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      printf("Not enough arguments specified.\n");
   }
   if(argc > 2)
   {
      printf("Too many arguments specified.\n");
   }
   int n, answer;
   n = atoi(argv[1]);
   answer = exponential(n); 
   printf("%d\n", answer);
   return 0; 
}
//exponential
//input: n 
//output: 2^n
int exponential(int n)
{
   if(n!=0)
   {
      return (exponential(n-1)+exponential(n-1));
   }
   else
   {
      return 1; 
   }
   
}