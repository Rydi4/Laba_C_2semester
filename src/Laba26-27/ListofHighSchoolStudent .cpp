#include "List.h"

void ListOfHighSchoolStudent::addPupils(HighSchoolStudent& pupils) {
	list.push_back(pupils);
}
void ListOfHighSchoolStudent::removePupils(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListOfHighSchoolStudent::showAll() {
	for (HighSchoolStudent& emp : list) 		
		cout << emp.print() << endl;
}
HighSchoolStudent& ListOfHighSchoolStudent::getPupils(const int index) { return list[index]; }
HighSchoolStudent& ListOfHighSchoolStudent::getPupilsGrade(const int grade) {
	for (HighSchoolStudent& emp : list) {
		if (emp.getGrade() == grade)
			return emp;
	}
}


int ListOfHighSchoolStudent::getSize() { return list.size(); }

HighSchoolStudent& ListOfHighSchoolStudent::operator[](const int index) {
	return list[index];
}

void ListOfHighSchoolStudent::addObjects() {
	bool choice = true;
	HighSchoolStudent tmp;
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
		cout << "	Do you have additional points? \n1.Yes\n2.No\nYour choose :";
		tmp.setAdditionalPoints(chooseInt(1, 2));
		cout << "	Sports activities\n1.Boxing\n2.Karate\n3.Swimming\n\nYour choose :";
		tmp.setSportsActivities(chooseInt(1, 3));

		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}
/*
void ListOfHighSchoolStudent::getWasBoxing() {
	for (HighSchoolStudent& emp : list) {
		if (emp.getSportsActivities() == 1)
			cout << emp.printPupils() << endl;
	}
}
*/
string ListOfHighSchoolStudent::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}

int ListOfHighSchoolStudent::chooseInt(int start, int end) {
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