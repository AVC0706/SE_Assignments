//============================================================================
// Name        : Assignment_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define COUNT 10

struct node {

	char value;
	node * left , * right;
};


class Exp
{

	node *root;

    public:
        Exp();

        void createPost(char post[]);
        void createPre(string pre);
        void Inorder(node * root);
        void Postorder(node * root);
        void Preorder(node * root);
        node * getroot(){ return root; }

        void print2DUtil(node *root, int space);
        void print2D(node *root);

};


Exp::Exp(){
	root = NULL;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;

    return false;
}


void  Exp :: print2DUtil(node *root, int space)
{
    if (root == NULL)
        return;


    space += COUNT;


    print2DUtil(root->right, space);


    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->value<<"\n";


    print2DUtil(root->left, space);
}


void Exp :: print2D(node *root)
{

    print2DUtil(root, 0);
}


void Exp :: Inorder(node *t)
{
    if(t)
    {
        Inorder(t->left);
        printf("%c ", t->value);
        Inorder(t->right);
    }
}


void Exp :: Preorder(node *t)
{
    if(t)
    {
    	printf("%c ", t->value);
    	Preorder(t->left);
    	Preorder(t->right);
    }
}



void Exp :: Postorder(node *t)
{
    if(t)
    {
        Postorder(t->left);
        Postorder(t->right);
        printf("%c ", t->value);

    }
}


node * newNode(char v)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->value = v;
    return temp;
};


void Exp :: createPost ( char * postfix ){


	stack<node *> st;

	  node *t, *t1, *t2;


	    for (unsigned int i=0; i<strlen(postfix); i++)
	    {

	        if (!isOperator(postfix[i]))
	        {
	            t = newNode(postfix[i]);
	            st.push(t);
	        }

	        else
	        {
	            t = newNode(postfix[i]);


	            t1 = st.top();
	            st.pop();
	            t2 = st.top();
	            st.pop();

	            t->right = t1;
	            t->left = t2;


	            st.push(t);
	        }
	    }


	    t = st.top();
	    st.pop();

	    root = t ;

}


void Exp :: createPre ( string prefix ){

	stack<node *> st;

	  node *t, *t1, *t2;


	    for (unsigned int i=prefix.length()-1; i>=0; i--)
	    {

	        if (!isOperator(prefix[i]))
	        {
	            t = newNode(prefix[i]);
	            st.push(t);
	        }

	        else
	        {
	            t = newNode(prefix[i]);


	            t1 = st.top();
	            st.pop();
	            t2 = st.top();
	            st.pop();

	            t->left = t1;
	            t->right = t2;



	            st.push(t);
	        }
	    }


	    t = st.top();
	    st.pop();

	    root = t ;

}




int main() {

	int ch;
	char postfix[50];
	string prefix;

	Exp tree;

//	 char p[50] = "ab+ef*g*-";
//	 tree.createPost(p);
//	 printf("infix expression is \n");
//	 tree.Inorder(tree.getroot());

	while(1){

			cout<<"\n\n------MENU------";
			cout<<"\n1.Create Tree (Postfix)";
			cout<<"\n2.Create Tree (Prefix)";
			cout<<"\n3.Traverse (Inorder)";
			cout<<"\n4.Traverse (Postorder)";
			cout<<"\n5.Traverse (Preorder)";
			cout<<"\n6.Display Tree";
			cout<<"\n7.Exit";
			cout<<"\nENTER CHOICE:- ";

			cin>>ch;

			switch(ch){

			case 1 :

					cout<<"\nEnter PostFix Expression:- ";
					cin>>postfix;

					tree.createPost(postfix);
					break;

			case 2 :
					cout<<"\nEnter PreFix Expression:- ";
					cin>>prefix;

					tree.createPre(prefix);
					break;

			case 6 :
					printf("\nInfix expression is \n");
					tree.Inorder(tree.getroot());
					break;

//			case 7 : return 0;



			}




}

	return 0;

}
