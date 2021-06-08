#include "List.h"

void ListOfJuniorStudent::addPupils(JuniorStudent& pupils) {
	list.push_back(pupils);
}
void ListOfJuniorStudent::removePupils(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListOfJuniorStudent::showAll() {
	for (JuniorStudent& emp : list)
		cout << emp.print() << endl;
}
JuniorStudent& ListOfJuniorStudent::getPupils(const int index) { return list[index]; }
JuniorStudent& ListOfJuniorStudent::getPupilsGrade(const int grade) {
	for (JuniorStudent& emp : list) {
		if (emp.getGrade() == grade)
			return emp;
	}
}


int ListOfJuniorStudent::getSize() { return list.size(); }
JuniorStudent& ListOfJuniorStudent::operator[](const int index) {
	return list[index];
}
void ListOfJuniorStudent::addObjects() {
	bool choice = true;
	JuniorStudent tmp;
	int digit;

	while (choice) {
		getchar;
		cout << "\n\nCreate a new pupils now.\n	Enter full name : ";
		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		tmp.setAge(chooseInt(5, 20));
		cout << "	Enter number school : ";
		tmp.setNumberSchool(chooseInt(1, 999));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		tmp.setGrade(chooseInt(1, 12));
		cout << "	Availability of insurance \n1.Yes\n2.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));;
		cout << "	Enter exam score : ";
		tmp.setMarkExam(chooseInt(1, 200));
		cout << "	Have you changed school? \n1.Yes\n2.No\n\nYour choose :";
		tmp.setChangeSchool(chooseInt(0, 1));

		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}
/*
void ListOfJuniorStudent::getWasChangeSchool() {
	for (JuniorStudent& emp : list) {
		if (emp.getChangeSchool() == 0)
			cout << emp.printPupils() << endl;
	}
}
*/
string ListOfJuniorStudent::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}


int ListOfJuniorStudent::chooseInt(int start, int end) {
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