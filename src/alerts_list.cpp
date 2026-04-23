#include "alerts_list.h"
#include <cstring>

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