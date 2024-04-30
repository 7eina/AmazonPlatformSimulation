
#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include "Entity.h"


class Distributor : public Entity {

    public:
        //ctor
        Distributor(const string& name = "DefaultDistributor",
                    const Location& location = Location(0, 0));

        //creates new Order and adds to Distributor Queue
        void acceptOrder(const string& custName, int product, const Location& loc);

        //transfers all Order from Distributor Queue to Driver Queue
        void driverPickup(Queue& o);

        void print() const; //print Distributor info - id, name, location, num orders

    private:
        static const char code = 'B'; //Distributor prefix
        inline static int nextId = 1; //next ID# to pass into Entity ctor
};


#endif //DISTRIBUTOR_H
