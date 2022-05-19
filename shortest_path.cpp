#include<iostream>
#include <string> // add string header
using namespace std;

const int rows = 5;
const int cols = 6;
string path[rows][cols]; // declare a path matrix, it is a string matrix

int cost(int i, int j) {
    // i is the row, j is the column
    static int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
};

    static int memo[rows][cols] = { 0 }; // declare the static memo matrix

    // base case (leftmost column)
    if (j == 0) {
    path[i][0] = to_string(i);// update the base case path matrix
    return weight[i][0];
}

    // If the cost has already been calculated
    //return it.
    if(memo[i][j] != 0) return memo[i][j];
    // recursive call - cost(i, j) = weight[i][j] + min_cost(left/up/down-row_index,j-1)
    
    // all 3 type move, we have col_index - 1
    int left = cost(i, j-1); // move left, row_index doesn't change
    int up = cost((i+(rows-1))%rows, j-1); // move up, (row_index + (rows-1)) % rows
    int down = cost((i + 1) % rows, j-1); // move down, (row_index + 1) % rows

    // find the value of the shortest path through cell (i,j)
    int minCost = min(up,min(left,down));

    // update the path matrix
    // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
    if (minCost == up)
        path[i][j] =  path[(i+(rows-1))%rows][j-1] + to_string(i);

    // If left is the minimum...
    if (minCost == left)
        path[i][j] =  path[i][j-1] + to_string(i);

    // If down is the minimum..
    if (minCost == down)
        path[i][j] =  path[(i+1)%rows][j-1] + to_string(i);

    // cost(i, j) = weight[i][j] + min_cost(left/up/down-row_index, j-1)
    memo[i][j] = weight[i][j] + minCost;
    return memo[i][j];
}//end of cost function

int main() {
    int ex[rows];
    
    // get the shortest path out of each cell on the right
    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i, cols - 1); // call recursive function to get the shortest path for each exit
// store the row index
}

    // now find the smallest of them
    int minRow = ex[0];
    int index = 0;

    // for-loop
     for (int i = 0; i < rows; i++){
          if (ex[i] < minRow) minRow = ex[i];
          index = i;
       }


    cout << "The sortest path is of length " << minRow << endl;
    cout << "The rows of the path from left to right are " << path[index][cols-1]<< endl;
    return 0;
}