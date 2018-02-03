#include <iostream>
#include <stdio.h>
#include "Personnel.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
class database {
private:
	ifstream datain;
	ofstream dataout;
public:
	database(string fname) {
		ifstream datain(fname.c_str());
		ofstream dataout(fname.c_str());
	}
	//add a new record
	void add(T data) {
		Personnel d = (Personnel) data;
		data.writeToFile(dataout);
	}
	void modify(int index, T data) //change a index
			{
		int i = T::size;
		dataout.seekp(index * i);
		data.writeToFile(dataout);
	}
	void print() //print the datastructure
	{
		datain.seekg(0);
		while (!datain.eof()) {
			string s;
			getline(datain, s);
			cout << s;
		}
	}

	int find(T data) {
		//sets cursor to beginning of the file
		datain.seekg(0);

		string s;
		int index = 0;

		Personnel p;
		while (!(p == data)) {
			//read a line
			getline(datain, s);
			T::datafromstring(s);
			//implement such code in student as well

			if (p == data) {
				return index;
			}
			index++;
		}
		return -1;
	}
	T operator [](int index) {
		datain.seekg(0);
		string s;
		for (int i = 0; i < index; i++) {
			getline(datain, s);
			if (datain.eof()) {
				return nullptr;
			}
		}
		getline(datain, s);
		return T::datafromstring(s);
	}
};


void choices(char a, database<Personnel> file) {

	switch (a) {
	case '1':
		file.add(Personnel::inputToFile());
		break;

	case '2':
		file.find(Personnel::inputToFile());
		break;

	case '3':
		cout << "Enter the index you want to modify";
		int i;
		cin >> i;
		file.modify(i, Personnel::inputToFile());
		break;

	case '4':
		file.print();
		exit(1);
	}

}

int main() {
	char choice = 0;
	cout << "Enter file name" << endl;
	string filename;
	cin >> filename;
	database<Personnel> personnelfile(filename);
	database<Student> studentfile(filename);

	while (choice != 4) {
		cout << "Enter option: 1 - add, 2 - find, 3 - modify, 4 - exit" << endl;
		cin >> choice;
		choices(choice, filename);
	}


	return 0;
}
/*
 type Personnel - SSN, name, city, year of birth, salary
 Student extends - also includes major
 find() function override == operator
 modify() contains the find function and prompts change of data



 I - Write a class Personal
 make sure you have the private data members name ..etc.…. and 2 important member functions
 writetofile and readfromfile
 name of the file will be passed as parameter to both functions

 II - Write a class student which inherits from Personal, additional attribute Major and override the above 2 functions …

 III - Write a class database as a template with a very important attribute file and functions :add, find, modify and print(can be

 overloaded << )

 IV - In main declare a variable of type database such as
 database <student> studentfile;

 V - Display a menu program
 1 - Add                             …studentfile.add(…
 2 - Find
 3 - modify
 4 - exit
 enter your choice
 */
