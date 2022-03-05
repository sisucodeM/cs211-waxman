#include<iostream>
using namespace std;

int main() {
    //initialize variables;
    int q[8] ,c = 0, count = 0;
    q[0] = 0;
   
    
    Nc: c++;
     if(c == 8) goto print; // finish checking the whole board and move to print part
        q[c] = -1;

    Nr: q[c]++;
        if(q[c] == 8) goto backtrack; // can not find the correct position of queen, go back to the previous column

    
    // row test and diagonal test
    for(int i = 0; i < c; i++)
        if(q[i] == q[c] || c - i == abs(q[c] - q[i])) goto Nr;

        goto Nc;  

    backtrack: c--;
        if(c == -1) return 0;
        goto Nr;

    print: count++;
        cout << "Solution #" << count << " : ";
    
        for(int i = 0; i < 8; i++)
            cout << q[i];
        cout << endl;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
               if(q[j] == i) cout  << "1 ";
               else cout << "0 ";
            }  cout << endl;
        } cout << endl;  
        goto backtrack;    
    
    return 0;
}
