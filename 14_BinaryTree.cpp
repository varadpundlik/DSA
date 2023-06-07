#include <bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node*left,*right;
public:
	Node(int d){
		data=d;
		left=right=NULL;
	}
	friend class BT;
};

class BT{
public:
	Node* root;
	int leaf,count,internal;
	BT(){
		root=NULL;
		leaf=0;
		internal=0;
		count=0;
	}
	void create(){
		queue<Node*> q;
		int data;
		cout<<"Enter value of root : ";
		cin>>data;
		Node* newNode=new Node(data);
		if(root==NULL){
			root=newNode;
			q.push(root);
			count++;
		}
		while(!q.empty()){
			Node* parent=q.front();
			q.pop();
			int r_data,l_data;
			cout<<"Enter data for left and right children (enter 0 for NULL) of "<<parent->data<<" :"<<endl;
			cin>>l_data>>r_data;
			if(l_data!=0){
				parent->left=new Node(l_data);
				q.push(parent->left);
				count++;
			}
			if(r_data!=0){
				parent->right=new Node(r_data);
				q.push(parent->right);
				count++;
			}
			if(l_data==0 && r_data==00) leaf++;

		}
	}
	void inorder(Node* n){
		if(n!=NULL){
			inorder(n->left);
			cout<<n->data<<" ";
			inorder(n->right);
		}
	}
	void preorder(Node* n){
		if(n!=NULL){
			cout<<n->data<<" ";
			preorder(n->left);
			preorder(n->right);
		}
	}
	void iterative_inorder(){
		stack<Node*> s;
		Node* temp=root;
		while(!s.empty() || temp!=NULL){
			if(temp!=NULL){
				s.push(temp);
				temp=temp->left;
			}
			else{
				temp=s.top();
				s.pop();
				cout<<temp->data<<" ";
				temp=temp->right;
			}
		}
	}
	void iterative_preorder(){
		stack<Node*> s;
		s.push(root);
		while(!s.empty()){
			Node* n = s.top();
			cout<<n->data<<" ";
			s.pop();
			if (n->right)
			    s.push(n->right);
			if (n->left)
			    s.push(n->left);
		}
	}
	void postorder(Node* n){
		if(n!=NULL){
			postorder(n->left);
			postorder(n->right);
			cout<<n->data<<" ";
		}
	}
	void iterative_postorder(){
		if (root == NULL) {
		    return;
		}
		stack<Node*> s;
		s.push(root);
		stack<int> out;
		while (!s.empty())
		{
		    Node* curr = s.top();
		    s.pop();
		    out.push(curr->data);
		    if (curr->left) {
		        s.push(curr->left);
		    }
		    if (curr->right) {
		        s.push(curr->right);
		    }
		}
		while (!out.empty())
		{
            cout << out.top() << " ";
	        out.pop();
	    }

	}
	void status(){
		cout<<"Total no.of nodes : "<<count<<endl;
		cout<<"Total no.of internal nodes : "<<count-leaf<<endl;
		cout<<"Total no.of leaf nodes : "<<leaf<<endl;
	}
	int height(Node* n){
		if(n==NULL) return 0;
		return max(1+height(n->left),1+height(n->right));
	}
	void swap(Node* n){
		Node *parent = n;
		if (parent != NULL)
	    {
	        if (parent->left != NULL && parent->right != NULL)
		    {
		        Node *temp = parent->left;
		        parent->left = parent->right;
		        parent->right = temp;
		    }
		    swap(parent->left);
		    swap(parent->right);
		 }
	}
	void erase(Node* n){
		if(n==NULL) return;
		erase(n->left);
		erase(n->right);
		cout<<"Deleting "<<n->data<<endl;
		delete n;
	}
	void display(){
		cout<<"Inorder :";
		inorder(root);
		cout<<"\nIterative Inorder :";
		iterative_inorder();

		cout<<"\nPreorder :";
		preorder(root);
		cout<<"\nIterative Preorder :";
		iterative_preorder();

		cout<<"\nPostorder :";
		postorder(root);
		cout<<"\nIterative Postorder :";
		iterative_postorder();
	}
	Node* copy(Node* root){
	    if (root == nullptr) {
	        return nullptr;
	    }
	    Node* root_copy = new Node(root->data);
	    root_copy->left = copy(root->left);
	    root_copy->right = copy(root->right);
	    return root_copy;
	}
	int minValue(Node* temp){
		if(temp==NULL) return INT_MAX;
		return min({temp->data,minValue(temp->left),minValue(temp->right)});
	}
	int maxValue(Node* temp){
		if(temp==NULL) return INT_MIN;
		return max({temp->data,maxValue(temp->left),maxValue(temp->right)});
	}
	void operator=(BT b){
		root=copy(b.root);
	}
};



int main() {
	BT btr;
	cout<<"**********Creation of a binary tree**********"<<endl;
	btr.create();
	while(true){
		cout<<"\n\n\n**********Operations on binary tree**********"<<endl;
		cout<<"1.Display Binary tree"<<endl;
		cout<<"2.Find no. of leaf and internal nodes of Binary tree"<<endl;
		cout<<"3.Display Maximum height of Binary tree"<<endl;
		cout<<"4.Swap the Binary tree"<<endl;
		cout<<"5.Erase the entire Binary tree"<<endl;
		cout<<"6.Copy the binary tree into another binary tree"<<endl;
		cout<<"7.Min. and max. values in binary tree"<<endl;
		cout<<"8.Exit"<<endl<<endl;
		cout<<"Enter your choice : ";
		int res;
		cin>>res;

		if(res==1){
			btr.display();
		}
		else if(res==2){
			btr.status();
		}
		else if(res==3){
			cout<<"Max Height of Binary tree : "<<btr.height(btr.root)<<endl;
		}
		else if(res==4){
			btr.swap(btr.root);
			cout<<"Binary tree after swapping"<<endl;
			btr.display();
		}
		else if(res==5){
			btr.erase(btr.root);
			cout<<"Binary tree erased"<<endl;
		}
		else if(res==6){
			BT b1;
			b1=btr;
			cout<<"Copied Binary tree: "<<endl;
			b1.display();
		}
		else if(res==7){
			cout<<"Minimum value : "<<btr.minValue(btr.root)<<endl;
			cout<<"Maximum value : "<<btr.maxValue(btr.root)<<endl;
		}
		else if(res==8){
			cout<<"Terminating program"<<endl;
			break;
		}
		else{
			cout<<"Invalid input"<<endl;
			continue;
		}
	}
	return 0;
}