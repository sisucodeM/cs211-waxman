#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
   for (int i = 0; i < c; i++)
      // if col difference == row difference, bishop c and i are diagonal to each other
      // row # = q[...] % n
      // col # = q[...] / n
      if(abs(q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) return false;
      
      return true;
}

int kBishops(int n, int k) {
   int solutions = 0; // add a counter

   // dynamic allocate an array in heap base on k (num of bishops)
   int* q = new int[k];

   // place first bishop (c=0) at first (top-left) box (q[c]=0)
   int c = 0;
   q[c] = 0;

   // Similar Backtracking Algorithm
   // Bishop-loop (c-loop)
   while (c >= 0) {
      c++; // NEXT BISHOP

      // if all the bishop has been put onto the broad
      if (c == k) {
         solutions++; // increment solution count
         c--; // backtrack to look for next solution
      }
      else
            // start from the position of the previous bishop to avoid duplicate solutions
         q[c] = q[c-1];

      // Position-loop (q[c]-loop)
      while (c >= 0) {
         q[c]++; // NEXT SQUARE

         if (q[c] == pow(n,2)) // If all the squares have been tried (passed the bottomright square) for the bishop
               c--; // backtrack

         // check if it's ok to put the bishop on this sqaure...
         else if (ok(q, c, n)) break;
      }
   }
   // free up the memory in heap
   delete[] q;
   return solutions; //Return the number of solutions found.
}


int main() {
   // Declare n and k.
   int n, k;

   // ask user input for n and k.
   // n >= k
   // if user input -1 for n, terminate the loop.
   // otherwise call the kBishop(n, k) function to get the number of solutions.
   while(true){
      cout << "Enter value of n: ";
      cin >> n;
      
      if (n == -1)
         return 0;

      cout << "Enter value of k: ";
      cin >> k;

      cout << "number of solutions: " << kBishops(n, k) << "\n";  
   }

   return 0;
}