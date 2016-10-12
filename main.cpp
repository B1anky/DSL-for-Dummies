#include "mainwindow.h"


void testList();
void testingAdding();
void testingDeletingAll(LinkedList toDelete);
void testingDeletingOne(LinkedList toDelete);

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //testList();

    return 0;
}

//Stress tests the list class
void testList(){
    srand(time(NULL));
    for(int i = 0; i < 50; i++)
        testingAdding();
}

void testingAdding(){
    LinkedList list;
    int randLength = rand() % 20 + 1;
    for(int i = 0; i < randLength; i++){
        int valToAdd = rand() % 10 + 1;
        list.addNode(valToAdd);
    }
    list.printAll();
    //Utilizes the copy constructor when passing through the function, so both deletes don't affect each other
    testingDeletingAll(list);
    testingDeletingOne(list);

}

//Deletes a single instance of 1, 2, and 5
void testingDeletingOne(LinkedList toDelete){
    cout << "Deleting a single 1, 2, and 5!" << endl;
    toDelete.removeOneNode(1);
    toDelete.removeOneNode(2);
    toDelete.removeOneNode(5);
    toDelete.printAll();
}

//Deletes all instances of all possible numbers
void testingDeletingAll(LinkedList toDelete){
    cout << "Deleting entire list!" << endl;
    for(int i = 1; i < 11; i++){
        toDelete.removeAllNodes(i);
    }
    toDelete.printAll();
}


