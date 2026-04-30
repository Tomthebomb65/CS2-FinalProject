#include "bst.h"
#include <iostream>

//Constructor
BST::BST() {
    root = nullptr;
    size = 0;
}

//Destructor
BST::~BST() {
    destroyTree(root);
}

//Delete Tree
void BST::destroyTree(BSTNode* node) {
    if (node == nullptr)
        return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node->data;
    delete node;
}

//Insert
BSTNode* BST::insert(BSTNode* node, System* system) {
    if (node == nullptr) {
        size++;
        return new BSTNode(system);
    }

    if (system->getId() < node->data->getId()) {
        node->left = insert(node->left, system);
    }
    else if (system->getId() > node->data->getId()) {
        node->right = insert(node->right, system);
    }
    else {
        return node;
    }

    return node;
}

bool BST::insert(System* system) {
    int before = size;
    root = insert(root, system);
    return size > before;
}

//Search
BSTNode* BST::search(BSTNode* node, int id) {
    if (node == nullptr)
        return nullptr;

    if (id == node->data->getId())
        return node;

    if (id < node->data->getId())
        return search(node->left, id);

    return search(node->right, id);
}

System* BST::search(int id) {
    BSTNode* result = search(root, id);
    return (result ? result->data : nullptr);
}

//Delete
BSTNode* BST::findMin(BSTNode* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

BSTNode* BST::remove(BSTNode* node, int id) {
    if (node == nullptr)
        return nullptr;

    if (id < node->data->getId()) {
        node->left = remove(node->left, id);
    }
    else if (id > node->data->getId()) {
        node->right = remove(node->right, id);
    }
    else {
    //Node found
    if (node->left == nullptr && node->right == nullptr) {
        delete node->data;
        delete node;
        size--;
        return nullptr;
    }
    else if (node->left == nullptr) {
        BSTNode* temp = node->right;
        delete node->data;
        delete node;
        size--;
        return temp;
    }
    else if (node->right == nullptr) {
        BSTNode* temp = node->left;
        delete node->data;
        delete node;
        size--;
        return temp;
    }
    else {
        //Two children
        BSTNode* minNode = findMin(node->right);

        *(node->data) = *(minNode->data);
        node->right = remove(node->right, minNode->data->getId());
    }
}

    return node;
}

bool BST::deleteNode(int id) {
    int before = size;
    root = remove(root, id);
    return size < before;
}

//Getters
int BST::getSize() const {
    return size;
}

BSTNode* BST::getRoot() const {
    return root;
}