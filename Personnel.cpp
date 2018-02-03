#include "Personnel.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Personnel::Personnel() :
		nameLen(10), cityLen(10) {
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
	SSN = "";
	name = "";
	city = "";
	year = "";
	salary = "";
}
Personnel::Personnel(string s, string n, string c, string y, string sal) :
		nameLen(10), cityLen(10) {
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
	SSN = s;
	name = n;
	city = c;
	year = y;
	salary = sal;
}

string Personnel::getSSN() {
	return SSN;
}
string Personnel::getcity() {
	return city;
}
string Personnel::getname() {
	return name;
}
string Personnel::getyear() {
	return year;
}
string Personnel::getsalary() {
	return salary;
}
void Personnel::setSSN(string s) {
	SSN = s;
}
void Personnel::setcity(string c) {
	city = c;
}
void Personnel::setname(string n) {
	name = n;
}
void Personnel::setyear(string y) {
	year = y;
}
void Personnel::setsalary(string sal) {
	salary = sal;
}
void Personnel::writeToFile(ofstream& out) {
	out << SSN << "," << name << "," << city << "," << year << "," << salary;
}
void Personnel::readFromFile(string filename) {
	ifstream f(filename);
	while (!f.eof()) {
		string s;
		getline(f, s, ',');
	}
}
bool Personnel::operator ==(Personnel otherperson) {
	if (SSN == otherperson.getSSN() && city == otherperson.getcity()
			&& year == otherperson.getyear() && name == otherperson.getname()
			&& salary == otherperson.getsalary()) {
		return true;
	} else
		return false;
}
Personnel Personnel::datafromstring(string data) {
	stringstream temp(data);
	string n, c, s, b, sal;
	getline(temp, s, ',');
	getline(temp, n, ',');
	getline(temp, c, ',');
	getline(temp, b, ',');
	getline(temp, sal, ',');
	Personnel p(s, n, c, b, sal);
	return p;
}
Personnel Personnel::inputToFile() {

	string n, c, s, b, sal;
	cout << "SSN: ";
	cin >> s;
	cout << "Name: ";
	cin >> n;
	cout << "City: ";
	cin >> c;
	cout << "Year of Birth: ";
	cin >> b;
	cout << "Salary";
	cin >> sal;
	Personnel p(s, n, c, b, sal);
	return p;
}
