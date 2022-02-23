//cards.cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards.h
#include "cards.h"
#include "utility.h"
using namespace std;
#include <iostream>
using std::cout;

cards::cards(char s, char v){
    suit=s;
    value=v;
}

int cards::getValue(){
    int a=0;
    int b=0;
    if (suit=='h') a=400;
    else if (suit=='s') a=300;
    else if (suit =='d') a=200;
    else a=100;
    if (value=='a') b=1;
    else if(value=='j') b=11;
    else if (value=='q') b=12;
    else if (value=='k') b=13;
    else b=value-48;
    return a+b;
}

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert
bool IntBST::insert(int value) {
    if (!root) {
	root = new Node(value);
	return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}
int IntBST::min(){
    Node* n=root;
    if (!n){
        return 0;
    }
    while (n->left){
        n=n->left;
    }
    return n->info;
}
int IntBST::max(){
    Node* n=root;
    if (!n){
        return 0;
    }
    while (n->right){
        n=n->right;
    }
    return n->info;
}
void IntBST::printInOrder() const {
    printInOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printInOrder(Node *n) const {
    if (n) {
	printInOrder(n->left);
    printCard(n->info);
	printInOrder(n->right);
    }
}
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {    
    printCard(n->info);
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    while(n){
        if(n->info == value){
            return n;
        }
        if(n->info < value){
           n = n->right;
        }
        if(n->info > value){
           n = n->left;
        }
    }
    return nullptr;
}

// find
bool IntBST::contains(int value) const {
    Node* n=root;
    while(n){
        if (n->info==value){
            return true;
        }
        if (n->info>value){
            n=n->left;
        }
        else{
            n=n->right;
        }
    }
    return false; 
}

// returns the Node containing the predecessor of the given value
    IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* n=root;
    while(n){
        if (n->info==value){
            if (!n->left){
                if (!n->parent) return nullptr;
                n=n->parent;
                if (n->info>value)
                    return nullptr;
                while(n->parent){
                    if (n->parent->info<value&&n->parent->info>n->info)
                    n=n->parent;
                    else;
                    break;
                }
                return n;
            }
            n=n->left;
            while(n->right){
                n=n->right;
            }
            return n;
        }
        if (n->info>value){
            n=n->left;
        }
        else{
            n=n->right;
        }
    }
    return nullptr;
}

  


// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* n=root;
    while(n){
        if (n->info==value){
            if (!n->left){
                if (!n->parent) return 0;
                n=n->parent;
                while(n){
                    if (n->info>value){
                        n=n->parent;
                    }else{
                        return n->info;
                    }
                }
                return 0;
            }
            n=n->left;
            while(n->right){
                n=n->right;
            }
                return n->info;
        } 
        if (n->info<value){
            n=n->right;
        }
        else{
            n=n->left;
        }
    }
    return 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* n=root;
    while(n){
        if (n->info==value){
            if (!n->right){
                if (!n->parent) return nullptr;
                n=n->parent;
                if (n->info<value)
                    return nullptr;
                while(n->parent){
                    if (n->parent->info>value&&n->parent->info<n->info)
                    n=n->parent;
                    else;
                    break;
                }
                return n;
            }
            n=n->right;
            while(n->left){
                n=n->left;
            }
            return n;
        }
        if (n->info>value){
            n=n->left;
        }
        else{
            n=n->right;
        }
    }
    return NULL; 
}

// successor
int IntBST::getSuccessor(int value) const{
    Node* n=root;
    while(n){
        if (n->info==value){
            if (!n->right){
                if (!n->parent) return 0;
                n=n->parent;
                while(n){
                    if (n->info<value){
                        n=n->parent;
                    }else{
                        return n->info;
                    }
                }
                return 0;
            }
            n=n->right;
            while(n->left){
                n=n->left;
            }
                return n->info;
        } 
        if (n->info>value){
            n=n->left;
        }
        else{
            n=n->right;
        }
    }
    return 0;
}

// delete

bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if(!n){return false;}
    root->parent=nullptr;
    if((!n->right) && (!n->left)){
        if(!n->parent){
            root = nullptr;
        }
        else if(n->parent->left == n){
            n->parent->left = nullptr;
        }
        else if(n->parent->right == n){
            n->parent->right = nullptr;
        }
      delete n;
      return true;
    }
    if((!n->right) && (n->left)){
        if(!n->parent){
            root = n->left;
        }
        if(n->parent->left == n){
            n->parent->left = n->left;
        }
        if(n->parent->right == n){
            n->parent->right = n->left;
        }
        n->left->parent=n->parent;
        delete n;
        return true;
    }
    if((n->right) && (!n->left)){
        if(!n->parent){
            root = n->right;
            delete n;
            return true;
        }
        if(n->parent->left == n){
            n->parent->left = n->right;
        }
        if(n->parent->right == n){
            n->parent->right = n->right;
        }
        n->right->parent=n->parent;
        delete n;
        return true;
    }
    if((n->right) && (n->left)){
        Node* suc = getSuccessorNode(n->info);
        int temp = suc->info;
        remove(temp);
        n->info = temp;
        return true;
    }
    return false;
}

