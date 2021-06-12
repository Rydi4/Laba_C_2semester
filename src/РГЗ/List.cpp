#include "List.h"

void List::addStudent() {
	cout << "Do you want to create a Graduate Student or Bachelor Student? \n1.Graduate Student\n2.Bachelor Student\nYour choose:";
	int choose = chooseInt(1, 2);
	Student* p = NULL;
	int digit;
	getchar;

	if (choose == 1) {
		GraduateStudent tmp;
		cout << "\n\nCreate a new Student now.\n	Enter does the student have a budget ? \n1.Yes\n0.No\n\nYour choose : "; 

		tmp.setBudget(chooseInt(0, 1));
		cout << "	Enter name student : ";
		tmp.setNameStudent(check(regName));
		cout << "	Enter name curator : ";
		tmp.setNameCurator(check(regName));
		cout << "	Enter group :";
		tmp.setGroup(check(regGroup));
		cout << "	Enter year of entry: ";
		tmp.setYearOfEntry(chooseInt(2000, 2020));
		cout << "	Enter department building \n1.VC\n2.GAK\n3.Y1\n4.Y2\nYour choose : ";
		tmp.setDepartmentBuilding(chooseInt(1, 4));
		cout << "	Have you changed university? \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setChangeUniversity(chooseInt(0, 1));
		cout << "	Enter Evi score :";
		tmp.setMarkEvi(chooseInt(1, 200));
		p = &tmp;

	}
	else if (choose == 2) {
		BachelorStudent tmp;
		cout << "\n\nCreate a new Student now.\n	Enter does the student have a budget ? \n1.Yes\n0.No\n\nYour choose : ";

		tmp.setBudget(chooseInt(0, 1));
		cout << "	Enter name student : ";
		tmp.setNameStudent(check(regName));
		cout << "	Enter name curator : ";
		tmp.setNameCurator(check(regName));
		cout << "	Enter group :";
		tmp.setGroup(check(regGroup));
		cout << "	Enter year of entry: ";
		tmp.setYearOfEntry(chooseInt(2000, 2020));
		cout << "	Enter department building \n1.VC\n2.GAK\n3.Y1\n4.Y2\nYour choose : ";
		tmp.setDepartmentBuilding(chooseInt(1, 4));
		cout << "	Do you have additional points? \n1.Yes\n0.No\nYour choose :";
		tmp.setAdditionalPoints(chooseInt(0, 1));
		cout << "	Sports activities\n1.School\n2.Technical school\n3.College\n\nYour choose :";
		tmp.setPreviousEducationalInstitution(chooseInt(1, 3));
		
		p = &tmp;
	}
	list.push_back	(p);
}
void ListofGraduateStudent::get2018YearOfEntry() {
	for (GraduateStudent& emp : list) {
		if (emp.getYearOfEntry() == 2018)
			cout << emp.print() << endl;
	}
}
void ListofBachelorStudent::get2018YearOfEntry() {
	for (BachelorStudent& emp : list) {
		if (emp.getYearOfEntry() == 2018)
			cout << emp.print() << endl;
	}
}
void ListofBachelorStudent::getWasCollege() {
	for (BachelorStudent& emp : list) {
		if (emp.getPreviousEducationalInstitution() == 3)
			cout << emp.print() << endl;
	}
}

