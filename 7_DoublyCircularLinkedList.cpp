#include<bits/stdc++.h>
using namespace std;

class Node{
	int col;
	char booked;
	Node *next;
	Node* prev;
public:
	Node(int y,char c='_'){
		col=y;
		next=NULL;
		prev=NULL;
		booked=c;
	}
	friend class DCLL;
};

class DCLL{
	Node* head[11];
public:
	DCLL(){
		for(int i=1;i<11;i++){
			head[i]=NULL;
			for(int j=1;j<8;j++){
					Node* newNode=new Node(j);
					if(head[i]==NULL){
						head[i]=newNode;
						head[i]->prev = head[i]->next = head[i];
					}
					else{
						newNode->next=head[i];
						head[i]->prev->next=newNode;
						newNode->prev=head[i]->prev;
						head[i]->prev=newNode;
						}
				}
			}
	}

	void display(){
		cout<<"Current available seats"<<endl;
		cout << "	1   2   3   4   5   6   7     " << endl;
		for(int r=1;r<=10;r++){
			Node* temp=head[r];
			cout << "Row-" << r << "  ";
			for (int j = 1; j < 8; j++){
				cout <<"|"<< "" << temp->booked << "| ";
				temp=temp->next;
			}
			cout<<endl<<endl;
		}
	}

	void book(int r,int c){
		Node* temp=head[r];
		while(temp->col!=c && temp->next!=head[r]){
					temp=temp->next;
		}
		temp->booked='x';
		cout<<"Seat "<<r<<" "<<c<<" is booked successfully"<<endl;
	}
	void cancel(int r,int c){
		Node* temp=head[r];
		while(temp->col<c &&temp->next!=head[r]){
			temp=temp->next;
		}
		if(temp->booked=='_'){
			cout<<"Seat not booked"<<endl;
			return;
		}
		else{
			temp->booked='_';
			cout<<"Seat "<<r<<" "<<c<<" is cancelled successfully"<<endl;
		}
	}
};

int main(){
	DCLL d;
	while(true){
		cout<<"Movie Booking Program"<<endl;
		cout<<"Enter 1 to display available seats"<<endl;
		cout<<"Enter 2 to book a seat"<<endl;
		cout<<"Enter 3 to cancel a seat"<<endl;
		cout<<"Enter 4 to exit"<<endl;
		int res;
		cout<<"Enter your response : "<<endl;
		cin>>res;
		if(res==1){
			d.display();
		}
		else if(res==2){
			int ro,co;
			cout<<"Enter row : "<<endl;
			cin>>ro;
			cout<<"Enter column : "<<endl;
			cin>>co;
			d.book(ro,co);
		}
		else if(res==3){
			int ro,co;
			cout<<"Enter row : "<<endl;
			cin>>ro;
			cout<<"Enter column : "<<endl;
			cin>>co;
			d.cancel(ro,co);
		}
		else if(res==4) break;
		else continue;
	}
}

