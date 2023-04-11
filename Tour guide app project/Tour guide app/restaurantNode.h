#include<iostream>
#include<string>
#include<vector>
#include <map>

using namespace std;

class restaurantNode {
private:
    int restaurantId;
    string restaurantName;
    double restaurantPrice;
    string restaurantAct;
    struct restaurantNode *NextLoc;

public:
    restaurantNode();
    restaurantNode(int id, string name, double price, string act) {
        this->restaurantId = id;
        this->restaurantName = name;
        this->restaurantPrice = price;
        this->restaurantAct = act;
    }
    int getId() {
        return restaurantId;
    }
    string getName() {
        return restaurantName;
    }
    double getPrice() {
        return restaurantPrice;
    }
    string getAct() {
        return restaurantAct;
    }
    void setId(int id) {
        this->restaurantId = id;
    }
    void setName(string name) {
        this->restaurantName = name;
    }
    void setPrice(double price) {
        this->restaurantPrice = price;
    }
    void setAct(string act) {
        this->restaurantAct = act;
    }

};

