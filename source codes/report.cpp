#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define LOCATION_TXT "location.txt"
#define COST_TXT "cost.txt"
#define TECH_TXT "tech.txt"
#define REPORT_TXT "report.txt"

int i, menuChoice, rowNumber, counter, x, y, t, u, v, w,l,m,n;

vector <string> serverIdLocation, serverCity, serverCountry;
vector <string> serverIdCost, serverCost, serverMembers, serverProfit;
vector <string> serverIdTech, serverSpeed, serverCapacity;

void showMenu() {
	cout << "\n--------------------------------" << endl;
	cout << "|   SERVER REPORT MENU          |" << endl;
	cout << "|1: Show the all data           |" << endl;
	cout << "|2: Write report to report.txt  |" << endl;
	cout << "|3: Go to main menu             |" << endl;
	cout << "|Enter your choice : ";
	cin >> menuChoice;
	cout << "--------------------------------" << endl;
}

void takeLocationData() {
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
			serverIdLocation.push_back(content);
		}

		if (i % 3 == 0)
			i = 0;

	}
	reading.close();
	rowNumber = 0;
}

void takeTechData() {
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
			serverIdTech.push_back(content);
		}

		if (i % 3 == 0)
			i = 0;

	}
	reading.close();
	rowNumber = 0;
}

void takeCostData() {
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
			serverIdCost.push_back(content);
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
    combo:
	l = 0;m = 0;n = 0;
	for (l = 0; l < serverIdLocation.size(); l++) {
		for (m = 0; m < serverIdCost.size(); m++) {
			for ( n = 0; n < serverIdTech.size(); n++){
				if (serverIdLocation[l] == serverIdCost[m] && serverIdCost[m] == serverIdTech[n]) {
					cout << "\nServer ID=" << serverIdLocation[l];
					cout << "\nServer City=" << serverCity[l];
					cout << "\nServer Country=" << serverCountry[l];
					cout << "\nServer Members=" << serverMembers[m];
					cout << "\nServer Cost=" << serverCost[m];
					cout << "\nServer Profit=" << serverProfit[m];
					cout << "\nServer Speed="<< serverSpeed[n];
					cout << "\nServer Capacity=" <<serverCapacity[n]<< endl;

					serverIdLocation.erase(serverIdLocation.begin() + l);
					serverCity.erase(serverCity.begin() + l);
					serverCountry.erase(serverCountry.begin() + l);

					serverIdCost.erase(serverIdCost.begin() + m);
					serverMembers.erase(serverMembers.begin() + m);
					serverCost.erase(serverCost.begin() + m);
					serverProfit.erase(serverProfit.begin() + m);

					serverIdTech.erase(serverIdTech.begin() + n);
					serverSpeed.erase(serverSpeed.begin() + n);
					serverCapacity.erase(serverCapacity.begin() + n);
					
					goto combo;
				}

			}
		}
	}



	locationAndCost:
	x = 0; y = 0;
	for (x = 0; x < serverIdLocation.size(); x++) {
		for (y = 0; y < serverIdCost.size(); y++) {
			if (serverIdLocation[x] == serverIdCost[y]) {
				cout << "\nServer ID=" << serverIdLocation[x];
				cout << "\nServer City=" << serverCity[x];
				cout << "\nServer Country=" << serverCountry[x];
				cout << "\nServer Members="<< serverMembers[y];
				cout << "\nServer Cost=" << serverCost[y];
				cout << "\nServer Profit="<< serverProfit[y];
				cout << "\nServer Speed="  ;
				cout << "\nServer Capacity=" << endl;

				serverIdLocation.erase(serverIdLocation.begin() + x);
				serverCity.erase(serverCity.begin() + x);
				serverCountry.erase(serverCountry.begin() + x);

				serverIdCost.erase(serverIdCost.begin() + y);
				serverMembers.erase(serverMembers.begin() + y);
				serverCost.erase(serverCost.begin() + y);
				serverProfit.erase(serverProfit.begin() + y);
				goto locationAndCost;
			}
		}
	}

	locationAndTech:
	t = 0; u = 0;
	for (t = 0; t < serverIdLocation.size(); t++) {
		for (u = 0; u < serverIdTech.size(); u++) {
			if (serverIdLocation[t] == serverIdTech[u]) {
				cout << "\nServer ID=" << serverIdLocation[t];
				cout << "\nServer City=" << serverCity[t];
				cout << "\nServer Country=" << serverCountry[t];
				cout << "\nServer Members=";
				cout << "\nServer Cost=";
				cout << "\nServer Profit=";
				cout << "\nServer Speed=" << serverSpeed[u];
				cout << "\nServer Capacity=" << serverCapacity[u] << endl;

				serverIdLocation.erase(serverIdLocation.begin() + t);
				serverCity.erase(serverCity.begin() + t);
				serverCountry.erase(serverCountry.begin() + t);

				serverIdTech.erase(serverIdTech.begin() + u);
				serverSpeed.erase(serverSpeed.begin() + u);
				serverCapacity.erase(serverCapacity.begin() + u);
				goto locationAndTech;
			}
		}
	}

	techAndCost:
	v = 0;w = 0;
	for (v = 0; v < serverIdCost.size(); v++) {
		for (w = 0; w < serverIdTech.size(); w++) {
			if (serverIdTech[w] == serverIdCost[v]) {
				cout << "\nServer ID=" << serverIdCost[v];
				cout << "\nServer City=";
				cout << "\nServer Country=";
				cout << "\nServer Members=" << serverMembers[v];
				cout << "\nServer Cost=" << serverCost[v];
				cout << "\nServer Profit=" << serverProfit[v];
				cout << "\nServer Speed=" << serverSpeed[w];
				cout << "\nServer Capacity=" << serverCapacity[w] << endl;

				serverIdCost.erase(serverIdCost.begin() + v);
				serverMembers.erase(serverMembers.begin() + v);
				serverCost.erase(serverCost.begin() + v);
				serverProfit.erase(serverProfit.begin() + v);

				serverIdTech.erase(serverIdTech.begin() + w);
				serverSpeed.erase(serverSpeed.begin() + w);
				serverCapacity.erase(serverCapacity.begin() + w);
				goto techAndCost;
			}
		}
	}

	for (int a = 0; a < serverIdLocation.size(); a++) {
		cout << "\nServer ID=" << serverIdLocation[a];
		cout << "\nServer City=" << serverCity[a];
		cout << "\nServer Country=" << serverCountry[a];
		cout << "\nServer Members=";
		cout << "\nServer Cost=";
		cout << "\nServer Profit=";
		cout << "\nServer Speed=";
		cout << "\nServer Capacity=" << endl;
	}

	for (int b = 0; b < serverIdCost.size(); b++) {
		cout << "\nServer ID=" << serverIdCost[b];
		cout << "\nServer City=";
		cout << "\nServer Country=";
		cout << "\nServer Members=" << serverMembers[b];
		cout << "\nServer Cost=" << serverCost[b];
		cout << "\nServer Profit=" << serverProfit[b];
		cout << "\nServer Speed=";
		cout << "\nServer Capacity=" << endl;
	}

	for (int c = 0; c < serverIdTech.size(); c++) {
		cout << "\nServer ID=" << serverIdTech[c];
		cout << "\nServer City=";
		cout << "\nServer Country=";
		cout << "\nServer Members=";
		cout << "\nServer Cost=";
		cout << "\nServer Profit=";
		cout << "\nServer Speed=" << serverSpeed[c];
		cout << "\nServer Capacity=" << serverCapacity[c] << endl;
	}

	serverIdLocation.clear(); serverIdTech.clear(); serverIdCost.clear();
	serverCity.clear(); serverCountry.clear(); serverMembers.clear();
	serverCost.clear(); serverProfit.clear(); serverSpeed.clear(); 	serverCapacity.clear();

	takeLocationData();
	takeCostData();
	takeTechData();
}

