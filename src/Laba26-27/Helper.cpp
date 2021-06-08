#include "Helper.h"


void Helper::menu(List& list) {
	cout << "\n\nA list of pupils.Select an action from the following.\n\n";
	cout << "1.Write list to screen.\n";
	cout << "2.Generate and add pupils.\n";
	cout << "3.Delete pupils by index.\n";
	cout << "4.Search for pupils with insurance.\n";
	cout << "5.Reading pupils from a file.\n";
	cout << "6.Writing pupils in file.\n";
	cout << "0.Exit.\n\n";
	cout << "Your choice: ";

	int choice = -1;

	while (choice < 0 || choice>7) {
		cin >> choice;
		if (choice < 0 || choice>7)
			cout << "You entered an invalid value, please retry\n\nYour choice: ";
	}
	cout << endl << endl;

	switch (choice) {
	case 0: return;
	case 1:
		list.showAll();
		break;
	case 2:
		list.addPupils();
		break;
	case 3:
		choice = 0;
		cout<<"Choose index(0-" << list.getSize() << "):";
		while (choice < 0 || choice > list.getSize()) {
			cin >> choice;
			if (choice < 0 || choice > list.getSize())
				cout << "You entered an index that is larger than the size of the list, please retry\n\nYour choice: ";
		}
		list.removePupils(choice - 1);
		break;
	case 4:
		cout << list.getPupilsGrade(10).print();
		break;
	case 5:
		list.readFromFile();
		break;
	case 6:
		list.writeToFile();
		break;
	}
	cout << "\n\nSuccessful.";
	menu(list);
}

