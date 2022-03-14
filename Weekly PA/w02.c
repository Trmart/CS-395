/*********************************************
   * Id: mart8517
   * 
   * This program is an updated and more efficient
   * Version of w01 MinDistance
   * This program finds the min distance within
   * an array of non-negative integers
   *********************************************/ 
#include <limits.h> //for "INT_MAX" largest possible int on system
#include <stdlib.h> // for abs(), abs val function 
#include <stdio.h> // for I/O
int minDistanceVer2(int A[], int SIZE); 
void quickSort(int A[], int start, int end);
void mergeSort(int A[], int left, int right); 
void merge(int A[], int left, int middle, int right); 

int main(int argc, char *argv[]) 
{
   // main
   if(argc <= 1) 
   {
      printf("Not enough arguments specified\n"); 
      exit(1);
   }
   
   int A[argc];
   int i; 

   for (i = 1; i < argc;i++)
   {
      A[i] = atoi(argv[i]);
   }

   //quickSort(A,0,argc-1); 
   mergeSort(A,0,argc-1); 
   int min = minDistanceVer2(A,argc);
   printf("min distance: %d\n", min); 

   return 0;
}
//min distance function 
int minDistanceVer2(int A[], int SIZE)
{
   //finds the min distance within 
   //an array of non-negative integers

   int dmin = INT_MAX;
   int i; 
   int j; 

   // for(i=0; i < SIZE - 1; i++)
   // {
   //    for(j=i+1; j < SIZE-1; j++)
   //    {
   //       if( i != j && abs(A[i]-A[j]) < dmin)
   //       {
   //          dmin = abs(A[i]-A[j]);
   //       }
   //    }
   // }
   for(i=0; i < SIZE - 1; i++)
   {
      j = i + 1;
      if( i != j && abs(A[i]-A[j]) < dmin)
      {
         dmin = abs(A[i]-A[j]);
      }
      
   }

   return dmin; 
}

void quickSort(int A[], int start, int end)
{
   //sorts the sent in array A[]
   int pivot, value1, value2, temp;
   
   if (start < end)
   {
      pivot = start;
      value1 = start;
      value2 = end;

      while (value1 < value2)
      {
         while (A[value1] <= A[pivot] && value1 <= end)
         {
            value1++;
         }
         while (A[value2] > A[pivot] && value2 >= start)
         {
            value2--;
         }
         if (value1 < value2)
         {
            temp = A[value1];
            A[value1] = A[value2];
            A[value2] = temp;
         }
      }

      temp = A[value2];
      A[value2] = A[pivot];
      A[pivot] = temp;
      quickSort(A, start, value2 - 1);
      quickSort(A, value2 + 1, end);
   }
}
//sorts an array using mergeSort function
//input: A[]-> array to be sorted
//left -> left index of array to be sorted
//right -> right index of array to be sorted
void mergeSort(int A[], int left, int right)
{
   if(left < right)
   {
      //same as (l+r)/2 but avoids overflow for large l and r values
      int middle = left + (right-left) / 2;
      //sort first and second halves
      mergeSort(A,left,middle);
      mergeSort(A,middle+1,right);
      //merge the seperated arrays
      merge(A,left,middle,right); 
   }
}
//merges to subarrays of A[]
//First subarray is A[left...middle]
//Second sub array is A[middle+1....right]
void merge(int A[], int left, int middle, int right)
{
   int i,j,k;
   int n1 = middle - left +1; 
   int n2 = right -middle; 

   //create the temp arrays from A[]
   int leftTemp[n1],rightTemp[n2];

   //copy data to temp arrays
   for(i = 0; i < n1; i++)
   {
      leftTemp[i] = A[left + i]; 
   }
   for(j=0;j<n2;j++)
   {
      rightTemp[j] = A[middle+1+ j];
   }
   //merge the temp arrays back into A[l...r]
   i=0; //Initial index of first subarray
   j=0; //Initial index of second subarray
   k=left; //Initial index of merged subarray
   while(i <n1 && j <n2)
   {
      if(leftTemp[i] <= rightTemp[j])
      {
         A[k] = leftTemp[i]; 
         i++; 
      }
      else
      {
         A[k] = rightTemp[j];
         j++; 
      }
      k++; 
   }

   //copy the remaining elements of leftTemp
   //if there are any left
   while(i < n1)
   {
      A[k] = leftTemp[i];
      i++;
      k++;
   }

   //copy the remaining elements of leftTemp
   //if there are any left
   while(j < n2)
   {
      A[k] = rightTemp[j];
      j++;
      k++;
   }
}