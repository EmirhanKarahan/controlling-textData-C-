#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define COST_TXT "cost.txt"
int i, menuChoice, rowNumber;

string id, members, cost, profit;
vector <string> serverId;
vector <string> serverMembers;
vector <string> serverCost;
vector <string> serverProfit;

ofstream writing;

void showMenu() {
	cout << "\n-----------------------" << endl;
	cout << "| SERVER COST MENU     |" << endl;
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
	cout << "# of the members= ";
	cin >> members;
	cout << "Cost of the server= ";
	cin >> cost;
	cout << "Profit of the server= ";
	cin >> profit;

	serverId.push_back(id);
	serverMembers.push_back(members);
	serverCost.push_back(cost);
	serverProfit.push_back(profit);
	writing.open(COST_TXT, ios_base::app);
	writing << id << endl;
	writing << members << endl;
	writing << cost << endl;
	writing << profit << endl;
	writing.close();
}

void initialization() {
	ifstream forRowNumber;
	ifstream reading;
	string content;

	forRowNumber.open(COST_TXT);
	while (!forRowNumber.eof()) {
		getline(forRowNumber, content);
		rowNumber++;
	}
	forRowNumber.close();


	reading.open(COST_TXT);

	for (int k = 1;k < rowNumber;k++) {
		i++;
		getline(reading, content);
		if (i == 1) {
			serverId.push_back(content);
		}
		else if (i == 2) {
			serverMembers.push_back(content);
		}
		else if (i == 3) {
			serverCost.push_back(content);
		}
		else {
			serverProfit.push_back(content);
		}

		if (i == 4)
			i = 0;

	}
	reading.close();
	rowNumber = 0;
}


void showingServer() {

	for (int j = 0;j < serverId.size();j++) {
		cout << "\nServer ID=" << serverId[j];
		cout << "\nServer's Member Number=" << serverMembers[j];
		cout << "\nServer Cost=" << serverCost[j];
		cout << "\nServer Profit=" << serverProfit[j] << endl;
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

