#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;


int *input(ifstream & fin, int & size)    // funtion for taking input
{
	int * temp = nullptr;

	fin >> size;
	if (size > 0)						// validating size
	{
		temp = new int[size];			// creating array on heap of size size

		int * endPtr = temp + size;

		for (int * startPtr = temp; startPtr < endPtr; startPtr++)   // storing elements in array at heap
		{
			fin >> *startPtr;
		}

	}
	else if (size < 0)               // validating if size < 0
	{
		char word[50];
		fin.getline(word, 50);
	}
	return temp;
}

void sort(int * arrayPtr, int size)					// funtion for sorting 
{
	int i, key, j;
	if (arrayPtr != nullptr)
	{
		for (int i = 1; i < size; i++)
		{
			key = *(arrayPtr + i);
			j = i - 1;
			while (j >= 0 && *(arrayPtr + j) > key)
			{
				*(arrayPtr + (j + 1)) = *(arrayPtr + j);
				j--;
			}
			*(arrayPtr + (j + 1)) = key;
		}
	}
}

void outputOriginalArray(int * arrayPtr, int size)
{
	int * endPtr = arrayPtr + size;

	if (size > 0)													// validating size
	{
		cout << "Test Case " << endl << "Array before sorting: ";
	
		for (int * startPtr = arrayPtr; startPtr < endPtr; startPtr++)		// print original array
		{
			cout << *startPtr << ", ";
		}
		cout << endl;
	}

	else if (size < 0)										//  validating size and priting error message
	{
		cout << "ERROR :  the size of the array must be greater than 0 " << endl << endl;
	}
}

void outputSortedArray(int * arrayPtr, int size)
{
	int * endPtr = arrayPtr + size;

	if (arrayPtr != nullptr)								// valiating and printing sorted array
	{
		cout << "Sorted Array: " << endl;
		for (int * startPtr = arrayPtr ; startPtr < endPtr; startPtr++)
		{
			cout << *startPtr << ", ";
		}
		cout << endl << endl;
	}
}

int main()
{
	int size;
	int * arrayPtr=nullptr;

	ifstream fin;
	fin.open("Data1.txt");	//open file
	if (fin.is_open())		//check if file has been opened
	{
		while (!fin.eof())		//Stop reading at End of File
		{			
			arrayPtr = input(fin, size);            // storing original array and returning its pointer

			outputOriginalArray(arrayPtr, size);   // printing original array

			sort(arrayPtr,size);					// sorting

			outputSortedArray(arrayPtr,size);		// printing final sorted array

			size = 0;

			delete[] arrayPtr;			// deallocation of memory on heap

		}

		fin.close();			//Close file
	}
	else										// output error message
	{
		cout << "Error opening file.\n";
	}
	
	_getch();
    return 0;
}

