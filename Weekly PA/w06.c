/*********************************************
 * Id: mart8517
 * 
 * This program plays the a restricted ver
 * of Tower of Hanoi
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
//moveDisks, tower of hanoi restricted recursive function
//must 
//input: numDisks, source peg, destination peg, and temp peg
//output: prints moving of disks to the screen
void moveDisks(int numDisks, char source, char temp, char destination)
{
   if(numDisks ==1)
   {
      printf("MOVE %c TO %c\n", source, temp);
      printf("MOVE %c TO %c\n", temp,destination);
      return;
   }
   
   moveDisks(numDisks-1,source,temp,destination);
   printf("MOVE %c TO %c\n", source, temp); 
   moveDisks(numDisks-1,destination,temp,source);
   printf("MOVE %c TO %c\n", temp, destination); 
   moveDisks(numDisks-1,source,temp,destination);
   
}

// Recursively transfer n−1 disks from peg 1 to peg 3, with every move involving peg 2.

// Move the one disk currently on peg 1
// to peg 2. (This uses peg 2,

// as required.)

// Recursively transfer n−1
// disks from peg 3 back to peg 1, with every move involving peg 2.

// Move the one disk currently on peg 2
// to peg 3. (This uses peg 2,

// as required.)

// Recursively transfer n−1
// disks from peg 1 to peg 3, with every move involving peg 2.

// Of course, when the recursive transfer calls for moving 0
// disks, there's nothing to do (that's the base of the recursion).