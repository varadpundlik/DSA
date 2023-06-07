#include <iostream>
using namespace std;

template<class T>
class Node{
public:
	T job;
	int pr;
	bool operator<=(const Node<string> &n1){
			if(pr<=n1.pr) return true;
			else return false;
		}
};

class PriorityQueue{
	Node<string> q[10];
	int front=-1,rear=-1;
public:

	void insertJob(Node<string> data){
		if(front==-1){
			front=rear=0;
			q[rear]=data;
		}
		else if(rear==19){
			cout<<"Queue Overflow"<<endl;
			return;
		}
		else{
			rear++;
			q[rear]=data;
			int j=rear-1;
			while(q[j]<=data && j>=front){
				q[j+1]=q[j];
				j--;
				q[j+1]=data;
			}
		}
		cout<<"Job Inserted Successfully"<<endl;
	}

	void deleteJob(){
		if(front==-1 || front==rear+1){
			cout<<"Queue Underflow"<<endl;
		}
		else{
			front++;
			cout<<"Job deleted successfully"<<endl;
		}
	}

	void displayJob(){
		if(front==-1 || front==rear+1){
			cout<<"Queue Underflow"<<endl;
		}
		for(int i=front;i<=rear;i++){
			cout<<q[i].job<<" Priority : "<<q[i].pr<<"\n";
		}
	}

};

int main(){
	PriorityQueue q;
	while(true){
		cout << "1. Insert Job" << endl;
		cout << "2. Delete Job" << endl;
		cout << "3. Display Job" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter Choice::--" << endl;
		int ch;
		cin >> ch;
		if(ch==1){
			Node<string> j;
			cout<<"Enter Job : "<<endl;
			cin.ignore();
			getline(cin,j.job);
			cout<<"Enter Job Priority"<<endl;
			cin>>j.pr;
			q.insertJob(j);
		}
		else if(ch==2){
			q.deleteJob();
		}
		else if(ch==3){
			q.displayJob();
		}
		else if(ch==4) break;
		else continue;
	}
}