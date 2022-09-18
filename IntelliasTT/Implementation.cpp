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
	months.insert(pair<string, string>("1", "January"));
	months.insert(pair<string, string>("2", "February"));
	months.insert(pair<string, string>("3", "March"));
	months.insert(pair<string, string>("4", "April"));
	months.insert(pair<string, string>("5", "May"));
	months.insert(pair<string, string>("6", "June"));
	months.insert(pair<string, string>("7", "July"));
	months.insert(pair<string, string>("8", "August"));
	months.insert(pair<string, string>("9", "September"));
	months.insert(pair<string, string>("10", "October"));
	months.insert(pair<string, string>("11", "November"));
	months.insert(pair<string, string>("12", "December"));
}