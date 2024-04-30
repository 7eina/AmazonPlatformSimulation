
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Entity.h"
#include "Order.h"
#include "Distributor.h"
#include "Driver.h"
#include <vector>

using namespace std;


class Warehouse {

    public:
        Warehouse(); //ctor

        //adds new Driver w/ given params
        void addDriver(const string& name, const Location& loc);

        //adds new Distributor w/ given params
        void addDistributor(const string& name, const Location& loc);

        //makes new Order w/ given params
        //adds Order to Distributor - that is closest to given Location - Queue
        void takeOrder(const string& customerName, int menuItem, const Location& loc);

        /*
         * if Driver isFree():
         * adds all Orders from Distributor (w/ most Orders) Queue to Driver Queue
         * sets Driver location to Distributor location
         * & if all Distributors are empty, cout 'On Break' msg
         *
         * if Driver !isFree():
         * Removes next Order from Driver Queue
         * cout 'driver is delivering the order' msg
         * delete delivered Order
         * set driver location to Order location
         */
        void updateDrivers();

        void printDistributors() const; //print all Distributors
        void printDrivers() const; //print all Drivers

    private:
        vector<Driver*> drivers;
        vector<Distributor*> distributors;

        //returns Distributor w/ most Orders
        Distributor* getLargestDistributor() const;

        //returns Distributor closest to given Location
        Distributor* findClosestDistributor(const Location&) const;


};


#endif //WAREHOUSE_H
