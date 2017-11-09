/*
 * QueueTest.cpp
 *
 *  		Created on: Oct 30, 2017
 *      Duc Nguyen & Amirali Safaei
 *		CIS 22C, Lab 5
 *		Instructor: Jennifer Parrish
 */


#ifndef Stack_H_
#define Stack_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
    public:
        /**constructors and destructors*/

        Stack();

        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &Oldstack);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack


        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize() const;
       //returns the size of the stack

       bool empty() const;
       //returns whether the stack is empty


       /**additional operations*/

       void print() const;
       //prints the elements in the stack each element separate by a blank space to stdout

    private:
       struct Node {
           stackdata data;
           Node* link;

           Node(stackdata ndata) {
                data = ndata;
                link = NULL;
          }
       };

       Node* top;
       int size;

};

template <class stackdata>
Stack<stackdata>::Stack()
{
	top = NULL;
	size = 0;
}

template <class stackdata>
Stack <stackdata>::Stack(const Stack &Oldstack)
{
	if (Oldstack.size == 0)
	{
		top = NULL;
		size = 0;
	}
	else
	{
			top = new Node(Oldstack.top->data);
			Node* oldStackWalker = Oldstack.top;
			Node* newStackWalker = top;
			while(oldStackWalker -> link != NULL)
				{
					oldStackWalker = oldStackWalker ->link;
					newStackWalker -> link = new Node(oldStackWalker->data);
					newStackWalker = newStackWalker ->link;
				}
			size = Oldstack.size;
	}

//	size = Oldstack.size;
//    if(Oldstack.top == NULL)
//    {
//         top = NULL;
//         cout << "The list is empty, nothing to copy\n";
//    }
//
//    else
//     {
//         top = new Node(Oldstack.top->data);
//        Node* temp = Oldstack.top;
//        Node* qtemp = top; //create temporary iterator
//
//         while(temp->link != NULL)
//         {
//
//             temp = temp->link;
//             qtemp->link = new Node(temp->data);
//             qtemp = qtemp->link;
//
//         }
//
//         top = qtemp;
//     }


}


template <class stackdata>
Stack<stackdata> :: ~Stack()
{
	 Node* temp = top;
	    Node* temp2 = top;
	    while (temp != NULL)
	    {
	        temp = temp->link;
	        delete temp2;
	        temp2 = temp;
	    }
}

template <class stackdata>
void Stack<stackdata>:: pop()
{
	assert(size !=0);

	if(size==1)
	{
		delete top;
		top = NULL;
		size = 0;
	}

	else
	{
		Node* temp = top;
		top = top -> link;
		delete temp;
		temp = NULL;
		size--;

	}


}

template<class stackdata>
void Stack<stackdata> :: push(stackdata data)
{
	Node* newNode = new Node(data);

	if(size==0)
	{
		top = newNode;
	}
	else
	{
		newNode -> link = top;
		top = newNode;

	}
	size++;

}

template<class stackdata>
stackdata Stack<stackdata> :: peek() const
{
	assert(size!=0);
	return top -> data;
}

template<class stackdata>
int Stack<stackdata>::getSize() const
{
	assert(size!=0);
	return size;
}

template<class stackdata>
bool Stack<stackdata>::empty() const
{
	return size == 0;
}

template<class stackdata>
void Stack<stackdata>:: print() const
{
	Node* temp = top;
	    while (temp != NULL)
	    {
	        cout << temp->data << " ";
	        temp = temp->link;
	    }
	    cout << endl;
}

template<class stackdata>
bool Stack<stackdata>:: operator==(const Stack &oldstack)
{

	Node *previousStack = oldstack.top;
	Node *newNodeptr = top;


		if(size == oldstack.size)
		{
			while(newNodeptr != NULL)
			{
					if(newNodeptr->data == previousStack->data)
					{
						newNodeptr = newNodeptr->link;
						previousStack = previousStack->link;
						return  true;
					}
					else
					{
						return false;
					}
			}

			return true;
		}


		return false;

}










#endif /* STACK_H_ */
