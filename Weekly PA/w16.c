/*********************************************
 * Id: mart8517
 * Name: Taylor Martin
 * Class: CS-395 Analysis Of Algorithms 
 * Assignment : w16
 * Date: 4/8/2022
 * File : w16.c
 * Compile: gcc -Wall -Wextra w16.c -o w16.exe
 * Run: ./w16.exe
 * 
 * This program implements the quick hull algorithm
 * from section 5.5
 *********************************************/ 

int quickHullAlgorithm(int X_Coordinates[], int Y_Coordinates[], int SIZE); 

int main(int argc, char* argv[])
{

   return 0; 
}


//Solves the closest-pair problem by divide-and-conquer
//Input: An array P of n ≥ 2 points in the Cartesian plane sorted in
// nondecreasing order of their x coordinates and an array Q of the
// same points sorted in nondecreasing order of the y coordinates
//Output: Euclidean distance between the closest pair of points
int quickHullAlgorithm(int X_Coordinates[], int Y_Coordinates[], int SIZE)
{

   // if n ≤ 3
   if(SIZE <= 3)
   {
      // return the minimal distance found by the brute-force algorithm
      int i,j, minDistance; 
      for(i = 0; i < SIZE; i++)
      {
         for(j = 0; j < SIZE; j++)
         {
            if( i != j && abs(X_Coordinates[i]-Y_Coordinates[j]) < minDistance)
            {
               minDistance = abs(X_Coordinates[i]-Y_Coordinates[j]);
            }
         }
      }

      return minDistance; 
   }
   
   // else
   else
   {
      // copy the first n/2 points of P to array Pl
      // copy the same n/2 points from Q to array Ql
      // copy the remaining n/2 points of P to array Pr
      // copy the same n/2 points from Q to array Qr
      // dl ← EfficientClosestPair(Pl, Ql)
      // dr ← EfficientClosestPair(Pr, Qr)
      // d ←min{dl, dr}
      // m ← P[n/2 − 1].x
      // copy all the points of Q for which |x − m| < d into array S[0..num − 1]
      // dminsq ← d2
      // for i ← 0 to num − 2 do
      // k ← i + 1
      // while k ≤ num − 1 and (S[k].y − S[i].y)2 < dminsq
      // dminsq ← min((S[k].x − S[i].x)2+ (S[k].y − S[i].y)2, dminsq)
      // k ← k + 1
   }

   // return sqrt(dminsq)
}


// Quick Hull 

// Implement the Quick Hull algorithm section 5.5.

// The input is a set of command line integers representing each point (the x coordinate followed by the y coordinate).

// The output is the set of points in the convex hull order listed clockwise.
// Hint: List the top arch in increasing x coordinates and the bottom arch in decreasing x coordinates.
//       Break ties with the Y coordinate.

// For example:

// ./quickHull 0 3 1 1 2 2 4 4 0 0 1 2 3 1 3 3
// The points in Convex Hull are:
// (0, 0) (0, 3) (4, 4) (3, 1) (0, 0)

// ./quickHull 0 0 0 4 -4 0 5 0 0 -6 1 0
// The points in Convex Hull are:
// (-4, 0) (0, 4) (5, 0) (0, -6) (-4, 0)

 // if n ≤ 3
   // return the minimal distance found by the brute-force algorithm
   // else
   // copy the first n/2 points of P to array Pl
   // copy the same n/2 points from Q to array Ql
   // copy the remaining n/2 points of P to array Pr
   // copy the same n/2 points from Q to array Qr
   // dl ← EfficientClosestPair(Pl, Ql)
   // dr ← EfficientClosestPair(Pr, Qr)
   // d ←min{dl, dr}
   // m ← P[n/2 − 1].x
   // copy all the points of Q for which |x − m| < d into array S[0..num − 1]
   // dminsq ← d2
   // for i ← 0 to num − 2 do
   // k ← i + 1
   // while k ≤ num − 1 and (S[k].y − S[i].y)2 < dminsq
   // dminsq ← min((S[k].x − S[i].x)2+ (S[k].y − S[i].y)2, dminsq)
   // k ← k + 1
   // return sqrt(dminsq)