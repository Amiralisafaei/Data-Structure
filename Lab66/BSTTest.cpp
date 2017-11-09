/*
 * BSTTest.cpp
 *
 *  		Created on: November 7, 2017
 *      Duc Nguyen & Amirali Safaei
 *		CIS 22C, Lab 6
 *		Instructor: Jennifer Parrish
 */


#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    int x=0;
    bool y=true;
    cout << "Going to Test all ASSERTS\n";
    cout << "\tJust created Tree1\n";
    BST<int> tree1;
    cout << "\t\tTesting \"GetRoot Assert\" (Program should crash): (DONE)\n";
//    x = tree1.getRoot();
//    cout << x;
    cout << "\t\tTesting \"Maximum Assert\" (Program should crash): (DONE)\n";
//    x = tree1.maximum();
//    cout << x;
    cout << "\t\tTesting \"Minimum Assert\" (Program should crash): (DONE)\n";
//    x = tree1.minimum();
//    cout << x;
    cout << "\t\tTesting \"Remove Assert\" (Program should crash): (DONE)\n";
    cout << "\t\t\tGoing to attempt to remove \"3\" in an empty list\n";
//    tree1.remove(3);
    cout << "\t\tTesting \"Search Assert\" (Program should crash): (DONE)\n";
    cout << "\t\t\tGoing to attempt to look for \"3\" in an empty list\n";
//    y = tree1.search(3);
//    cout << y;

    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to Test INSERT\n";
    cout << "\tBefore Inserting, what is the size? (Should be 0): " << tree1.getSize() << " (DONE)"<< endl;
    cout << "\tBefore Inserting, what is the height? (Should be 0): " << tree1.getHeight() << " (DONE)"<< endl;
    cout << "\tNow going to Insert\n";
    tree1.insert(15);
    tree1.insert(6);
    tree1.insert(3);
    tree1.insert(4);
    tree1.insert(2);
    tree1.insert(7);
    tree1.insert(13);
    tree1.insert(9);
    tree1.insert(18);
    tree1.insert(17);
    tree1.insert(20);
    cout << "\t\tTesting \"Size\" (Should be \"11\"): " << tree1.getSize() << " (DONE)" << endl;
    cout << "\t\tTesting \"GetRoot\" (Should be \"15\"): " << tree1.getRoot() << " (DONE)" << endl;
    cout << "\t\tTesting \"Insert Duplicate if\" (Should display a message): ";
    tree1.insert(20);

    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to test all PRINTS\n";
    cout << "\tPreOrder: ";
    tree1.preOrderPrint(cout);
    cout << "\tIn Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tPostOrder: ";
    tree1.postOrderPrint(cout);
    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to test Copy Constructor\n";
    cout << "\tCreating tree2 with tree1\n";
    BST<int> tree2(tree1);
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to test Height, Maximum, Minimum\n";
    cout << "\tTesting \"Height\" of tree1 (Should be \"4\"): " << tree1.getHeight() << " (DONE)" << endl;
    cout << "\tTesting \"Maximum\" of tree1 (Should be \"20\"): " << tree1.maximum() << " (DONE)" << endl;
    cout << "\tTesting \"Minimum\" of tree2 (Should be \"2\"): " << tree1.minimum() << " (DONE)" << endl;
    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to test Search\n";
    cout << "\tIs the \"7\" in tree1? (Should be true): " << boolalpha << tree1.search(7) << " (DONE)"<< endl;
    cout << "\tIs the \"8\" in tree1? (Should be false): " << boolalpha << tree1.search(8) << " (DONE)"<< endl;
    for (int x = 1; x < 100; x++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "Going to test Remove/DeleteNode\n";
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    cout << "\t\tGoing to delete tree1 \"20\" (Leaf): " << endl;
    tree1.remove(20);
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    cout << "\t\tGoing to delete tree1 \"7\" (1 Right Child): " << endl;
    tree1.remove(7);
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    cout << "\t\tGoing to delete tree1 \"13\" (1 left Child): " << endl;
    tree1.remove(13);
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    cout << "\t\tGoing to delete tree1 \"15\" (The Root with 2 kids): " << endl;
    tree1.remove(15);
    cout << "\tTree1 In Order: ";
    tree1.inOrderPrint(cout);
    cout << "\t\tWhat is tree1 new root?(Should be \"17\"): " << tree1.getRoot() << " (DONE)" << endl;
    cout << "\tTree2 In Order: ";
    tree2.inOrderPrint(cout);
    cout<<"\tTesting the isEmpty function in the old tree1: "<<tree1.isEmpty()<<endl;
    BST<int>tree3;
    cout<<"\tTesting the isEmpty function in the new tree3: "<<tree3.isEmpty()<<endl;




    return 0;
}









