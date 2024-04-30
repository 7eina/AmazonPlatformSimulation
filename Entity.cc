// Purpose: Implementation of Entity class

#include "Entity.h"

Entity::Entity(char type, int num, const string& entName, const Location& entLocation) {
    id = type + to_string(num);
    name = entName;
    location = Location(location.getX(), location.getY());
    location = entLocation;
    orders = Queue();
}

void Entity::setLocation(int x, int y) {
    location.setLocation(x, y);
}

Location Entity::getLocation() const { return location; }

string Entity::getName() const { return name; }

string Entity::getId() const { return id; }

int Entity::getNumOrders() const { return orders.getSize(); }

bool Entity::equals(const string& entId) const {
    return entId == id;
}

void Entity::print() const {
    cout << "Name: " << name << ", ID: " << id << ", Location: ";
    location.print();
    cout << ", # Orders: " << getNumOrders() << endl;
}