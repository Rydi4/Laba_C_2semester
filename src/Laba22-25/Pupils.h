#pragma once
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::regex;


#define filename "D:\\text.txt"
static regex regName("^([A-Z]{1}[a-z]{1,}[ -,]{0,1}){1,3}");

class Pupils
{
private:
	int numberSchool;
	string fullname;
	int age;
	string characteristic;
	int grade;
	bool insurance;
public:
	Pupils();
	Pupils(const int numberSchool, const string fullname, const int age, const string characteristic, const int grade, const bool insurance);
	Pupils(const Pupils& obj);
	~Pupils();

	Pupils& operator=(const Pupils& obj); 
	friend bool operator==(const Pupils& obj1, const Pupils& obj2) {
		return (obj1.grade == obj2.grade);
	}
	friend bool operator!=(const Pupils& obj1, const Pupils& obj2) {
		return !(obj1 == obj2);
	}
	friend std::ostream& operator<< (std::ostream& out, const Pupils& obj) {
		out << "\nNumberSchool:" << obj.numberSchool;
		out << "\nFullname:" << obj.fullname;
		out << "\nAge:" << obj.age;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nGrade" << obj.grade;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Pupils& obj) {
		in >> obj.numberSchool;
		in >> obj.fullname;
		in >> obj.age;
		in >> obj.characteristic;
		in >> obj.grade;
		in >> obj.insurance;

		return in;
	}

	string printPupils();

	void setNumberSchool(int numberSchool);
	void setFullname(string fullName);
	void setAge(int age);
	void setCharac(string charac);
	void setGrade(int grade);
	void setInsurance(bool insurance);

	int getNumberSchool();
	string getFullname();
	int getAge();
	string getCharac();
	int getGrade();
	bool getInsurance();
};

