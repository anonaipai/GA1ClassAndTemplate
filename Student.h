#ifndef STUDENT_H
#define STUDENT_H
#include "Personnel.h"
using namespace std;

class Student: public Personnel {
	int sizeofmajor;
	string major;
public:
	Student();
	string getmajor() { return major; } // get major
	int getsizeofmajor() { return sizeofmajor; } // get sizeofmajor
	void writeToFile(std::fstream& out);
	void readFromFile(std::string filename);
	bool operator==(Student &an) { if (sizeofmajor == an.sizeofmajor && major == an.major && getSSN() == an.getSSN()) { return true; } else { return false; } }
	int size();
	const string& getMajor() const;
	void setMajor(const std::string& major,int sizeofmajor);
};

#endif

