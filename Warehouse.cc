// Purpose: Implementation of Warehouse class

#include "Warehouse.h"

Warehouse::Warehouse() {}

void Warehouse::addDriver(const string& name, const Location& loc) {
    Driver* driver = new Driver(name, loc);
    drivers.push_back(driver);
}

void Warehouse::addDistributor(const string& name, const Location& loc) {
    Distributor* dist = new Distributor(name, loc);
    distributors.push_back(dist);
}

void Warehouse::takeOrder(const string& customerName, int menuItem, const Location& newLoc) {
    findClosestDistributor(newLoc)->acceptOrder(customerName, menuItem, newLoc);
}

void Warehouse::updateDrivers() {
    for (Driver* d : drivers) {
        if (d->isFree()) {
            if (getLargestDistributor()->getNumOrders() == 0) {
                cout << "Driver " << d->getName() << " is taking a lunch break" << endl;
            }
            d->setLocation(getLargestDistributor()->getLocation().getX(), getLargestDistributor()->getLocation().getY());
            cout << "Driver " << d->getName() << " is picking up orders from " << getLargestDistributor()->getName() << endl;
            d->pickupOrders(*getLargestDistributor());
        } else {
            Order* o = d->deliverOrder();
            d->setLocation(o->getLocation()->getX(), o->getLocation()->getY());
            cout << "Driver " << d->getName() << " is delivering an order" << endl;
        }
    }
}

void Warehouse::printDistributors() const {
    for (Distributor* d : distributors) {
        d->print();
    }
}

void Warehouse::printDrivers() const {
    for (Driver* d : drivers) {
        d->print();
    }
}


// Helper functions

Distributor* Warehouse::findClosestDistributor(const Location& loc) const {

    int curDistance = distributors[0]->getLocation().getDistance(loc);
    int i = 0;
    int minDistance = i;
    for (Distributor* d : distributors) {
        int temp = d->getLocation().getDistance(loc);
        if (temp < curDistance) {
            curDistance = temp;
            minDistance = i;
        }
        ++i;
    }
    return distributors[minDistance];
}

Distributor* Warehouse::getLargestDistributor() const {
    int curSize = 0;
    int i = 0;
    int maxOrders = i;
    for (Distributor* d : distributors) {
        if (d->getNumOrders() > curSize) {
            curSize = d->getNumOrders();
            maxOrders = i;
        }
        ++i;
    }
    return distributors[maxOrders];
}
