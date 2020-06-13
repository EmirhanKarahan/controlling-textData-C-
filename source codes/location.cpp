#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define LOCATION_TXT "location.txt"
int i, menuChoice, rowNumber;

string id, city, country;
vector <string> serverId;
vector <string> serverCity;
vector <string> serverCountry;

ofstream writing;

void showMenu() {
	cout << "\n-----------------------" << endl;
	cout << "| SERVER LOCATION MENU |" << endl;
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
	cout << "City of the server= ";
	cin >> city;
	cout << "Country of the server= ";
	cin >> country;

	serverId.push_back(id);
	serverCity.push_back(city);
	serverCountry.push_back(country);
	writing.open(LOCATION_TXT, ios_base::app);
	writing << id << endl;
	writing << city << endl;
	writing << country << endl;
	writing.close();
}

void initialization() {
	ifstream forRowNumber;
	ifstream reading;
	string content;

	forRowNumber.open(LOCATION_TXT);
	while (!forRowNumber.eof()) {
		getline(forRowNumber, content);
		rowNumber++;
	}
	forRowNumber.close();


	reading.open(LOCATION_TXT);

	for (int k = 1;k < rowNumber;k++) {
		i++;
		getline(reading, content);
		if (i % 2 == 0) {
			serverCity.push_back(content);
		}
		else if (i % 3 == 0) {
			serverCountry.push_back(content);
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
		cout << "\nServer City=" << serverCity[j];
		cout << "\nServer Country=" << serverCountry[j] << endl;
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

