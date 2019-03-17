/*
Author: Shazeb Suhail
Programming Challenge 9.2 Test Scores #1
*/

#include <iostream>
#include <iomanip>
using namespace std;

// No Global Constants
// Function Prototypes
void swap(int &, int &);
void selectionSort(float [], int);
void *calcAverage(float [], int);

int main()
{
	cout << "Programming Challenge 9.2\n";
	cout << "-------------------------\n";
	float *iptr; // 
	int numScores;
	// Get the number of test scores
	cout << "How many test scores do you want to enter: ";
	cin >> numScores;
	
	// Test Scores array
	float testScores[numScores]; // Array for test scores
	iptr = testScores; // initialize ptr to array
	for (int i = 0; i < numScores; i++)
	{
		cout << "Enter Test Score " << i+1 << ": ";
		cin >> iptr[i];
		while (iptr[i] < 0)
		{
			cout << "Test score cannot be negative.\n";
			cout << "Enter a positive test score: ";
			cin >> iptr[i];
		}
	}
	// Sort the test scores
	selectionSort(iptr, numScores); // Function Call
	
	// Print the Array
	cout << endl;
	cout << "Test Scores listed in Ascending Order:\n";
	for (int i=0;i<numScores;i++)
    {
    	cout << iptr[i] << endl;
	}
	cout << endl;
	// Calculate the average 
	calcAverage(iptr,numScores); // Function Call 
	
	return 0;
	
}
void selectionSort(float ptr[], int size)
{
	int minIndex, minVal;
	
	for (int start=0;start<(size-1);start++)
	{
		minIndex = start;
		minVal = ptr[start];
		for (int index = start +1;index<size;index++)
		{
			if(ptr[index] < minVal)
			{
				minVal = ptr[index];
				minIndex = index;
			}
		}
		swap(ptr[minIndex],ptr[start]);
	}
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void *calcAverage(float *ptr, int size)
{
	float total = 0.0;
	float avgScore;
	for (int i = 0; i < size; i++)
	{
		total += ptr[i]; // Running Total 
	}
	
	// Output Results
	avgScore = total/(size); 
	cout << "Average Test Score:" << endl;
	cout << fixed << setprecision(2) << avgScore << endl;
}
