
#ifndef DRIVER_H
#define DRIVER_H

#include "Entity.h"
#include "Distributor.h"


class Driver : public Entity {

    public:
        Driver(const string& name = "DefaultDriver", const Location& location = Location());

        bool isFree() const; //True if Driver has no orders in Queue

        Order* deliverOrder(); //returns next Order in Queue, else nullptr

        //sets Driver location to Distributor location
        //adds all Orders from Distributor Queue to Driver Queue
        void pickupOrders(Distributor& dist);

        void print() const; //print Driver info - id, name, location, num orders

        int getDistance(const Location& location);

private:
        static const char code = 'A'; //Driver prefix
        inline static int nextId = 1; //next ID# to pass into Entity ctor
};


#endif //DRIVER_H
