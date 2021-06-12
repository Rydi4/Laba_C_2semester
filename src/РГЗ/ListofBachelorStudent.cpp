#include "List.h"

void ListofBachelorStudent::addStudent(BachelorStudent& student) {
	list.push_back(student);
}
void ListofBachelorStudent::removeStudent(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListofBachelorStudent::showAll() {
	for (BachelorStudent& emp : list)
		cout << emp.print() << endl;
}
BachelorStudent& ListofBachelorStudent::getStudent(const int index) { return list[index]; }
BachelorStudent& ListofBachelorStudent::getStudentBudget(const int yearOfEntry) {
	for (BachelorStudent& emp : list) {
		if (emp.getYearOfEntry() == yearOfEntry)
			return emp;
	}
}


int ListofBachelorStudent::getSize() { return list.size(); }
BachelorStudent& ListofBachelorStudent::operator[](const int index) {
	return list[index];
}
void ListofBachelorStudent::addObjects() {
	bool choice = true;
	BachelorStudent tmp;
	int digit;

	while (choice) {
		getchar;
		cout << "\n\nCreate a new Student now.\n	Enter does the student have a budget ? \n1.Yes\n0.No\n\nYour choose : ";

		tmp.setBudget(chooseInt(0, 1));
		cout << "	Enter name student :";
		tmp.setNameStudent(check(regName));
		cout << "	Enter name curator : ";
		tmp.setNameCurator(check(regName));
		cout << "	Enter group :";
		tmp.setGroup(check(regGroup));
		cout << "	Enter year of entry : ";
		tmp.setYearOfEntry(chooseInt(2000, 2020));
		cout << "	Enter department building \n1.VC\n2.GAK\n3.Y1\n4.Y2\nYour choose : ";
		tmp.setDepartmentBuilding(chooseInt(1, 4));
		cout << "	Do you have additional points? \n1.Yes\n0.No\nYour choose :";
		tmp.setAdditionalPoints(chooseInt(0, 1));
		cout << "	Previous Educational Institution\n1.School\n2.Technical school\n3.College\n\nYour choose :";
		tmp.setPreviousEducationalInstitution(chooseInt(1, 3));


		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}

string ListofBachelorStudent::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}


int ListofBachelorStudent::chooseInt(int start, int end) {
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