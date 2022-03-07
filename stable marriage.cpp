#include<iostream>
using namespace std;

bool ok(int q[], int c) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man#i) and (Man#c's wife) both like each other more than their own spouse
	  Third condition checks if (Man#c) and (Man#i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man#i likes Woman#j. (0 = favorite; 2 = least favorite) 
	  wp[i][j] tells you how much Woman#i likes Man#j.

	  mp[i][q[i]] tells you how much Man#i likes his own wife. 
	  mp[i][q[c]] tells you how much Man#i likes Man#c's wife. 
	  wp[q[i]][i] tells you how much Man#i's wife likes Man#i. 
	  wp[q[i]][c] tells you how much Man#i's wife likes Man#c. 
	  If mp[i][q[c]] < mp[i][q[i]], it means that Man#i likes Man#c's wife more than his own wife
	*/
	//First condition || 
	for(int i = 0; i < c; i++)
		if(q[i] == q[c] || (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) || (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]))
			return false;
	//if we pass the loop, what do we return?
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function
	for(int i = 0; i < 3; i++)
		cout << i << "\t" << q[i] << endl;
	cout << endl;
}


int main() {
	//Write the main function.
	//The main function is exactly the same as 1D Queens. EXCEPT the array size is different.
	int q[3] = {0}, c = 0;
	q[c] = 0;

	while(c >= 0) {
		c++;
		if(c == 3) {
			print(q);
			c--;
		}
		else
		q[c] = -1;
	

		while(c >= 0){
			q[c]++;
			if(q[c] == 3) c--;
			else 
			if(ok(q,c)) break;
		}
	}
	return 0;
}
