/*
 * Queue.h
 *
 *  Created on: Oct 11, 2017
 *  Author: amiralisafaei
 *  course: 22C
 *  Instructor: Jennifer Parrish
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

template <class queuedata>
class Queue
{
    public:
        /**constructors and destructors*/

        Queue();
        //initializes an empty queue
        //postcondition: an empty queue

        Queue(const Queue &queue);
        //initializes queue to have same elements as another queue
        //postcondition: a copy of queue

        ~Queue();
        //frees memory allocated to the queue
        //postcondition: memory for queue has been freed

        /**manipulation procedures*/

        void dequeue();
        //removes an element from the front of the queue
        //precondition:size!=0
        //postcondition: an element has been removed from the front of the queue

        void enqueue(queuedata data);
        //adds an element to the end of the queue
        //postcondition: an element added to the end of the queue

        /**accessors*/

        bool operator==(const Queue &queue);
        //returns whether this queue is equal to another queue

        queuedata getFront();
        //returns the element at the front of the queue
        //precondition: size != 0

        int getSize();
        //returns the size of the queue

        bool empty();
        //returns whether the queue is empty

        /**additional queue operations*/
        void print();
        //prints the elements in the queue separated by a blank space to stdout


    private:
        struct Node
        {
            queuedata data;
            Node* link;
            Node(queuedata newData){
                data = newData;
                link = NULL;
            }
        };

        Node* front;
        Node* back;
        int size;

};

#endif /* QUEUE_H_ */



template <class queuedata>
Queue<queuedata>::Queue()
{
	front = NULL;
	back = NULL;
	size = 0;
}

template <class queuedata>
Queue<queuedata>::Queue (const Queue &Oldqueue)
{

    size = Oldqueue.size;
    if(Oldqueue.front == NULL)
    {
        back = front = NULL;
    }

    else
     {
         front = new Node(Oldqueue.front->data);
        Node* temp = Oldqueue.front;
        Node* qtemp = front; //create temporary iterator

         while(temp->link != NULL)
         {

             temp = temp->link;
             qtemp->link = new Node(temp->data);
             qtemp = qtemp->link;

         }

         back = qtemp;
     }

}

template <class queuedata>
Queue<queuedata>::~Queue() //destructor
{
    Node* temp = front;
    Node* temp2 = front;
    while (temp != NULL)
    {
        temp = temp->link;
        delete temp2;
        temp2 = temp;
    }
}

template <class queuedata>
void Queue<queuedata>::print()
{
    Node* temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

template <class queuedata>
void Queue<queuedata>::enqueue(queuedata data)
{
	Node* newNode = new Node(data);
	if(size == 0)
	{
		front = newNode;
		back = newNode;

	}
	else
	{
		back -> link = newNode;
		back = newNode;

	}
	size ++;

}

template <class queuedata>
void Queue<queuedata>::dequeue()
{
	assert(size !=0);

	if(size==1)
	{
		front = NULL;
		back = NULL;

	}

	else
	{
		Node* temp = front;
		front = front -> link;
		delete temp;
		temp = NULL;
		size--;

	}



}



template <class queuedata>
queuedata Queue <queuedata>::getFront()
{
	assert(size !=0);
	return front -> data;
}

template <class queuedata>
bool Queue<queuedata>::empty()
{
	return size == 0;
}


template <class queuedata>
int Queue<queuedata>::getSize()
{
	return size;
}

template <class queuedata>
bool Queue<queuedata>::operator==(const Queue &oldqueue)
{

		Node *previousqueue = oldqueue.front;
		Node *newNodeptr = front;


		if(size == oldqueue.size)
		{
			while(newNodeptr != NULL)
			{
					if(newNodeptr->data == previousqueue->data)
					{
						newNodeptr = newNodeptr->link;
						previousqueue = previousqueue->link;
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
