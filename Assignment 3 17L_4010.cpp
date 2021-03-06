// ass 3 final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;



void StringConcatenate(char *str1, char *str2)
{

	int i = 0;
	for (; *(str1 + i) != '\0'; i++)        // counting string 1 length
	{

	}


	*(str1 + i) = ' ';
	i++;

	while (*str2 != '\0')			// copying string 2 to string 1
	{
		*(str1 + i) = *str2;
		i++;
		str2++;
	}
	*(str1 + i) = '\0';
}


char * gettingToken(char * str1, int & s)
{
	int count = 0;
	int i = s;
	while (*(str1 + i) != ' ' && *(str1 + i) != '\0')           // to see where a word ends
	{
		count++;
		i++;
	}
	char * token = new char[count + 1];                // array on heap of size of the word + 1
	i = 0;
	while (*(str1 + s) != ' ')
	{
		*(token + i) = *(str1 + s);							// copy the word in new char array to make it a token
		i++;
		s++;
	}
	*(token + i) = '\0';
	s++;

	return token;
}


char** StringTokens(char* str1)
{

	int i = 0;            // for calculating length
	int nTokens = 1;
	while (*(str1 + i) != '\0')        // finding number of total words
	{
		if (*(str1 + i) == ' ')
		{
			nTokens++;
		}
		i++;
	}
	char ** temp = new char *[nTokens + 1];   // making an array of char * on heap


	int s = 0;							// integer to count from the 1st word at first and than tell where the next word starts from 

	int j = 0;
	for (; j < nTokens; j++)                 // assignment of address of array of each token to char * array
	{
		*(temp + j) = gettingToken(str1, s);
	}
	*(temp + j) = '\0';                         // null character at the end of char * array

	return temp;							// return a 2d char pointer

}


char ** InverseStringTokens(char* str1)
{


	char ** temp = StringTokens(str1);          // getting tokens at first 

	int tokens = 0;
	for (; *(temp + tokens) != '\0'; tokens++)              // counting number of tokens 
	{

	}

	char ** temp2 = new char *[tokens];        // creating 2d char array on heap of same size as the number of tokens

	*(temp2 + tokens) = '\0';               // putting null char at the end of char * array

	int k = 0;
	tokens--;

	for (; tokens >= 0; tokens--)          // copying the last token in the first place of new array and so on
	{
		*(temp2 + k) = *(temp + tokens);
		k++;
	}


	return temp2;				// return address of reversed array;

}


char * ReverseSentence(char* str1)
{
	char ** temp = InverseStringTokens(str1);     // getting reversed tokens 

	char * revSenPtr = new char[80];			// making a new char array to store reversed sentence and not alter original string
	*(revSenPtr + 0) = '\0';

	int i = 0;
	while (*(temp + i) != '\0')							// concatinating the new char array revsenptr with reversed tokens in a loop
	{
		StringConcatenate(revSenPtr, *(temp + i));
		i++;
	}
	return revSenPtr;					// return reversed sentence array ptr;
}


void CompressString(char* str)
{
	int index = 0;                // Used as index in the modified string

	int len = 0;
	for (int i = 0; *(str+i) != '\0'; i++)				// calculate length of original string 
	{
		len++;
	}
	
	for (int i = 0; i < len; i++)          // traverse through all characters
	{  
		int j;
		for (j = 0; j < i; j++)
		{
			if (*(str+i) == *(str+j) )       // Check if *(str+i) is present before it
			{
				break;
			}
		}
		if (j == i)														// If not present, then add it to the result;
		{ 
			*(str+index) = *(str+i);
			index++;
		}
	}
	cout << "String after Compression:     ";  // print compressed string
	for (int i = 0; i < len; i++)
	{
		if (i == 6)
			break;

		cout << *(str+i);
	}
}


int main()
{
	char * string1 = new char[80];     // creating strings on heap
	char * string2 = new char[80];
	char * string3 = new char[80];

	ifstream fin;
	fin.open("Data.txt");	//open file

	fin.getline(string1, 80);    // getting lines into respective strings arrays	
	fin.getline(string2, 80);
	fin.getline(string3, 80);


	cout << "Testing StringConcatenate: " << endl;   // String Concatenate 
	cout << "String 1:     " << string1 << endl;
	cout << "String 2:     " << string2 << endl;
	StringConcatenate(string1, string2);
	cout << "After Concatenation: " << endl;
	cout << "String 1:      " << string1 << endl;
	cout << "String 2:      " << string2 << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;




	char ** tokenizedString = StringTokens(string1);   // String Tokenization
	cout << "Testing StringTokens: " << endl << endl;
	cout << "Tokens of String are as follows: " << endl << endl;
	for (int l = 0; *(tokenizedString+l) != '\0'; l++)
	{
		cout << *(tokenizedString+l) << endl;
	}
	cout << "-------------------------------------------------------------------------------" << endl << endl;




	cout << "Testing InverseStringTokens: " << endl << endl;     // Inverse String Tokens
	cout << "Tokens of the string in reverse order are as follows: " << endl << endl;
	char ** reversedTokens = InverseStringTokens(string1);
	for (int l = 0; *(reversedTokens+l) != '\0'; l++)
	{
		cout << *(reversedTokens+l) << endl;
	}
	cout << endl << "--------------------------------------------------------" << endl << endl;





	cout << "Testing ReverseSentence: " << endl << endl;		// Reverse Sentece
	char * ReversedSentence = ReverseSentence(string1);
	cout << "Reverse Sentence of String is:      " << ReversedSentence;
	cout << endl << "----------------------------------------------------" << endl << endl;



	cout << "Testing CompressString:" << endl << endl;			// Compress String
	cout << "String:      " << string3 << endl << endl;
	CompressString(string3);
	cout << endl << "----------------------------------------------------" << endl << endl;






	for (int l = 0; *(tokenizedString + l) != '\0'; l++)       // de allocation of all the memory
	{
		delete[] * (tokenizedString + l);
	}
	delete[] tokenizedString;


	for (int l = 0; *(reversedTokens + l) != '\0'; l++)
	{
		delete[] * (reversedTokens + l);
	}
	delete[] reversedTokens;


	delete[] ReversedSentence;


	delete[] string1;
	delete[] string2;
	delete[] string3;


	_getch();
	return 0;
}
