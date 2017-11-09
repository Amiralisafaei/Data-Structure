/*
 * BST.h
 *
 *  		Created on: November 7, 2017
 *      Duc Nguyen & Amirali Safaei
 *		CIS 22C, Lab 6
 *		Instructor: Jennifer Parrish
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;
template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* leftchild;
        Node* rightchild;

        Node(bstdata newdata){
            data = newdata;
            leftchild = NULL;
            rightchild = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertNode(Node* treeNode, bstdata data); //DONE
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrint(ostream& out, Node* root) const; //DONE
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrint(ostream& out, Node* root) const; //DONE
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrint(ostream& out, Node* root) const; //DONE
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy) ; //DONE
    //recursive helper function to the copy constructor

    void freeNode(Node* root); //DONE
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data) const; //DONE
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimum(Node* root) const; //DONE
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximum(Node* root) const; //DONE
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* deleteNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeight(Node* treeNode) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    BST(); //DONE
    //Instantiates a new BST

    BST(const BST &bst); //DONE
    //copy constructor

    ~BST(); //DONE
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const; //DONE
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const; //DONE
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const; //DONE
    //determines whether the BST is empty

    int getSize() const; //DONE
    //returns the size of the tree

    bstdata getRoot() const; //DONE
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const; //DONE
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data); //DONE
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const; //DONE
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const; //DONE
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const; //DONE
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};

template <class bstdata>
BST<bstdata>::BST() //DONE!!!
{
    root = NULL;
}

template <class bstdata>
BST<bstdata>::BST(const BST &bst) //DONE!!! Look Over
{
//    if (bst.root == NULL)
//    {
        root = NULL; //Notice how logic does not work this is becuz if
        // I enter else, root is not NULL, it is pointed to a random area. This will mess
        //up my if's inside my copyNode, which calls insert.
        //I will leave the if and else to remind myself how it is wrong.
//    }
//    else
//    {
        copyNode(bst.root); //If bst.root is NULL, it will fall thru copyNode definition
//    }
}

template <class bstdata>
void BST<bstdata>::copyNode(Node* copy) //DONE!!! Look Over
{
    if(copy != NULL) //Base Case
    {
        insert(copy->data); //Inserts the node
        copyNode(copy->rightchild); //Order does not matter becuz insert takes care of the greater than or less than value.
        copyNode(copy->leftchild); //Handles the left subtrees if there's any (Notice the base case condition)
//        copyNode(copy->rightchild); //Handles the right subtrees if there's any (Notice the base case condition)
    }
}

template <class bstdata>
BST<bstdata>::~BST() //DONE!!!
{
    freeNode(root);
}

template <class bstdata>
typename BST<bstdata>::Node* BST<bstdata>::deleteNode(Node* root, bstdata data) //DONE!! Look Over
{
    if (root == NULL)
    {
        return root;
    }
    else if(data < root->data) //Finding
    {
        root->leftchild = deleteNode(root->leftchild, data);
    }
    else if(data > root->data) //Finding
    {
        root->rightchild = deleteNode(root->rightchild, data);
    }
    else //Found
    {
        if(!root->leftchild && !root->rightchild) //CASE 1 leaf case
        {
            delete root;
            root = NULL;
        }
        else if(root->leftchild && !root->rightchild) // CASE 2 One Child: left side
        {
            Node* temp = root;
            root = root->leftchild;
            delete temp;
        }
        else if(!root->leftchild && root->rightchild) // CASE 2 One Child: right side
        {
            Node* temp = root;
            root = root->rightchild;
            delete temp;
        }
        else // CASE 3 Two Kids
        {
            root->data = minimum(root->rightchild);
            root->rightchild = deleteNode(root->rightchild, root->data);
        }
    }return root;
}

template <class bstdata>
void BST<bstdata>::freeNode(Node* root) //Look Over
{
    if (root != NULL)
    {
        if(root->leftchild != NULL)
        {
            freeNode(root->leftchild); //Purpose is to go all the way down on left side
        }
        if(root->rightchild != NULL)
        {
            freeNode(root->rightchild); //purpose is to go all the way down on the right side
        }
        delete root;
    }
}

template <class bstdata>
int BST<bstdata>::getHeight() const //DONE!!!
    //returns the height of the tree
{
    return getHeight(root);
}

template <class bstdata>
int BST<bstdata>::getHeight(Node* treeNode) const //DONE!!! Look Over
{
    int leftHeight, rightHeight, max;
    if (root == NULL)
        {
            return 0;
        }
    if(treeNode == NULL && root != NULL)
        {
            return -1;
        }

    leftHeight = getHeight(treeNode->leftchild);
    rightHeight = getHeight(treeNode->rightchild);
    if(leftHeight > rightHeight)
        {
            max = leftHeight;
        }
    else
        {
            max = rightHeight;
        }
    return max + 1;

}

template <class bstdata>
bstdata BST<bstdata>::getRoot() const //DONE!!!
{
    assert(!isEmpty());
    return root->data;
}

template <class bstdata>
int BST<bstdata>::getSize() const //DONE!!!
{
    int size = 0;
    getSize(root, size);
    return size;

}

template <class bstdata>
void BST<bstdata>::getSize(Node* root, int& size) const //DONE!!!
{
    if (root != NULL)
    {
        size++;
        getSize(root->leftchild, size);
        getSize(root->rightchild, size);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const //DONE!!!
{
        inOrderPrint(out, root);
        cout << endl;
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, Node* treeNode) const //DONE!!!
{
    if (treeNode != NULL)
    {
        inOrderPrint(out, treeNode->leftchild);
        out << treeNode->data << " ";
        inOrderPrint(out, treeNode->rightchild);

    }
}

template <class bstdata>
void BST<bstdata>::insert(bstdata data) //DONE!!!
{
    if (root == NULL)
    {
        root = new Node(data); //if the tree is empty insert the value at the root
    }
    else
    {
        insertNode(root, data); //otherwise call the helper function, passing it the root
    }
}

template <class bstdata>
void BST<bstdata>::insertNode(Node* treeNode, bstdata data) //DONE!!!
{
//    if root is NULL is already taken care of in the public helper function
    if (data == treeNode->data)
    {
        cout << "No Duplicate!\n";
    }
    else if (data < treeNode->data)
        {
            if (!treeNode->leftchild)
            {
                treeNode->leftchild = new Node(data);
            }
            else
            {
                insertNode(treeNode->leftchild, data);
            }
        }
    else
    {
        if (!treeNode->rightchild)
        {
            treeNode->rightchild = new Node(data);
        }
        else
        {
            insertNode(treeNode->rightchild, data);
        }
    }
}

template <class bstdata>
bool BST<bstdata>::isEmpty() const //
{
    return root == NULL;
}

template <class bstdata>
bstdata BST<bstdata>::maximum() const //DONE!!!
{
    assert(!isEmpty());

    return maximum(root);
}

template <class bstdata>
bstdata BST<bstdata>::maximum(Node* root) const //DONE!!!
{
    if(root->rightchild == NULL)
    {
        return root->data;
    }
    else
    {
        return maximum(root->rightchild);
    }
}

template <class bstdata>
bstdata BST<bstdata>::minimum() const //DONE!!!
{
    assert(!isEmpty());

    return minimum(root);
}

template <class bstdata>
bstdata BST<bstdata>::minimum(Node* root) const //DONE!!!
{
    if(root->leftchild == NULL)
        {
            return root->data;
        }
    else
    {
        return minimum(root->leftchild);
    }
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const //DONE!!!
{
        postOrderPrint(out, root);
        cout << endl;
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out, Node* treeNode) const //DONE!!!
{
    if (treeNode != NULL)
    {
        postOrderPrint(out, treeNode->leftchild);
        postOrderPrint(out, treeNode->rightchild);
        out << treeNode->data << " ";
    }
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const //DONE!!!
{
        preOrderPrint(out, root);
        cout << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, Node* treeNode) const //DONE!!!
{

    if (treeNode != NULL)
    {
        out << treeNode->data << " ";
        preOrderPrint(out, treeNode->leftchild);
        preOrderPrint(out, treeNode->rightchild);
    }
}

template <class bstdata>
void BST<bstdata>::remove(bstdata data)//DONE!!!
{
    assert(search(data)); //assert (!isEmpty()) is inside search
    root = deleteNode(root, data);
}

template<class bstdata>
bool BST<bstdata>::search(bstdata data) const //DONE!!!!
{
    assert(!isEmpty());
    return searchNode(root, data);
}

template<class bstdata>
bool BST<bstdata>::searchNode(Node* root, bstdata data) const //DONE!!!
{
    bool status;
    if (root->data == data)
    {
        status = true;
//        return true;
    }
    else if(data < root->data)
    {
        if(!root->leftchild)
        {
            status = false;
//            return false;
        }
        else
        {
            status = searchNode(root->leftchild, data);
        }
    }
    else
        {
            if(!root->rightchild)
            {
                status = false;
//                return false;
            }
            else
            {
                status = searchNode(root->rightchild, data);
            }
        }
    return status;
}


#endif /* BST_H_ */






