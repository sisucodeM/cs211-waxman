#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8]; // bb and wb are boxes (5x7 arrays).  board is an 8x8 array of pointers to boxes.
                             // You don't have to clean up the board after printing, because it's not static,
                             // so it'll be reinitialized the next time you call the funtion.

   // Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
   // You only need to create one of each, since the chessboard can contain many pointers to the same box.
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {
         wb[i][j] = ' ';
         bb[i][j] = '*';
      }
   
   // Create 2 more boxes to represent the queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {'*','*','*','*','*','*','*'},
                     {'*',' ','*',' ','*',' ','*'},
                     {'*',' ',' ',' ',' ',' ','*'},
                     {'*',' ',' ',' ',' ',' ','*'},
                     {'*','*','*','*','*','*','*'} };
               
   static box wq = { {' ',' ',' ',' ',' ',' ',' '},
                     {' ','*',' ','*',' ','*',' '},
                     {' ','*','*','*','*','*',' '},
                     {' ','*','*','*','*','*',' '},
                     {' ',' ',' ',' ',' ',' ',' '} };

   // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
   
   // Set up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares.
   // i.e. connect solutions q[] with fancy queen bq/wq via pointer board
   // Write the code.
   for (int i = 0; i < 8; i++)
      if ( (q[i]+i)%2==0)
          board[q[i]][i] = &wq;
      else
          board[q[i]][i] = &bq;

   cout << "Solution #" << ++solution << ":\n ";
   
   // Print upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print the board
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << '|';
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               // board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << '|' << "\n";
      }

   // Print lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << '-';
   cout << "\n\n";
}

int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;

    while (c >= 0) {  // NEXT COL:
        c++;                // Move to the next column
        if (c > 7) {          // If you have passed the last column, a solution is found
            print(q);      // Call the print function and backtrack
            c--;
        }
        else q[c] = -1;   // set to -1 so in inner loop you can start q[c] from 0
        while (c >= 0) {  // NEXT ROW:
            q[c]++;           // Move to the next row
            if (q[c] > 7) c--;  // If you have passed the end of the row, backtrack
            else              // Otherwise, call the ok function.
                if (ok(q, c)) break; // If ok (returns true), a queen is filled in the row
        }
    }
    return 0;
}
