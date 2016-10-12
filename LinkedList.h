#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList{
    private:
        Node *head;
        Node *tail;
        int *length;
    public:
        //constructors
        LinkedList();
        LinkedList(int val);
        //copy constructor
        LinkedList(const LinkedList& otherList);
        //assignment operator
        LinkedList& operator =(const LinkedList& otherList);
        //destructor
        ~LinkedList();
        //Accessor/Mutators
        int getLength() const;
        void setLength(int size);
        Node* getTail();
        Node* getHead();
        bool addNode(int val);
        bool addNode(int val, int index);
        int removeOneNode(int val);
        int remove(int val, bool multiple);
        int removeAllNodes(int val);
        //Console helpers for checking correct values
        string printList();
        string printReverseList();
        string printAll();
};

#endif
