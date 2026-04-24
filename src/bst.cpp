#include "bst.h"
#include <iostream>

//Default Constructor
BST::BST() {
    root = nullptr;
    size = 0;
}

//Parameterized Constructor
BST::BST(System* system) {
    root = new BSTNode{system, nullptr, nullptr};
    size = 1;
}

//Destructor
BST::~BST() {
    deleteTree(root);
}

//Recursively delete all nodes
bool BST::deleteTree(BSTNode* node) {
    if (node == nullptr) {
        return false;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node->data;  //delete System*
    delete node;        //delete node itself

    return true;
}

//Insert helper (iterative)
bool BST::insert(BSTNode* current, BSTNode* insertion) {
    if (current == nullptr || insertion == nullptr) {
        return false;
    }

    while (true) {
        if (insertion->data->getId() < current->data->getId()) {
            if (current->left == nullptr) {
                current->left = insertion;
                return true;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = insertion;
                return true;
            }
            current = current->right;
        }
    }
}

// Public insert
bool BST::insert(System* system) {
    BSTNode* newNode = new BSTNode{system, nullptr, nullptr};

    if (root == nullptr) {
        root = newNode;
        size = 1;
        return true;
    }

    bool success = insert(root, newNode);
    if (success) {
        size++;
    }

    return success;
}

//Recursive search
BSTNode* BST::search(BSTNode* current, int id) {
    if (current == nullptr) {
        return nullptr;
    }
    if (id == current->data->getId()) {
        return current;
    }
    if (id < current->data->getId()) {
        return search(current->left, id);
    }
    return search(current->right, id);
}

//Delete a node by ID
bool BST::deleteNode(BSTNode* current, int id) {
    BSTNode* parent = nullptr;
    BSTNode* node = current;

    //Search for node
    while (node != nullptr && node->data->getId() != id) {
        parent = node;
        if (id < node->data->getId()) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    if (node == nullptr) {
        return false;
    }

    //Node has two children
    if (node->left != nullptr && node->right != nullptr) {
        //Find inorder successor
        BSTNode* successorParent = node;
        BSTNode* successor = node->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        node->data = successor->data;

        node = successor;
        parent = successorParent;
    }

    //Node has 0 or 1 child
    BSTNode* child = (node->left != nullptr) ? node->left : node->right;

    if (parent == nullptr) {
        root = child;
    }
    else if (parent->left == node) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    delete node->data;
    delete node;
    size--;

    return true;
}

//Getters
int BST::getSize() const {
    return size;
}

BSTNode* BST::getRoot() const {
    return root;
}
