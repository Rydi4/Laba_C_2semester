#include "Pupils.h"

Pupils::Pupils() :numberSchool(0), fullname("exampleName"), age(0), characteristic("exampleCharac"), grade(0), insurance(1)
{
	//cout << "\n\t\tThere was a DEFAULT constructor here\n";
}

Pupils::Pupils(const int numberSchool, const string fullname, const int age, const string characteristic, const int grade, const bool insurance) :
	numberSchool(numberSchool), fullname(fullname), age(age), characteristic(characteristic), grade(grade), insurance(insurance)
{
	//cout << "\n\t\tHere was a constructor with PARAMETRS\n";
}

Pupils::Pupils(const Pupils& obj) :numberSchool(obj.numberSchool), fullname(obj.fullname), age(obj.age),
characteristic(obj.characteristic), grade(obj.grade), insurance(obj.insurance)
{
	//cout << "\n\t\tThere was a COPY constructor here\n";
}

Pupils& Pupils::operator= (const Pupils& obj) {
	characteristic = obj.characteristic;
	grade = obj.grade;
	insurance = obj.insurance;
	age = obj.age;
	numberSchool = obj.numberSchool;
	fullname = obj.fullname;

	return *this;
}

string JuniorStudent::print() {
	std::stringstream ss;
	ss << "\nNumberSchool:" << numberSchool;
	ss << "\nFullname:" << fullname;
	ss << "\nAge:" << age;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nGrade:" << grade;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";
	ss << "\nMarkExam:" << markExam;
    ss << "\nChanged school:" << changeSchool ? "Yes" : "No";
	return ss.str();
}
string HighSchoolStudent::print() {
	std::stringstream ss;
	ss << "\nNumberSchool:" << numberSchool;
	ss << "\nFullname:" << fullname;
	ss << "\nAge:" << age;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nGrade:" << grade;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";
	ss << "\nSports activities : ";
    switch (sportsActivities)
	{
	case 1:
		ss << "Boxing";
		break;
	case 2:
		ss << "Karate";
		break;
	case 3:
		ss << "Swimming";
		break;
	}
	ss << "\nAdditional points:" << additionalPoints ? "Yes" : "No";
	
	return ss.str();
}
int JuniorStudent::whoIAm() { return 1; };
int HighSchoolStudent::whoIAm() { return 2; };

JuniorStudent::JuniorStudent(int numberSchool, string fullname, int age, string characteristic, int grade, bool insurance, int markExam, bool changeSchool) {
	 setNumberSchool(numberSchool);
	 setFullname(fullname);
	 setAge(age);
	 setCharac(characteristic);
	 setGrade(grade);
	 setInsurance(insurance);
	 setMarkExam(markExam);
	 setChangeSchool(changeSchool);
	
} 

HighSchoolStudent::HighSchoolStudent(int numberSchool, string fullname, int age, string characteristic, int grade, bool insurance, int sportsActivities, bool additionalPoints) {
	setNumberSchool(numberSchool);
	setFullname(fullname);
	setAge(age);
	setCharac(characteristic);
	setGrade(grade);
	setInsurance(insurance);
	setSportsActivities(sportsActivities);
	setAdditionalPoints(additionalPoints);
}


void Pupils::setNumberSchool(int numberSchool) { this->numberSchool = numberSchool; }
void Pupils::setFullname(string fullname) { this->fullname = fullname; }
void Pupils::setAge(int age) { this->age = age; }
void Pupils::setCharac(string charac) { this->characteristic = charac; }
void Pupils::setGrade(int grade) { this->grade = grade; }
void Pupils::setInsurance(bool insurance) { this->insurance = insurance; }

int Pupils::getNumberSchool() { return numberSchool; }
string Pupils::getFullname() { return fullname; }
int Pupils::getAge() { return age; }
string Pupils::getCharac() { return characteristic; }
int Pupils::getGrade() { return grade; }
bool Pupils::getInsurance() { return insurance; }