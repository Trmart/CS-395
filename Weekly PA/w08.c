/*********************************************
 * Id: mart8517 
 *
 * Program finds/counts the specified word 
 * inside a sentence or string.
 *********************************************/

#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt);
/* Driver program to test above function */

int main(int argc, char *argv[])
{  

   search(argv[1], argv[2]);

   return 0;
}

//brute force search to find string.
void search(char* pat, char* txt)
{
   int M = strlen(pat);
   int N = strlen(txt);
   int i;

   printf("Matches found at locations:");
   
   if(M == 0 || N == 0)   {
      printf("Nothing in string.\n");
     
   }

   for ( i = 0; i <= N - M; i++) {
      int j;
    
      for (j = 0; j < M; j++)
      if (txt[i + j] != pat[j])
      break;
    
      if (j == M)
	
      printf(" %d", i);
   }
   printf("\n");
}