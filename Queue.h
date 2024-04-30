
#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h"

class Queue {

    class Node {
        public:
            Order* data;
            Node* next;
    };

    public:
        Queue(); //ctor
        ~Queue(); //dtor

        //true if Queue is empty
        bool isEmpty() const;

        //returns Queue size
        int getSize() const;

        //returns first Order in Queue, nullptr otherwise
        const Order* peekFirst() const;

        //removes first Order in Queue & returns it, nullptr otherwise
        Order* popFirst();

        //adds Order to back of Queue
        void addLast(Order* order);

        //remove Orders from queue and add them to this Queue
        void addAll(Queue& queue);

    private:
        Node* head;
        Node* tail;
        int size;

};


#endif //QUEUE_H