void ListofGraduateStudent::getWasAtAnotherUniversity() {
	for (GraduateStudent& emp : list) {
		if (emp.getChangeUniversity() == 1)
			cout << emp.print() << endl;
	}
}
void List::removeStudent(const int index) {
	if (!list.empty())
		delete* (list.begin() + index);
		list.erase(list.begin() + index);
}
void List::showAll() {
	for (int i = 0; i < list.size(); i++) {

		cout << list[i]->print() << endl;
	}
}
void List::setStudent(const int index) {
	int choice = 0, type = 0;
	type = list[index]->whoIAm();

	cout << "Your Student:\n\n";
	cout << list[index]->print() << endl;
	cout << "\nWhat do u want to change?\n1.Budget\n2.NameStudent\n3.NameCurator\n4.Group\n5.Year\n6.DepartmentBuilding\n";

	cout << "Your choise(1-6): ";
	choice = chooseInt(1, 6);

	switch (choice)
	{
	case 1:
		list[index]->setBudget(chooseInt(0, 1));
		break;
	case 2:
		list[index]->setNameStudent(check(regName));
		break;
	case 3:
		list[index]->setNameCurator(check(regName));
		break;
	case 4:
		list[index]->setGroup(check(regGroup));
		break;
	case 5:
		list[index]->setYearOfEntry(chooseInt(2000, 2020));
		break;
	case 6:
		list[index]->setDepartmentBuilding(!list[index]->getDepartmentBuilding());
		break;
		
	}
}
void List::clear() {
	if (!list.empty()) {
		for (int i = list.size(); i > 0; i--) {
			removeStudent(i - 1);
		}
	}
}
Student& List::getStudent(const int index) {
	return *(list[index]);
}
Student& List::getStudentYearOfEntry(const int yearOfEntry) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getYearOfEntry() == yearOfEntry)
			return *(list[i]);
	}
}
void List::sortYearOfEntry() {
	cout << "\nSelect sorting type: \n1. Ascending \n2. Descending \n	Your choose:";
	int type = chooseInt(1, 2);

	if (type == 1) {
		std::sort(list.begin(), list.end());
	}
	else {
		std::sort(list.begin(), list.end());
		std::reverse(list.begin(), list.end());
	}
}
int List::getSize() { 
	return list.size();
}
Student& List::operator[](const int index) {
	return *list[index];
}

string List::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}
int List::chooseInt(const int start, const int end) {
	int digit = 0;
	do {
		cin >> digit;
		if (digit >= start && digit <= end) {
			return digit;
		}
		else
			cout << "\nTry again : ";
	} while (true);
}
void List::readFromFile() {
	bool budget;
	string nameStudent;
	string nameCurator;
	string group;
	int yearOfEntry;
	int departmentBuilding;
	bool changeUniversity;
	int markEvi;
	bool additionalPoints;
	int previousEducationalInstitution;

	std::ifstream in(filename);
	if (in.is_open())
	{
		int size = 0;
		int type = 0;
		list.clear();

		in >> size;
		list.reserve(size);
		for (int i = 0; i < size; i++) {
			Student* p = NULL;
			in >> type;
			if (type == 1) {
				in >> budget >> nameStudent >> nameCurator >> group >> yearOfEntry >> departmentBuilding >> changeUniversity >> markEvi;
				GraduateStudent* tmp = new GraduateStudent(budget, nameStudent, nameCurator, group, yearOfEntry, departmentBuilding, changeUniversity, markEvi);
				p = *(&tmp);
				list.push_back(p);
			}
			else if (type == 2) {
				in >> budget >> nameStudent >> nameCurator >> group >> yearOfEntry >> departmentBuilding >> additionalPoints >> previousEducationalInstitution;
				BachelorStudent* tmp = new BachelorStudent(budget, nameStudent, nameCurator, group, yearOfEntry, departmentBuilding, additionalPoints, previousEducationalInstitution);
				p = *(&tmp);	
				list.push_back(p);
			}

		}
		in.close();
	}	
}
void List::writeToFile() {
	std::ofstream out(filename);
	if (out.is_open()) {
		out << list.size() << endl;
		for (int i = 0; i < list.size(); i++)
			out << list[i]->whoIAm() << " " << list[i]->getBudget() << " " << list[i]->getNameStudent() << " " << list[i]->getNameCurator() << " " << list[i]->getGroup() << " " << list[i]->getYearOfEntry() << " " << list[i]->getDepartmentBuilding() << endl;
	}
	out.close();
}
