#include<iostream>
#include<string>
#include<vector>
#include <map> 

using namespace std;

class locationNode{
	private:
		int locId;
		string locName;
		string locDesc;
		vector <map<string, string>> ListofHotels;
		vector <map<string, string>> ListofRest;
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
	//Using locId load in all hotels into vector
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





