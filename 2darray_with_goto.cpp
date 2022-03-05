#include<iostream>
using namespace std;

int main() {
    //initialize variables;
    int q[8][8] = {0}, r , c = 0, count = 0;
    q[0][0] = 1;
   
    
    Nc: c++;
     if(c == 8) goto print; // finish checking the whole board and move to print part
        r = -1;

    Nr: r++;
        if(r == 8) goto backtrack; // can not find the correct position of queen, go back to the previous column

    // row test
    for(int i = 0; i < c; i++)    
        if(q[r][i] == 1) goto Nr;

    // up diagonal test
    for(int i = 1; r - i >= 0 && c - i >= 0; i++)
        if(q[r - i][c - i] == 1) goto Nr;

    // down diagonal test
    for(int i = 1; r + i < 8 && c - i >= 0; i++)
        if(q[r + i][c - i] == 1) goto Nr;

        q[r][c] = 1; // find the queen's position of current column
        goto Nc;  

    backtrack: c--;
        if(c == -1) return 0;
        r = 0;
        while(q[r][c] != 1)
            r++;
        q[r][c] = 0;
        goto Nr;

    print: count++;
        cout << "-------" << count << "-------\n";
    
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cout << q[i][j] << " ";
            }  cout << endl;
        } cout << endl;
        goto backtrack;    
    
    return 0;
}
