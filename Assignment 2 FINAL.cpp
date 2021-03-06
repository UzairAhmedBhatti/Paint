// Assignment 2 FINAL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;

int ** InputMatrix(ifstream & fin, int & rows, int & cols)
{
	fin >> rows;
	fin >> cols;
	int ** tempMatrix = nullptr;
	tempMatrix = new int * [rows];

	for (int i = 0; i < rows; i++)          // allocation of memory on heap
	{ 
		*(tempMatrix+i) = new int[cols];
	}

	int **endPtr = tempMatrix + rows;                           
	for (int ** iPtr = tempMatrix; iPtr < endPtr; iPtr++)	// storing elements read from file to array on heap
	{
		int * endCol = *iPtr + cols;
		for (int * jPtr= *iPtr	; jPtr < endCol; jPtr++)
		{
			fin >> *jPtr;
		}
	}
	return tempMatrix;
}

void OutputMatrix(int ** matrix, const int & ROWS, const int & COLS)
{
	int **endPtr = matrix + ROWS;                    
	for (int ** iPtr = matrix; iPtr < endPtr; iPtr++)            // printing matrix in proper format 
	{
		int * endCol = *iPtr + COLS;
		for (int * jPtr = *iPtr; jPtr < endCol; jPtr++)
		{
			cout << " " << *jPtr << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int ** AddMatrix(int ** matrixA, int ** matrixB, const int & ROWS, const int & COLS)
{
	int ** R = nullptr;                 // matrix R to store added matrix
	if (ROWS == COLS)					// if square matrix 
	{
		R = new int *[ROWS];
		for (int i = 0; i < ROWS; i++)			// allocation of memory on head
		{
			*(R + i) = new int[COLS];
		}

		int ** endPtr = R + ROWS;             // pointing  to an index greater than actual size ( matrix R)
		int ** endPtr1 = matrixA + ROWS;	  // pointing  to an index greater than actual size of a matrix 
		int ** endPtr2 = matrixB + ROWS;      // pointing  to an index greater than actual size of another matrix

		int ** iPtr = R;                   // pointing  to first index of array R
		int ** iPtr1 = matrixA;			  // pointing  to first index of an array 
		int ** iPtr2 = matrixB;		     // pointing  to first index of another array

		for (	; iPtr < endPtr && iPtr1 < endPtr1 && iPtr2 < endPtr2; iPtr++, iPtr1++, iPtr2++)  // checking that values dont go out of bound
		{
			int * endCol = *iPtr + COLS;				// pointing to and index greater than last index of 1st row initially and so on ( array R) 
			int * endCol1 = *iPtr1 + COLS;				// pointing to and index greater than last index of 1st row initially and so on (array 1)
			int * endCol2 = *iPtr2 + COLS;			// pointing to and index greater than last index of 1st row initially and so on (array 2)

			int * jPtr = *iPtr;						// pointing  to first index of array R initially 
			int * jPtr1 = *iPtr1;					// pointing  to first index of array 1
			int * jPtr2 = *iPtr2;					// pointing  to first index of array 2

			for (	; jPtr < endCol && jPtr1 < endCol1 && jPtr2 < endCol2; jPtr++, jPtr1++, jPtr2++)    // condition for not going out of bound
			{
				*jPtr = *jPtr1 + *jPtr2;		// adding and placing in new array R
			} 
		}
	}
	else
	{
		cout << "Addition Not Possible." << endl << endl;
	}
	return R;
}

int** TransposeMatrix(int** matrix, const int & ROWS, const int & COLS)
{
	if (ROWS == COLS)								// if square matrix
	{
		int ** tempMatrix=nullptr;
		tempMatrix = new int * [ROWS];
		for (int i = 0; i < ROWS; i++)           // memory allocation of a temporary matrix to store matrix being received as function parameter
		{
			*(tempMatrix+i) = new int[COLS];
		}

		int ** transposedMatrix= nullptr;                // memory allocation of a matrix to store transposed matrix
		transposedMatrix = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			*(transposedMatrix+i) = new int[COLS];
		}

		for (int i = 0; i < ROWS; i++)				//storing matrix received in temporaray matrix;
		{
			for (int j = 0; j < COLS; j++)
			{
				*(*(tempMatrix + i) + j) = *(*(matrix + i) + j);
			}
		}

		for (int i = 0; i < ROWS; i++)                 // code for transposing matrix and storing the transposed matrix finally in transposedMatrix
		{
			for (int j = 0; j < COLS; j++)
			{
				if (j > i)               // condition of transposition
				{
					swap(*(*(tempMatrix + i) + j), *(*(tempMatrix + j) + i));

					*(*(transposedMatrix + i) + j) = *(*(tempMatrix + i) + j);
				}

				*(*(transposedMatrix + i) + j) = *(*(tempMatrix + i) + j);
			}
		}
		return transposedMatrix;
	}
	else                   // if not a square matrix
	{
		int ** transposedMatrix=nullptr;  
		transposedMatrix = new int * [COLS];			// memory allocation for storing transposed matrix
		for (int i = 0; i < COLS; i++) 
		{
			*(transposedMatrix+i) = new int[ROWS];
		}

		int l = 0, m = 0;     // initial indexes of transpoed matrix     

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)                       // algo of transposition of non square matrix
			{
				*(*(transposedMatrix + l) + m) = *(*(matrix + i) + j);    // elements of matrix1 array being copied row wise to transposed matrix array column wise 
				l++;                    // column of tranposed matrix++;
			}
			l = 0;  // make row again zero
			m++;   // column ++ of transposed matrix array
		}
		return transposedMatrix;
	}
}

