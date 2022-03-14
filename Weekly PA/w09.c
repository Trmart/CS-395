/*********************************************
 * Id: mart8517
 * 
 * This program implements selection sort
 * sorting an array of non-negative integers
 *********************************************/ 
#include <stdlib.h> 
#include <stdio.h> // for I/O

void selectionSort(int A[],int SIZE);
void printArray(int A[], int SIZE);
void swap(int *a, int *b); 
int main(int argc, char *argv[]) 
{
   // main
   if(argc <= 1) 
   {
      printf("Not enough arguments specified\n"); 
      exit(1);
   }
   int SIZE = argc;
   int A[SIZE];
   int i; 

   for (i = 1; i < SIZE;i++)
   {
      A[i] = atoi(argv[i]);
   }

   selectionSort(A,SIZE);

   return 0;
}

//function to print out an array
void printArray(int A[],int SIZE)
{
   int i; 
   for(i = 1; i < SIZE; i++)
   {
      printf("%d ",A[i]); 
   }
   printf("\n"); 
}

//swap function for swaping values
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
//sorts an array with selection sort
void selectionSort(int A[], int SIZE)
{
   int i, j, min_idx;
  
   // One by one move boundary of unsorted subarray
   for (i = 0; i < SIZE-1; i++)
   {
      // Find the minimum element in unsorted array
      min_idx = i;
      for (j = i+1; j < SIZE; j++)
      {
         if (A[j] < A[min_idx])
         {
            min_idx = j;
         }
         
      }
      // Swap the found minimum element with the first element
      swap(&A[min_idx], &A[i]);
      printArray(A,SIZE);
   }
}