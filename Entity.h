
#ifndef ENTITY_H
#define ENTITY_H

#include "Location.h"
#include "Queue.h"


class Entity {

    public:
        Entity(char type, int num, const string& entName, const Location& entLocation);

        //Location setter
        void setLocation(int x, int y);

        //getters
        Location getLocation() const; //return location
        string getName() const; //return name
        string getId() const; //return id

        //returns number of Orders this Entity has in its Queue
        int getNumOrders() const;

        //True if this Entity::id matches the given id
        bool equals(const string& entId) const;

        void print() const; //print Entity info - id, name, location, num orders

    protected:
        string id;  //unique Entity ID
        string name; //Driver or Distibutor name
        Location location; //Entity location

        //orders @ Dist awaiting pickup by Driver
        //or order currently being delivered by a Driver
        Queue orders;

};


#endif //ENTITY_H
