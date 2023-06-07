#include <bits/stdc++.h>
using namespace std;

class Data{
	unsigned long long int num;
	string name;


public:
	Data(string n,unsigned long long int no){
		name=n;
		num=no;
	}
    void display(){
    	cout<<"Name : "<<name<<"\t";
    	cout<<"Tel. No. : "<<num<<endl;
    }
    friend class HashMap;
};

const int size=10;

class HashMap{
	Data* mp[size]={NULL};
public:
	void insertWithoutRepl(string k,unsigned long long int no){
		Data *d=new Data(k,no);

		int hs=hashKey(k);
		int index=hs%size;
		cout<<"Hashed index :"<<index<<endl;
		if(mp[index]==NULL){
			mp[index]=d;
			cout<<"Record inserted at :"<<index<<endl;
			return;
		}

		if(mp[index]!=NULL)
		index=linProbe(index);
		if(index==-1){
			cout<<"Cannot Insert"<<endl;
			return;
		}
		mp[index]=d;
		cout<<"Record inserted at :"<<index<<endl;

	}
	void insertWithRepl(string k,unsigned long long int no){
		Data *d=new Data(k,no);

		int hs=hashKey(k);
		int index=hs%size;
		cout<<"Hashed index :"<<index<<endl;
		if(mp[index]==NULL){
			mp[index]=d;
			cout<<"Record inserted at :"<<index<<endl;
			return;
		}
		if((hashKey(mp[index]->name)%size)!=index){
			cout<<"Hashed index of existing record : "<<hashKey(mp[index]->name)%size<<endl;
			Data *temp=d;
			d=mp[index];
			mp[index]=temp;
			cout<<k<<" Record inserted at :"<<index<<endl;
		}
		index=linProbe(index);
		if(index==-1){
			cout<<"Cannot Insert"<<endl;
			return;
		}
		mp[index]=d;
		cout<<d->name<<" Replaced at :"<<index<<endl;
	}

	int hashKey(string key){
		int h=0;
		for(long unsigned int i=0;i<key.length();i++)
		{
			h+=(i+1)*key[i];
		}

		return h;
	}

	void search(string key){
		int hs=hashKey(key);
		int index=hs%size;
		int i=index;
		int k=1;

		if(mp[index]->name==key){
			mp[index]->display();
			cout<<"\nComparisons : "<<k<<endl;
			return;
		}
		index++;
		k++;
		while(mp[index]->name!=key && index!=i){
			index++;
			k++;
			index=index%size;
		}
		if(index!=i){
			mp[index]->display();
			cout<<"\nComparisons : "<<k<<endl;
			return;
		}
		else
			cout<<"Person not listed in directory"<<endl;

	}

	int linProbe(int stInd){
		int index=stInd+1;
		while(mp[index]!=NULL &&index!=stInd){
			index++;
			index=index%size;
		}
		if(index==stInd) return -1;
		return index;
	}

	void deletion(string key){
		int hs=hashKey(key);
		int index=hs%size;
		int i=index;
		if(mp[index]->name==key){
			delete mp[index];
			mp[index]=NULL;
			cout<<"Record deleted successfully"<<endl;
			return;
		}
		while(mp[index]->name!=key && index!=i){
			index++;
			index=index%size;
		}
		if(index!=i){
			delete mp[index];
			mp[index]=NULL;
			cout<<"Record deleted succesfully"<<endl;
			return;
		}
		else{
			cout<<"Person not listed in directory"<<endl;
		}

	}

	void display(){
		for(int i=0;i<size;i++){
			if(mp[i]!=NULL){
				cout<<"index :"<<i<<"\t";
				mp[i]->display();
			}
		}
	}

};

int main() {
	HashMap mp_repl;
	HashMap mp_w;
	while(true){
		cout<<"Telephone Directory Program\n";
		cout<<"1. Insert a new no. in directory "<<endl;
		cout<<"2. Search by name in directory"<<endl;
		cout<<"3. Delete a record in directory"<<endl;
		cout<<"4. Display complete directory"<<endl;
		cout<<"5. Exit"<<endl;

		int res;
		cout<<"Enter your choice: ";
		cin>>res;

		if(res==1){
			string key;
			unsigned long long int val;
			cout<<"Enter Name: ";
			cin>>key;
			cout<<"Enter Telephone No: "<<endl;
			cin>>val;
			cout<<"Without Replacement : "<<endl;
			mp_w.insertWithoutRepl(key,val);
			cout<<"With Replacement : "<<endl;
			mp_repl.insertWithRepl(key,val);
		}

		else if(res==2){
			string key;
			cout<<"Enter Name: ";
			cin>>key;
			cout<<"Without Replacement :"<<endl;
			mp_w.search(key);
			cout<<"With Replacement :"<<endl;
			mp_repl.search(key);
		}
		else if(res==3){
			string key;
			cout<<"Enter Name: ";
			cin>>key;
			cout<<"Without Replacement :"<<endl;
			mp_w.deletion(key);
			cout<<"With Replacement :"<<endl;
			mp_repl.deletion(key);
		}
		else if(res==4){
			cout<<"Without Replacement :"<<endl<<endl;
			mp_w.display();
			cout<<"With Replacement :"<<endl<<endl;
			mp_repl.display();
		}
		else if(res==5) break;

		else continue;
	}
	return 0;
}