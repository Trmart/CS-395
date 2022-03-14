/*********************************************
 * Id: mart8517
 * 
 * This program plays the tower of hanoi
 *********************************************/ 
#include <stdlib.h>
#include <stdio.h>
void moveDisks(int numDisks, char source, char temp, char destination);

int main(int argc, char *argv[])
{
   if(argc <= 1)
   {
      printf("Not enough arguments specified. Need at least 2 arguments\n");
   }
   
   int numDisks = atoi(argv[1]);
   moveDisks(numDisks,'A','B','C'); 
   //printf("\nAll disks have been moved!\n"); 
   return 0; 
}

//moveDisks, tower of hanoi recursive function
//input: numDisks, source peg, destination peg, and temp peg
//output: prints moving of disks to the screen
void moveDisks(int numDisks, char source, char temp, char destination)
{
   if(numDisks > 0)
   {
      //move n-1 disks from source to temp
      //using destination as the temp peg
      moveDisks(numDisks-1,source,temp,destination);
      //move a disk from source to destination 
      printf("Move %c to %c\n", source, destination); 
      //move n-1 disks from temp to destination
      //using source as a temp peg
      moveDisks(numDisks-1, temp, destination,source);
   }
   return;
}