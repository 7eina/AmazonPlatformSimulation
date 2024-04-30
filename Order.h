
#ifndef ORDER_H
#define ORDER_H

#include "Location.h"
#include "defs.h"

class Order {

    public:

        Order(const string& name, int id, const Location& location); //ctor

        //location getter
        Location* getLocation() const;

        void print() const; //print customer name and product

        inline static const string PRODUCTS[NUM_PRODUCTS] =
                {"Bike", "Book", "Brush", "Camera", "Computer",
                 "TV", "Skateboard","Tie", "Unicycle", "Table"};


    private:
        string name; //customer name
        int prodId; //ordered product id
        Location location; //delivery location

};


#endif //ORDER_H
