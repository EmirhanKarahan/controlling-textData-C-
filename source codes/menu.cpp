#include <iostream>  
#include <process.h>
#include <fstream>
using namespace std;
int menuChoice;

void showMenu() {
	cout << "\n-----------------------------" << endl;
	cout << "|        MAIN MENU          |" << endl;
	cout << "|1: Servers' Locations      |" << endl;
	cout << "|2: Servers' Technology     |" << endl;
	cout << "|3: Servers' Cost and Profit|" << endl;
	cout << "|4: Servers' Report         |" << endl;
	cout << "|5: Clear the screen        |" << endl;
	cout << "|6: EXIT                    |" << endl;
	cout << "|Enter your choice : ";
	cin >> menuChoice;
	cout << "-----------------------------<" << endl;
}

void avoidMissingFile() {
	ofstream location("location.txt", ios::app);
	ofstream cost("cost.txt", ios::app);
	ofstream tech("tech.txt", ios::app);
	location.close();
	cost.close();
	tech.close();
}

int main() {
	avoidMissingFile();
again:
	system("CLS");


	do
	{
		showMenu();
		switch (menuChoice)
		{
		case 1:
			_spawnl(P_WAIT, "location.exe", "location.exe", NULL);
			break;
		case 2:
			_spawnl(P_WAIT, "tech.exe", "tech.exe", NULL);
			break;
		case 3:
			_spawnl(P_WAIT, "cost.exe", "cost.exe", NULL);
			break;
		case 4:
			_spawnl(P_WAIT, "report.exe", "report.exe", NULL);
			break;
		case 5:
			goto again;
			break;
		case 6:
			break;

		default:
			cout << "\nInvalid input" << endl;
		}
	} while (menuChoice != 6);

	return 0;
}