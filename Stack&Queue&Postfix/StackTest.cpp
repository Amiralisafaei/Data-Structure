/*
 * StackTest.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: amiralisafaei
 *      Cours: 22C
 *      Instructor: Jennifer Parrish
 */

#include <iostream>
#include <string>
#include "Stack.h"


using namespace std;

int main()
{


	Stack<int> stack1;


	cout<<"    **This file will test the Stack header file**\n\n";


	cout<<"empty():\n";
	cout <<"----------------------------------------------------\n";
	if(stack1.empty())
	{
		cout<<"Stack currently is empty.";
	}


	cout<<endl<<endl;


	//testing push function
	cout<<"Push():\n";
	cout <<"----------------------------------------------------\n";

	cout<<"adding some number into stack\n";
	int number;

	for(int i=1; i<7 ; i++)
	{

	stack1.push(i);


	}
	stack1.print();
	cout<<endl<<endl;


	//testing peek function
	cout<<"peek():\n";
	cout <<"----------------------------------------------------\n";
	cout<<"Current number on the top:\n";
	cout<<stack1.peek();
	cout<<endl<<endl;


	//testing getSize function
	cout<<"getSize():\n";
	cout <<"----------------------------------------------------\n";
	cout<<"The current size of the stack is:\n";
	cout<<stack1.getSize();
	cout<<endl<<endl;


	//testing pop function

	cout<<"pop():\n";
	cout <<"----------------------------------------------------\n";
	cout<<"removing two number from the stack:\n";

	stack1.pop();
	stack1.pop();
	stack1.print();
	cout<<endl;
	cout<<"The current size of the stack is:\n";
	cout<<stack1.getSize();
	cout<<endl;
	cout<<"The current number on the top is:\n";
	cout<<stack1.peek();
	cout<<endl<<endl;

	//testing copy constructor
	cout<<"copy constructor()\n";
	cout <<"----------------------------------------------------\n";
	cout<<"Here is the elements in the first stack:\n";
	stack1.print();
	cout<<endl;
	cout<<"The second stack would be the same as the first one:\n";
	Stack<int> stack2(stack1);
	stack2.print();
	cout<<endl<<endl;



	//testing operator==
	cout<<"operator==(const Stack &oldstack)\n";
	cout <<"----------------------------------------------------\n";
	cout<<"Using operator== to compare two stacks:\n";
	cout<<boolalpha<<stack2.operator==(stack1);
	cout<<endl<<endl;

return 0;


}



