#include <iostream>
using namespace std;

// No Global Constants

// Function Prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
	// Ask user to enter the number of donations
	int NUM_DONATIONS;
	cout << "Programming Challenge 9.7\n";
	cout << "---------------------------------------\n";
	cout << "Enter in the number of donations: ";
	cin >> NUM_DONATIONS;
	
	// An array containing the donations amount
	int donations[NUM_DONATIONS];
	// Enter user's own set of donations
	for (int i = 0; i < NUM_DONATIONS; i++)
	{
		cout << "Donation " << i+1 << ": ";
		cin >> donations[i];
	}
	
	// An array of pointers to int
	int *arrPtr[NUM_DONATIONS];
	
	
	// Each element of arrPtr is a pointer to an int.
	// Make each element point to an element in the donations array
	for (int count = 0; count < NUM_DONATIONS; count++)
	{
		arrPtr[count] = &donations[count];
	}
	
	// Sort the elements of the array of pointers
	arrSelectSort(arrPtr, NUM_DONATIONS);
	
	// Display the donations using the array of pointers. This
	// will display them in sorted order
	cout << "\nThe donations, sorted in ascending order, are: \n";
	showArrPtr(arrPtr, NUM_DONATIONS);
	
	// Display the donations in their original order
	cout << "\nThe donations, in their original order, are: \n";
	showArray(donations, NUM_DONATIONS);
	
	return 0;
	
}
void arrSelectSort(int *arr[], int size)
{
	int startScan, minIndex;
	int *minElem;
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = arr[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(arr[index]) < *minElem)
			{
				minElem = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minElem;
	}
}
void showArray(const int arr[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << arr[count] << " ";
	} 
	cout << endl;
}
void showArrPtr(int *arr[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << *(arr[count]) << " ";
	}
	cout << endl;
}
