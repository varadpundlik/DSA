#include<iostream>
#include<string>
using namespace std;

class queue{
	string q[20];
	int front=-1,rear=-1;
public:
	void insertJob(string data){
		if(front==-1){
			front=rear=0;
			q[rear]=data;
		}
		if(rear==19){
			cout<<"Queue Overflow"<<endl;
			return;
		}
		else q[++rear]=data;
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
			cout<<q[i]<<endl;
		}
	}
};

int main(){
	queue q;
	while(true){
		cout << "1. Insert Job" << endl;
		cout << "2. Delete Job" << endl;
		cout << "3. Display Job" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter Choice::--" << endl;
		int ch;
		cin >> ch;
		if(ch==1){
			string job;
			cout<<"Enter Job : "<<endl;
			cin.ignore();
			getline(cin,job);
			q.insertJob(job);
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