#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define TECH_TXT "tech.txt"
int i, menuChoice, rowNumber;

string id, speed, capacity;
vector <string> serverId;
vector <string> serverSpeed;
vector <string> serverCapacity;

ofstream writing;

void showMenu() {
	cout << "\n-----------------------" << endl;
	cout << "| SERVER TECH MENU     |" << endl;
	cout << "|1: Add a new server   |" << endl;
	cout << "|2: Show the all data  |" << endl;
	cout << "|3: Clear the screen   |" << endl;
	cout << "|4: Go to main menu    |" << endl;
	cout << "|Enter your choice : ";
	cin >> menuChoice;
	cout << "-----------------------" << endl;
}


void addingServer() {
id:
	cout << "ID of server= ";
	cin >> id;
	for (int x = 0; x < serverId.size(); x++) {
		if (id == serverId[x]) {
			cout << "This ID is already given." << endl;
			goto id;
		}
	}
	cout << "Speed of the server= ";
	cin >> speed;
	cout << "Capacity of the server= ";
	cin >> capacity;

	serverId.push_back(id);
	serverSpeed.push_back(speed);
	serverCapacity.push_back(capacity);
	writing.open(TECH_TXT, ios_base::app);
	writing << id << endl;
	writing << speed << endl;
	writing << capacity << endl;
	writing.close();
}

void initialization() {
	ifstream forRowNumber;
	ifstream reading;
	string content;

	forRowNumber.open(TECH_TXT);
	while (!forRowNumber.eof()) {
		getline(forRowNumber, content);
		rowNumber++;
	}
	forRowNumber.close();


	reading.open(TECH_TXT);

	for (int k = 1;k < rowNumber;k++) {
		i++;
		getline(reading, content);
		if (i % 2 == 0) {
			serverSpeed.push_back(content);
		}
		else if (i % 3 == 0) {
			serverCapacity.push_back(content);
		}
		else {
			serverId.push_back(content);
		}

		if (i % 3 == 0)
			i = 0;

	}
	reading.close();
	rowNumber = 0;
}


void showingServer() {

	for (int j = 0;j < serverId.size();j++) {
		cout << "\nServer ID=" << serverId[j];
		cout << "\nServer City=" << serverSpeed[j];
		cout << "\nServer Country=" << serverCapacity[j] << endl;
	}

}

int main()
{
again:
	system("CLS");
	initialization();
	do
	{
		showMenu();
		switch (menuChoice)
		{
		case 1:
			addingServer();
			break;
		case 2:
			showingServer();
			break;
		case 3:
			goto again;
			break;
		case 4:
			break;
		default:
			cout << "\nInvalid input" << endl;
		}
	} while (menuChoice != 4);

}

