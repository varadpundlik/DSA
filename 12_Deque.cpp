#include <iostream>
using namespace std;

class dequeue{
	string q[20];
	int front=-1,rear=-1;
public:
	void insertFromEnd(string data){
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
		}
		cout<<"Job Inserted Successfully"<<endl;
		displayJob();
	}

	void insertFromStart(string data){
			if(front==-1){
				front=rear=0;
				q[rear]=data;
			}
			else if(front==0){
				cout<<"Cannot Insert from start"<<endl;
				return;
			}
			else{
				front--;
				q[front]=data;
			}
			cout<<"Job Inserted Successfully"<<endl;
			displayJob();
		}

	void deleteFromStart(){
		if(front==-1 || front==rear+1){
			cout<<"Queue Underflow"<<endl;
		}
		else{
			front++;
			cout<<"Job deleted successfully"<<endl;
			displayJob();
		}
	}

	void deleteFromEnd(){
		if(front==-1 || front==rear+1){
			cout<<"Queue Underflow"<<endl;
		}
		else{
			rear--;
			cout<<"Job deleted successfully"<<endl;
			displayJob();
		}
	}

	void displayJob(){
		if(front==-1 || front==rear+1){
			cout<<"Queue Underflow"<<endl;
		}
		for(int i=front;i<=rear;i++){
			cout<<q[i]<<endl;
		}
	}
};

int main() {
	dequeue q;
	while(true){
		cout << "1. Insert Data from End" << endl;
		cout << "2. Insert Data from Start" << endl;
		cout << "3. Delete Data from End" << endl;
		cout << "4. Delete Data from Start" << endl;
		cout << "5. Display Dequeue" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter Choice::--" << endl;
		int ch;
		cin >> ch;
		if(ch==1){
			string job;
			cout<<"Enter Job : "<<endl;
			cin.ignore();
			getline(cin,job);
			q.insertFromEnd(job);
		}
		else if(ch==2){
			string job;
			cout<<"Enter Job : "<<endl;
			cin.ignore();
			getline(cin,job);
			q.insertFromStart(job);
		}
		else if(ch==3){
			q.deleteFromEnd();
		}
		else if(ch==4){
			q.deleteFromStart();
		}
		else if(ch==5){
			q.displayJob();
		}
		else if(ch==6) break;
		else continue;
	}
	return 0;
}