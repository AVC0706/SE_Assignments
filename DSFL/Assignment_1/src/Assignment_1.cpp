
#include <iostream>
#include<bits/stdc++.h>
#include "Stack.h"
#include "Stack.cpp"
#include <string.h>
#include <cctype>

using namespace std;


int getA(char x){

	if( x == '^')
		return 10;
	if( x == '/')
		return 9;
	if( x=='*' )
		return 9;
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


int convertPost (string a , char post[] ){


	int p=0;

	Stack <char> s;

	char ch;
	for(int i=0 ; a[i]!=NULL ; i++){

		ch = a[i];

		if( isalnum(ch) ){
			post[p]=ch;
			p++;


		}

		else if(ch=='(')
			s.push(ch);


		else if(ch == ')')
		        {
			  	  char ch1;
		            while( !s.isempty() && s.gettop() != '(')
		            {

		                ch1=s.pop();
		                post[p++]=ch1;
		            }

		            if(s.gettop() == '(')
		            {

		               ch= s.pop();
		            }
		        }



		  else{
		              while(!s.isempty() && getA(ch) <= getA(s.gettop()))
		              {
		                  char ch1 =  s.pop();
		                  post[p++]=ch1;

		              }
		              s.push(ch);
		  	  }

	}


	while(!s.isempty()){
		ch=s.pop();
		post[p]=ch;
		p++;
	}

return p;

}


void reverseStr(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


int convertPre (string a , char post[]){

	int p=0;
	Stack <char> s;
	char ch;
	 reverseStr(a);
	 int n = a.length();


	 for (int i = 0; i < n; i++) {

		        if (a[i] == '(') {
		            a[i] = ')';
		            i++;
		        }
		        else if (a[i] == ')') {
		            a[i] = '(';
		            i++;
		        }
		    }



	for(int i=0 ; i<n ; i++){

		ch = a[i];

		if( isalnum(ch) ){
			post[p]=ch;
			p++;


		}

		else if(ch=='(')
			s.push(ch);


		else if(ch == ')')
		        {
			  	  char ch1;
		            while( !s.isempty() && s.gettop() != '(')
		            {

		                ch1=s.pop();
		                post[p++]=ch1;
		            }

		            if(s.gettop() == '(')
		            {

		               ch= s.pop();
		            }
		        }



		  else{
		              while(!s.isempty() && getA(ch) < getA(s.gettop()))
		              {
		                  char ch1 =  s.pop();
		                  post[p++]=ch1;

		              }
		              s.push(ch);
		          }

	}


	while(!s.isempty()){
		ch=s.pop();
		post[p]=ch;
		p++;
	}

return p;
}


//
//int Bracketcheck(string a){
//
//	for (int i= 0 ; a[i]!=NULL ; i++ ){
//
//
//	}
//
//}


float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a);
}


float postE (string a){

	char post[100];
	int n = convertPost(a , post);
			cout<<"\nPostfix is : ";

			for(int i=0 ; i<n ; i++){
				cout<<post[i];
				a[i]=post[i];
		}


	Stack <float> s;

	for(int i=0 ; i<n ; i++){

		if(isalpha(a[i])){
			float n;
			cout<<"\nEnter Value for "<<a[i]<<" :- ";
			cin>>n;
			s.push(n);
		}

		else if(isdigit(a[i])){
			s.push(a[i]-'0');
			cout<<s.gettop();
		}
		else {
			float x = s.pop();
			float y = s.pop();
			float result = operation(x,y,a[i]);
			s.push(result);
		}
	}

	return s.pop();


}


float preE (string a){

	char post[100];
	int n = convertPre(a , post);
			cout<<"\nPrefix is : ";

			for(int i=0 ; i<n ; i++){
				cout<<post[i];
				a[i]=post[i];
		}


	Stack <float> s;

	for(int i=0 ; i<n ; i++){

		if(isalpha(a[i])){
			float n;
			cout<<"\nEnter Value for "<<a[i]<<" :- ";
			cin>>n;
			s.push(n);
		}

		else if(isdigit(a[i])){
			s.push(a[i]-'0');

		}
		else {
			float x = s.pop();
			float y = s.pop();
			float result = operation(y,x,a[i]);
			s.push(result);
		}
	}

	return s.pop();


}






int main() {

	string a , b;
	char post[100] , pre[100];
	int n ;
	float result ;
	stack <char>  x  ;

	while(1){
		int check=0;
		int choice;
		cout<<"\n\n----MENU----\n";
		cout<<"1. Enter Data\n";
		cout<<"2. Print List \n";
		cout<<"3. Convert To Postfix \n";
		cout<<"4. Convert To Prefix \n";
		cout<<"5. Evalute Postfix \n";
		cout<<"6. Evalute Prefix \n";
		cout<<"7. EXIT \n";
		cout<<"Enter Choice : ";

		cin>>choice;

		switch(choice){

		case 1: cin>>a;
				check=1;
				break;

		case 2: cout<<"\nList is : ";
				cout<<a;
				break;

		case 3: n = convertPost(a , post);

				cout<<"\nPostfix is : ";

				for(int i=0 ; i<n ; i++)
					cout<<post[i];
				break;

		case 4: n = convertPre(a , pre);
				cout<<"\nPrefix is : ";

				for(int i=n-1 ; i>=0 ; i--)
					cout<<pre[i];
				break;


		case 5:result = postE(a);
				cout<<"\nResult is :- "<<result;
				break;

		case 6: result = preE(a);
				cout<<"\nResult is :- "<<result;
				break;

		case 7: return 0;

		}


	}



	return 0;
}
