
#include "Distributor.h"

Distributor::Distributor(const string& name, const Location& location)
            :Entity(code, nextId++, name, location){}

void Distributor::acceptOrder(const string& custName, int product, const Location& loc) {
    Order* o = new Order(custName, product, loc);
    orders.addLast(o);
}

void Distributor::driverPickup(Queue& o) {
    o.addAll(orders);
}

void Distributor::print() const {
    cout << "Distributor info:" << endl;
    Entity::print();
}