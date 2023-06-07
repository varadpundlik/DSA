#include <bits/stdc++.h>
using namespace std;


class Edge{
public:
	int weight;
	int src;
	int destn;

	Edge(int w,int s,int d){
		weight=w;
		src=s;
		destn=d;
	}
};

vector<Edge> edge;

class Graph{
public:
	int **gr;
	int n;
	Graph(){
		int n1;
		cout<<"Enter the no. of vertices in graph : ";
		cin>>n1;
		n=n1;
		gr=new int*[n];
		for(int i=0;i<n;i++){
			gr[i]=new int[n];
			for(int j=0;j<n;j++){
				gr[i][j]=0;
			}
		}
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
				cout<<"Enter weight of edge("<<i<<","<<d<<") : ";
				int w;
				cin>>w;
				gr[i][d]=w;
			}
			cout<<endl;
		}
	}

	void PrintGraph()
	{
		for(int i=0;i<n;i++){
			cout<<"Vertex "<<i<<" : ";
			for(int j=0;j<n;j++){
				cout<<gr[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	void prim(){
		int mst[n][n];
		int ver[n];
		int cost=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				mst[i][j]=0;
			}
			ver[i]=0;
		}
		EdgesList();
		cout<<"Sorted Edge List"<<endl;
		cout<<"W\tS\tD"<<endl;
		for(auto ed:edge){
			cout<<ed.weight<<"\t"<<ed.src<<"\t"<<ed.destn<<endl;
		}
		int s=0;
		while(s<n-1){
			if(s==0){
				Edge e=edge[0];
				ver[e.src]=1;
				ver[e.destn]=1;
				mst[e.src][e.destn]=e.weight;
				mst[e.destn][e.src]=e.weight;
				cost+=e.weight;
				s++;
			}
			for(int j=0;j<edge.size();j++){
				Edge e=edge[j];
				if(ver[e.src]==0 ^ ver[e.destn]==0){
					ver[e.src]=1;
					ver[e.destn]=1;
					mst[e.src][e.destn]=e.weight;
					mst[e.destn][e.src]=e.weight;
					s++;
					cost+=e.weight;
					break;
				}
			}
		}
		cout<<"Prim's MST"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mst[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"Total cost of MST : "<<cost<<endl;

	}

	void kruskal(){
		int mst[n][n];
		int ver[n];
		int cost=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				mst[i][j]=0;
			}
			ver[i]=i;
		}
		EdgesList();
		cout<<"Sorted Edge List"<<endl;
		cout<<"W\tS\tD"<<endl;
		for(auto ed:edge){
			cout<<ed.weight<<"\t"<<ed.src<<"\t"<<ed.destn<<endl;
		}
		int j=0;
		int s=0;
		while(s<n-1){
			Edge e=edge[j];
			if(ver[e.src]!=ver[e.destn]){
				mst[e.src][e.destn]=e.weight;
				mst[e.destn][e.src]=e.weight;
				cost+=e.weight;
				s++;
				cout<<"Edge added : "<<e.weight<<"\t"<<e.src<<"\t"<<e.destn<<endl;
				for(int i=0;i<n;i++){
					if(ver[i]==ver[e.src]){
						ver[i]=ver[e.destn];
					}
				}
			}
			j++;
		}
		cout<<"Kruskal's MST"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mst[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"Total cost of MST : "<<cost<<endl;
	}

	void EdgesList(){
		edge.clear();
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(gr[i][j]!=0){
					Edge e(gr[i][j],i,j);
					edge.push_back(e);
				}
			}
		}

		sort(edge.begin(),edge.end(),[](Edge a, Edge b){ return a.weight < b.weight; });
	}


};
int main() {
	cout<<"*************Minimum Spanning Tree*************"<<endl<<endl;
	Graph g;
	g.ReadGraph();
	while(true){
		cout<<"\n\n1. Print Graph"<<endl;
		cout<<"2. Print MST by Prim's Algorithm"<<endl;
		cout<<"3. Print MST by Kruskal's Algorithm"<<endl;
		cout<<"4. Exit"<<endl;
		int res;
		cout<<"Enter your response : ";
		cin>>res;
		cout<<endl;
		if(res==1) g.PrintGraph();
		else if(res==2) g.prim();
		else if(res==3) g.kruskal();
		else if(res==4) break;
		else continue;
	}
	return 0;
}