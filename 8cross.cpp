#include<iostream>
#include<cmath>
using namespace std;

// Backtrack Method:
bool ok(int q[], int c){
    static int a[8][5] = {
        {-1},
        {0,-1},
        {0,1,-1},
        {0,2,-1},
        {1,2,-1},
        {1,2,3,4,-1},
        {2,3,5,-1},
        {4,5,6,-1}
    }; // Helper Array
    
    //check if the number in position c has already been used
    for(int i = 0; i < c; i++)
        if(q[i] == q[c]) return false;
    
    //check if numbers are consecutive
    for(int i = 0; a[c][i] != -1; i++)
        if(abs(q[c] - q[a[c][i]]) == 1) return false;
    
    return true;    
    
}

void print(int q[]){
    static int count = 1;
    cout << "Solution #" << count++ << ": " << endl;

    cout << " " << q[1] << q[4] << endl;
    cout << q[0]<< q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    cout << endl;

}

int main() {
    //initialize variables;
    int q[8] = {0},c = 0;
    q[c] = 1; //place number 1 at position 0
    
   
    while(c >= 0){ // end the loop if you have no square to backtrack
        c++; // Move to the next position c
        
        // if you have passed the last position, print and backtrack
         if(c == 8) {
            print(q); // print this solution
            c--; // backtrack to look for next sol
         }
        // Otherwise, move num to 0, which is one num smaller than 1
        else q[c] = 0;


        while(c >= 0){
            // Move to the next num
            q[c]++;

            // if no num can be placed at current position c
            if(q[c] > 8) c--;  // backtrack to previous position
           
            // else if number is ok break and go to next position c
            else 
            if (ok(q,c)) break;
        }
    }
    
    
    return 0;
}