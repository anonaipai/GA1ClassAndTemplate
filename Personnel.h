#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <string>

class Personnel {
	int const nameLen, cityLen;
	std::string SSN, name, city, year, salary;
public:
	static const int size = 999;//todo fix this shit
	Personnel();
	Personnel(std::string s, std::string n, std::string c, std::string y, std::string sal);
	std::string getSSN();
	std::string getname();
	std::string getcity();
	std::string getyear();
	std::string getsalary();

	void setcity(std::string c);
	void setSSN(std::string s);
	void setname(std::string n);
	void setyear(std::string y);
	void setsalary(std::string sal);
	void writeToFile(std::ofstream& out);
	void readFromFile(std::string filename);
	bool operator ==(Personnel otherperson);
	static Personnel datafromstring(std::string data);
	static Personnel inputToFile();
};

#endif // !PERSONNEL_H

