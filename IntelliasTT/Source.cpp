#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <map>
#include <chrono>

using std::ofstream;
using std::ifstream;
using std::string;
using std::map;
using std::pair;
using std::cout;
using std::cin;
using namespace std::chrono;


int main() {

	auto start = high_resolution_clock::now();

	string fin_name, fout_name;
	char separator;

	cout << "Plese enter input data file name: ";
	cin >> fin_name;
	ifstream fin(fin_name);
	if (fin.fail()) {
		cout << "Incorrect input file name.\n";
		exit(1);
	}

	cout << "Please enter output data file name: ";
	cin >> fout_name;
	ofstream fout(fout_name);
	if (fout.fail()) {
		cout << "Incorrect output file name.\n";
		exit(1);
	}

	cout << "Please enter separator in the file: ";
	cin >> separator;
	
	string line, name, date, hours_worked;

	try {
		while (!fin.eof()) {
			getline(fin, line);
			name = getName(line, separator);
			date = getDate(line, separator);
			modifyDate(date);
			hours_worked = getHoursWorked(line, separator);
			fout << "Name: " << name << ", date: " << date << ", hours worked: " << hours_worked << ".\n";
		}
	}
	catch (...) {
		cout << "Most likely you've entered wrong separator. Check it.\n";
	}
	
	fin.close();
	fout.close();
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "Program took: "<<duration.count()<<" ms.";
}