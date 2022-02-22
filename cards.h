//cards.h
//Authors: Maya Ma
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
using namespace std;

class cards{
    private:
        char suit;
        char value;
    public:
        cards(char s, char v);
        int getValue();
};

class IntBST {
 public:
    IntBST();                   // constructor
    ~IntBST();                  // destructor
    bool insert(int value);     // insert
    bool contains(int value) const;  // find
    int getPredecessor(int value) const;       // predecessor
    int getSuccessor(int value) const;         // successor
    bool remove(int value);                    // delete
    void printInOrder() const;
    void printPreOrder() const;
    int min();
    int max();
 
 private:
    struct Node {
	int info;
	Node *left, *right, * parent;
    Node(int v=0) : info(v), left(0), right(0), parent(0) { }
    };
    Node *root;
    Node* getNodeFor(int value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); // note overloading names for simplicity
    Node* getSuccessorNode(int value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(int value) const; // returns the Node containing the predecessor of the given value 
    void printInOrder(Node *n) const;
    void printPreOrder(Node *n) const;
};
#endif
