// ASSIGNMENT 5 OK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;

class Helper
{
public:
	static int StringLenght(char* str)     // This function should return lenght of str
	{
		int i = 0;
		for (; str[i] != '\0'; i++)
		{

		}
		return i;
	}


	static char * getStringFromBuffer(char * str)
	{
		int len = StringLenght(str);

		char * newString = new char[len + 1];
		strcpy_s(newString, len + 1, str);
		return newString;
	}


	static int stringCompare(char *str, char * toSearch)
	{
		int flag = 0;
		int i = 0;
		while (str[i] != '\0' && toSearch[i] != '\0')
		{
			if (str[i] != toSearch[i])
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0)
		{
			return 1;
		}
		return 0;
	}
};


class Student
{
	friend void printStatistics(Student * arr);

	friend void deallocateStatic();

private:
	char * rollNo;
	char * firstName;
	char * lastName;
	int * quizMarks;
	int * assgMarks;
	int total;

	static int totalStudents;
	static int totalQuiz;
	static int totalAssg;
	static int totalQandA;
	static int * quizTotalMarks;
	static int * assgTotalMarks;


public:
	Student()
	{
		rollNo = firstName = lastName = 0;
		quizMarks = assgMarks = 0;
		total = 0;
	}


	~Student()
	{

	}


	void deallocate()
	{
		delete[] rollNo;
		delete[] firstName;
		delete[] lastName;
		delete[] quizMarks;
		delete[] assgMarks;

		/*delete[] quizTotalMarks;
		delete[] assgTotalMarks;*/
	}

	void deallocateStatic()
	{
		delete[] quizTotalMarks;
		delete[] assgTotalMarks;
	}



	Student(Student & rhs)          // copy constructor;
	{
		rollNo = rhs.rollNo;
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		quizMarks = rhs.quizMarks;
		assgMarks = rhs.assgMarks;
		total = rhs.total;
	}

	Student & operator=(Student & rhs)    //assignment operator
	{
		if (this != &rhs)
		{
			rollNo = rhs.rollNo;
			firstName = rhs.firstName;
			lastName = rhs.lastName;
			quizMarks = rhs.quizMarks;
			assgMarks = rhs.assgMarks;
			total = rhs.total;
		}
		return *this;
	}

	static void setTotalQandA(int n)
	{
		totalQandA = n;
	}

	static int getTotalQandA()
	{
		return totalQandA;
	}

	static void setTotalStudents(int n)
	{
		totalStudents = n;
	}

	static int getTotalStudents()
	{
		return totalStudents;
	}

	static void setTotalQuiz(int n)
	{
		totalQuiz = n;
	}

	static int getTotalQuiz()
	{
		return totalQuiz;
	}

	static void setTotalAssg(int n)
	{
		totalAssg = n;
	}

	static int getTotalAssg()
	{
		return totalAssg;
	}

	static void setQuizTotalMarks(int * arr)
	{
		quizTotalMarks = arr;
	}

	static int * getQuizTotalMarks()
	{
		return quizTotalMarks;
	}

	static void setAssgTotalMarks(int * arr)
	{
		assgTotalMarks = arr;
	}

	static int * getAssgTotalMarks()
	{
		return assgTotalMarks;
	}

	void setRollNo(char * str)
	{
		rollNo = Helper::getStringFromBuffer(str);
	}

	char * getRollNo()
	{
		return rollNo;
	}

	void setFirstName(char * str)
	{
		firstName = Helper::getStringFromBuffer(str);
	}

	char * getFirstName()
	{
		return firstName;
	}

	void setLastName(char * str)
	{
		lastName = Helper::getStringFromBuffer(str);
	}

	char * getLastlName()
	{
		return lastName;
	}

	void setQuizMarks(int * arr)
	{
		quizMarks = arr;
	}

	int * getQuizMarks()
	{
		return quizMarks;
	}

	void setAssgMarks(int * arr)
	{
		assgMarks = arr;
	}

	int * getAssgMarks()
	{
		return assgMarks;
	}


	int getTotal()
	{
		return total;
	}

	void setTotal(int n)
	{
		total = n;
	}

	void printListView()
	{
		cout << rollNo << " " << firstName << " " << lastName << '\t';
		for (int i = 0; i < totalQuiz; i++)
		{
			cout << quizMarks[i] << '\t';
		}
		for (int i = 0; i < totalAssg; i++)
		{
			cout << assgMarks[i] << '\t';
		}
		cout << " Total:" << total << '\t';

		cout << endl;
	}


