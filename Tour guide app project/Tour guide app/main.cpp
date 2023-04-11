#include<iostream>
#include<string>
#include<vector>
#include "locationNode.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>     // std::string, std::to_string

using namespace std;

int main()
{
	sql::ConnectOptionsMap connection_properties;

	//Paul
	connection_properties["hostName"] = "localhost";
	connection_properties["userName"] = "root";
	connection_properties["password"] = "root";
	connection_properties["port"] = 3351;


	//Aadil
	//connection_properties["hostName"] = "localhost";
	//connection_properties["userName"] = "root";
	//connection_properties["password"] = "Aadil123!";

	//Doha
	//connection_properties["hostName"] = "localhost";
	//connection_properties["userName"] = "root";
	//connection_properties["password"] = "SaDa2903!";

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	// sql::PreparedStatement* pstmt;
	sql::ResultSet* res;


		int ch;
		int touristsNum;
		int totalPrice = 0;
		struct locationNode *Headloc = NULL;
		struct locationNode *CurrLoc = NULL;
		locationNode* tempNode;
		vector<int> idList;



		//Get num people on tour
		cout << endl;
		cout<<"Enter the number of people on tour: ";
		cin>> touristsNum;

		//Show tour packages and get response
		cout << "Please select your tour: " <<endl;
		cout << "1: Nature (£10 per person) " << endl;
		cout << "2: City (£20 per person)" << endl;
		cout << "3: Cultural (£40 per person)" << endl;

		ch = 0;
		do {
			cout << "Choice: ";
			cin >> ch;
			cout << endl;
		} while (ch != 1 && ch != 2 && ch != 3);

		//Using response load in locations nodes and create linked list of nodes. For each node call load in hotel/rest functions.

		if (ch==1) {
			idList.push_back(1);
			idList.push_back(2);
			idList.push_back(3);
			idList.push_back(4);
			totalPrice += 1000 * touristsNum;
		}
		else if (ch == 2) {
			idList.push_back(5);
			idList.push_back(6);
			idList.push_back(7);
			idList.push_back(8);
			totalPrice += 2000 * touristsNum;
		}
		else{
			idList.push_back(9);
			idList.push_back(10);
			idList.push_back(11);
			idList.push_back(12);
			totalPrice += 4000 * touristsNum;
		}

		try
		{
			driver = get_driver_instance();
			con = driver->connect(connection_properties);

		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}

		con->setSchema("tour_guide_system");
		for (int x : idList) {
			stmt = con->createStatement();
			string sql = "SELECT * FROM location WHERE locationId = " + to_string(x);
			res = stmt->executeQuery(sql);

			res->next();
			if (Headloc == NULL) {
				Headloc = new locationNode(res->getInt(1), res->getString(2), res->getString(3), res->getString(4), res->getString(5));
				CurrLoc = Headloc;
				CurrLoc->loadHotels();
				CurrLoc->loadRest();
			}
			else {
				tempNode = new locationNode(res->getInt(1), res->getString(2), res->getString(3), res->getString(4), res->getString(5));
				CurrLoc->setNextLoc(tempNode);
				CurrLoc = CurrLoc->getNextLoc();
				CurrLoc->loadHotels();
				CurrLoc->loadRest();
			}
		}




		CurrLoc = Headloc;
		do {
			CurrLoc->viewMenu();
			
			cout << "Choice: ";
			cin >> ch;
			cout << endl;

			if (ch==1) {
				CurrLoc->visitHotels(touristsNum, totalPrice);
			}
			else if (ch == 2) {
				CurrLoc->eatAtRest(touristsNum, totalPrice);
			}
			else if (ch == 3) {
				CurrLoc->uniqueAct();
			}
			else if(ch == 4) {
				CurrLoc = CurrLoc->getNextLoc();
			}
			else {
				cout << "Invalid input" << endl;
			}

		} while (CurrLoc);

		cout << "Thank you for taking our tour!!" << endl;
		cout << "Your total amount spent is £" << totalPrice/100.0 <<"." << endl;
}