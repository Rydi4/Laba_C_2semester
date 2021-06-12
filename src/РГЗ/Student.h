#pragma once
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>  

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::regex;


#define filename "D:\\text.txt"
static regex regName("([A-Z]{1}[a-z]{1,}[_]{1}[A-Z]{1}\.[A-Z]{1}\.)");
static regex regGroup("([A-Z]{1,4}[-]{1}[0-9]{3}[a-z]{1})");


class Student
{
public:
	bool budget;
	string nameStudent;
	string nameCurator;
	string group;
	int yearOfEntry;
    int departmentBuilding;
	


	Student();
	Student(const bool budget, const string nameStudent, const string nameCurator, const string group, const int yearOfEntry, const int departmentBuilding);
	Student(const Student& obj);
	virtual ~Student() = 0 {};

	virtual string print() = 0;
	virtual int whoIAm() = 0;

	Student& operator=(const Student& obj); 
	friend bool operator==(const Student& obj1, const Student& obj2) {
		return (obj1.yearOfEntry == obj2.yearOfEntry);
	}
	friend bool operator>(const Student& obj1, const Student& obj2) {
		return (obj1.yearOfEntry > obj2.yearOfEntry);
	}
	friend bool operator<(const Student& obj1, const Student& obj2) {
		return (obj1.yearOfEntry < obj2.yearOfEntry);
	}
	friend bool operator!=(const Student& obj1, const Student& obj2) {
		return !(obj1 == obj2);
	}
	friend std::ostream& operator<< (std::ostream& out, const Student& obj) {
		out << "\nBudget:" << obj.budget ? "Yes" : "No";
		out << "\nName Student:" << obj.nameStudent;
		out << "\nName Curator:" << obj.nameCurator;
		out << "\nGroup:" << obj.group;
		out << "\nYear:" << obj.yearOfEntry;
		out << "\nDepartment Building:";
		switch (obj.departmentBuilding)
		{
		case 1:
			out << "VC";
			break;
		case 2:
			out << "GAK";
			break;
		case 3:
			out << "Y1";
			break;
		case 4:
			out << "Y2";
			break;
		}
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Student& obj) {
		in >> obj.budget;
		in >> obj.nameStudent;
		in >> obj.nameCurator;
		in >> obj.group;
		in >> obj.yearOfEntry;
		in >> obj.departmentBuilding;

		return in;
	}

	void setBudget(bool budget);
	void setNameStudent(string nameStudent);
	void setNameCurator(string nameCurator);
	void setGroup(string group);
	void setYearOfEntry(int yearOfEntry);
	void setDepartmentBuilding(int departmentBuilding);

	bool getBudget();
	string getNameStudent();
	string getNameCurator();
	string getGroup();
	int getYearOfEntry();
	int getDepartmentBuilding();
};

class GraduateStudent : public Student {
private:
	bool changeUniversity;
	int markEvi;
	
public:
	GraduateStudent() :markEvi(0), changeUniversity(false) {};
	GraduateStudent(bool budget, string nameStudent, string nameCurator, string group, int yearOfEntry, int departmentBuilding, bool changeUniversity, int markEvi);
	~GraduateStudent() {}

	friend std::ostream& operator<< (std::ostream& out, const GraduateStudent& obj) {

		out << "\nBudget:" << obj.budget ? "Yes" : "No";
		out << "\nName Student:" << obj.nameStudent;
		out << "\nName Curator:" << obj.nameCurator;
		out << "\nGroup:" << obj.group;
		out << "\nYear:" << obj.yearOfEntry;
		out << "\nDepartment Building:";
		switch (obj.departmentBuilding)
		{
		case 1:
			out << "VC";
			break;
		case 2:
			out << "GAK";
			break;
		case 3:
			out << "Y1";
			break;
		case 4:
			out << "Y2";
			break;
		}
		out << "\nChanged university:" << obj.changeUniversity ? "Yes" : "No";
		out << "\nMark Evi:" << obj.markEvi;
		

		return out;
	}

	friend std::istream& operator>> (std::istream& in, GraduateStudent& obj) {
		in >> obj.budget >> obj.nameStudent >> obj.nameCurator >> obj.group >> obj.yearOfEntry >> obj.departmentBuilding >> obj.changeUniversity >> obj.markEvi;
		return in;	 
	}
	friend bool operator==(const GraduateStudent& obj1, const GraduateStudent& obj2) { 
		return (obj1.changeUniversity == obj2.changeUniversity);
	}

	virtual string print()override final;
	virtual int whoIAm()override final;

	int getChangeUniversity() { return changeUniversity; }
    int getMarkEvi() { return markEvi; }

	void setChangeUniversity(int s) { changeUniversity = s; }
	void setMarkEvi(int l) { markEvi = l; }
};

class BachelorStudent : public Student {
private:
	bool additionalPoints;
	int previousEducationalInstitution;
	 
public:
	BachelorStudent() : additionalPoints(false), previousEducationalInstitution(0) {};
	BachelorStudent(bool budget, string nameStudent, string nameCurator, string group, int yearOfEntry, int departmentBuilding, bool additionalPoints, int previousEducationalInstitution);
	~BachelorStudent() {};

	friend std::ostream& operator<< (std::ostream& out, const BachelorStudent& obj) {

		out << "\nBudget:" << obj.budget ? "Yes" : "No";
		out << "\nName Student:" << obj.nameStudent;
		out << "\nName Curator:" << obj.nameCurator;
		out << "\nGroup:" << obj.group;
		out << "\nYear:" << obj.yearOfEntry;
		out << "\nDepartment Building:";
		switch (obj.departmentBuilding)
		{
		case 1:
			out << "VC";
			break;
		case 2:
			out << "GAK";
			break;
		case 3:
			out << "Y1";
			break;
		case 4:
			out << "Y2";
			break;
		}
		out << "\nAdditional points:" << (obj.additionalPoints ? "Yes" : "No");
		out << "\nPrevious Educational Institution : ";
		switch (obj.previousEducationalInstitution)
		{
		case 1:
			out << "School";
			break;
		case 2:
			out << "Technical school";
			break;
		case 3:
			out << "College";
			break;
		}
	

	 return out;
	}

	friend std::istream& operator>> (std::istream& in, BachelorStudent& obj) {
		in >> obj.budget >> obj.nameStudent >> obj.nameCurator >> obj.group >> obj.yearOfEntry >> obj.departmentBuilding >>obj.additionalPoints >> obj.previousEducationalInstitution;
		return in;
	}
	friend bool operator==(const BachelorStudent& obj1, const BachelorStudent& obj2) {
		return (obj1.previousEducationalInstitution == obj2.previousEducationalInstitution);
	}
	virtual string print()override final;
	virtual int whoIAm()override final;

	bool getAdditionalPoints() { return additionalPoints; }
	int getPreviousEducationalInstitution() { return previousEducationalInstitution; }

	void setAdditionalPoints(bool s) { additionalPoints = s; }
	void setPreviousEducationalInstitution(int l) { previousEducationalInstitution = l; }
};