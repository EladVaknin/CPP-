/**
 * Author: Elad Vaknin
 */

#include "snowman.hpp"
#include <iostream>
#include <math.h>


using namespace std;
const int max_dig = 4;
const int min_dig = 1;

// returns a random number (a valid one)
int random_number(){
	int rand_dig = 0; 
	int ans = 0;
	for (int i=7; i>=0; i--){
		rand_dig = rand() % max_dig + min_dig;
		ans += rand_dig*(pow(10,i));
	}
	return ans;
}

int main() {

	// Example 1 -  prints 100 random snowmen
	int snowman_number;
	for (int i=0; i<100; i++){
		snowman_number = random_number();
		cout << " The Random number is:" << "\t";
		cout << snowman_number << endl;
		cout << " The Random snowman is:" << "\t";
		cout << ariel::snowman(snowman_number) + "\n" << endl;
	}



	// Example 2 -  Ask from the user to insert a 8 digit input
	int input ;
	// i make the while loop to allow the try block in case of incorrect input
	int flag = 1; 
	while (flag){
		cout << "Please enter a number an  8 digits number, above are examples of snowmen you are welcome to choose from there :  " << endl;
		try{
			cin >> input;
			cout << ariel::snowman(input) << endl;
			flag=0;
		}
		catch(exception e){
			cout << "You inserted invalid input, please try again" << endl;
		}
	}
	return 0;
}
