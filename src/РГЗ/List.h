#pragma once
#include "Pupils.h"
class List
{
private:
	std::vector<Pupils*> list;

public:
	void addPupils();
	void removePupils(const int index);
	void setPupils(const int index);
	void clear();
	void showAll();

	int getSize();
	Pupils& getPupils(const int index);
	Pupils& getPupilsGrade(const int grade);

	void sortGrade();

	string check(regex reg);
	int chooseInt(int start, int end);

	Pupils& operator[](const int index);
	friend std::ostream& operator << (std::ostream& out, const List& obj) {
		for (int i = 0; i < obj.list.size(); i++)
			out << obj.list[i];

		return out;
	}

	void readFromFile();
	void writeToFile();
};

class ListOfJuniorStudent {
private:
	std::vector<JuniorStudent> list;

public:
	void addPupils(JuniorStudent& pupils);
	void addObjects();
	void removePupils(const int index);
	void showAll();

	int getSize();
	JuniorStudent& operator[](const int index);
	JuniorStudent& getPupils(const int index);
	JuniorStudent& getPupilsGrade(const int grade);
	string check(regex reg);
	int chooseInt(int start, int end);
	void getWasChangeSchool();

	void get6thGradeStudent();

	};

class ListOfHighSchoolStudent {
private:
	std::vector<HighSchoolStudent> list;

public:
	void addPupils(HighSchoolStudent& pupils);
	void addObjects();
	void removePupils(const int index);
	void showAll();

	int getSize();
	HighSchoolStudent& operator[](const int index);
	HighSchoolStudent& getPupils(const int index);
	HighSchoolStudent& getPupilsGrade(const int grade);
	string check(regex reg);
	int chooseInt(int start, int end);
	void getWasBoxing();
	void get6thGradeStudent();
};

