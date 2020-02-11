/*
 * stack.cpp
 *
 *  Created on: 17-Dec-2019
 *      Author: dsfle-10
 */

#include<iostream>
#include "stack.h"
using namespace std;

stack::stack() {
	// TODO Auto-generated constructor stub
	top=NULL;

}



stack::~stack() {
	// TODO Auto-generated destructor stub
}


node * stack :: gettop(){

	return top;
}



void stack ::push(char x){

	 node *temp;
	 temp= new node();

	 temp->data=x;

	 if(gettop()==NULL){

		 top=temp;

	 }

	 else{

		 temp->next=top;
		 top=temp;

	 }

}




char stack::pop(){

	if(gettop()!=NULL){

		 node *temp;

		temp = gettop();
		char x = temp->data;
		top=top->next;
		temp->next=NULL;
		delete(temp);

		return x;

	}


		cout<<"Empty Stack";


}



