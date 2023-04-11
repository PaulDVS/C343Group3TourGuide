#include<iostream>
#include<string>
#include<vector>
#include <map>

#include "hotelNode.h"
#include "restaurantNode.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <string>     // std::string, std::to_string


using namespace std;

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


class locationNode{
	private:
		int locId;
		string locName;
		string locDesc;
		vector<hotelNode> ListofHotels;
		vector<restaurantNode> ListofRest;
		string UniqueAct;
		string UniqueActDesc;
		struct locationNode *NextLoc;

	public:
		locationNode();
		locationNode(int id, string name, string desc, string act, string actDesc);
		void loadHotels(); //Using id load in hotel data as a dict (Maybe create new class?)
		void loadRest(); //Same
		void viewMenu(); //Print a mneu of actions to do, view hotels, view rest, unique act name, go to next loc (Onlyn if not empty)
		void visitHotels(int touristsNum, int &totalCost); //Show list of hotels and ask user which one to stay at, -1 to exit
		void eatAtRest(int touristsNum, int &totalCost); //Same
		void uniqueAct(); //Print unique act and unique act description
		locationNode* getNextLoc(); //Return nextloc pointer
		void setNextLoc(struct locationNode *newLoc);
		
		void printHotels(){
			cout<< ListofHotels[0].getName() <<endl;
			cout<< ListofHotels[1].getName() <<endl;
		}
};

locationNode::locationNode(){
	return;
}

locationNode::locationNode(int id, string name, string desc, string act, string actDesc){
	locId =id;
	locName = name;
	locDesc = desc;
	UniqueAct = act;
	UniqueActDesc = actDesc;
	NextLoc = NULL;
}

void locationNode::loadHotels(){
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	// sql::PreparedStatement* pstmt; 
	sql::ResultSet* res;

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

	vector<int> ids; // vector of hotel ids
	vector<hotelNode> hotels; // vector of Hotel objects
	con->setSchema("tour_guide_system");
	stmt = con->createStatement();
	int id = this->locId; // id is the objects id
	string str_id = to_string(id); // string version of id
	string sql = "SELECT hotelId FROM locHotel WHERE locationId = " + str_id; // sql statement
	res = stmt->executeQuery(sql); // excuete and save to resultset object res
	
	while (res->next()) // loop through the result set
	{
		int id = res->getInt(1); // get the 1st colunm of the result (which is just the hotel id) -> we only have 1 colunm in the result of the statement
		cout << "HotelId: " << res->getInt(1) << endl; // print just to confirm we are getting the correct hotelids (remove later)
		ids.push_back(id); // add the id to our ids vector
	}

	cout << endl;

	delete stmt; // we need to delete stmt before executing a new query

	// now we have a list of hotel ids associated with a given location id
	// we will loop thorugh those ids and for each id we will get the corresponding hotel object
	for (int i = 0; i < ids.size(); i++) {
		stmt = con->createStatement();
		sql = "SELECT hotelName,price,hotelAct FROM hotel WHERE hotelId = " + to_string(ids[i]);
		res = stmt->executeQuery(sql);
		while (res->next()) 
		{
			// getting the values from each row in resultset and print statements just for verification (remove prints later)
			cout << ids[i] << endl;
			string name = res->getString("hotelName");
			cout << name << endl;
			int price = res->getInt(2);
			cout << price << endl;
			string act = res->getString("hotelAct");
			cout << act << endl;
			cout << endl;

			// creating hotelNode object from those values
			hotelNode hotel = hotelNode(ids[i], name, price, act);

			// adding our object to our hotels vector
			hotels.push_back(hotel);

		}
		delete stmt; // delete at the end of each iteration before excueting query in next iteration
	} 

	delete con; // connection is no longer needed so delete and return our hotels vector
	
	ListofHotels = hotels;
}

void locationNode::loadRest(){
	//Using locId load in all restaurants into vector
}

void locationNode::viewMenu(){ 
	cout<<"You are at "<<locName<<endl;
	cout<<"Action Menu"<<endl;
	if(ListofHotels.size() != 0){
		cout<<"\t"<<"Hotels: View Hotels at current Location"<<endl;	
	}
	if(ListofRest.size() != 0){
		cout<<"\t"<<"Restaurants: View Hotels at current Location"<<endl;	
	}
	if(UniqueAct != ""){
		cout<<"\t"<<"Action: "<<UniqueAct<<endl;	
	}
	cout<<"\t"<<"Next: Go to next location"<<endl;
	cout<<"Please enter your choice:"<<endl;
}

void locationNode::visitHotels(int touristsNum, int &totalCost){
	//Display list of hotels
	//Loop asking user which hotel to stay at with -1 to end loop
		//Increate total depending on hotel price
}

void locationNode::eatAtRest(int touristsNum, int &totalCost){
	//Display list of restaurants
	//Loop asking user which restaurant to eat at with -1 to end loop
		//Increate total depending on restaurant price
}

void locationNode::uniqueAct(){
	cout<<UniqueAct<<endl;
	cout<<UniqueActDesc<<endl;
}

locationNode* locationNode::getNextLoc(){
	return NextLoc
}

void locationNode::setNextLoc(struct locationNode *newLoc){
	NextLoc = newLoc;
}





