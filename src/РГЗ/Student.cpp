#include "Student.h"

Student::Student() :budget(1), nameStudent("exampleName"), nameCurator("exampleName"), group("exampleGroup"), yearOfEntry(0), departmentBuilding(0)
{
	//cout << "\n\t\tThere was a DEFAULT constructor here\n";
}

Student::Student(const bool budget, const string nameStudent, const string nameCurator, const string group, const int yearOfEntry, const int departmentBuilding) :
	budget(budget), nameStudent(nameStudent), nameCurator(nameCurator), group(group), yearOfEntry(yearOfEntry), departmentBuilding(departmentBuilding)
{
	//cout << "\n\t\tHere was a constructor with PARAMETRS\n";
}

Student::Student(const Student& obj) :budget(obj.budget), nameStudent(obj.nameStudent), nameCurator(obj.nameCurator), group(obj.group), yearOfEntry(obj.yearOfEntry), departmentBuilding(obj.departmentBuilding)
{
	//cout << "\n\t\tThere was a COPY constructor here\n";
}

Student& Student::operator= (const Student& obj) {
	budget = obj.budget;
	nameStudent = obj.nameStudent;
	nameCurator = obj.nameCurator;
	group = obj.group;
	yearOfEntry = obj.yearOfEntry;
	departmentBuilding = obj.departmentBuilding;

	return *this;
}

string GraduateStudent::print() {
	std::stringstream ss;
	ss << "\nBudget:" << budget ? "Yes" : "No";
	ss << "\nName Student:" << nameStudent;
	ss << "\nName Curator:" << nameCurator;
	ss << "\nGroup:" << group;
	ss << "\nYear:" << yearOfEntry;
	ss << "\nDepartment Building:";
	switch (departmentBuilding)
	{
	case 1:
		ss << "VC";
		break;
	case 2:
	    ss << "GAK";
		break;
	case 3:
		ss << "Y1";
		break;
	case 4:
		ss << "Y2";
		break;
	}
	ss << "\nChanged university:" << changeUniversity ? "Yes" : "No";
	ss << "\nMark Evi:" << markEvi;
	return ss.str();
}
string BachelorStudent::print() {
	std::stringstream ss;
	ss << "\nBudget:" << budget ? "Yes" : "No";
	ss << "\nName Student:" << nameStudent;
	ss << "\nName Curator:" << nameCurator;
	ss << "\nGroup:" << group;
	ss << "\nYear:" << yearOfEntry;
	ss << "\nDepartment Building:";
	switch (departmentBuilding)
	{
	case 1:
		ss << "VC";
		break;
	case 2:
		ss << "GAK";
		break;
	case 3:
		ss << "Y1";
		break;
	case 4:
		ss << "Y2";
		break;
	}
	ss << "\nAdditional points:" << (additionalPoints ? "Yes" : "No");
	ss << "\nPrevious Educational Institution : ";
	switch (previousEducationalInstitution)
	{
	case 1:
		ss << "School";
		break;
	case 2:
		ss << "Technical school";
		break;
	case 3:
		ss << "College";
		break;
	}
	
	return ss.str();
}
int GraduateStudent::whoIAm() { return 1; };
int BachelorStudent::whoIAm() { return 2; };

GraduateStudent::GraduateStudent(bool budget, string nameStudent, string nameCurator, string group, int yearOfEntry, int departmentBuilding, bool changeUniversity, int markEvi) {
	 setBudget(budget);
	 setNameStudent(nameStudent);
	 setNameCurator(nameCurator);
	 setGroup(group);
	 setYearOfEntry(yearOfEntry);
     setDepartmentBuilding(departmentBuilding);
	 setChangeUniversity(changeUniversity);
	 setMarkEvi(markEvi);
	
} 

BachelorStudent::BachelorStudent(bool budget, string nameStudent, string nameCurator, string group, int yearOfEntry, int departmentBuilding, bool additionalPoints, int previousEducationalInstitution) {
	setBudget(budget);
	setNameStudent(nameStudent);
	setNameCurator(nameCurator);
	setGroup(group);
	setYearOfEntry(yearOfEntry);
	setDepartmentBuilding(departmentBuilding);
	setAdditionalPoints(additionalPoints);
	setPreviousEducationalInstitution(previousEducationalInstitution);
}


void Student::setBudget(bool budget) { this->budget = budget; }
void Student::setNameStudent(string nameStudent) { this->nameStudent = nameStudent; }
void Student::setNameCurator(string nameCurator) { this->nameCurator = nameCurator; }
void Student::setGroup(string group) { this->group = group; }
void Student::setYearOfEntry(int yearOfEntry) { this->yearOfEntry = yearOfEntry; }
void Student::setDepartmentBuilding(int departmentBuilding) { this->departmentBuilding = departmentBuilding; }

bool Student::getBudget() { return budget; }
string Student::getNameStudent() { return nameStudent; }
string Student::getNameCurator() { return nameCurator; }
string Student::getGroup() { return group; }
int Student::getYearOfEntry() { return yearOfEntry; }
int Student::getDepartmentBuilding() { return departmentBuilding; }