#include<iostream>
#include<string>
#include<vector>

using namespace std;

class locationNode{
	private:
		int locId;
		string locName;
		string locDesc;
		vector <int> ListofHotels;
		vector <int> ListofRest;
		string UniqueAct;
		string UniqueActDesc;
		struct locationNode *NextLoc;

	public:
		void loadHotels(); //Using id load in hotel data as a dict (Maybe create new class?)
		void loadRest(); //Same
		void viewMenu(); //Print a mneu of actions to do, view hotels, view rest, unique act name, go to next loc (Onlyn if not empty)
		void visitHotels(); //Show list of hotels and ask user which one to stay at, -1 to exit
		void eatAtRest(); //Same
		void uniqueAct(); //Print unique act and unique act description
		locationNode* getNextLoc(); //Return nextloc pointer
};
