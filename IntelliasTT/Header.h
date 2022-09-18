#ifndef TT
#define TT
#include <string>
#include <map>
using std::string;
using std::map;
using std::pair;

string getName(string& line, char separator);
string getDate(string& line, char separator);
string getHoursWorked(string& line, char separator);
int separatorCount(string& line, char separator);
void modifyDate(string& date);
#endif // !TT
