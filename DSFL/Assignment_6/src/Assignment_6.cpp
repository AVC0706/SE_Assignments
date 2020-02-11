#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct graphEdge
	{
		graphEdge *nextEdgePointer;
		struct graphVertex *destinationVertexPointer;

	};
	struct graphVertex
	{
		string name;
		int DOBd,DOBm,DOBy;
		int commentsMade;
		bool visited;
		graphEdge *nextEdgePointer;
		graphVertex *nextVertexPointer;
	};
	struct graphHead
	{
		int count;
		graphVertex *firstVertex;
	};

class graphSocialnetwork {

	graphHead *G;
	//graphEdge E;

public:
//	virtual ~graphSocialnetwork();
	void createGraph();
	graphVertex* getVertex(string);
	graphVertex* getVertexPtr(string);
	int insertVertex(string );
	int insertEdge(string, string,int);
	void displayGraph();

	//other program related functions

};

//graphSocialnetworkl::graphKruskal() {
//	// TODO Auto-generated constructor stub
//	G=NULL;
//}
//
//graphSocialnetwork::~graphKruskal() {
//	// TODO Auto-generated destructor stub
//}

void graphSocialnetwork::createGraph()
{
	G=new graphHead;
	G->count=0;
	G->firstVertex=NULL;
}

graphVertex* graphSocialnetwork:: getVertex(string name)
{
	graphVertex *newptr;
	//allocate the memory for newptr
	newptr = new graphVertex;
	newptr->name = name;
	newptr->nextVertexPointer = NULL;
	G->count=G->count+1;

	return newptr;
}

//graphEdge* graphKruskal::getEdge()
graphVertex* graphSocialnetwork::getVertexPtr(string name){
	graphVertex *newPtr;
	newPtr = G->firstVertex;
	while(newPtr->name != name && newPtr!=NULL){
		newPtr = newPtr->nextVertexPointer;
	}

	return newPtr;

}



int graphSocialnetwork::insertVertex(string name)
{

	graphVertex *newPtr,*locPtr;
	newPtr=getVertex(name);
	if(G->firstVertex == NULL){
		G->firstVertex = newPtr;
	}
	else{
		locPtr = G->firstVertex;
		while(locPtr->nextVertexPointer != NULL){
			locPtr = locPtr->nextVertexPointer;
		}
		locPtr->nextVertexPointer = newPtr;
	}
	//Insert the new user/vertex in the network/graph. Here we have just taken name (string). U can get complete details (struct object).
	return 1;
}

int graphSocialnetwork::insertEdge(string startVertex, string endVertex, int w)
{


	graphVertex *fromPtr, *toPtr;
	fromPtr = getVertexPtr(startVertex);
	toPtr = getVertexPtr(endVertex);


	if(fromPtr->nextEdgePointer==NULL){

		graphEdge *newptr;

		newptr = new graphEdge;
		fromPtr->nextEdgePointer = newptr;
		newptr->nextEdgePointer=NULL;
		newptr->destinationVertexPointer=toPtr;

	}

	else{
		graphEdge *newptr , *edgeptr;

		newptr = new graphEdge;

		edgeptr=fromPtr->nextEdgePointer;
		while( edgeptr->nextEdgePointer !=NULL ){
			edgeptr=edgeptr->nextEdgePointer;
		}

		edgeptr->nextEdgePointer = newptr;
		newptr->nextEdgePointer=NULL;
		newptr->destinationVertexPointer=toPtr;

	}

	if(toPtr->nextEdgePointer==NULL){

			graphEdge *newptr;

			newptr = new graphEdge;
			toPtr->nextEdgePointer = newptr;
			newptr->nextEdgePointer=NULL;
			newptr->destinationVertexPointer=fromPtr;

		}

		else{
			graphEdge *newptr , *edgeptr;

			newptr = new graphEdge;

			edgeptr=toPtr->nextEdgePointer;
			while( edgeptr->nextEdgePointer !=NULL ){
				edgeptr=edgeptr->nextEdgePointer;
			}

			edgeptr->nextEdgePointer = newptr;
			newptr->nextEdgePointer=NULL;
			newptr->destinationVertexPointer=fromPtr;

		}
	//Insert Edge (friend of user and create the proper links)

	return 1;
}

void graphSocialnetwork::displayGraph()
{
	graphVertex *vertexPtr;
	graphEdge *edgePtr;
	vertexPtr = G->firstVertex;
	while(vertexPtr != NULL){


		cout<<vertexPtr->name<<"::";
		edgePtr=vertexPtr->nextEdgePointer;
			while(edgePtr!=NULL){

				cout<<""<<edgePtr->destinationVertexPointer->name<<",";
				edgePtr = edgePtr->nextEdgePointer;

		}
		cout<<endl;
		vertexPtr = vertexPtr->nextVertexPointer;
	}


	//display the graph in adjacency list form
}



int main(){

	graphSocialnetwork Graph;
	int ch ;
	string friend1 , user  ;

	while(1){

			cout<<"\n\n------MENU------";
			cout<<"\n1.Create Graph";
			cout<<"\n2.Insert User";
			cout<<"\n3.Add Friend";
			cout<<"\n4.Display Graph";
			cout<<"\n5.Find Who has Max Friends";

			cout<<"\n6.Exit";
			cout<<"\nENTER CHOICE:- ";

			cin>>ch;

			switch(ch){

			case 1 :
					Graph.createGraph();
					cout<<"\nGraph Created ";

					break;

			case 2 :
					cout<<"\nEnter Username:- ";
					cin>>user;
					Graph.insertVertex(user);

					break;

			case 3 :
					cout<<"\nEnter Username :- ";
					cin>>user;
					cout<<"Enter Friend Name:- ";
					cin>>friend1;
					Graph.insertEdge(user , friend1 , 0 );
					break;

			case 4 :
					Graph.displayGraph();
					break;

			case 6 :
					return 0;

//			case 7 : return 0;



			}




	}




//	create graph
//	Insert vertices
//	Insert Edges
//	display Graph
//	Perform Operations

}
