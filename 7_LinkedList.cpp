#include <bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node *next;
public:
	Node(int x){
		data=x;
		next=NULL;
	}
	friend class LinkedList;
};

class LinkedList{
	Node* head;
	Node* tail;
public:
//**********************INSERTION*******************************************
	void append(int x){
		Node* newNode=new Node(x);
	    if(head==NULL){
	    	head=tail=newNode;
	    }
	    else{
	    	tail->next=newNode;
	    	tail=newNode;
	    }
	}

	void InsertAtStart(int x){
		Node* newNode=new Node(x);
		newNode->next=head;
		head=newNode;
	}

	void InsertAtPos(int x,int p){
		Node* newNode=new Node(x);
		Node* temp=head;
		for(int c=1;c<p;c++){
			temp=temp->next;
		}
		Node* tempNext=temp->next;
		newNode->next=tempNext;
		temp->next=newNode;
	}
//***********************TRAVERSAL******************************************
	void display(){
		Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" --->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
//**********************DELETION********************************************
	void deleteAtTail(){
		Node* temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		Node* del=temp->next;
		temp->next=NULL;
		delete del;
	}
	void deleteAtHead(){
		Node* del=head;
		head=head->next;
		delete del;
	}
	void deleteAtPos(int p){
		Node* temp=head;
		for(int c=1;c<p;c++){
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next;
	}
};

