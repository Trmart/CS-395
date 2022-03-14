/*********************************************
 * Id: mart8517
 * 
 * This program plays the a cyclic ver
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
//moveDisks, tower of hanoi cyclic clockwise recursive function
//must 
//input: numDisks, source peg, destination peg, and temp peg
//output: prints moving of disks to the screen
void moveDisks(int numDisks, char source, char temp, char destination)
{
   if(numDisks == 1)
   {
      printf("MOVE %c TO %c\n", source, temp);
      printf("MOVE %c TO %c\n", temp,destination);
      return;
   }
   else if(numDisks == 2)
   {
      printf("MOVE %c TO %c\n", source, temp);
      printf("MOVE %c TO %c\n", temp,destination);
      printf("MOVE %c TO %c\n", source, temp);
      printf("MOVE %c TO %c\n", destination,source);
      printf("MOVE %c TO %c\n", temp,destination);
      printf("MOVE %c TO %c\n", source,temp);
      printf("MOVE %c TO %c\n", temp, destination);
   }
   else
   {
      moveDisks(numDisks-1,source,temp,destination);
      printf("MOVE %c TO %c\n", source, temp); 
      moveDisks(numDisks-2,destination,source,temp);
      printf("MOVE %c TO %c\n",destination,source); 
      moveDisks(numDisks-2,temp,destination,source);
      printf("MOVE %c TO %c\n",temp,destination); 
      moveDisks(numDisks-1,source,temp,destination);
   }
   
}