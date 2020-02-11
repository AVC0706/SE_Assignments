/*
 * stack.h
 *
 */

//#ifndef STACK_H_
//#define STACK_H_
//
//
//struct node{
//
//		char data;
//		node * next;
//} ;
//
//
//class Stack {
//
//		node* top;
//
//public:
//
//	Stack();
//	virtual ~Stack();
//
//	void push(char x);
//	char pop();
//	char gettop();
//	int isempty();
//
//
//};
//
//#endif




#ifndef STACK_H_
#define STACK_H_

template<class T>
class node{
public:
		T data;
		node * next;
} ;

template<class T>
class Stack {

		node<T> * top;

public:

	Stack();
	virtual ~Stack();

	void push(T x);
	T pop();
	T  gettop();
	int isempty();

};

#endif /* STACK_H_ */
