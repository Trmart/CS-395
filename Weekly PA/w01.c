/*********************************************
* Id: mart8517
* 
* This program finds the minDistance within an array of non
* negative integers
*********************************************/ 
#include <limits.h> //for "INT_MAX" largest possible int on system
#include <stdlib.h> // for abs(), abs val function 
#include <stdio.h> // for I/O
int minDistance(int A[], int SIZE); 
int main(int argc, char *argv[]) 
{
   if(argc <= 1) 
   {
      printf("Not enough arguments specified\n"); 
      exit(1);
   }
   
   int array[argc];
   int i; 
   for (i = 1; i < argc;i++)
   {
      array[i] = atoi(argv[i]);
   }

   int min = minDistance(array,argc); 
   printf("min distance: %d\n", min); 

   return 0;
}
int minDistance(int A[], int SIZE)
{
   int dmin = INT_MAX;
   int i; 
   int j; 

   for(i=0; i < SIZE - 1; i++)
   {
      for(j=0; j < SIZE-1; j++)
      {
         if( i != j && abs(A[i]-A[j]) < dmin)
         {
            dmin = abs(A[i]-A[j]);
         }
      }
   }
   return dmin; 
}