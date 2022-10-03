/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w14
 * Date: 4/7/2022
 * File : w14.c
 * Compile: gcc -Wall -Wextra w14.c -o w14.exe
 * Run: ./w14.exe
 * 
 * This program implements Horspools Algorithm
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET_LENGTH 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE_SIZE 32

void shiftTable(char A[], int m, int **T);
void printTable(int T[]);
int horspoolMatchingAlgorithm(char A[], int m, char B[],int n, int C[], int num, int **T); 

int main(int argc, char* argv[])
{

   int* T;
   T = (int*)malloc(sizeof(int) * (MAX_ALPHABET_LENGTH - MIN_WRITEABLE_SIZE));

   int NEEDLE_SIZE = strlen(argv[1]);
   int HAYSTACK_SIZE = strlen(argv[2]);

   char Needle[NEEDLE_SIZE];
   char Haystack[HAYSTACK_SIZE];

   int M[HAYSTACK_SIZE];

   strcpy(Needle, argv[1]);
   strcpy(Haystack, argv[2]);

   shiftTable(Needle, NEEDLE_SIZE, &T);
   horspoolMatchingAlgorithm(Needle, NEEDLE_SIZE, Haystack, HAYSTACK_SIZE, M, HAYSTACK_SIZE, &T);

   return 0;
}

void shiftTable(char Needle[], int m, int **T)
{
   int i = 0;
   for (i = 0; i <= MAX_ALPHABET_LENGTH - MIN_WRITEABLE_SIZE; i++)
   {
      (*T)[i] = m;
   }
   for (i = 0; i <= m - 2; i++)
   {
      (*T)[Needle[i] - MIN_WRITEABLE_SIZE] = m - 1 - i;
   }
   printTable(*T);
}

void printTable(int T[])
{
   int i = 0;
   int start = 0;
   for(start = MIN_WRITEABLE_SIZE; start < MAX_ALPHABET_LENGTH; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", T[i - MIN_WRITEABLE_SIZE]);
      }
      printf("\n\n");
   }
}

int horspoolMatchingAlgorithm(char Needle[], int m, char Haystack[],int n, int Match[], int num, int **T)
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
         printf("%*s%s---found\n", i-m+1,"", Needle);
         Match[j++] = i - m + 1;
         Match[j] = -1;
      }
      else
      {
         printf("%*s%s\n", i - m + 1, "", Needle);
      }
      i = i + (*T)[Haystack[i] - MIN_WRITEABLE_SIZE];
   }
   printf("Matches found at locations:");
   j = 0;
   while(Match[j] != -1)
   {
      printf(" %d", Match[j++]);
   }
   printf("\n");
   return -1;
}