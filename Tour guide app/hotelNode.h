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
    hotelNode(int id, string name, double price, string act);
};

hotelNode::hotelNode(){
    return;
}


