#ifndef NODE_H
#define NODE_H
#include "iostream"

using namespace std;

class Node{
    private:
        int *value;
        Node *prevNode;
        Node *nextNode;
    public:
        Node();
        Node(int num);
        Node(const Node& otherNode);
        Node& operator =(const Node& otherNode);
        ~Node();

        //Accessor/Mutators
        void setVal(int num);
        int getVal() const;
        void setPrev(Node *newPrevNode);
        Node* getPrev() const;
        void setNext(Node *newNextNode);
        Node *getNext() const;
};


#endif
