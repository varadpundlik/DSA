#include <bits/stdc++.h>
using namespace std;
const int n=100;
class Heap{
public:
	int arr[n];
	int m;
	Heap(){
		m=0;
	}
	void heapify(int m1,int i){
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		if(l<m1 && arr[l]>arr[largest]){
			largest=l;
		}
		if(r<m1 && arr[r]>arr[largest]){
				largest=r;
		}
		if(i!=largest){
			int temp=arr[i];
			arr[i]=arr[largest];
			arr[largest]=temp;
			heapify(m1,largest);
		}
	}

	void HeapSort(){
		for(int i=m/2-1;i>=0;i--){
			heapify(m,i);
		}
		for(int i=m-1;i>0;i--){
			int temp=arr[i];
			arr[i]=arr[0];
			arr[0]=temp;
			heapify(i,0);
		}
	}

	void PrintHeap(){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	void Insert(int d){
		if(m==-1){
			arr[m++]=d;
		}
		else{
			arr[m++]=d;
			for(int i=m/2-1;i>=0;i--){
				heapify(m,i);
			}
		}
	}

	void Delete(int d){
		int i;
		for(i=0;i<m;i++){
			if(arr[i]==d) break;
		}
		arr[i]=arr[m-1];
		arr[m-1]=0;
		m--;

		for(int i=m/2 -1;i>=0;i--){
			heapify(m,i);
		}
	}

};



int main() {
	Heap h;
	while(true){
		cout<<"1. Insert element in Heap"<<endl;
		cout<<"2. Display the Heap"<<endl;
		cout<<"3. HeapSort"<<endl;
		cout<<"4. Delete element from Heap"<<endl;
		cout<<"5. Exit"<<endl;
	    cout<<"Enter your response : ";
		int res;
		cin>>res;
		if(res==1){
			int val;
			cout<<"Enter data to insert : ";
			cin>>val;
			h.Insert(val);
		}
		else if(res==2) h.PrintHeap();
		else if(res==3){
			h.HeapSort();
			h.PrintHeap();
		}
		else if(res==4){
			int val;
			cout<<"Enter data to delete : ";
			cin>>val;
			h.Delete(val);
		}
		else if(res==5) break;
		else continue;
	}
	return 0;
}