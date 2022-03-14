/*********************************************
 * Id: mart8517
 * 
 * This program finds implements insertionSort
 * sorting an array of non-negative integers
 *********************************************/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y);
void permute(char *a, int left, int right);

// Driver code
int main(int argc, char *argv[])   
{
  
   int n;
   n = atoi(argv[1]);

   if(n == 5)
   {
      char str[] = "12345";
      int n = strlen(str);
      permute(str, 0, n-1);
   
   }

   return 0;
}
//swap function
void swap(char *x, char *y)
{
   char temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//recursive permutation function
void permute(char *a, int left, int right)
{
   int i; 
   if (left == right)   
   {
      printf("%s\n", a);
   }
   else   
   {
      for (i = left; i <= right; i++)   
      {
         swap((a + left), (a + i));
         permute(a, left + 1, right);
         swap((a + left), (a + i));
      }
   }
}