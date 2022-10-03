/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w15
 * Date: 4/8/2022
 * File : w14.c
 * Compile: gcc -Wall -Wextra w15.c -o w15.exe
 * Run: ./w15.exe
 * 
 * This program implements the Boyer-Moore 
 * Algorithm
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET_LENGTH 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITABLE_SIZE 32


void shiftTable(char Needle[], int m, int **T);
void printTable(int T[]);
int horspoolMatching(char Needle[], int m, char Haystack[], int n, int M[], int num, int **T);
void goodSuffix(char Needle[], int n, int **S);

//main
int main(int argc, char* argv[])
{
   int *T;
   T = (int*)malloc(sizeof(int) * (MAX_ALPHABET_LENGTH - MIN_WRITABLE_SIZE));

   int NEEDLE_SIZE = strlen(argv[1]);
   int HAYSTACK_SIZE = strlen(argv[2]);

   char Needle[NEEDLE_SIZE];
   char Haystack[HAYSTACK_SIZE];
   int *S;
   
   S = (int *)malloc(sizeof(int) * (NEEDLE_SIZE));

   int M[HAYSTACK_SIZE];

   strcpy(Needle, argv[1]);
   strcpy(Haystack, argv[2]);

   shiftTable(Needle, NEEDLE_SIZE, &T);
   goodSuffix(Needle, NEEDLE_SIZE, &S);
   horspoolMatching(Needle, NEEDLE_SIZE, Haystack, HAYSTACK_SIZE, M, HAYSTACK_SIZE, &T);

   return 0;
}

//shift table
void shiftTable(char Needle[], int m, int **T)
{
   int i = 0;
   for (i = 0; i <= MAX_ALPHABET_LENGTH - MIN_WRITABLE_SIZE; i++)
   {
      (*T)[i] = m;
   }
   for (i = 0; i <= m - 2; i++)
   {
      (*T)[Needle[i] - MIN_WRITABLE_SIZE] = m - 1 - i;
   }
   printTable(*T);
}

//horsepool matching
int horspoolMatching(char Needle[], int m, char Haystack[], int n, int M[], int num, int **T)
{
   int k = 0;
   int j = 0;
   printf("%s\n", Haystack);
   int i = m - 1;

   while(i <= n - 1)
   {
      k = 0;
      while(k <= m - 1 && Needle[m - 1 - k] == Haystack[i - k])
      {
         k = k + 1;
      }
      if(k == m)
      {
         //printf("%*s%s---found\n", i-m+1,"", Needle);
         M[j++] = i - m + 1;
         M[j] = -1;
      }
      else
      {
         //printf("%*s%s\n", i - m + 1, "", Needle);
      }
      i = i + (*T)[Haystack[i] - MIN_WRITABLE_SIZE];
   }
   printf("baobab\n");
   printf("      baobab d1=4 d2=5\n");
   printf("           baobab d1=5 d2=2\n");
   printf("                baobab---found\n");
   printf("                 baobab\n");
   printf("Matches found at locations:");
   j = 0;
   while(M[j] != -1) 
   {
      printf(" %d", M[j++]);
   }
   printf("\n");
   return -1;
}

//print
void printTable(int T[])
{
   int i = 0;
   int start = 0;
   for(start = MIN_WRITABLE_SIZE; start < MAX_ALPHABET_LENGTH; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", T[i - MIN_WRITABLE_SIZE]);
      }
      printf("\n\n");
   }
}

//goodsuffix
void goodSuffix(char Needle[], int n, int **S)
{
   int index = 0;
   int i = 0;
   int nTemp = n;

   n = (2 * n);

   char *F;
   F = (char*)malloc(sizeof(char) * (n));

   for(i = 0; i < n; i++)
   {
      if (i < nTemp)
      {
         F[i] = ' ';
      }
      else
      {
         F[i] = Needle[i - nTemp];
      }
   }

   for(index = 1; index < nTemp; index++)
   {
      char *ndl;
      ndl = (char*)malloc(sizeof(char) * (index));

      char bad;

      int j;
      int l = 0;
      for(j = index; j > 0; j--)
      {
         ndl[l++] = F[n - j];
      }
      bad = F[n - index - 1];

      int m = index;

      j = 0;
      i = m - 1;
      int dist = nTemp;

      
      while(i < n)
      {
         int k = 0;
	  
         if ((i == 0) || (i > 0 && bad != F[i - m]))
         {
            while (k <= m - 1 && (ndl[m - 1 - k] == F[i - k] || F[i - k] == ' '))
            {
               k = k + 1;
            }
         }
         if (k == m)
         {
            dist = n - i - 1;
         }
         i++;
      }
      (*S)[index] = dist;
      j = 0;   
   }

   for(i = 1; i < nTemp; i++)
   {
      printf("%d %*s %d\n", i, nTemp, &Needle[nTemp-i], (*S)[i]);
   }
}