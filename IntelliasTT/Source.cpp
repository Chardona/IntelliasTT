#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <map>
using std::ofstream;
using std::ifstream;
using std::string;
using std::map;
using std::pair;
using std::cout;
using std::cin;






int main() {
	char separator = '*';
	string fin_name, fout_name;
	cout << "Plese enter input data file name: ";
	cin >> fin_name;
	cout << "Please enter output data file name: ";
	cin >> fout_name;
	ifstream fin(fin_name);
	ifstream fin("Stuff.txt");
	if (fin.fail()) {
		cout << "Incorrect input file name.\n";
		exit(1);
	}
	//ofstream fout(fout_name);
	ofstream fout("ModifiedStuff.txt");
	if (fout.fail()) {
		cout << "Incorrect output file name.\n";
		exit(1);
	}
	string line, name, date, hours_worked;

	while (!fin.eof()) {

		getline(fin, line);

		name = getName(line, separator);
		date = getDate(line, separator);
		modifyDate(date);
		hours_worked = getHoursWorked(line, separator);
		fout << "Name: " << name << ", date: " << date << ", hours worked: " << hours_worked << ".\n";
	}
	
	
	
	
	fin.close();
	fout.close();
}

