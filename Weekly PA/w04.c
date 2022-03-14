/*********************************************
 * Id: mart8517
 * 
 * This program performs Gaussian Elimanation
 * on a 2D matrix
 *********************************************/ 
#include <stdio.h> 
#include <stdlib.h> 
void printMatrix2D(int n, float A[n][n+1]); 
void printMatrix(int n, float A[]); 
void GE(int n, float A[]); 
void GE2D(int n, float A[n][n+1]); 
int main(int argc, char *argv[])
{
   // main
   if(argc <= 1) 
   {
      printf("Not enough arguments specified\n"); 
      exit(1);
   }
   
   int n = atoi(argv[1]);
   float A[argc]; 
   float A2D[n][n+1]; 
   int i,j; 

   for(i=0; i<argc-2; i++)
   {
      A[i]= atof(argv[i+2]); 
   }
   for(i = 2; i < n; i++)
   {
      for(j = 0; j < n+1; j++)
      {
         A2D[i][j]=atof(argv[i]); 
      }
   }
   printMatrix(n,A); 
   printMatrix2D(n,A2D); 
   GE(n,A); 

   return 0;
}
// ALGORITHM GE(A[0..n − 1, 0..n])
//Input: An n × (n + 1) matrix A[0..n − 1, 0..n] of real numbers
// for i ← 0 to n − 2 do
//    for j ← i + 1 to n − 1 do
//       save A[j,i] here
//       for k ← i to n do
//       A[j, k]← A[j, k] − A[i, k] ∗ A[j, i] / A[i, i]
//                                     ^use the saved A[j,i] here instead
void GE(int n, float A[])
{
   //this function performs Gaussian elimination
   //input: n-> row size and number of equations 
   //and A-> a 2D array with n rows and n+1 cols
   int i,j,k;
   for(i=0; i<n-1; i++)
   {
      for(j=i+1; j<n; j++)
      {
         float tempValue = A[i +  j * (n + 1)] * -1 / A[i * (n + 1) + i];

         for(k=0; k<n+1; k++)
         {
            A[j * (n + 1) + k] += tempValue * A[i * (n + 1) + k];
         }
      }
      printMatrix(n,A); 
   }
}
void GE2D(int n, float A[n][n+1])
{
   int i,j,k;
   for(i=0; i<n-1; i++)
   {
      for(j=i+1; j<n; j++)
      {
         float tempValue = A[i][j]/A[i][i];

         for(k=0; k<n+1; k++)
         {
            A[i][k] -= tempValue * A[j][k];
         }
      }
   }
}

//printMatrix
//input: n-> row size and number of equations 
// and A[]
//output A-> as a 2D array with n rows and n+1 cols
void printMatrix(int n, float A[])
{
   //this function prints a 2D matrix
   int i,j;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n+1; j++)
      {
         printf("%.2f ", A[j+i*(n+1)]); 
      }
      printf("\n");
   }
   printf("\n");
}

void printMatrix2D(int n, float A[n][n+1])
{
   //this function prints a 2D matrix
   int i,j;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n+1; j++)
      {
         printf("%.2f ", A[i][j]); 
      }
      printf("\n");
   }
   printf("\n");
}