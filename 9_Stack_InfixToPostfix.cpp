#include <iostream>
#include<string>
using namespace std;

template <class t>
class Stack{
	t st[20];
	int top=-1;

public:

	void push(char data){
		top++;
		if(top==20){
			return;
		}
		st[top]=data;
	}

	void pop(){
		if(top==-1){
			return;
		}
		top--;
	}

	t top_ele(){
		if(top==-1) return 'e';
		return st[top];
	}

	bool isEmpty(){
		return top==-1;
	}
};

Stack<char> st;
Stack <int> s1;

int precedance(char ch){
	if(ch=='-') return 1;
	if(ch=='+') return 2;
	if(ch=='*') return 3;
	if(ch=='/') return 4;
	if(ch=='%') return 5;
	else return 0;
}

string postfix(string s){
	string inf=" ";

	for(int i=0;i<s.length();i++){

		if(s[i]>='a' && s[i]<='z'){
			inf+=s[i];
		}
		else if(s[i]=='(') st.push(s[i]);

		else if(s[i]==')'){
			while(st.top_ele()!='('){
				inf+=st.top_ele();
				st.pop();
			}
		}

		else if(s[i]>='0' && s[i]<='9'){
			inf+=s[i];
		}

		else{
			while(st.isEmpty()==false && precedance(s[i]) <= precedance(st.top_ele()) && st.top_ele()!='('){
				inf+=st.top_ele();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.isEmpty()){
		if(st.top_ele()!='('){
			inf+=st.top_ele();
		}
		st.pop();
	}
	return inf;
}

int eval(char ch,int x,int y){
	if(ch=='-') return y-x;
	if(ch=='+') return y+x;
	if(ch=='*') return y*x;
	if(ch=='/') return y/x;
	if(ch=='%') return y%x;
	else return 0;
}

int  evaluation(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			s1.push(s[i]-'0');
		}
		else{
			int x=s1.top_ele();
			s1.pop();
			int y=s1.top_ele();
			s1.pop();
			int z=eval(s[i],x,y);
			s1.push(z);
		}
	}
	int ans=s1.top_ele();
	s1.pop();
	return ans;
}

int main() {
	string exp;
	cout<<"Enter an infix expression"<<endl;
	getline(cin,exp);
	string po=postfix(exp);
	cout<<"Postfix expression"<<po<<endl;
	cout<<"Ans : "<<evaluation(po)<<endl;
	return 0;
}