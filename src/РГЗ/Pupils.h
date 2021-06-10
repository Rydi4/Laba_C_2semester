#pragma once
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector		>
#include <sstream>
#include <algorithm>  

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::regex;


#define filename "D:\\text.txt"
static regex regName("^([A-Z]{1}[a-z]{1,}[ -,]{0,1}){1,3}");

class Pupils
{
public:
	int numberSchool;
	string fullname;
	int age;
	string characteristic;
	int grade;
	bool insurance; 


	Pupils();
	Pupils(const int numberSchool, const string fullname, const int age, const string characteristic, const int grade, const bool insurance);
	Pupils(const Pupils& obj);
	virtual ~Pupils() = 0 {};

	virtual string print() = 0;
	virtual int whoIAm() = 0;

	Pupils& operator=(const Pupils& obj); 
	friend bool operator==(const Pupils& obj1, const Pupils& obj2) {
		return (obj1.grade == obj2.grade);
	}
	friend bool operator>(const Pupils& obj1, const Pupils& obj2) {
		return (obj1.grade > obj2.grade);
	}
	friend bool operator<(const Pupils& obj1, const Pupils& obj2) {
		return (obj1.grade < obj2.grade);
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

class JuniorStudent : public Pupils {
private:
	int markExam;
	bool changeSchool;
public:
	JuniorStudent() :markExam(0), changeSchool(false) {};
	JuniorStudent(int numberSchool, string fullname, int age, string characteristic, int grade, bool insurance, int markExam, bool changeSchool);
	~JuniorStudent() {}

	friend std::ostream& operator<< (std::ostream& out, const JuniorStudent& obj) {

		out << "\nNumberSchool:" << obj.numberSchool;
		out << "\nFullname:" << obj.fullname;
		out << "\nAge:" << obj.age;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nGrade:" << obj.grade;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		out << "\nMarkExam:" << obj.markExam;
		out << "\nChanged school:" << obj.changeSchool ? "Yes" : "No";

		return out;
	}

	friend std::istream& operator>> (std::istream& in, JuniorStudent& obj) {
		in >> obj.numberSchool >> obj.fullname >> obj.age >> obj.characteristic
			>> obj.grade >> obj.insurance >> obj.markExam >> obj.changeSchool;
		return in;	 
	}
	friend bool operator==(const JuniorStudent& obj1, const JuniorStudent& obj2) { 
		return (obj1.changeSchool == obj2.changeSchool);
	}

	virtual string print()override final;
	virtual int whoIAm()override final;

	int getMarkExam() { return markExam; }
	int getChangeSchool() { return changeSchool; }

	void setMarkExam(int l) { markExam = l; }
	void setChangeSchool(int s) { changeSchool = s; }
};

class HighSchoolStudent : public Pupils {
private:
	int sportsActivities;
	bool additionalPoints;
public:
	HighSchoolStudent() :sportsActivities(0), additionalPoints(false) {};
	HighSchoolStudent(int numberSchool, string fullname, int age, string characteristic, int grade, bool insurance, int sportsActivities, bool additionalPoints);
	~HighSchoolStudent() {};

	friend std::ostream& operator<< (std::ostream& out, const HighSchoolStudent& obj) {

		out << "\nNumberSchool:" << obj.numberSchool;
		out << "\nFullname:" << obj.fullname;
		out << "\nAge:" << obj.age;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nGrade:" << obj.grade;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		out << "\nSports activities : ";
		switch (obj.sportsActivities)
		{
		case 1:
			out << "Boxing";
			break;
		case 2:
			out << "Karate";
			break;
		case 3:
			out << "Swimming";
			break;
		}
	 out << "\nAdditional points:" << (obj.additionalPoints ? "Yes" : "No");

	 return out;
	}

	friend std::istream& operator>> (std::istream& in, HighSchoolStudent& obj) {
		in >> obj.numberSchool >> obj.fullname >> obj.age >> obj.characteristic
			>> obj.grade >> obj.insurance >> obj.sportsActivities >> obj.additionalPoints;
		return in;
	}
	friend bool operator==(const HighSchoolStudent& obj1, const HighSchoolStudent& obj2) {  
		return (obj1.sportsActivities == obj2.sportsActivities);
	}
	virtual string print()override final;
	virtual int whoIAm()override final;

	int getSportsActivities() { return sportsActivities; }
	bool getAdditionalPoints() { return additionalPoints; }

	void setSportsActivities(int l) { sportsActivities = l; }
	void setAdditionalPoints(bool s) { additionalPoints = s; }
};