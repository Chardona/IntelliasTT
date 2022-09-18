#include "Header.h"

string getName(string& line, char separator) {
	string name;
	for (size_t i{}; i < line.length(); i++) {
		if (line[i] == separator) {
			break;
		}
		name += line[i];
	}
	return name;
}
string getDate(string& line, char separator) {
	string date;
	int separator_count = separatorCount(line, separator);
	int current_separator{};
	for (size_t i{}; i < line.length(); i++) {
		if (line[i] == separator) {
			current_separator++;
		}
		if (current_separator == separator_count - 1 && line[i] != separator) {
			date += line[i];
		}
	}
	return date;
}
string getHoursWorked(string& line, char separator) {
	string hours_worked;
	int separator_count = separatorCount(line, separator);
	int current_separator{};
	for (size_t i{}; i < line.length(); i++) {
		if (line[i] == separator) {
			current_separator++;
		}
		if (current_separator == separator_count && line[i] != separator) {
			hours_worked += line[i];
		}
	}
	return hours_worked;
}
int separatorCount(string& line, char separator) {
	int separator_count{};
	for (size_t i{}; i < line.length(); i++) {
		if (line[i] == separator) {
			separator_count++;
		}
	}
	return separator_count;
}
void modifyDate(string& date) {
	map <string, string> months;
	months.insert(pair<string, string>("01", "January"));
	months.insert(pair<string, string>("02", "February"));
	months.insert(pair<string, string>("03", "March"));
	months.insert(pair<string, string>("04", "April"));
	months.insert(pair<string, string>("05", "May"));
	months.insert(pair<string, string>("06", "June"));
	months.insert(pair<string, string>("07", "July"));
	months.insert(pair<string, string>("08", "August"));
	months.insert(pair<string, string>("09", "September"));
	months.insert(pair<string, string>("10", "October"));
	months.insert(pair<string, string>("11", "November"));
	months.insert(pair<string, string>("12", "December"));

	string y = date.substr(0, 4);
	string m = date.substr(5, 2);
	date = y + " " + months[m];
}