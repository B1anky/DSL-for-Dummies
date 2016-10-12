#include "Node.h"

//Regular Constructor
Node::Node(){
    value = new int;
    *value = 0;
    nextNode = nullptr;
    prevNode = nullptr;
}

//Regular Constructor with starting number
Node::Node(int num){
    value = new int;
    *value = num;
    nextNode = nullptr;
    prevNode = nullptr;
}

//Copy Constructor
Node::Node(const Node& otherNode){
    value = new int;
    *value = otherNode.getVal();
    nextNode = nullptr;
    prevNode = nullptr;
}

//Assignment Operator Overload
Node& Node::operator =(const Node& otherNode){
    delete value;
    value = new int;
    *value = otherNode.getVal();
    return *this;
}

//Destructor
Node::~Node(){
    delete value;
}

//Sets the value of the node
void Node::setVal(int num){
    *value = num;
}

//Returns a dereferenced integer pointer, or the value the Node contains
int Node::getVal() const{
    return *value;
}

//Sets the Node prior to the current one
void Node::setPrev(Node *newPrevNode){
    prevNode = newPrevNode;
}

//Returns a Node pointer to the node prior to the current one
Node* Node::getPrev() const{
    return prevNode;
}

//Sets the Node after the current one
void Node::setNext(Node *newNextNode){
    nextNode = newNextNode;
}

//Returns the Node after the current one
Node* Node::getNext() const{
    return nextNode;
}

