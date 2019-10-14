#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include <time.h>

using namespace std;

void main()
{
	cout << "Enter size of array: ";
	int size;
	cin >> size;

	UnorderedArray<int> unordered(size);
	//OrderedArray<int> ordered(size);

	for (int i = 0; i < size; i++)
	{
		int rng = rand() % 101;
		unordered.push(rng);
		//ordered.push(rng);
	}

	cout << "\nGenerated array: " << endl;
	cout << "Unordered: ";
	for (int i = 0; i < unordered.getSize(); i++)
		cout << unordered[i] << "   ";
	//cout << "\nOrdered: ";
	//for (int i = 0; i < ordered.getSize(); i++)
	//	cout << unordered[i] << "   ";

	cout << "\n\nEnter number to search: ";
	int input;
	cin >> input;
	cout << endl;

	cout << "Unordered Array(Linear Search):\n";
	int result = unordered.linearSearch(input);
	if (result >= 0)
		cout << input << " was found at index " << result << ".\n";
	else
		cout << input << " not found." << endl;

	//cout << "Ordered Array(Binary Search):\n";
	//result = ordered.binarySearch(input);
	//if (result >= 0)
	//	cout << input << " was found at index " << result << ".\n";
	//else
	//	cout << input << " not found." << endl;
	system("pause");
}