#pragma once
#include "Pupils.h"
class List
{
private:
	std::vector<Pupils> list;

public:
	void addPupils(Pupils& pupils);
	void addObjects();
	void removePupils(const int index);
	void showAll();

	int getSize();
	Pupils& getPupils(const int index);
	Pupils& getPupilsGrade(const int grade);
	string check(regex reg);

	Pupils& operator[](const int index);
	friend std::ostream& operator << (std::ostream& out, const List& obj) {
		for (int i = 0; i < obj.list.size(); i++)
			out << obj.list[i];

		return out;
	}

	void readFromFile();
	void writeToFile();
};

