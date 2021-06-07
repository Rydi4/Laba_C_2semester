#include "List.h"

void List::addPupils(Pupils& pupils) {
	list.push_back(pupils);
}
void List::removePupils(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void List::showAll() {
	for (Pupils& emp : list)
		cout << emp.printPupils() << endl;
}
Pupils& List::getPupils(const int index) {
	return list[index];
}
Pupils& List::getPupilsGrade(const int grade) {
	for (Pupils& emp : list) {
		if (emp.getGrade() == grade)
			return emp;
	}
}

void List::readFromFile() {
	int numberSchool;
	string fullname;
	int age;
	string characteristic;
	int grade;
	bool insurance;

	std::ifstream in(filename);
	if (in.is_open())
	{
		list.clear();
		while (in >> numberSchool >> fullname >> age >> characteristic >> grade >> insurance)
			list.push_back(Pupils(numberSchool, fullname, age, characteristic, grade, insurance));
	}
	in.close();
}
void List::writeToFile() {
	std::ofstream out(filename);
	if (out.is_open()) {
		for (int i = 0; i < list.size(); i++)
			out << list[i].getNumberSchool() << " " << list[i].getFullname() << " " << list[i].getAge() << " " << list[i].getCharac() << " " << list[i].getGrade() << " " << list[i].getInsurance() << endl;
	}
	out.close();
}

int List::getSize() { return list.size(); }
Pupils& List::operator[](const int index) {
	return list[index];
}
void List::addObjects() {
	bool choice = true;
	Pupils tmp;
	int digit;

	while (choice) {
		getchar();
		cout << "\n\nCreate a new pupils now.\n	Enter full name : ";
		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		do {
			cin >> digit;
			if (digit >= 5 && digit <= 20)
			{
				tmp.setAge(digit);
				break;
			}
			else
				cout << "\nTry again : ";
		} while (true);
		cout << "	Enter number school : ";
		do {
			cin >> digit;
			if (digit >> 0 && digit <= 999)
			{
				tmp.setNumberSchool(digit);
				break;
			}
			else
				cout << "\nTry again : ";
		} while (true);
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		do {
			cin >> digit;
			if (digit >= 1 && digit <= 12)
			{
				tmp.setGrade(digit);
				break;
			}
			else
				cout << "\nTry again : ";
		} while (true);
		cout << "	Availability of insurance (1 - yes, 0 - no) : ";
		do {
			cin >> digit;
			if (digit == 1 || digit == 0) {
				tmp.setInsurance(digit);
				break;
			}
			else
				cout << "\nTry again : ";
		} while (true);
		list.push_back(tmp);
		cout << "A new pupils has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
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