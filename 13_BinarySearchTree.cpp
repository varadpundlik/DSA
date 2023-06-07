#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        root = NULL;
        cout << "Creation of Binary Search Tree" << endl;
        cout << "Enter no. of nodes : " << endl;
        int n;
        cin >> n;
        cout << "Enter values of each node : " << endl;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            root = addNode(root, a[i]);
        }
    }

    Node *addNode(Node *n, int d)
    {
        if (n == NULL)
        {
            Node *newNode = new Node(d);
            return newNode;
        }
        else if (d <= n->data)
        {
            n->left = addNode(n->left, d);
        }
        else
            n->right = addNode(n->right, d);
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
    int maxDepth(Node *n)
    {
        if (n == NULL)
            return 0;
        else
        {
            int l = maxDepth(n->left);
            int r = maxDepth(n->right);
            return max(l + 1, r + 1);
        }
    }

    int minValue(Node *n)
    {
        if (n->left == NULL)
        {
            return n->data;
        }
        else
            return minValue(n->left);
    }

    int maxValue(Node *n)
    {
        if (n->right == NULL)
        {
            return n->data;
        }
        else
            return maxValue(n->right);
    }

    void swapping(Node *root)
    {
        Node *parent = root;
        if (parent != NULL)
        {
            if (parent->left != NULL && parent->right != NULL)
            {
                Node *temp = parent->left;
                parent->left = parent->right;
                parent->right = temp;
            }
            swapping(parent->left);
            swapping(parent->right);
        }
    }

    void search(Node* &parent, Node* &curr, int key)
    {
        while (curr != NULL)
        {
            if (curr->data == key)
            {
                cout << "Element present in BST" << endl;
                return;
            }
            else if (curr->data > key)
            {
                parent = curr;
                curr = curr->left;
            }
            else
            {
                parent = curr;
                curr = curr->right;
            }
        }
        cout << "Element Not Found" << endl;
        return;
    }
    void deletenode(Node * &root, int key)
    {
        Node *parent = NULL;
        Node *curr = root;
        search(parent, curr, key);
        if (curr == NULL)
        {
            cout << key << " not present in BST" << endl;
            return;
        }
        if (curr->left == NULL && curr->right == NULL)
        {
            if (curr != root)
            {
                if (parent->left == curr)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else
                root = NULL;

            delete curr;
        }
        else if (curr->left && curr->right)
        {
            Node *succ = new Node(minValue(curr -> right));
            int val = succ->data;
            deletenode(root, succ->data);
            curr->data = val;
        }
        else
        {
            Node *child = (curr->left) ? curr -> left : curr->right;

            if (curr != root)
            {
                if (curr == parent->left)
                    parent->left = child;
                else
                    parent->right = child;
            }

            else
                root = child;
            delete curr;
        }
    }
};

int main()
{
    cout << "Binary Search Tree Implementation : " << endl;
    BinarySearchTree b;

    while (true)
    {
        cout << endl;
        cout << "1.Insert new element in BST" << endl;
        cout << "2.Traverse the BST" << endl;
        cout << "3.Longest path in BST from root" << endl;
        cout << "4.Max. and Min. value in BST" << endl;
        cout << "5.Change the tree so that the roles of the left and right pointers are swapped at every node" << endl;
        cout << "6.Search a node in BST" << endl;
        cout << "7.Delete a node" << endl;
        cout << "8.Exit" << endl;
        cout << endl;
        int res;
        cout << "Enter a choice : ";
        cin >> res;
        if (res == 1)
        {
            cout << "Enter the value of new Node : ";
            int data;
            cin >> data;
            b.addNode(b.root, data);
            cout << "Inorder : ";
            b.inorder(b.root);
            cout << endl;
            cout << "Preorder : ";
            b.preorder(b.root);
            cout << endl;
            cout << "Postorder : ";
            b.postorder(b.root);
            cout << endl;
        }
        else if (res == 2)
        {
            cout << "Inorder : ";
            b.inorder(b.root);
            cout << endl;
            cout << "Preorder : ";
            b.preorder(b.root);
            cout << endl;
            cout << "Postorder : ";
            b.postorder(b.root);
            cout << endl;
        }
        else if (res == 3)
        {
            cout << "Max. depth : " << b.maxDepth(b.root) << endl;
        }
        else if (res == 4)
        {
            cout << "Max. value : " << b.maxValue(b.root) << endl;
            cout << "Min. value : " << b.minValue(b.root) << endl;
        }
        else if (res == 5)
        {
            b.swapping(b.root);
            cout << "Inorder : ";
            b.inorder(b.root);
            cout << endl;
            cout << "Preorder : ";
            b.preorder(b.root);
            cout << endl;
            cout << "Postorder : ";
            b.postorder(b.root);
            cout << endl;
        }
        else if (res == 6)
        {
            cout << "Enter element to be searched : ";
            int k;
            cin >> k;
            Node* parent=NULL;
            b.search(parent,b.root,  k);
        }
        else if (res == 7)
        {
            cout << "Enter element to be deleted : ";
            int k;
            cin >> k;
            b.deletenode(b.root, k);
            b.inorder(b.root);
        }
        else if (res == 8)
            break;
        else
            continue;
    }
    return 0;
}