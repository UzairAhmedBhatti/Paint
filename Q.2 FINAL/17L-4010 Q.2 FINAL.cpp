#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void input(int * &aPtr, int* &bPtr, int &size1, int &size2, ifstream &fin)           // input in arrays and storing 
{
	fin >> size1;
	aPtr = new int[size1];

	int * endPtr = aPtr + size1;

	cout << "Array: ";
	for (int * startPtr = aPtr; startPtr < endPtr; startPtr++)
	{
		fin >> *startPtr;
		cout << *startPtr << ", ";
	}
	cout << endl;

	fin >> size2;
	bPtr = new int[size2];

	endPtr = bPtr + size2;

	cout << "Array: ";
	for (int * startPtr = bPtr; startPtr < endPtr; startPtr++)
	{
		fin >> *startPtr;
		cout << *startPtr << ", ";
	}
	cout << endl << endl;
}

int  * merge(int * &aPtr, int * &bPtr, int &size1, int &size2)                   // merging and storing merged array in new array and returning its pointer
{
	int size3 = size1 + size2;
	int * mergedArrayPtr = new int[size3];
	int k = 0;
	int j = size2 - 1;
	for (int i = 0; i < size1; i++)
	{
		for (j; j >= 0; j--)
		{
			if (*(aPtr + i) < *(bPtr + j))
			{
				*(mergedArrayPtr + k) = *(aPtr + i);
				k++;
				break;
			}
			else if (*(aPtr + i) > *(bPtr + j) || *(aPtr + i) == *(bPtr + j))
			{
				*(mergedArrayPtr + k) = *(bPtr + j);
				k++;
			}
		}

		if (j < 0)
		{
			*(mergedArrayPtr + k) = *(aPtr + i);
			k++;
		}
		if (i == size1 - 1)
		{
			*(mergedArrayPtr + k) = *(bPtr + j);
			k++;
		}
	}
	return mergedArrayPtr;
}

void outputMergedArray(int *newPtr, int size1, int size2)    // output of merged array
{
	int size3 = size1 + size2;

	cout << "Merged Array: " << endl;

	int *endPtr = newPtr + size3;

	for (int * startPtr = newPtr; startPtr < endPtr; startPtr++)
	{
		cout << *startPtr << ", ";
	}
	cout << endl << endl << endl;
}

int main()
{
	ifstream fin("Data2.txt");

	int *aPtr = nullptr;   // initial pointers
	int *bPtr = nullptr;

	int size1 = 0;       //initial sizes
	int size2 = 0;

	while (!fin.eof())
	{
		input(aPtr, bPtr, size1, size2, fin);   // to store original arrays

		int * mergedArrayPtr = merge(aPtr, bPtr, size1, size2);		// to merge

		outputMergedArray(mergedArrayPtr, size1, size2); // for output of merged array

		delete[] mergedArrayPtr; // deallocation of memory
		delete[] aPtr;
		delete[] bPtr;
	}

	_getch();
}
