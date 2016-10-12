/*
 * LinkedList.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: Brett Sackstein
 */

#include "LinkedList.h"

//Regular Constructor called
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    length = new int;
    *length = 0;
}

//Regular Constructor called with a head node already made
LinkedList::LinkedList(int val){
    Node *first = new Node(val);
    head = first;
    tail = first;
    length = new int;
    *length = 1;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList& otherList){
    head = new Node(otherList.head->getVal());
    tail = head;
    Node* iter = otherList.head->getNext();
    Node* currentNode = head;

    while(iter){
        currentNode->setNext(new Node(iter->getVal()));
        currentNode->getNext()->setPrev(currentNode);
        currentNode = currentNode->getNext();
        tail = currentNode;
        iter = iter->getNext();
    }
    length = new int;
    *length = otherList.getLength();
}

//Assignment Operator Overload
LinkedList& LinkedList::operator =(const LinkedList& otherList){
    //Make sure that you're not wasting resources by deleting and recopying itself
    if(this != &otherList){
        //Delete all previous nodes of the list until it is all NULL again, preventing memory leak
        while(head){
            Node* iter = head->getNext();
            delete(head);
            head = iter;
        }

        head = new Node(otherList.head->getVal());
        tail = head;
        Node* iter = otherList.head->getNext();
        Node* currentNode = head;

        while(iter){
            currentNode->setNext(new Node(iter->getVal()));
            currentNode->getNext()->setPrev(currentNode);
            currentNode = currentNode->getNext();
            tail = currentNode;
            iter = iter->getNext();
        }
        *length = otherList.getLength();
    }
    return *this;
}

//Destructor
LinkedList::~LinkedList(){
    Node* iter = head;
    Node* dummy = head;
    delete length;
    while(iter){
        iter = iter->getNext();
        delete(dummy);
        dummy = iter;
    }
}

//Returns a dereferenced integer pointer, or the value of the List's size
int LinkedList::getLength() const{
    return *length;
}

void LinkedList::setLength(int size){
    *length = size;
}

//Appends a new Node to the end of the Linked List
bool LinkedList::addNode(int val){
    //If the list was initialized without a node value
    if(!head && !tail){
        head = new Node(val);
        tail = head;
        setLength(getLength() + 1);
        return true;
    //There is at least one value in the list
    }else{
        Node *prev = tail;
        tail->setNext(new Node(val));
        tail = tail->getNext();
        tail->setPrev(prev);
        setLength(getLength() + 1);
        return true;
    }
}

//Appends a new Node to the end of the Linked List
bool LinkedList::addNode(int val, int index){
    Node* insertNode = new Node(val);

    //If the list was initialized without a node value
    if(!head && !tail){//Essentially if length is 0
        head = insertNode;
        tail = head;
        setLength(getLength() + 1);
        return true;
    //There is at least one value in the list
    }else if(index == 0){ //0 implies append to front
        head->setPrev(insertNode);
        insertNode->setNext(head);
        head = insertNode;
        setLength(getLength() + 1);
        return true;
    }else if(index == *length){ //Same length implies append to end
        tail->setNext(insertNode);
        insertNode->setPrev(tail);
        tail = insertNode;
        setLength(getLength() + 1);
        return true;
    }else{//Else we're appending somehwere that is inbetween two values
        Node* iter = head;
        //Iterate up until the index we wish to insert at, luckily we error check the bounds
        //so we don't have to worry about going out of bounds and causing a Segmentation Fault
        for(int i = 0; i < index; i++){
            iter = iter->getNext();
        }
        //This is the the most difficult concept to follow.
        //When there is a value inserted between two nodes
        //you need to fix up all of the next and previous Node pointers.
        //First, make the new node's previous pointer set equal to the current
        //iterator's previous pointer.
        //You'll have something that looks like this...
        insertNode->setPrev(iter->getPrev());



        //Oh no! Both the new node and the old one have the same previous value now!
        //Don't worry we'll clean that up in a second.
        //Next, we have to set the previous node's next pointer to our new node
        //instead of letting it be set equal to the old pointer that gets pushed over an index.
        //You'll have something that looks like this...
        insertNode->getPrev()->setNext(insertNode);



        //We're almost done! Now we have to clean up our new pointer's next value
        //by setting it equal to that iterator value that it's replacing.
        //Simply set our new node's next pointer to the iterator.
        //You'll have something that looks like this...
        insertNode->setNext(iter);



        //Finally, the last step. We have to clean up our iterator!
        //Its previous pointer is still pointing to the old previous value.
        //Simply set your iterator's previous pointer to the new node we made.
        //And then you'll you have something that looks like this...
        iter->setPrev(insertNode);



        //And what would you know!? The diagram finally looks like a normal Linked List again!
        //This is one of the most difficult concepts to wrap your head around.
        //Play around with the insert and try to understand why 4 pointer values needed
        //to be altered in order to make this work.
        //What would happen if you missed one of these steps?
        setLength(getLength() + 1);
        return true;
    }
}

