#include<iostream>
#include<string>
#include<vector>
#include <map>

using namespace std;

class hotelNode{
private:
    int hotelId;
    string hotelName;
    double hotelPrice;
    string hotelAct;
    struct hotelNode *NextLoc;

public:
    hotelNode();
    hotelNode(int id, string name, double price, string act) {
	    this->hotelId = id;
	    this->hotelName = name;
	    this->hotelPrice = price;
	    this->hotelAct = act;
	}
    int getId(){
        return hotelId;
    }
    string getName(){
        return hotelName;
    }
    double getPrice(){
        return hotelPrice;
    }
    string getAct(){
        return hotelAct;
    }
    void setId(int id){
        this->hotelId=id;
    }
    void setName(string name){
        this->hotelName=name;
    }
    void setPrice(double price){
        this->hotelPrice=price;
    }
    void setAct(string act){
        this->hotelAct=act;
    }

};


