#include "List.h"

void ListofGraduateStudent::addStudent(GraduateStudent& student) {
	list.push_back(student);
}
void ListofGraduateStudent::removeStudent(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListofGraduateStudent::showAll() {
	for (GraduateStudent& emp : list) 		
		cout << emp.print() << endl;
}
GraduateStudent& ListofGraduateStudent::getStudent(const int index) { return list[index]; }
GraduateStudent& ListofGraduateStudent::getStudentBudget(const int yearOfEntry) {
	for (GraduateStudent& emp : list) {
		if (emp.getYearOfEntry() == yearOfEntry)
			return emp;
	}
}


int ListofGraduateStudent::getSize() { return list.size(); }

GraduateStudent& ListofGraduateStudent::operator[](const int index) {
	return list[index];
}

void ListofGraduateStudent::addObjects() {
	bool choice = true;
	GraduateStudent tmp;
	int digit;

	while (choice) {
		getchar;
		cout << "\n\nCreate a new Student now.\n	Enter does the student have a budget ? \n1.Yes\n0.No\n\nYour choose : ";

		tmp.setBudget(chooseInt(0, 1));
		cout << "	Enter name student : ";
		tmp.setNameStudent(check(regName));
		cout << "	Enter name curator : ";
		tmp.setNameCurator(check(regName));
		cout << "	Enter group :";
		tmp.setGroup(check(regGroup));
		cout << "	Enter year of entry : ";
		tmp.setYearOfEntry(chooseInt(2000, 2020));
		cout << "	Enter department building \n1.VC\n2.GAK\n3.Y1\n4.Y2\nYour choose : ";
		tmp.setDepartmentBuilding(chooseInt(1, 4));
		cout << "	Have you changed university? \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setChangeUniversity(chooseInt(0, 1));
		cout << "	Enter Evi score :";
		tmp.setMarkEvi(chooseInt(1, 200));

		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}

string ListofGraduateStudent::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}

int ListofGraduateStudent::chooseInt(int start, int end) {
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