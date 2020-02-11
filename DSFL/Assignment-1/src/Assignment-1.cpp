
#include <iostream>
#include "stack.h"
#include "stack.cpp"
#include <string.h>

using namespace std;


int getA(char x){

	if( x == '^')
		return 10;
	if( x == '/')
		return 9;
	if( x=='*' )
		return 8;
	if( x=='+' || x=='-' )
		return 7;
	if( x=='(' || x==')' )
		return 1;

}



int getList(string a){

	int n=0;
	cout<<"\nEnter String : ";
	cin>>a;
	for(int x=0 ; a[x]!=NULL ; x++ ){
		n++;
	}
	return n;
}


string convertPost (string a){

	string post;

	for(int i=0 ; a[i]!=NULL ; i++){


	}

}


int main() {

	string a , post , pre ;
	int n;
	stack  x  ;

	while(1){

		int choice;
		cout<<"\n\n----MENU----\n";
		cout<<"1. Enter Data\n";
		cout<<"2. Print List \n";
		cout<<"3. Reverse List \n";
		cout<<"4. Convert To Postfix \n";
		cout<<"4. EXIT \n";
		cout<<"Enter Choice : ";
		cin>>choice;

		switch(choice){

		case 1 : cin>>a;
				break;

		case 2 : cout<<"\nList is : ";
				for(int i=0 ; i<n ; i++ )
					cout<<" "<<a[i];
				break;

		case 3 :cout<<"\nReverse List is : ";
				for(int i=0 ; i<n ; i++ ){
					char b=x.pop();
					cout<<" "<<b;
				}
				break;



		case 4 : return 0;

		}


	}



	return 0;
}
