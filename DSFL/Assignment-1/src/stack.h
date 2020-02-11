/*
 * stack.h
 *
 */

#ifndef STACK_H_
#define STACK_H_


struct node{

		char data;
		node * next;
} ;


class stack {

		node* top;

public:

	stack();
	virtual ~stack();

	void push(char x);
	char pop();
	node  * gettop();


};

#endif /* STACK_H_ */
