// Purpose: Implementation of Driver class

#include "Driver.h"

Driver::Driver(const string& name, const Location& location)
       :Entity(code, nextId++, name, location) {}

bool Driver::isFree() const {
    return orders.isEmpty();
}

//return next Order in Queue
Order* Driver::deliverOrder() {
    if (isFree()) return nullptr;
    return orders.popFirst();
}

void Driver::pickupOrders(Distributor& dist) { //TODO: complete adding orders to driver queue
    setLocation(dist.getLocation().getX(), dist.getLocation().getY());
    dist.driverPickup(orders);
}

void Driver::print() const {
    cout << "Driver info:" << endl;
    Entity::print();
}

int Driver::getDistance(const Location& l) {
    this->location = l;
    return location.getDistance(l);
}
