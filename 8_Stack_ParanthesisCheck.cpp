#include<iostream>
#include<string>
using namespace std;

class Stack{
	char st[20];
	int top=-1;
public:
	void push(char data){
		top++;
		if(top==20){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		st[top]=data;
	}
	void pop(){
		if(top==-1){
			cout<<"Stack Underflow"<<endl;
			return;
		}
		top--;
	}
	char top_ele(){
		if(top==-1) return 'e';
		return st[top];
	}
	bool isEmpty(){
		return top==-1;
	}
};


int main(){
	Stack s;
	string exp;
	cout<<"Enter Parenthesis Expression : "<<endl;
	getline(cin,exp);
	for(int i=0;i<exp.length();i++){
		char c;
		if(exp[i]=='('){
			c='r';
			s.push(c);
		}
		if(exp[i]=='{'){
			c='c';
			s.push(c);
		}
		if(exp[i]=='['){
			c='s';
			s.push(c);
		}
		if(exp[i]==')'){
			c='r';
			if(s.top_ele()==c){
				s.pop();
			}
			else{
				cout<<"Not well parenthesized"<<endl;
				return 0;
			}
		}
		if(exp[i]=='}'){
			c='c';
			if(s.top_ele()==c){
			s.pop();
			}
			else{
				cout<<"Not well parenthesized"<<endl;
				return 0;
			}
		}
		if(exp[i]==']'){
			c='s';
			if(s.top_ele()==c){
				s.pop();
			}
			else{
				cout<<"Not well parenthesized"<<endl;
				return 0;
			}
		}
	}
	if(s.isEmpty()) cout<<"Expression is well parenthesized"<<endl;
	else cout<<"Not well parenthesized"<<endl;
	return 0;
}