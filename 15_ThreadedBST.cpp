#include <bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node* left;
	Node*right;
	bool l_thread,r_thread;
public:
	Node(int d){
		data=d;
		left=right=NULL;
		l_thread=r_thread=true;
	}
	friend class ThreadedBST;
};

class ThreadedBST{
public:
	Node* root;

	ThreadedBST(){
		root = NULL;
		cout << "Creation of Threaded Binary Search Tree" << endl;
        cout << "Enter no. of nodes : " << endl;
        int n;
        cin >> n;
        cout << "Enter values of each node : " << endl;
        int a[n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	insert(a[i]);
        }
	}

    void insert(int key){
    	Node* newNode=new Node(key);
    	if(root==NULL){
    		root=newNode;
    		cout<<key<<" Added as root"<<endl;
    		return;
    	}
    	Node* temp=root;
    	Node* parent=NULL;
    	while(temp!=NULL){
    		if(key==temp->data){
    			return;
    		}
    		parent=temp;
    		if(key<temp->data){
    			if(temp->l_thread==false) temp=temp->left;
    			else break;
    		}
    		else{
    			if(temp->r_thread==false) temp=temp->right;
    			else break;
    		}
    	}
    	if(key<temp->data){
    		newNode->left=parent->left;
    		newNode->right=parent;
    		parent->l_thread=false;
    		parent->left=newNode;
    	}
    	else{
    		newNode->left=parent;
    		newNode->right=parent->right;
    		parent->r_thread=false;
    		parent->right=newNode;
    	}
    }

    void inorder(Node* root){
    	Node* temp=leftMost(root);
    	while(temp!=NULL){
    		cout<<temp->data<<" ";
    		if(temp->r_thread==true) temp=temp->right;
    		else {
    			temp=temp->right;
    			temp=leftMost(temp);
    		}
    	}
    	cout<<endl;
    }

    Node* leftMost(Node* temp){
    	if(temp==NULL) return NULL;
    	while(temp->left!=NULL && temp->l_thread==false){
    		temp=temp->left;
    	}
    	return temp;
    }

    Node* inSucc(Node *temp){
    	if(temp->r_thread==true){
    		return temp->right;
    	}
    	else{
    		temp=temp->right;
    		return leftMost(temp);
    	}
    }

    Node* inPred(Node* temp){
          return temp->left;
    }

    void preorder(Node* root){
    	if(root==NULL) return;
    	Node* temp=root;
    	while(temp!=NULL){
    		cout<<temp->data<<" ";
    		if(temp->l_thread==false)
    			temp=temp->left;
    		else if(temp->r_thread==false)
    			temp=temp->right;
    		else{
    			while(temp!=NULL && temp->r_thread==true)
    				temp=temp->right;
    			if(temp!=NULL)
    				temp=temp->right;
    		}
    	}
    	cout<<endl;
    }

    void deletion(int key){
    	Node* temp=root;
        Node* parent=NULL;
       	while(temp!=NULL){
       		if(key==temp->data){
    			break;
    	    }
    	    parent=temp;
    	    if(key<temp->data){
    	    	if(temp->l_thread==false) temp=temp->left;
    	    	else break;
    	    }
    	    else{
    	    	if(temp->r_thread==false) temp=temp->right;
    	    	else break;
    	    }
        }
       	if(key!=temp->data){
       		cout<<key<<" not found"<<endl;
       		return;
       	}
       	else if (temp->l_thread == true && temp->r_thread == true){
       		if (parent == NULL)
       		    root = NULL;

       		else if (temp == parent->left) {
       		   	parent->l_thread = true;
       		    parent->left = temp->left;
       		}
       		else {
       		    parent->r_thread = true;
       		    parent->right = temp->right;
       		}
       		delete temp;
           	cout<<key<<" Successfully deleted"<<endl;
           	return;
       	}
       	else if((temp->l_thread==true && temp->r_thread==false) || (temp->l_thread==false && temp->r_thread==true)){
       		Node* child;
       		if(temp->l_thread==false)
       			child=temp->left;
       		else
       			child=temp->right;
       		if(parent==NULL){
       			root=child;
       		}
       		if(temp==parent->left){
       			parent->left=child;
       		}
       		else parent->right=child;
       		Node* s=inSucc(temp);
       		Node* p=inPred(temp);

       		if(temp->l_thread==false){
       			p->right=s;
       		}
       		else{
       			s->left=p;
       		}
       		delete temp;
           	cout<<key<<" Successfully deleted"<<endl;
           	return;
       	}
       	else{

       		Node* s=inSucc(temp);
       		int t=s->data;
            deletion(s->data);
       	   	temp->data=t;
       	}

    }
};

int main() {
	ThreadedBST b;
	while(true){
		cout<<"Implementation of Threaded BST"<<endl<<endl;
		cout<<"1. Traversal of Threaded BST"<<endl;
		cout<<"2. Delete a node from Threaded BST"<<endl;
		cout<<"3. Exit"<<endl;
		int res;
		cout<<"Enter your choice : ";
		cin>>res;
		if(res==1){
			cout<<"Inorder :";
			b.inorder(b.root);
			cout<<"Preorder :";
			b.preorder(b.root);
			cout<<endl;
		}
		else if(res==2){
			int n;
			cout<<"Enter a no. to delete from threaded BST : ";
			cin>>n;
			b.deletion(n);
			cout<<"After deletion : "<<endl;
			cout<<"Inorder :";
			b.inorder(b.root);
			cout<<"Preorder :";
			b.preorder(b.root);
			cout<<endl;
		}
		else if(res==3){
			cout<<"Terminating program"<<endl;
			break;
		}
		else continue;
	}

	return 0;
}