/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w12
 * Date: 3/10/2022
 * File : w122.c
 * Compile: gcc -Wall -Wextra w12.c -o w12.exe
 * Run: ./w12.exe
 * 
 * This program implements insertionSort
 * Selection sort, and quicksort sorting an
 * array of random integers from 1-10.
 * With increasing sizes of magnitude 10^n.
 * I then compare the efficiency of each algorithm. 
 *********************************************/ 
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>
#include <sys/time.h>
#include <math.h>

//function prototypes 
void InsertionSort(int A[],int SIZE);
void SelectionSort(int A[], int SIZE); 
void QuickSort(int A[],int start,int end);
int HoarePartition(int A[],int p, int r); 
void printArray(int A[], int SIZE);
void buildRandomArray(int A[], int SIZE); 
void testSortingAlgorithms(int A[], int SIZE, char code); 

int main() 
{
   // main

   //10^2
   int SIZE = pow(10,2); 
   int A1[SIZE]; 

   testSortingAlgorithms(A1,SIZE,'s'); 
   testSortingAlgorithms(A1,SIZE,'i'); 
   testSortingAlgorithms(A1,SIZE,'q');

   //10^3
   SIZE = pow(10,3); 
   int A2[SIZE]; 

   testSortingAlgorithms(A2,SIZE,'s'); 
   testSortingAlgorithms(A2,SIZE,'i'); 
   testSortingAlgorithms(A2,SIZE,'q');
  
   
   //10^4
   SIZE = pow(10,4); 
   int A3[SIZE]; 
  
   testSortingAlgorithms(A3,SIZE,'s'); 
   testSortingAlgorithms(A3,SIZE,'i'); 
   testSortingAlgorithms(A3,SIZE,'q');

   return 0;
}

//swap function for swaping values
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

//sorts an array with selection sort
void SelectionSort(int A[], int SIZE)
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
   }
}

//QuickSort algorithm
void QuickSort(int A[],int start,int end) 
{
   int partition;
   if (end-start<2) 
   {
      return;
   }
   
   partition = HoarePartition(A,start,end);
   QuickSort(A,start,partition);
   QuickSort(A,partition,end);
}
//implements Hoares Partitioning algorithm for quicksort
int HoarePartition (int a[],int p, int r) 
{
   int x=a[p],i=p-1,j=r;
   while (1) 
   {
      do 
      {
         j--; 
      }
      while (a[j] > x);

      do
      {
         i++; 
      }  
      while (a[i] < x);
      if  (i < j) 
      {
         swap(&a[i],&a[j]);
      }
      else 
      {
         return j+1;
      } 
   }
}

//function to use insertion sort to sort an array
void InsertionSort(int A[],int SIZE)
{
   int i, key, j;
   for (i = 1; i < SIZE-1; i++) 
   {
      key = A[i];
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
void printArray(int A[],int SIZE)
{
   int i; 
   for(i = 1; i < SIZE; i++)
   {
      printf("%d ",A[i]); 
   }
   printf("\n"); 
}
//builds array with random integers 0-10
void buildRandomArray(int A[], int SIZE)
{
   srand(time(NULL)); 
   int i; 
   for(i = 0; i < SIZE; i++)
   {
      int newValue = rand()%10; 
      A[i] = newValue; 
   }
}

//test and compare times between sorting algorithms
void testSortingAlgorithms(int A[], int SIZE, char code)
{
   struct timeval start, stop; 
   buildRandomArray(A,SIZE); 
  
   if(code == 's')
   {
      gettimeofday(&start,NULL); 
      //run sort code here 
      SelectionSort(A,SIZE); 
      gettimeofday(&stop,NULL); 
      double Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec)/1000; 
      printf("Array Size:%d Selection Sort Time in Miliseconds: %f\n",SIZE,Time); 
   }
   if(code == 'i')
   {
      gettimeofday(&start,NULL); 
      //run sort code here 
      InsertionSort(A,SIZE); 
      gettimeofday(&stop,NULL); 
      double Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec)/1000; 
      printf("Array Size:%d Insertion Sort Time in Miliseconds: %f\n",SIZE,Time); 
   }
   if(code == 'q')
   {
      gettimeofday(&start,NULL); 
      //run sort code here 
      QuickSort(A,0,SIZE); 
      gettimeofday(&stop,NULL); 
      double Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec)/1000; 
      printf("Array Size:%d Quick Sort Time in Miliseconds: %f\n\n",SIZE,Time); 
   }
}
//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                    100|            0.018|             .01|        .008|
//|                   1000|            1.721|            .787|        .078|
//|                  10000|          127.742|          76.613|       4.527|
//+-----------------------+-----------------+----------------+------------+

// Array Size:100 Selection Sort Time in Miliseconds: 0.018000
// Array Size:100 Insertion Sort Time in Miliseconds: 0.010000
// Array Size:100 Quick Sort Time in Miliseconds: 0.008000

// Array Size:1000 Selection Sort Time in Miliseconds: 1.721000
// Array Size:1000 Insertion Sort Time in Miliseconds: 0.787000
// Array Size:1000 Quick Sort Time in Miliseconds: 0.078000

// Array Size:10000 Selection Sort Time in Miliseconds: 127.742000
// Array Size:10000 Insertion Sort Time in Miliseconds: 76.613000
// Array Size:10000 Quick Sort Time in Miliseconds: 4.527000