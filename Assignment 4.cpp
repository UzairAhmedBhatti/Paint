// Assignment 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;

class ComplexNumber
{
private:					// private members of classs
	int real;
	int imaginary;
public:							// public members of class

	ComplexNumber();						// default constructor
	ComplexNumber(int, int);				// parameterized constructor
	~ComplexNumber(); //Does Nothing.		// default destructr	
	void Input();							// function for taking input
	void Output();							// function for giving output
	bool IsEqual(ComplexNumber);			// checking if 2 complex number are equal
	ComplexNumber Conjugate();				// calc conjugate and return a new complex number
	ComplexNumber Add(ComplexNumber);		// add 2 complex numbers and return a new complex number	
	ComplexNumber Subtract(ComplexNumber);  // subtract 2 complex numbers and return a new complex number
	ComplexNumber Multiplication(ComplexNumber); // multiply 2 complex numbers and return a new complex number
	float Magnitude();							// calculate magnitude of a complex number
};

ComplexNumber::ComplexNumber()             // default cons initializing to 0;
{
	real = 0;
	imaginary = 0;
}

ComplexNumber::ComplexNumber(int realNumber, int imagNumber)        // parameterized cons giving specific values to private members
{
	real = realNumber;
	imaginary = imagNumber;
}

ComplexNumber:: ~ComplexNumber()    // destructor
{
	// does nothing
}

void ComplexNumber::Input()       // funtion for taking input
{
	cout << "Enter Real: ";
	cin >> real;
	cout << "Enter Imaginary: ";
	cin >> imaginary;
}

void ComplexNumber::Output()            // function for outputting complex number
{
	if (imaginary >= 0)                // if imag > 0 than output + sign
	{
		cout << real << "+" << imaginary << "i" << endl;
	}
	else if (imaginary <= 0)            // if imag < 0 than output sign with complex num will itseld be -
	{
		cout << real << imaginary << "i" << endl;
	}
}

bool ComplexNumber::IsEqual(ComplexNumber X)
{
	if (real == X.real && imaginary == X.imaginary)      // compare 2 complex numbers by comparing real with real and imag with imag
	{
		return true;
	}
	return false;
}

ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber conjugate;           // create a new complex number 
	conjugate.real = real;				// new real is real
	conjugate.imaginary = -imaginary;		// new complex is opposite of old complex
	return conjugate;
}

ComplexNumber ComplexNumber::Add(ComplexNumber X)
{
	ComplexNumber Added;					// create new complex number 
	Added.real = real + X.real;            // new real is this->real + x.real
	Added.imaginary = imaginary + X.imaginary;  // new img is this->imag + x.imag
	return Added;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber X)
{
	ComplexNumber Subtracted;					// new complex number 
	Subtracted.real = real - X.real;		    // new real is this->real - x.real
	Subtracted.imaginary = imaginary - X.imaginary;  // new imag is this->imag - x.imag
	return Subtracted;
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber X)
{
	ComplexNumber Multiplied;           // new complex number 
	Multiplied.real = ((real * X.real) - (imaginary * X.imaginary));   //new.real= multiply  this->imaginary with X.imaginary and subtract this from this->real * X.real 
	Multiplied.imaginary = ((real * X.imaginary) + (imaginary * X.real));  //new.complex= this->real * X.imaginary + this->imaginary * X.real;
	return Multiplied;
}

float ComplexNumber::Magnitude()
{
	float Magni = sqrt((real * real) + (imaginary * imaginary));      // square root of real square and imaginary square
	return Magni;
}

int main()
{
	ComplexNumber c1;                // first complex number object
	cout << "Enter c1: " << endl;
	c1.Input();						// input complex number 

	cout << endl << endl;

	ComplexNumber c2;				// second complex number object 
	cout << "Enter c2: " << endl;
	c2.Input();						// input complex number

	cout << endl << endl;


	cout << "c1 = ";
	c1.Output();					// output first complex number 
	cout << endl;

	cout << "c2 = ";
	c2.Output();					// output second complex number 
	cout << endl;


	int Equal = c1.IsEqual(c2);					// checking if two complex numbers are equal or not
	{
		if (Equal != 0)
		{
			cout << "c1 is Equal to c2." << endl;
		}
		else
		{
			cout << "c1 is Not Equal to c2." << endl;
		}
	}
	cout << endl;

	ComplexNumber Conjugated = (c1.Conjugate());       // finding out the conjugate of complex number 1 
	cout << "Conjugate of c1:   ";
	Conjugated.Output();							  //   output the conjugated complex number 
	cout << endl << endl;

	Conjugated = (c2.Conjugate());					   // finding out the conjugate of complex number 1
	cout << "Conjugate of c2:   ";
	Conjugated.Output();								//   output the conjugated complex number
	cout << endl << endl;



	ComplexNumber Added = (c1.Add(c2));						// adding the complex numbers
	cout << "c1 + c2 :    ";
	Added.Output();										// output the added complex number
	cout << endl;

	ComplexNumber Subtracted = (c1.Subtract(c2));		//subtracting the complex numbers
	cout << "c1 - c2 :    ";
	Subtracted.Output();								// output the subtracted complex number
	cout << endl;


	ComplexNumber Multiplied = (c1.Multiplication(c2));				// multiplying the complex number 
	cout << "c1 * c2 :    ";
	Multiplied.Output();										// output the multiplied complex number
	cout << endl;


	float Magni;
	Magni = c1.Magnitude();											//  finding magnitude of complex number  
	cout << "Magnitude of c1 = " << Magni << endl << endl;			// output the magnitude 

	Magni = c2.Magnitude();											//  finding magnitude of complex number
	cout << "Magnitude of c2 = " << Magni << endl << endl;			// output the magnitude

	_getch();
	return 0;
}

