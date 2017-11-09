///*
// * Postfix.cpp
// *
// *  Created on: Oct 14, 2017
// *      Author: amiralisafaei
// *      Course: 22C
// *		Instructor: Jennifer Parrish
// */
//#include <iostream>
//#include <string>
//#include "Queue.h"
//#include "Stack.h"
//#include <sstream>
//using namespace std;
//
//int precedence(string oprSymbol)
//{
//    int prec1;
//    if (oprSymbol == "*" || oprSymbol == "/")
//    {
//        prec1 = 2;
//    }
//    else if (oprSymbol == "+" || oprSymbol == "-")
//    {
//        prec1 = 1;
//    }
//    return prec1;
//}
//
//int main()
//{
//    string equation;
//    cout << "Welcome\n\n";
//
//    do{
//        cout << "Please enter an equation or \"q\" to quit: ";
//        getline(cin, equation);
//
//        if (equation != "q")
//        {
//            stringstream ss;
//            ss << equation;
//            Queue <string> operands;
//            Stack <string> operators;
//            string a;
//            while(ss >> a)
//            {
//                if ((a == "+") || (a == "-") || (a == "*") || (a == "/"))
//                {
//                    if(operators.empty())
//                    {
//                        operators.push(a);
//                    }
//                    else
//                    {
//                        int onTheSpot, inStack;
//                        onTheSpot = precedence(a);
//                        inStack = precedence(operators.peek());
//                        if (onTheSpot > inStack)
//                        {
//                            operators.push(a);
//                        }
//                        else if (inStack >= onTheSpot)
//                        {
//                            do
//                            {
//                                string temp = operators.peek();
//                                operands.enqueue(temp);
//                                operators.pop();
//                                if (!operators.empty())
//                                {
//                                    inStack = precedence(operators.peek());
//                                    if (onTheSpot > inStack)
//                                    {
//                                        operators.push(a);
//                                    }
//                                }
//                                else
//                                {
//                                    operators.push(a);
//                                    inStack = 0;
//                                }
//                            }while(inStack >= onTheSpot);
//                        }
//                    }
//                }
//                else
//                {
//                    operands.enqueue(a);
//                }
//            }
//
//
//            if (!operators.empty())
//            {
//                do
//                {
//                    string temp = operators.peek();
//                    operands.enqueue(temp);
//                    operators.pop();
//                }while(!operators.empty());
//            }
//
//            cout << "This is the Que: ";
//            operands.print();
//        }
//    }while (equation != "q");
//
//    cout << "\n\nGoodbye!\n";
//    return 0;
//}
//
//
//
