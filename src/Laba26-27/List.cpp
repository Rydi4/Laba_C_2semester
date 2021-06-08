#include "List.h"

void List::addPupils() {
	cout << "Do you want to create a Junior Student or High School Student? \n1.Junior Student\n2.High School Student\nYour choose:";
	int choose = chooseInt(1, 2);
	Pupils* p = NULL;
	int digit;
	getchar;

	if (choose == 1) {
		JuniorStudent tmp;
		cout << "\n\nCreate a new pupils now.\n	Enter full name : "; 

		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		tmp.setAge(chooseInt(5, 20));
		cout << "	Enter number school : ";
		tmp.setNumberSchool(chooseInt(1, 999));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		tmp.setGrade(chooseInt(1, 9));
		cout << "	Availability of insurance \n1.Yes\n2.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(1, 2));;
		cout << "	Enter exam score : ";
		tmp.setMarkExam(chooseInt(1, 200));
		cout << "	Have you changed school? \n1.Yes\n2.No\n\nYour choose :";
		tmp.setChangeSchool(chooseInt(1, 2));
		p = &tmp;

	}
	else if (choose == 2) {
		HighSchoolStudent tmp;
		cout << "\n\nCreate a new pupils now.\n	Enter full name : ";

		tmp.setFullname(check(regName));
		cout << "	Enter age : ";
		tmp.setAge(chooseInt(5, 20));
		cout << "	Enter number school : ";
		tmp.setNumberSchool(chooseInt(1, 999));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter grade : ";
		tmp.setGrade(chooseInt(10, 12));
		cout << "	Availability of insurance \n1.Yes\n2.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(1, 2));;
		cout << "	Do you have additional points? \n1.Yes\n2.No\nYour choose :";
		tmp.setAdditionalPoints(chooseInt(1, 2));
		cout << "	Sports activities\n1.Boxing\n2.Karate\n3.Swimming\n\nYour choose :";
		tmp.setSportsActivities(chooseInt(1, 3));
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
Pupils& List::getPupils(const int index) {
	return *(list[index]);
}
Pupils& List::getPupilsGrade(const int grade) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getGrade() == grade)
			return *(list[i]);
	}
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

int List::getSize() { return list.size(); }
Pupils& List::operator[](const int index) {
	return *list[index];
}
 /*void List::addObjects() {
	bool choice = true;
	Pupils tmp;
	int digit;

	while (choice) {
		getchar();
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
		tmp.setInsurance(chooseInt(0, 1));
		list.push_back(tmp);
		cout << "A new pupils has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}
void List::get6thGradeStudent() {
	for (Pupils& emp : list) {
		if (emp.getGrade() == 6)
			cout << emp.printPupils() << endl;
	}
} */
string List::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}

int List::chooseInt(int start, int end) {
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