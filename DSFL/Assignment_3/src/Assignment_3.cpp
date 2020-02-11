//============================================================================
// Name        : Assignment_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define COUNT 10

struct node
{
  int value;
  node *left;
  node *right;

};


class btree
{

	node *root;

    public:
        btree();


//        void insert(int key);
//        node *search(int key);

        void insert();
        node * create();
        void Inorder(node * root);
        node * getroot(){ return root; }
        void setroot( node * R ){ root=R; }

        int maxDepth(node* node);
        void printLeaf(node *root);

        void print2DUtil(node *root, int space);
        void print2D(node *root);
};


btree::btree(){
	root = NULL;
}


void btree :: Inorder(node * root) {
	if(root == NULL) return;


	Inorder(root->left);
	cout<<"\n "<<root->value;
	Inorder(root->right);
}


void  btree :: print2DUtil(node *root, int space)
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


void btree:: print2D(node *root)
{

    print2DUtil(root, 0);
}


node * btree :: create (){

	node * p;
	int x;
	cout<<"\nEnter Data ( -1 to end ) :- ";
	cin>>x;
	if(x==-1)
		return NULL;

	p=new node;
	p->value=x;
	cout<<"\nEnter Left child :- ";
	p->left = create();
	cout<<"\nEnter Right Child :- ";
	p->right = create();
	return p;

}


void btree :: insert(){

	if (root == NULL){
		cout<<"\n Tree Not created , Please Create tree first \n";
		return;
	}
	else{

		int lp=1;
		while(lp){

			int ch;
			node * t=root;

			cout<<"\n\n------MENU------";
			cout<<"\n1.Enter in Left";
			cout<<"\n2.Enter in Right";
			cout<<"\n3.Exit";

			cout<<"\nENTER CHOICE:- ";

			cin>>ch;

			if(ch==1){

				while(t->left!=NULL){
					t=t->left;
				}
				node * leaf;
				leaf=new node;

				cout<<"\nEnter Value:- ";
				cin>>leaf->value;

				t->left=leaf;

			}

			else if(ch==2){

							while(t->right!=NULL){
								t=t->right;
							}
							node * leaf;
							leaf=new node;

							cout<<"\nEnter Value:- ";
							cin>>leaf->value;

							t->right=leaf;

						}
			else{
				lp=0;
			}


		}


	}

}


int btree :: maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);


        if (lDepth > rDepth)
            return(lDepth + 1);

        else
        	return(rDepth + 1);

    }
}


void btree :: printLeaf(node *root)
{

    if (!root)
        return;


    if (!root->left && !root->right)
    {
        cout << root->value << " ";
        return;
    }


    if (root->left)
       printLeaf(root->left);


    if (root->right)
       printLeaf(root->right);
}





int main() {

	int ch,a=0 ;
	btree tree;


	while(1){

		cout<<"\n\n------MENU------";
		cout<<"\n1.Create";
		cout<<"\n2.Insert";
		cout<<"\n3.Display";
		cout<<"\n4.Depth";
		cout<<"\n5.Leaf Nodes";
		cout<<"\n6.Create Copy";
		cout<<"\n7.Exit";
		cout<<"\nENTER CHOICE:- ";

		cin>>ch;

		switch(ch){

		case 1:
				tree.setroot(tree.create());

				break;

		case 3:
				cout<<"\n Binary Tree is (Inorder) :- \n";
				tree.print2D(tree.getroot());
				break;

		case 2:
				tree.insert();
				break;


		case 4:
				a=tree.maxDepth(tree.getroot());
				cout<<"\nDepth of tree is : "<<a;
				break;

		case 5:	cout<<"\nLeaf of tree  : ";
				tree.printLeaf(tree.getroot());

				break;


		}

	}


	return 0;
}
