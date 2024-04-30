
#include "Order.h"

//ctor
Order::Order(const string& customer, int id, const Location& address)
      : name(customer), prodId(id), location(address) {}

//return location
Location* Order::getLocation() const {
    return (Location*)&location;
}

//print customer name and product
void Order::print() const {
    cout << "Customer: " << name << ", ordered: " << PRODUCTS[prodId] << endl;
}
