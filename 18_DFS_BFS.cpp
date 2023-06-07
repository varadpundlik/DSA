#include <bits/stdc++.h>
using namespace std;

const int N=10;
bool vis1[N], vis2[N];

class Node{
	int data;
	Node* next;
public:
	Node(int d){
		data=d;
		next=NULL;
	}
	friend class Graph;
};

class Graph{
	Node** gr;
	Node**reverse;
	int n;
	int traversable;
public:
	Graph(int num){
		n=num;
		gr=new Node*[n];
		reverse=new Node*[n];
		for(int i=0;i<n;i++){
			gr[i]=NULL;
			reverse[i]=NULL;
		}
		traversable=0;
	}
	void Insert(Node* &head ,int d){
		Node* n1=new Node(d);
		Node* temp=head;
		if(head==NULL){
			head=n1;
			return;
		}
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n1;
		return;
	}
	void ReadGraph(){
		cout<<"********Creating Graph**********\n\n\n";
		for(int i=0;i<n;i++){
			int nEdge;
			cout<<"Enter No. of edges of "<<i<<" : ";
			cin>>nEdge;
			cout<<endl;
			for(int j=0;j<nEdge;j++){
				int d;
				cout<<"Enter the neighbour of "<<i<<" : ";
				cin>>d;
				Insert(gr[i],d);
				Insert(reverse[d],i);
			}
			cout<<endl;
		}
	}

	void PrintGraph(){
		cout<<"*********Displaying Graph********\n\n";
		for(int i=0;i<n;i++){
			cout<<"Vertex "<<i<<" is connected with :";
			Node* temp=gr[i];
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		cout<<"\n\n";
		cout<<"*********Displaying Graph********\n\n";
		for(int i=0;i<n;i++){
			cout<<"Vertex "<<i<<" is connected with :";
			Node* temp=reverse[i];
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	void BFS_traversal(int k){
		bool visited[n];
		for(int i=0;i<n;i++) visited[i]=false;
		queue<int>q;

		cout<<endl;

		q.push(k);
		visited[k]=true;

		while(!q.empty()){
			int temp=q.front();
			cout<<q.front()<<" ";
			q.pop();
			Node* t=gr[temp];
			while(t!=NULL){
				if(visited[t->data]==false){
					visited[t->data]=true;
					q.push(t->data);
				}
				t=t->next;
			}
		}
		cout<<endl;
	}

	void DFS_traversal(int k){
		int tr=0;
		stack<int>st;


		cout<<endl;

		st.push(k);
		vis1[k]=true;
		while(!st.empty()){
			int temp=st.top();
			cout<<temp<<" ";
			st.pop();
			tr++;
			Node* t=gr[temp];
			while(t!=NULL){
				if(vis1[t->data]==false){
					st.push(t->data);
					vis1[t->data]=true;
				}
				t=t->next;
			}
		}
		cout<<endl;
	}

	void DFS_reverse(int k){
		int tr=0;
		stack<int>st;
		cout<<endl;
		st.push(k);
		vis2[k]=true;
		while(!st.empty()){
			int temp=st.top();
			cout<<temp<<" ";
			st.pop();
			tr++;
			Node* t=reverse[temp];
			while(t!=NULL){
				if(vis2[t->data]==false){
					st.push(t->data);
					vis2[t->data]=true;
				}
				t=t->next;
			}
		}
		cout<<endl;
	}

	void isConnected(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) vis1[i]=false;
			DFS_traversal(i);

			for (int k = 0; k < n; k++) {
				if (vis1[k]==false){
					cout<<"Graph is not strongly connected"<<endl;
					return;
				}
			}
		}
		cout<<"Grpah is connected"<<endl;

	}

	void degree(){
		for(int i=0;i<n;i++){
			cout<<"Outdegree of Vertex "<<i<<" is :";
			Node* temp=gr[i];
			int degree=0;
			while(temp!=NULL){
				degree++;
				temp=temp->next;
			}
			cout<<degree<<endl;
		}

		cout<<"\n\n";

		for(int i=0;i<n;i++){
			cout<<"Indegree of Vertex "<<i<<" is :";
			int indegree=0;
			for(int  j=0;j<n;j++){
				Node* temp=gr[j];
				while(temp!=NULL){
					if(temp->data==i){
						indegree++;
						break;
					}
					temp=temp->next;
				}
			}
			cout<<indegree<<endl;
		}
	}
};

int main() {
	int nV;
	cout<<"Enter No. of vertices : ";
	cin>>nV;
	Graph g(nV);
	while(true){
		cout<<"1.Create the graph"<<endl;
		cout<<"2.Print the graph in adjecency list form"<<endl;
		cout<<"3.DFS traversal"<<endl;
		cout<<"4.BFS traversal"<<endl;
		cout<<"5.Show degree of each vertex"<<endl;
		cout<<"6.Check whether the graph is connected or disconnected"<<endl;
		cout<<"7.exit"<<endl;
		int res;
		cout<<"\nEnter your responce :";
		cin>>res;
		if(res==1) g.ReadGraph();
		else if(res==2) g.PrintGraph();
		else if(res==3) {
			for(int i=0;i<10;i++) vis1[i]=false;
			cout<<"**********DFS traversal*******\n\n";
			cout<<"Enter the starting vertex for DFS :";
			int k;
			cin>>k;
			g.DFS_traversal(k);
		}
		else if(res==4) {
			cout<<"**********BFS traversal*******\n\n";
			cout<<"Enter the starting vertex for BFS :";
			int k;
			cin>>k;
			g.BFS_traversal(k);
		}
		else if(res==5) g.degree();
		else if(res==6) g.isConnected();
		else if(res==7) break;
		else continue;

	}
	return 0;
}