	void printDetailedView()
	{

		int index = 1;
		int totalQuiz = Student::getTotalQuiz();
		int totalAssg = Student::getTotalAssg();


		cout << endl << endl << "Student Information: " << endl << "Roll No:         " << rollNo << endl;
		cout << "Name:            " << firstName << " " << lastName << endl;
		cout << "Quizzez Marks: " << endl << "                   ";
		for (int i = 0; i < totalQuiz; i++)
		{
			cout << "Q" << index << ":     " << quizMarks[i] << "/" << quizTotalMarks[i];
			cout << endl << "                   ";
			index++;
		}
		cout << endl;

		index = 1;

		cout << "Assignment Marks: " << endl << "                   ";
		for (int i = 0; i < totalAssg; i++)
		{
			cout << "A" << index << ":     " << assgMarks[i] << "/" << assgTotalMarks[i];
			cout << endl << "                   ";
			index++;
		}
		cout << endl;

		cout << "Total:             " << total << "/" << totalQandA << endl << endl << endl;
	}

};

int Student::totalQandA = 0;
int Student::totalStudents = 0;
int Student::totalQuiz = 0;
int Student::totalAssg = 0;
int* Student::quizTotalMarks = 0;
int* Student::assgTotalMarks = 0;


void printStatistics(Student * arr)
{
	int total = 0;
	int index = 0;


	int totalstudents = Student::getTotalStudents();
	int numberOfQuizzes = Student::getTotalQuiz();
	int numberOfAssg = Student::getTotalAssg();

	int*  avg = new int[numberOfAssg + numberOfQuizzes];



	int * quizMarksOriginal = Student::getQuizTotalMarks();
	int * assgMarksOriginal = Student::getAssgTotalMarks();

	cout << "             ";
	for (int i = 0; i < numberOfQuizzes; i++)
	{
		cout << "Q" << i + 1 << "  ";
	}
	for (int i = 0; i < numberOfAssg; i++)
	{
		cout << "A" << i + 1 << "  ";
	}
	cout << endl;

	cout << "Total:       ";
	for (int i = 0; i < numberOfQuizzes; i++)
	{
		cout << quizMarksOriginal[i] << "  ";

	}
	for (int i = 0; i < numberOfAssg; i++)
	{
		cout << assgMarksOriginal[i] << "  ";
	}
	cout << endl;

	cout << "Maximum:     ";

	int max;

	for (int i = 0; i < numberOfQuizzes; i++)
	{

		max = arr[i].quizMarks[i];
		for (int j = 1; j < totalstudents; j++)
		{
			if (arr[j].quizMarks[i] > max)
			{
				max = arr[j].quizMarks[i];
			}
		}
		cout << max << "  ";
	}

	for (int i = 0; i < numberOfAssg; i++)
	{

		max = arr[i].assgMarks[i];
		for (int j = 1; j < totalstudents; j++)
		{
			if (arr[j].assgMarks[i] > max)
			{
				max = arr[j].assgMarks[i];
			}
		}
		cout << max << "  ";
	}
	cout << endl;
	cout << "Minimum:      ";


	int min;
	for (int i = 0; i < numberOfQuizzes; i++)
	{

		min = arr[i].quizMarks[i];
		for (int j = 1; j < totalstudents; j++)
		{
			if (arr[j].quizMarks[i] < min)
			{
				min = arr[j].quizMarks[i];
			}
		}
		cout << min << "   ";
	}

	for (int i = 0; i < numberOfAssg; i++)
	{

		min = arr[i].assgMarks[i];
		for (int j = 1; j < totalstudents; j++)
		{
			if (arr[j].assgMarks[i] < min)
			{
				min = arr[j].assgMarks[i];
			}
		}
		cout << min << "   ";
	}
	cout << endl;

	cout << "Average:      ";


	for (int i = 0; i < numberOfQuizzes; i++)
	{
		for (int j = 0; j < totalstudents; j++)
		{
			total = total + arr[j].quizMarks[i];
		}
		avg[index] = total / totalstudents;
		index++;
		total = 0;
	}
	total = 0;

	int x = 0;

	for (int i = 0; i < numberOfQuizzes; i++)
	{
		cout << avg[x] << "   ";
		x++;
	}


	for (int i = 0; i < numberOfAssg; i++)
	{
		for (int j = 0; j < totalstudents; j++)
		{
			total = total + arr[j].assgMarks[i];
		}
		avg[index] = total / totalstudents;
		index++;
		total = 0;
	}

	for (int i = 0; i < numberOfQuizzes; i++)
	{
		cout << avg[x] << "  ";
		x++;
	}
	cout << endl << endl << endl;
}





Student * searchStudentByRollNumber(Student* arr, char * searchString)
{
	int totalstudents = Student::getTotalStudents();
	for (int i = 0; i < totalstudents; i++)
	{
		int check = Helper::stringCompare(arr[i].getRollNo(), searchString);
		if (check == 1)
		{
			return &arr[i];
		}
	}
	return 0;
}

