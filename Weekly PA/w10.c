/*********************************************
 * Id: mart8517
 * 
 * This program finds implements quick sort
 * sorting an array of non-negative integers
 *********************************************/ 
#include <stdlib.h> 
#include <stdio.h> // for I/O

void QuickSort(int A[], int SIZE, int start, int end);
int HoarePartition(int A[],int p, int r); 
//void printArray(int A[], int SIZE); 
void printArray(int A[],int SIZE, int start, int end);
void swap(int *a, int *b); 

int main(int argc, char *argv[]) 
{
   // main
   if(argc <= 1) 
   {
      printf("Not enough arguments specified\n"); 
      exit(1);
   }
   int SIZE = argc -1; 
   int A[SIZE];
   int i; 

   for (i = 0; i < SIZE;i++)
   {
      A[i] = atoi(argv[i+1]);
   }

   QuickSort(A,SIZE,0,SIZE-1); 
   printArray(A,SIZE,0,SIZE-1); 
   
   return 0;
}

//swap function for swaping values
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
//QuickSort algorithm
void QuickSort(int A[],int SIZE, int start,int end) 
{
   int partition;
   if (start < end) 
   {
      partition = HoarePartition(A,start,end);
      QuickSort(A,SIZE,start,partition-1);
      QuickSort(A,SIZE,partition+1,end);
      printArray(A, SIZE, start, end); 
   }
}
//HoarePartition algorithm   
int HoarePartition (int a[],int p, int r) 
{
   int x = a[p];                                                        
   int i = p;                                                              
   int j = r+ 1;                                                            
                                                                                
   while (i < j)                                                                
   {                                                                            
      while (a[++i] < x)                                                     
      {                                                                         
      }                                                                         
      while (a[--j] > x)                                                     
      {                                                                         
      }                                                                         
      swap(&a[i], &a[j]);                                                         
   }                                                                            
   swap(&a[i], &a[j]);                                                             
   swap(&a[i], &a[j]);                                                        
   return j; 
}
//print subarray
void printSubArray(int arrP[], int startP, int endP, const int arrSize)         
{                                                                               
   int i;                                                                       
   for (i = 0; i < arrSize; ++i)                                                
   {                                                                            
      if (i == startP)                                                          
      {                                                                         
         printf("[");                                                           
      }                                                                         
                                                                                
      if (i == endP)                                                            
      {                                                                         
         printf("%d] ", arrP[i]);                                               
      }                                                                         
      else                                                                      
      {                                                                         
         printf("%d", arrP[i]);                                                 
      }                                                                         
                                                                                
      printf(" ");                                                              
   }                                                                            
   printf("\n");                                                                
}    
//function to print out an array
void printArray(int A[],int SIZE, int start, int end)
{
   int i; 
   for(i = 0; i < SIZE; i++)
   {
      if(i == start)
      {
         printf("["); 
      }
      if(i == end)
      {
         printf("%d] ", A[i]);
      }
      else
      {
         printf("%d",A[i]); 
      }
      printf(" "); 
   }
   printf("\n"); 
}

#include <stdio.h>                                                              
#include <stdlib.h>                                                             
                                                                                
int hoarePartition(int arrH[], int startH, int endH);                           
void printSubArray(int arrP[], int startP, int endP, const int arrSize);        
void quickSort(int arr[], int start, int end, const int arrSize);               
void swap(int arrS[], int indexOne, int indexTwo);                              
                                                  
int main (int argc, char *argv[])                                               
{                                                                               
   if (argc < 2)                                                                
   {                                                                            
      printf("Error.");                                                         
      return -1;                                                                
   }                                                                            
                                                                                
   int i;                                                                       
   const int numElements = argc - 1;                                            
   int numArr[numElements];                                                     
                                                                                
   for (i = 0; i < numElements; ++i)                                            
   {                                                                            
      numArr[i] = atoi(argv[i + 1]);                                            
   }                                                                            
                                                                                
   quickSort(numArr, 0, numElements - 1, numElements);                          
                                                                                
   printSubArray(numArr, 0, numElements - 1, numElements);                      
                                                                                
   return 0;                                                                    
}                                                                               
                                                                                
                                         
void printSubArray(int arrP[], int startP, int endP, const int arrSize)         
{                                                                               
   int i;                                                                       
   for (i = 0; i < arrSize; ++i)                                                
   {                                                                            
      if (i == startP)                                                          
      {                                                                         
         printf("[");                                                           
      }                                                                         
                                                                                
      if (i == endP)                                                            
      {                                                                         
         printf("%d] ", arrP[i]);                                               
      }                                                                         
      else                                                                      
      {                                                                         
         printf("%d", arrP[i]);                                                 
      }                                                                         
                                                                                
      printf(" ");                                                              
   }                                                                            
   printf("\n");                                                                
}                                                                               
                                                                                
                                            
void quickSort(int arr[], int start, int end, const int arrSize)                
{                                                                               
   int s;                                                                       
   if (start < end)                                                             
   {                                                                            
      s = hoarePartition(arr, start, end);                                      
      quickSort(arr, start, s - 1, arrSize);                                    
      quickSort(arr, s + 1, end, arrSize);                                      
      printSubArray(arr, start, end, arrSize);                                  
   }                                                                            
}                                                                               
                                                                                
                                                       
int hoarePartition(int arrH[], int startH, int endH)                            
{                                                                               
   int p = arrH[startH];                                                        
   int i = startH;                                                              
   int j = endH + 1;                                                            
                                                                                
   while (i < j)                                                                
   {                                                                            
      while (arrH[++i] < p)                                                     
      {                                                                         
      }                                                                         
      while (arrH[--j] > p)                                                     
      {                                                                         
      }                                                                         
      swap(arrH, i, j);                                                         
   }                                                                            
                                                                                
   swap(arrH, i, j);                                                            
   swap(arrH, startH, j);                                                       
   return j;                                                                    
}                                                        
void swap(int arrS[], int indexOne, int indexTwo)                               
{                                                                               
   int temp = arrS[indexOne];                                                   
   arrS[indexOne] = arrS[indexTwo];                                             
   arrS[indexTwo] = temp;                                                       
} 