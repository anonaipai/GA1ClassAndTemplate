#include "Student.h"
#include "Personnel.h"
using namespace std;

Student::Student()
{

}
void Student::writeToFile(fstream& out)
{

}
void Student::readFromFile(string filename)
{

}
bool operator==(Student &b1, Student &b2)
{
	if (b1.getsizeofmajor() == b2.getsizeofmajor() && b1.getmajor() == b2.getmajor() && b1.getSSN() == b2.getSSN()) { return true; } else { return false; }
}
int Student::size(){
	return sizeofmajor + Personnel::size;
}

const string& Student::getMajor() const {
	return major;
}

void Student::setMajor(const string& major, int size) {
	sizeofmajor = size;
	this->major = major;
}