void sortByTotal(Student * &arr)
{
	int totalStudents = Student::getTotalStudents();
	for (int i = 0; i < totalStudents; i++)
	{
		for (int j = 0; j < totalStudents - 1; j++)
		{
			if (arr[j].getTotal() < arr[j + 1].getTotal())
			{
				//swap(arr[j], arr[j + 1]);
				Student temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

Student* LoadDataFromFile()
{
	int totalQandA = 0;
	int total = 0;
	Student * allArr = nullptr;

	ifstream fin;
	fin.open("Data.txt");
	if (fin.is_open())		//check if file has been opened
	{
		int totalStudents;
		fin >> totalStudents;

		Student::setTotalStudents(totalStudents);

		int totalQuizzes;

		fin >> totalQuizzes;

		Student::setTotalQuiz(totalQuizzes);


		int totalAssignments;
		fin >> totalAssignments;


		Student::setTotalAssg(totalAssignments);


		int* quizzesTotalMarks = new int[totalQuizzes];

		for (int i = 0; i<totalQuizzes; i++)
		{
			fin >> quizzesTotalMarks[i];
			totalQandA = totalQandA + quizzesTotalMarks[i];
		}

		Student::setQuizTotalMarks(quizzesTotalMarks);



		int* assignTotalMarks = new int[totalAssignments];
		for (int i = 0; i<totalAssignments; i++)
		{
			fin >> assignTotalMarks[i];
			totalQandA = totalQandA + assignTotalMarks[i];
		}
		Student::setAssgTotalMarks(assignTotalMarks);

		Student::setTotalQandA(totalQandA);

		char tempBuffer[30];

		allArr = new Student[totalStudents];

		for (int i = 0; i < totalStudents; i++)
		{
			fin >> tempBuffer;

			allArr[i].setRollNo(tempBuffer);


			fin >> tempBuffer;

			allArr[i].setFirstName(tempBuffer);


			fin >> tempBuffer;

			allArr[i].setLastName(tempBuffer);


			int* quizzesEarnedMarks = new int[totalQuizzes];
			for (int i = 0; i<totalQuizzes; i++)
			{
				fin >> quizzesEarnedMarks[i];
				total = total + quizzesEarnedMarks[i];
			}



			allArr[i].setQuizMarks(quizzesEarnedMarks);


			int* assignEarnedMarks = new int[totalAssignments];
			for (int i = 0; i < totalAssignments; i++)
			{
				fin >> assignEarnedMarks[i];
				total = total + assignEarnedMarks[i];
			}

			allArr[i].setAssgMarks(assignEarnedMarks);


			allArr[i].setTotal(total);

			total = 0;


		}
		fin.close();
	}
	else
	{
		cout << "Error opening file.\n";

	}

	return allArr;
}


int main()
{
	char rollNoToSearch[20] = "15L-1234";
	char rollNoToSearch1[20] = "15L-4023";

	Student * all = LoadDataFromFile();
	int totalStudents = Student::getTotalStudents();
	if (all != nullptr)
	{
		cout << "---------------------------------Data Read from File----------------------------" << endl << endl;
		for (int i = 0; i < totalStudents; i++)
		{
			all[i].printListView();
		}


		cout << endl << "---------------------------------Sorted List------------------------------------" << endl << endl;
		sortByTotal(all);

		for (int i = 0; i < totalStudents; i++)
		{
			all[i].printListView();
		}

		cout << endl << "---------------------------------Student Information----------------------------" << endl << endl;

		cout << "Enter Student Roll Number: //User Enters: 15L-1234";
		//cin >> rollNoToSearch;
		cout << endl;
		Student * temp = searchStudentByRollNumber(all, rollNoToSearch);
		{
			if (temp != 0)
			{
				temp->printDetailedView();
			}
			else
			{
				cout << "Student not found" << endl << endl << endl;
			}
		}

		cout << endl << "---------------------------------Student Information---------------------------" << endl << endl;

		cout << "Enter Student Roll Number: //User Enters: 15L-4023";

		cout << endl;

		temp = searchStudentByRollNumber(all, rollNoToSearch1);
		{
			if (temp != 0)
			{
				temp->printDetailedView();
			}
			else
			{
				cout << "Student not found" << endl << endl << endl;
			}
		}

		cout << "-------------------------------Class Statistics---------------------------------" << endl;
		printStatistics(all);
	}

	for (int i = 0; i < totalStudents; i++)
	{
		all[i].deallocate();
	}

	delete[] all;


	//deallocateStatic();

	_getch();
	return 0;
}





