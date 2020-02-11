//
//
//#include<iostream>
//#include "Stack.h"
//using namespace std;
//
//Stack::Stack() {
//	// TODO Auto-generated constructor stub
//	top=NULL;
//
//}
//
//
//
//Stack::~Stack() {
//	// TODO Auto-generated destructor stub
//}
//
//
//char Stack :: gettop(){
//
//	return top->data;
//}
//
//s
//
//void Stack ::push(char x){
//
//	 node *temp;
//	 temp= new node();
//
//	 temp->data=x;
//
//	 if(top==NULL){
//
//		 top=temp;
//
//	 }
//
//	 else{
//
//		 temp->next=top;
//		 top=temp;
//
//	 }
//
//}
//
//int Stack :: isempty(){
//
//	if(top==NULL)
//		return 1;
//	else
//		return 0;
//
//}
//
//
//char Stack::pop(){
//
//	if(top!=NULL){
//
//		 node *temp;
//
//		temp = top;
//		char x = temp->data;
//		top=top->next;
//		temp->next=NULL;
//		delete(temp);
//
//		return x;
//
//	}
//
//
//		cout<<"Empty Stack";
//
//
//}




#include<iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	top=NULL;

}


template <class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
}

template <class T> T
Stack<T>:: gettop(){

	return top->data;
}

template <class T>
int Stack<T> :: isempty(){

	if(top==NULL)
		return 1;
	else
		return 0;

}

template <class T>
void Stack<T> ::push(T x){

	 node<T> *temp;
	 temp= new node<T>();

	 temp->data=x;

	 if(top==NULL){

		 top=temp;

	 }

	 else{

		 temp->next=top;
		 top=temp;

	 }

}


template <class T> T
Stack<T>::pop(){

	if(top!=NULL){

		 node<T> *temp;

		temp =top;
		T x = temp->data;
		top=top->next;
		temp->next=NULL;
		delete(temp);
		return x;

	}

	else{
		cout<<"Empty Stack";
	}

}