//Looks through List for a number match and removes one match
int LinkedList::removeOneNode(int val){
    return remove(val, false);
}

//Looks through List for a number match and removes all matches
int LinkedList::removeAllNodes(int val){
    return remove(val, true);
}

int LinkedList::remove(int val, bool multiple){
    int count = 0;
    Node* iter = head;
    bool foundValue = false;

    //Loop through all of the Nodes
    while(iter && !foundValue){
        Node *prev = iter->getPrev();
        Node *next = iter->getNext();
        //Value match
        if(iter->getVal() == val){
            //To change the boolean depending on if we're deleting one or all matches
            if(!multiple){
                foundValue = true;
            }
            //If node has a previous and next node, then isn't a head node or tail
            if(prev && next){
                //cout << "Here 1" << endl;
                prev->setNext(next);
                next->setPrev(prev);
                delete iter;
            //There is a previous value, but no next, must be deleting the tail
            }else if(prev && !next){
                //cout << "Here 2" << endl;
                tail = prev;
                tail->setNext(nullptr);
                delete iter;
            //There is no previous, but there is a next, must be deleting the head
            }else if(!prev && next){
                //cout << "Here 3" << endl;
                head = next;
                head->setPrev(nullptr);
                delete iter;
            //Must be deleting the only value left
            }else{
                //cout << "Here 4" << endl;
                delete iter;
                iter = nullptr;
                head = nullptr;
                tail = nullptr;
            }
            setLength(getLength() - 1);
            count++;
        }
        iter = next;
    }
    return count;
}

//Neatly prints the list in a way that looks similar to a standard library array.
string LinkedList::printList(){
    string retString = "";
    //So long as the length is more than 0, there must be an element to print.
    if(*length > 0){
        Node* iter = head;
        cout << "[";
        retString += "[";
        //To loop  through the entire list
        while(iter){
            //Add a comma and space if there's a value after the current one,
            if(iter->getNext()){
                cout << iter->getVal() << ", ";
                retString += to_string(iter->getVal());
                retString += ", ";
            //otherwise it is the last number to print.
            }else{
                cout << iter->getVal();
                retString += to_string(iter->getVal());
            }
            //To change nodes
            iter = iter->getNext();
        }
        cout << "]" << endl;
        retString += "]";
    }else{
        cout << "List is empty" << endl;
        retString = "List is empty.";
    }
    return retString;
}

//Neatly prints the list backwards in a way that looks similar to a standard library array.
string LinkedList::printReverseList(){
    string retString = "";
    //So long as the length is more than 0, there must be an element to print.
    if(*length > 0){
        //Start at the tail instead
        Node* iter = tail;
        cout << "[";
        retString += "[";
        //To loop  through the entire list
        while(iter){
            //Add a comma and space if there's a value after the current one,
            if(iter->getPrev()){
                cout << iter->getVal() << ", ";
                retString += to_string(iter->getVal());
                retString += ", ";
            //otherwise it is the last number to print.
            }else{
                cout << iter->getVal();
                retString += to_string(iter->getVal());
            }
            //To change nodes
            iter = iter->getPrev();
        }
        cout << "]" << endl;
        retString += "]";
    }else{
        cout << "List is empty" << endl;
        retString = "List is empty.";
    }
    return retString;
}

//Returns the last node of the list
Node* LinkedList::getTail(){
    return tail;
}

//Returns the first node of the list
Node* LinkedList::getHead(){
    return head;
}


//Auxiliary print that additionally gives the head, tail, length, and entire list neatly
string LinkedList::printAll(){
    string retString = "";
    cout << "--------------------------" << endl;
    if(*length > 0){
        cout << "Head: " << head->getVal() << endl;
        cout << "Tail: " << tail->getVal() << endl;
        cout << "Length: " << *length << endl;
        printList();
        retString += "Head: ";
        retString += to_string(head->getVal());
        retString += "\nTail: ";
        retString += to_string(tail->getVal());
        retString += "\nLength: ";
        retString += to_string(*length);
        retString += "\n";
        retString += printList();

    }else{
        cout << "List is empty" << endl;
        retString = "List is empty.";
    }
    return retString;
}
