#include "List.h"

void List::addPupils() {
	cout << "Do you want to create a Junior Student or High School Student? \n1.Junior Student\n2.High School Student\nYour choose:";
	int choose = chooseInt(1, 2);
	Pupils* p = NULL;
	int digit;
	getchar;

	if (choose == 1) {
		JuniorStudent tmp;
		cout << "\n\nCreate a new Pupils now.\n	Enter full name : anastasia"; 

		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		tmp.setAge(chooseInt(5, 16));
		cout << "	Enter number school : ";
		tmp.setNumberSchool(chooseInt(1, 999));
		cout << "	Describe the positive qualities in 3 words : smart";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		tmp.setGrade(chooseInt(1, 9));
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));;
		cout << "	Enter exam score : ";
		tmp.setMarkExam(chooseInt(1, 200));
		cout << "	Have you changed school? \n1.Yes\n0.No\n\nYour choose :";
		tmp.setChangeSchool(chooseInt(0, 1));
		p = &tmp;

	}
	else if (choose == 2) {
		HighSchoolStudent tmp;
		cout << "\n\nCreate a new pupils now.\n	Enter full name : ";

		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		tmp.setAge(chooseInt(16, 20));
		cout << "	Enter number school : ";
		tmp.setNumberSchool(chooseInt(1, 999));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		tmp.setGrade(chooseInt(10, 12));
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));
		cout << "	Sports activities\n1.Boxing\n2.Karate\n3.Swimming\n\nYour choose :";
		tmp.setSportsActivities(chooseInt(1, 3));
		cout << "	Do you have additional points? \n1.Yes\n0.No\nYour choose :";
		tmp.setAdditionalPoints(chooseInt(0, 1));
		
		p = &tmp;
	}
	list.push_back	(p);
}
void List::removePupils(const int index) {
	if (!list.empty())
		delete* (list.begin() + index);
		list.erase(list.begin() + index);
}
void List::showAll() {
	for (int i = 0; i < list.size(); i++) {

		cout << list[i]->print() << endl;
	}
}
void List::setPupils(const int index) {
	int choice = 0, type = 0;
	type = list[index]->whoIAm();

	cout << "Your Pupils:\n\n";
	cout << list[index]->print() << endl;
	cout << "\nWhat do u want to change?\n1.NumberSchool\n2.Fullname\n3.Age\n4.Characteristic\n5.Grade\n6.Insurance\n";

	cout << "Your choise(1-8): ";
	choice = chooseInt(1, 8);

	switch (choice)
	{
	case 1:
		list[index]->setNumberSchool(chooseInt(1, 999));
		break;
	case 2:
		list[index]->setFullname(check(regName));
		break;
	case 3:
		list[index]->setAge(chooseInt(5, 20));
		break;
	case 4:
		list[index]->setCharac(check(regName));
		break;
	case 5:
		list[index]->setGrade(chooseInt(1, 12));
		break;
	case 6:
		list[index]->setInsurance(!list[index]->getInsurance());
		break;
		
	}
}
void List::clear() {
	if (!list.empty()) {
		for (int i = list.size(); i > 0; i--) {
			removePupils(i - 1);
		}
	}
}
Pupils& List::getPupils(const int index) {
	return *(list[index]);
}
Pupils& List::getPupilsGrade(const int grade) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getGrade() == grade)
			return *(list[i]);
	}
}
void List::sortGrade() {
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
Pupils& List::operator[](const int index) {
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
	int numberSchool;
	string fullname;
	int age;
	string characteristic;
	int grade;
	bool insurance;
	int markExam;
	bool changeSchool;
	int sportsActivities;
	bool additionalPoints;

	std::ifstream in(filename);
	if (in.is_open())
	{
		int size = 0;
		int type = 0;
		list.clear();

		in >> size;
		list.reserve(size);
		for (int i = 0; i < size; i++) {
			Pupils* p = NULL;
			in >> type;
			if (type == 1) {
				in >> numberSchool >> fullname >> age >> characteristic >> grade >> insurance >>  markExam >> changeSchool;
				JuniorStudent* tmp = new JuniorStudent(numberSchool, fullname, age, characteristic, grade, insurance, markExam, changeSchool);
				p = *(&tmp);
				list.push_back(p);
			}
			else if (type == 2) {
				in >> numberSchool >> fullname >> age >> characteristic >> grade >> insurance >> sportsActivities >> additionalPoints;
				HighSchoolStudent* tmp = new HighSchoolStudent(numberSchool, fullname, age, characteristic, grade, insurance, sportsActivities, additionalPoints);
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
			out << list[i]->whoIAm() << " " << list[i]->getNumberSchool() << " " << list[i]->getFullname() << " " << list[i]->getAge() << " " << list[i]->getCharac() << " " << list[i]->getGrade() << " " << list[i]->getInsurance() << endl;
	}
	out.close();
}
