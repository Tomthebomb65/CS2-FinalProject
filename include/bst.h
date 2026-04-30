#ifndef BST_H
#define BST_H

#include "ship_systems.h"

struct BSTNode {
    System* data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(System* s) {
        data = s;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;
    int size;

    BSTNode* insert(BSTNode* node, System* system);
    BSTNode* search(BSTNode* node, int id);
    BSTNode* remove(BSTNode* node, int id);
    BSTNode* findMin(BSTNode* node);
    void destroyTree(BSTNode* node);

public:
    BST();
    ~BST();

    bool insert(System* system);
    System* search(int id);
    bool deleteNode(int id);

    //Getters
    int getSize() const;
    BSTNode* getRoot() const;
};

#endif