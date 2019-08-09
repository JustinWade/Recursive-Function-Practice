//This program will give the user a choice to execute 4 different
//recursive functions.

#include "parameters.h"
#include <iostream>
#include <string>

using namespace std;

//Function prototypes;
int fib(int);
int sum(int);
int longInt(int arr[], int, int, int);
int shortWord(string arr[], int);

int main() {

	int n, x, size, count = 0, max_count = 0;
	int array[20];
	string sentence, strArray[20];
	bool condition = true;

	while (condition = true) {
		//User interface
		cout << "=========================================================" << endl;
		cout << "1. Fibonacci series" << endl;
		cout << "2. Calculate the sum of integers 1, 2, ..., n." << endl;
		cout << "3. Longest sequence of positive numbers" << endl;
		cout << "4. Shortest word in a sentence" << endl;
		cout << "5. Exit" << endl;
		cout << "=========================================================" << endl;
		cout << "Please enter your choice [1 - 5]: ";
		cin >> x;
	
		switch (x) {
			//Invokes fib function	
			case 1:
				cout << "Please input n: ";
				cin >> n;
				cout << "fibonacci[" << n << "]" << " = " << fib(n) << endl;
				break;
			
			//Invokes sum function
			case 2:
				cout << "Please input n: ";
				cin >> n;
				for (int i = 1; i < n; i++) {			//displays our operation(ex. 1 + 2 = 3)
					cout << i << " + ";
				}
				for (int i = 1; i < n; i++) {
					if (i = n) {
						cout << i << " = ";
					}
				}
				cout << sum(n) << endl;
				break;
			
			//Invokes longInt function
			case 3:
				cout << "Please input the size of the array: ";
				cin >> size;
				cout << "Please input " << size << " integers: ";
				for (int nums = 0; nums < size; nums++) {				//Stores numbers in array
					cin >> array[nums];
				}
				cout << "The longest sequence of positive values in the given array is "
					<< longInt(array, size, count, max_count) << endl;
				break;
			
			//Invokes shortWord function
			case 4:
				cout << "Please input the number of words in the sentence:";
				cin >> size;
				cout << "Please input the sentence with " << size << " words: ";
				for (int words = 0; words > size; words++) {
					cin >> strArray[words];
				}
				cout << "The number of chars in the shortest word for the given sentence is "
					<< shortWord(strArray, size) << endl;
				break;
			

			//Exits 
			case 5:
				condition = false;
				exit(0);
			default: cout << "Please input valid choice between 1 and 5!" << endl;
		}
	}
	system("pause");
	return 0;
}

//This function recursively computes the fibonacci series.
int fib(int n) {
	if (n <= 1)			//base case
		return n;
	return fib(n - 1) + fib(n - 2);
}

//This function recursively computes the sum of intgers.
int sum(int n) {
	if (n <= 1)			//base case
		return n;
	return n + sum(n-1);
}

//This function recursively computes the amount of positive numbers in a sequence.
int longInt(int arr[], int size, int count, int max_count) {
	if (size < 0)
		return max_count;				//base case
	if (arr[size] > 0) {				//adds total positive ints
		count++; 
		if (count > max_count)
			max_count = count;			//counts max total
	}
	else
		count = 0; 
	size--;								//traverse through array
	max_count = longInt(arr, size, count, max_count);
	return max_count;
}


/*************** Unable to get shortWord() to work properly ************************/

//This function finds the smallest word in a given sentence and counts the number of chars.
int shortWord(string arr[], int size) {
	int shortLength = arr[0].length();
	for (int i = 1; i < size; i++) {
		if (arr[i].length() < shortLength) {
			shortLength = arr[i].length();
		}
	}
	return shortLength;

}


