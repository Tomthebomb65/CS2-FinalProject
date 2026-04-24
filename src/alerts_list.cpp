#include "alerts_list.h"
#include <iostream>

//Default Constructor
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

//Destructor
LinkedList::~LinkedList() {
    AlertsNode* current = head;
    while (current != nullptr) {
        AlertsNode* temp = current;
        current = current->next;
        delete temp;
    }
}

//Insert at the beginning
void LinkedList::insert(const Alert& alert) {
    AlertsNode* newNode = new AlertsNode;
    newNode->data = alert;
    newNode->next = head;
    head = newNode;
    size++;
}

//Search by ID
Alert* LinkedList::search(int id) {
    AlertsNode* current = head;
    while (current != nullptr) {
        if (current->data.getId() == id) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

//Delete a node by ID
bool LinkedList::deleteNode(int id) {
    if (head == nullptr) {
        return false;
    }

    //If the head is the one to delete
    if (head->data.getId() == id) {
        AlertsNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    //Search through the list
    AlertsNode* current = head;
    while (current->next != nullptr) {
        if (current->next->data.getId() == id) {
            AlertsNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }

    return false;
}

//Getters
int LinkedList::getSize() const {
    return size;
}

AlertsNode* LinkedList::getHead() const {
    return head;
}