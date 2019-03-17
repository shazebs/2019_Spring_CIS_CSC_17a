#include <iostream>
using namespace std;

// No Global Constants

// Function Prototypes
int *allocate(int); // Function for allocating dynamic int array

int main()
{
	// Declare Variables 
	int userInput; 
	int *iptr;
	
	// Program Start 
	cout << "Programming Challenge 9.1 Array Allocator\n";
	cout << "------------------------------------------\n";
	cout << "This program will dynamically allocated a user inputed array of integers\n";
	cout << "How many integer elements do you want to allocate: ";
	cin >> userInput; 
	
	// "allocate" Function Call
	iptr = allocate(userInput);
	
	// Output Results
	for (int i = 0; i < userInput; i++)
	{
		cout << iptr[i] << " ";
	}
	
	return 0;
}
int *allocate(int n)
{
	int *array = new int[n];
	
	// fill array
	for (int i = 0; i < n; i++)
	{
		*(array+i) = i+1;
	}
	
	// Exit Function
	return array; 
}
