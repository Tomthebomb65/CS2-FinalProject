#ifndef ALERTS_LIST_H
#define ALERTS_LIST_H

#include "alerts.h"

struct AlertsNode {
    Alert data;
    AlertsNode* next;
};

class LinkedList {
    private:
        AlertsNode* head;
        int size;

    public:
        //Constructor and Destructor
        LinkedList();
        ~LinkedList();

        //Insert, search, and delete operations
        void insert(const Alert& alert);
        Alert* search(int id);
        bool deleteNode(int id);

        //Getters
        int getSize() const;
        AlertsNode* getHead() const;
};
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 1f3b703d3c55e8f614bed6a6dd1353d7914ef686
