
#include "Queue.h"

Queue::Queue() : head(nullptr), tail(nullptr), size(0) {}

Queue::~Queue() {
    Node* curr = head;
    Node* prev;

    while (curr != tail) {
        prev = curr;
        curr = curr->next;
        delete prev;
        size--;
    }

}

bool Queue::isEmpty() const {
    return size == 0;
}

int Queue::getSize() const {
    return size;
}

const Order* Queue::peekFirst() const {
    if (isEmpty()) return nullptr;
    return head->data;
}

Order* Queue::popFirst() {
    if (isEmpty()) return nullptr;

    Node* curr = head;
    head = head->next;

    Order* o = curr->data;
    delete curr;
    size--;

    if (size == 0) {
        tail = nullptr;
    }

    return o;
}

void Queue::addLast(Order* order) {
    if (isEmpty()) {
        Node* newNode = new Node;
        newNode->data = order;
        newNode->next = nullptr;
        head = tail = newNode;
        tail->next = nullptr;
        size++;
        return;
    }

    Node* newNode = new Node;
    newNode->data = order;
    newNode->next = nullptr;

    tail->next = newNode;
    tail = newNode;

    size++;
}

void Queue::addAll(Queue& queue) {
    if (queue.isEmpty()) return;

    if (head == nullptr) {
        head = queue.head;
        tail = queue.tail;
        size = queue.getSize();
    }
    else {
        tail->next = queue.head;
        tail = queue.tail;
        size = size + queue.size;
    }

    queue.head = nullptr;
    queue.tail = nullptr;
    queue.size = 0;
}