#include "ship_systems.h"

struct BSTNode {
    System* data;
    BSTNode* left;
    BSTNode* right;
};

class BST {
    private:
        BSTNode* root;
        int size;

        bool insert(BSTNode* current, BSTNode* insertion);
        bool deleteTree(BSTNode* node);

    public:
        //Constructors and Destructor
        BST();
        BST(System* system);
        ~BST();
        
        //Insert, search, and delete operations
        bool insert(System* system);
        BSTNode* search(BSTNode* current, int id);
        bool deleteNode(BSTNode* current, int id);

        //Getters
        int getSize() const;
        BSTNode* getRoot() const;
};