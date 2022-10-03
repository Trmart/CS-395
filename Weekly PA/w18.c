/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w16
 * Date: 4/8/2022
 * File : w16.c
 * Compile: gcc -Wall -Wextra w18.c -o w18.exe
 * Run: ./w18.exe
 *
 * The Clique Problem 
 *
 * A clique, C, in an undirected graph G = (V, E) is a subset of the vertices, 
 * such that every two distinct vertices in C are adjacent. 
 * In other words, a clique is a complete subgraph of G. 
 * The size of a clique is the number of vertices it contains. 
 * The clique problem is the optimization problem of finding a clique of maximum size in a graph.
 *
 * Design an exhaustive-search algorithm for determining the number of verticies in the largest clique in the graph.
 * 
 * The input to your program will be command line arguments in the form 
 * number_of_elements upper triangle of adjacency matrix.
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int find_clique(int size, int matrix[][size], int row, int clique[], int total);
int calculate_max_clique(int size, int matrix[][size]);

//main function
int main(int argc, char *argv[])
{
   int size = atoi(argv[1]);
   int matrix[size][size];
   int i, j, k, count;

   j = 0;
   for (k = 0; k < size - 1; k++)
   {
      count = 0;
      for (i = k + 1; i < size; i++)
      {
         matrix[k][i] = atoi(argv[2 + j + count]);
         count++;
      }
      j += count;
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < i + 1; j++)
      {
         matrix[i][j] = 0;
      }
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         matrix[j][i] = matrix[i][j];
      }
   }

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   int result = calculate_max_clique(size, matrix);

   for (i = size; i > 0; i--)
   {
      if (result < i)
      {
         printf("No clique found of size %d\n", i);
      }
      if (result == i)
      {
         printf("Clique found of size %d\n", i);
      }
   }

   return 0;
}


// find clique from adjacency matrix
int find_clique(int size, int matrix[][size], int row, int clique[], int total)
{
   int i;
   int count = 0;

   for (i = 0; i < size; i++)
   {
      if (clique[i] == 1 && matrix[row][i] == 1)
      {
         count++;
      }
   }
   if (count == total)
   {
      return 1;
   }
   return 0;
}

// return max clique
int calculate_max_clique(int size, int matrix[][size])
{
   int i, j, k, l, count, maxClique;
   int clique[size];
   maxClique = 2;
   count = 1;
   for (l = 0; l < size; l++)
   {
      for (j = 0; j < size; j++)
      {
         clique[j] = 0;
      }
      clique[l] = 1;
      for (i = 0; i < size; i++)
      {
         k = 0;

         if (matrix[l][i] == 1)
         {
            k = find_clique(size, matrix, i, clique, count);
         }

         if (k == 1)
         {
            count++;
            clique[i] = 1;
         }
      }

      if (count > maxClique)
      {
         maxClique = count;
      }
      count = 1;
   }
   return maxClique;
}

// The Clique Problem 

// A clique, C, in an undirected graph G = (V, E) is a subset of the vertices, 
// such that every two distinct vertices in C are adjacent. 
// In other words, a clique is a complete subgraph of G. 
// The size of a clique is the number of vertices it contains. 
// The clique problem is the optimization problem of finding a clique of maximum size in a graph.

// Design an exhaustive-search algorithm for determining the number of verticies in the largest clique in the graph.

// The input to your program will be command line arguements in the form 
//    number_of_elements upper triangle of adjacency matrix.
// For examle 
//    ./clique 6  1 0 0 1 1  1 1 0 0  1 1 1  0 1  1
// Represents the graph
//   1 0 0 1 1
//     1 1 0 0
//       1 1 1
//         0 1
//           1

// Your output should be like this:
// ./clique 7 1 1 0 1 1 0   1 1 0 1 0     1 0 0 1     1 1 1     0 1      0
// 0 1 1 0 1 1 0
// 1 0 1 1 0 1 0
// 1 1 0 1 0 0 1
// 0 1 1 0 1 1 1
// 1 0 0 1 0 0 1
// 1 1 0 1 0 0 0
// 0 0 1 1 1 0 0
// No clique found of size 7
// No clique found of size 6
// No clique found of size 5
// No clique found of size 4
// Clique found of size 3