void writeToFile() {
	ofstream writing;
	writing.open(REPORT_TXT);
    combo:
	l = 0;m = 0;n = 0;
	for (l = 0; l < serverIdLocation.size(); l++) {
		for (m = 0; m < serverIdCost.size(); m++) {
			for (n = 0; n < serverIdTech.size(); n++) {
				if (serverIdLocation[l] == serverIdCost[m] && serverIdCost[m] == serverIdTech[n]) {
					writing << "\nServer ID=" << serverIdLocation[l] << endl;
					writing << "Server City=" << serverCity[l] << endl;
					writing << "Server Country=" << serverCountry[l] << endl;
					writing << "Server Members=" << serverMembers[m] << endl;
					writing << "Server Cost=" << serverCost[m] << endl;
					writing << "Server Profit=" << serverProfit[m] << endl;
					writing << "Server Speed=" << serverSpeed[n] << endl;
					writing << "Server Capacity=" << serverCapacity[n] << endl;

					serverIdLocation.erase(serverIdLocation.begin() + l);
					serverCity.erase(serverCity.begin() + l);
					serverCountry.erase(serverCountry.begin() + l);

					serverIdCost.erase(serverIdCost.begin() + m);
					serverMembers.erase(serverMembers.begin() + m);
					serverCost.erase(serverCost.begin() + m);
					serverProfit.erase(serverProfit.begin() + m);

					serverIdTech.erase(serverIdTech.begin() + n);
					serverSpeed.erase(serverSpeed.begin() + n);
					serverCapacity.erase(serverCapacity.begin() + n);

					goto combo;
				}

			}
		}
	}



locationAndCost:
	x = 0; y = 0;
	for (x = 0; x < serverIdLocation.size(); x++) {
		for (y = 0; y < serverIdCost.size(); y++) {
			if (serverIdLocation[x] == serverIdCost[y]) {
				writing << "\nServer ID=" << serverIdLocation[x] << endl;
				writing << "Server City=" << serverCity[x] << endl;
				writing << "Server Country=" << serverCountry[x] << endl;
				writing << "Server Members=" << serverMembers[y] << endl;
				writing << "Server Cost=" << serverCost[y] << endl;
				writing << "Server Profit=" << serverProfit[y] << endl;
				writing << "Server Speed=" << endl;
				writing << "Server Capacity=" << endl;

				serverIdLocation.erase(serverIdLocation.begin() + x);
				serverCity.erase(serverCity.begin() + x);
				serverCountry.erase(serverCountry.begin() + x);

				serverIdCost.erase(serverIdCost.begin() + y);
				serverMembers.erase(serverMembers.begin() + y);
				serverCost.erase(serverCost.begin() + y);
				serverProfit.erase(serverProfit.begin() + y);
				goto locationAndCost;
			}
		}
	}

locationAndTech:
	t = 0; u = 0;
	for (t = 0; t < serverIdLocation.size(); t++) {
		for (u = 0; u < serverIdTech.size(); u++) {
			if (serverIdLocation[t] == serverIdTech[u]) {
				writing << "\nServer ID=" << serverIdLocation[t] << endl;
				writing << "Server City=" << serverCity[t] << endl;
				writing << "Server Country=" << serverCountry[t] << endl;
				writing << "Server Members=" << endl;
				writing << "Server Cost=" << endl;
				writing << "Server Profit=" << endl;
				writing << "Server Speed=" << serverSpeed[u] << endl;
				writing << "Server Capacity=" << serverCapacity[u] << endl;

				serverIdLocation.erase(serverIdLocation.begin() + t);
				serverCity.erase(serverCity.begin() + t);
				serverCountry.erase(serverCountry.begin() + t);

				serverIdTech.erase(serverIdTech.begin() + u);
				serverSpeed.erase(serverSpeed.begin() + u);
				serverCapacity.erase(serverCapacity.begin() + u);
				goto locationAndTech;
			}
		}
	}

techAndCost:
	v = 0;w = 0;
	for (v = 0; v < serverIdCost.size(); v++) {
		for (w = 0; w < serverIdTech.size(); w++) {
			if (serverIdTech[w] == serverIdCost[v]) {
				writing << "\nServer ID=" << serverIdCost[v] << endl;
				writing << "Server City=" << endl;
				writing << "Server Country=" << endl;
				writing << "Server Members=" << serverMembers[v] << endl;
				writing << "Server Cost=" << serverCost[v] << endl;
				writing << "Server Profit=" << serverProfit[v] << endl;
				writing << "Server Speed=" << serverSpeed[w] << endl;
				writing << "Server Capacity=" << serverCapacity[w] << endl;

				serverIdCost.erase(serverIdCost.begin() + v);
				serverMembers.erase(serverMembers.begin() + v);
				serverCost.erase(serverCost.begin() + v);
				serverProfit.erase(serverProfit.begin() + v);

				serverIdTech.erase(serverIdTech.begin() + w);
				serverSpeed.erase(serverSpeed.begin() + w);
				serverCapacity.erase(serverCapacity.begin() + w);
				goto techAndCost;
			}
		}
	}

	for (int a = 0; a < serverIdLocation.size(); a++) {
		writing << "\nServer ID=" << serverIdLocation[a] << endl;
		writing << "Server City=" << serverCity[a] << endl;
		writing << "Server Country=" << serverCountry[a] << endl;
		writing << "Server Members=" << endl;
		writing << "Server Cost=" << endl;
		writing << "Server Profit=" << endl;
		writing << "Server Speed=" << endl;
		writing << "Server Capacity=" << endl;
	}

	for (int b = 0; b < serverIdCost.size(); b++) {
		writing << "\nServer ID=" << serverIdCost[b] << endl;
		writing << "Server City=" << endl;
		writing << "Server Country=" << endl;
		writing << "Server Members=" << serverMembers[b] << endl;
		writing << "Server Cost=" << serverCost[b] << endl;
		writing << "Server Profit=" << serverProfit[b] << endl;
		writing << "Server Speed=" << endl;
		writing << "Server Capacity=" << endl;
	}

	for (int c = 0; c < serverIdTech.size(); c++) {
		writing << "\nServer ID=" << serverIdTech[c] << endl;
		writing << "Server City=" << endl;
		writing << "Server Country=" << endl;
		writing << "Server Members=" << endl;
		writing << "Server Cost=" << endl;
		writing << "Server Profit=" << endl;
		writing << "Server Speed=" << serverSpeed[c] << endl;
		writing << "Server Capacity=" << serverCapacity[c] << endl;
	}

	serverIdLocation.clear(); serverIdTech.clear(); serverIdCost.clear();
	serverCity.clear(); serverCountry.clear(); serverMembers.clear();
	serverCost.clear(); serverProfit.clear(); serverSpeed.clear(); 	serverCapacity.clear();
	writing.close();
	takeLocationData();
	takeCostData();
	takeTechData();
}


int main()
{
again:
	system("CLS");
	takeLocationData();
	takeCostData();
	takeTechData();

	do
	{
		showMenu();
		switch (menuChoice)
		{
		case 1:
			showingServer();
			break;
		case 2:
			writeToFile();
			break;
		case 3:
			break;
		default:
			cout << "\nInvalid input" << endl;
		}
	} while (menuChoice != 3);

}
