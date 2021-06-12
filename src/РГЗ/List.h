#pragma once
#include "Student.h"
class List
{
private:
	std::vector<Student*> list;

public:
	void addStudent();
	void removeStudent(const int index);
	void setStudent(const int index);
	void clear();
	void showAll();
	

	int getSize();
	Student& getStudent(const int index);
	Student& getStudentYearOfEntry(const int grade);

	void sortYearOfEntry();

	string check(regex reg);
	int chooseInt(int start, int end);

	Student& operator[](const int index);
	friend std::ostream& operator << (std::ostream& out, const List& obj) {
		for (int i = 0; i < obj.list.size(); i++)
			out << obj.list[i];

		return out;
	}

	void readFromFile();
	void writeToFile();
};

class ListofGraduateStudent {
private:
	std::vector<GraduateStudent> list;

public:
	void addStudent(GraduateStudent& student);
	void addObjects();
	void removeStudent(const int index);
	void showAll();

	int getSize();
	GraduateStudent& operator[](const int index);
	GraduateStudent& getStudent(const int index);
	GraduateStudent& getStudentBudget(const int grade);
	string check(regex reg);
	int chooseInt(int start, int end);
		void get2018YearOfEntry();
        void getWasAtAnotherUniversity();
	

	};

class ListofBachelorStudent {
private:
	std::vector<BachelorStudent> list;

public:
	void addStudent(BachelorStudent& pupils);
	void addObjects();
	void removeStudent(const int index);
	void showAll();

	int getSize();
	BachelorStudent& operator[](const int index);
	BachelorStudent& getStudent(const int index);
	BachelorStudent& getStudentBudget(const int grade);
	string check(regex reg);
	int chooseInt(int start, int end);
	void get2018YearOfEntry();
	void getWasCollege();
};

