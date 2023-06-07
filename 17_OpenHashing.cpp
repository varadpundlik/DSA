#include <bits/stdc++.h>
#define size 10
using namespace std;

class Node{
    string key;
    string value;
    Node* next;

public:

    Node(){
    	key="";
    	value="";
    	next=NULL;
    }

    Node(string k,string v){
       	key=k;
       	value=v;
        next=NULL;
    }

    friend class OpenHashing;
};

class OpenHashing{
    Node **hashArray = new Node*[size];
public:

    OpenHashing()
    {
        for(int i=0;i<size;i++)
        hashArray[i]=NULL;
    }

    void InsertAtBegin(Node *&head, string key, string value)
    {
        Node *p1 = new Node(key,value);
        if(head==NULL)
        head=p1;
        else
        {
            p1->next = head;
            head = p1;
        }
    }

    int HashFunction(string key)
    {
		int h=0;
		for(long unsigned int i=0;i<key.length();i++)
		{
			h+=key[i];
		}

		return h%size;
    }

    void Insert(string key, string value)
    {
        int index = HashFunction(key);
        InsertAtBegin(hashArray[index],key,value);
    }

    void Search(string key)
    {
        int index = HashFunction(key);
        Node *p = hashArray[index];
        while(p!=NULL)
        {
            if(p->key==key){
            	cout<<"Element present at index :"<<index<<endl;
            	return;
            }
            p=p->next;
        }
        cout<<"Elemrnt not found"<<endl;
    }

    void Delete(string key)
    {

        int index = HashFunction(key);
        Node *P = hashArray[index];
        Node *Q = NULL;

        while (P != NULL && P->key != key){
            Q = P;
            P = P->next;
        }
        if(P==NULL){
            cout << "Key is not present in the hash table." << endl;
            return;
        }
        if (Q == NULL){
            hashArray[index] = P->next;
            P->next = NULL;
            delete P;
            cout<<key<<" deleted successfully"<<endl;
        }
        else{
            Q->next = P->next;
            P->next = NULL;
            delete P;
            cout<<key<<" deleted successfully"<<endl;
        }
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
            Node *P = hashArray[i];
            while (P != NULL)
            {
                cout << "{" << P->key << ":" << P->value << "}";
                if(P->next) cout<<"->";
                P = P->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    OpenHashing h;
    while (true)
    {
    	cout<<"*********Open Hashing Implementation***********";
        cout << "\n\n\n1.Insert key\n2.Display Hash Table\n3.Delete key\n4.Find key\n5.Exit" << endl;
        cout<<"\nEnter your choice : ";
        int n;
        cin >> n;
        if (n == 1)
        {
            string s, s1;
            cout << "Enter the key you want to insert" << endl;
            cin.ignore();
            getline(cin, s);
            cout << "Enter the value you want to insert" << endl;
            getline(cin, s1);
            h.Insert(s, s1);
        }
        else if (n == 2)
            h.Display();
        else if (n == 3)
        {
            string s;
            cout << "Enter the key you want to delete" << endl;
            cin.ignore();
            getline(cin, s);
            h.Delete(s);
        }
        else if (n == 4)
        {
            string s;
            cout << "Enter the key you want to find" << endl;
            cin.ignore();
            getline(cin, s);
            h.Search(s);
        }
        else if (n==5)
        break;
        else
        cout<<"Invalid choice. Please enter a valid number from 1 to 5."<<endl;
    }

    return 0;
}
