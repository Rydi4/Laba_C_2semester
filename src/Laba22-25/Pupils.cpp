#include "Pupils.h"

Pupils::Pupils() :numberSchool(0), fullname("exampleName"), age(0), characteristic("exampleCharac"), grade(0), insurance(1)
{
	cout << "\n\t\tThere was a DEFAULT constructor here\n";
}

Pupils::Pupils(const int numberSchool, const string fullname, const int age, const string characteristic, const int grade, const bool insurance) :
	numberSchool(numberSchool), fullname(fullname), age(age), characteristic(characteristic), grade(grade), insurance(insurance)
{
	cout << "\n\t\tHere was a constructor with PARAMETRS\n";
}

Pupils::Pupils(const Pupils& obj) :numberSchool(obj.numberSchool), fullname(obj.fullname), age(obj.age),
characteristic(obj.characteristic), grade(obj.grade), insurance(obj.insurance)
{
	cout << "\n\t\tThere was a COPY constructor here\n";
}

Pupils::~Pupils() {
	cout << "\n\t\tThere was DESTRUCTOR here\n";
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

string Pupils::printPupils() {
	std::stringstream ss;
	ss << "\nNumberSchool:" << numberSchool;
	ss << "\nFullname:" << fullname;
	ss << "\nAge:" << age;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nGrade:" << grade;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";

	return ss.str();
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