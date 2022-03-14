/*********************************************
 * Id: mart8517
 * 
 * This program finds implements insertionSort
 * sorting an array of non-negative integers
 *********************************************/ 
#include <stdlib.h> 
#include <stdio.h> // for I/O

void InsertionSort(int A[],int SIZE);
void printArray(int A[], int SIZE,int key);
void printFinalArray(int A[], int SIZE); 

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

   
   InsertionSort(A,SIZE);
   printFinalArray(A,SIZE);
   return 0;
}

//function to use insertion sort to sort an array
void InsertionSort(int A[],int SIZE)
{
   int i, key, j;
   //printArray(A,SIZE);
   for (i = 1; i < SIZE-1; i++) 
   {
      key = A[i];
      printArray(A,SIZE,key);
      j = i - 1;
 
      /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
      while (j >= 0 && A[j] > key) 
      {
         A[j + 1] = A[j];
         j = j - 1;
      }
      A[j + 1] = key;
   }
} 

//function to print out an array
void printArray(int A[],int SIZE, int key)
{
   int i; 
   for(i = 1; i < SIZE; i++)
   {
      if(A[i] == key)
      {
         printf("| %d ", A[i]); 
      }
      if(A[i] != key)
      {
         printf("%d ", A[i]); 
      }
      
   }
   printf("\n"); 
}
void printFinalArray(int A[],int SIZE)
{
   int i; 
   for(i = 1; i < SIZE; i++)
   {
      printf("%d ",A[i]); 
   }
   printf("| \n"); 
}