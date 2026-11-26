#include <iostream>
#include "Orders.h"
#include<string>
using namespace std;
 
string Orders::getOrderId() { return orderId; }
double Orders::getCost() { return cost; }
void Orders::setOrderId(string id) { orderId = id; cout << "set successfully"; }
void Orders::setCost(double newcost) { cost = newcost; cout << "cost set successfully"; }
//void Orders::addMobile(const Mobile& m) { mobiles.insertEnd(m); }