bool IsSymmetric(int ** matrix, const int & ROWS, const int & COLS)
{
	bool temp;
	if (ROWS == COLS)         // if square matrix
	{
		int ** tempMatrix=nullptr;
		tempMatrix = TransposeMatrix(matrix, ROWS, COLS);            // receive trasnposed matrix in a matrix
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (*(*(matrix + i) + j) == *(*(tempMatrix + i) + j))              // checking if matrix element and its transposed element is same
				{
					temp = true;
				}
				else
				{
					temp = false;    // if even a single element not same than break
					break;
				}
			}
			if (temp == false)
			{
				break;
			}
		}
		for (int i = 0; i < ROWS; i++)       // deallocate memory
		{
			delete[] * (tempMatrix + i);
		}
		delete[] tempMatrix;

	}
	else
	{
		temp = false;
	}

	
	return temp;
}

void InterchangeRows(int * & row1, int * & row2)
{
	// swap the rows
	int * temp = nullptr;
	temp = row1;
	row1 = row2;
	row2 = temp;
}

void InterchangeRows(int** matrix, const int& ROWS, const int& COLS)
{
	int * row1 = nullptr;
	int * row2 = nullptr;
	row1 = *(matrix+0);  // initialize the rows
	row2 = *(matrix+2);
	InterchangeRows(row1, row2);
	*(matrix+0) = row1;  // finally store the swapped values of rows
	*(matrix+2) = row2;
}



int main()
{
	int ** matrix1 = nullptr;                      // initialize the **'s to nullptr
	int ** matrix2 = nullptr;   
	int ** matrix3 = nullptr;
	int ** addedMatrix = nullptr;
	int ** transposedMatrix = nullptr;

	int row1, col1, row2, col2, row3, col3;


	ifstream fin("Data.txt");          // open file

	cout << "Matrix A = " << endl;
	matrix1 = InputMatrix(fin, row1, col1);    // store matrix and return its pointer
	OutputMatrix(matrix1, row1, col1);			// output the matrix

	cout << "Matrix B = " << endl;
	matrix2 = InputMatrix(fin, row2, col2);		//store matrix and return its pointer
	OutputMatrix(matrix2, row2, col2);			// output the matrix

	cout << "Matrix C = " << endl;
	matrix3 = InputMatrix(fin, row3, col3);   // store matrix and return its pointer
	OutputMatrix(matrix3, row3, col3);			// output the matrix


	cout << "A + B = " << endl;
	addedMatrix = AddMatrix(matrix1, matrix2, row1, col1);     // add matrix and return its pointer
	if (addedMatrix != nullptr)
	{
		OutputMatrix(addedMatrix, row1, col1);				// output the added matrix
	}


	cout << "A + C = " << endl;
	addedMatrix = AddMatrix(matrix1, matrix3, row3, col3);    // add matrix and return its pointer
	if (addedMatrix != nullptr)
	{
		OutputMatrix(addedMatrix, row3, col3);			// output the added matrix
	}

	cout << "Transpose of A = " << endl;
	transposedMatrix = TransposeMatrix(matrix1, row1, col1);     // tranpose the matrix and receive the transposed array's ptr
	swap(row1, col1);                                       // swap the row and col as it's going to be transposed
	OutputMatrix(transposedMatrix, row1, col1);   // output transposed matrix
	swap(row1, col1);             // swap row and col back for orignal use

	cout << "Transpose of C = " << endl;
	transposedMatrix = TransposeMatrix(matrix3, row3, col3);	// tranpose the matrix and receive the transposed array's ptr
	swap(row3, col3);											// swap the row and col as it's going to be transposed
	OutputMatrix(transposedMatrix, row3, col3);					// output transposed matrix
	swap(row3, col3);											// swap row and col back for orignal use


	if (IsSymmetric(matrix1, row1, col1))              // if true is returned than is symetric
	{
		cout << "Matrix A is Symmetric" << endl << endl << endl;
	}
	else                                              // if true is not returned than is not symetric
	{
		cout << "Matrix A is NOT Symmetric" << endl << endl << endl;
	}


	if (IsSymmetric(matrix2, row2, col2))                      // if true is returned than is symetric
	{
		cout << "Matrix B is Symmetric" << endl << endl << endl;
	}
	else													 // if true is not returned than is not symetric
	{
		cout << "Matrix B is NOT Symmetric" << endl << endl << endl;
	}


	cout << "Interchanging Rows of Matrix A :" << endl;     
	cout << "row1: 1" << endl;
	cout << "row2: 3" << endl << endl << endl;

	InterchangeRows(matrix1, row1, col1);           // function to interchange the rows


	cout << "After Interchanging Rows Matrix A=" << endl;
	OutputMatrix(matrix1, row1, col1);       // ouput matrix after rows being swapped



	// deallocation of memory

	for (int i = 0; i < row1; i++)              // deallocating matrix1
	{
		delete[] * (matrix1 + i);
	}
	delete[] matrix1;


	for (int i = 0; i < row2; i++)			// deallocating matrix2
	{
		delete[] * (matrix2 + i);
	}
	delete[] matrix2;


	for (int i = 0; i < row3; i++)				// deallocating matrix3
	{
		delete[] * (matrix3 + i);
	}
	delete[] matrix3;



	delete[] addedMatrix;					// deallocating added matrix (not by loop as finally it was a null ptr);


	for (int i = 0; i < row3; i++)           // deallocating transposed matrix
	{
		delete[] * (transposedMatrix + i);
	}
	delete[] transposedMatrix;


	fin.close();

	_getch();
	return 0;
}

