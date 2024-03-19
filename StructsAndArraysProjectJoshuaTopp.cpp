// StructsAndArraysProjectJoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <iomanip>
#include <fstream>
using namespace std; 
const int MaxRows = 20;
const int NCols = 8; 
const string inFile = "RuunnersText.txt";
ifstream inFilie;
struct runnerData {
	string name;
	double milesRun[NCols];
	double average;
	double total;
};
//Read the data off of the input file
// Preconditions - needs a place to send the names of the runners and they miles they ran, which are empty arrrays. 
// Post conditions - Return the number of rows (names) on the file and store the data into the arrays. 
double GetMilesRan(runnerData runners[], int MaxRows);

// Calc. Total miles and average miles ran per day for each runner
// Preconditions - recieves the number of miles ran each day for each runner. 
// Post conditions - The average miles per day of each runner is calculated and output in the right spot. 
void CalcAverage(runnerData runners[], double rows);


//Clac toal miles of each runner in that week and display it. 
//Preconditions - Table of milesRan[i][j] has to be accessible so the numbers can be added and returned. 
// Post condition - The total miles of each runners' week is out put next to their average at the end of the table. 
void CalcTotal(runnerData runners[], double rows);
	

int main()
{
	ifstream inFile;
	inFile.open("RuunnersText.txt");
	if (inFile.is_open()) {
	}
	runnerData runners[MaxRows]; 
	double numRecords;
	numRecords = GetMilesRan(runners, MaxRows);
	CalcAverage(runners, numRecords);
	CalcTotal(runners, numRecords);
	for (int i = 0; i < numRecords; i++) {
		runners[i].average = GetMilesRan(runners, numRecords);
		}
			cout << endl;
			//cout << CalcAverage(milesRan[i][j], MaxRows);
			//cout << CalcTotal(milesRan[i][j], MaxRows) << endl;
		}

double GetMilesRan(runnerData runners[], int MaxRows) {
	ifstream  inFile;
	int rows = 0;
	inFile.open("RuunnersText.txt");
	inFile >> runners[rows].name;
	while (!inFile.eof() && !(rows >= MaxRows)) {
		for (int i = 0; i < NCols-2; i++) {
			inFile >> runners[rows].milesRun[i];
		}
		rows++;
		inFile >> runners[rows].name;
	}
	inFile.close();
	return rows; 


}
void CalcAverage(runnerData runners[], double rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 2; j++)
			sum += runners[i].milesRun[j];
		runners[i].average= sum / (NCols - 2);
	}
}
void CalcTotal(runnerData runners[], double rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 2; j++)
			sum += runners[i].milesRun[j];
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
