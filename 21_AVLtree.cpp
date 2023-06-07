#include<bits/stdc++.h>
using namespace std;

class Node{
    string word,meaning;
    Node* right;
    Node* left;
    int height;
public:
    Node(string w,string m){
        word=w;
        meaning=m;
        height=0;
        left=right=NULL;
    }
    friend class AVLtree;
};

class AVLtree{
    Node* ll(Node* p){
        Node*pl=p->left;
        
        p->left=pl->right;
        pl->right=p;

        p->height=calculate_height(p);
        pl->height=calculate_height(pl);
        if(root==p) root=pl;
        return pl;
    }
    Node* rr(Node* p){
        Node* pr=p->right;

        p->right=pr->left;
        pr->left=p;

        p->height=calculate_height(p);
        pr->height=calculate_height(pr);
        if(root==p) root=pr;
        return pr;
    }
    void rl(){
        
    }
    void lr(){

    }
    int calculate_height(Node* n){
        if(n==NULL) return 0;
        else return 1+max(calculate_height(n->left),calculate_height(n->right));
    }
    int bf(Node* n){
        return calculate_height(n->left)-calculate_height(n->right);
    }
public:
    Node* root;
    void insert(){

    }
    void search(){

    }
    void inorder(){

    }
    void preorder(){

    }
    void remove(){

    }
    void update(){

    }
};

int main(){

}