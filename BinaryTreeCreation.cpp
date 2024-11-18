#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x)
        {
            data=x;
            left=nullptr;
            right=nullptr;
        }
};

class BinaryTree
{
    public:
    Node* root;

    BinaryTree()
    {
        root=nullptr;
    }

    void insert(int val)
    {
        if(!root)
        {
            root= new Node(val);
        }
        else
        {
            insertdata(root, val);
        }
    }

    void insertdata(Node* node, int val)
    {
        char direction;
        cout<<"Enter Direction whether the data to be stored at left position or right position [Press 'l' or 'L' for left & 'r' or 'R' for right]: ";
        cin>>direction;
        if(direction=='l' || direction=='L')
        {
            if(node->left)
            {
                insertdata(node->left,val);
            }
            else
            {
                node->left=new Node(val);
            }
        }
        else if(direction=='r' || direction=='R')
        {
            if(node->right)
            {
                insertdata(node->right, val);
            }
            else
            {
                node->right=new Node(val);
            }
        }
        else
        {
            cout<<"Enter valid direction";
            insertdata(node,val);
        }
    }
    void inorder_tra(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }

        inorder_tra(root->left);
        cout<<root->data<<" ";
        inorder_tra(root->right);
    }
    void preorder_tra(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        cout<<root->data<<" ";
        preorder_tra(root->left);
        preorder_tra(root->right);
    }
    void postorder_tra(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        postorder_tra(root->left);
        postorder_tra(root->right);
        cout<<root->data<<" ";
    }
    void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Visit the root node
        cout << current->data << " ";

        // Enqueue left child
        if (current->left != nullptr) q.push(current->left);

        // Enqueue right child
        if (current->right != nullptr) q.push(current->right);
    }
}
    void display()
    {
        cout<<"Enter choice for printing traversals"<<endl;
        cout<<"1.) Inorder Traversal"<<endl<<"2.) Preorder Traversal"<<endl<<"3.) Postorder Traversal"<<endl;
        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Inorder Traversal: ";
                inorder_tra(root);
                cout<<endl;
                break;
            case 2:
                cout<<"Preorder Traversal: ";
                preorder_tra(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Postorder Traversal: ";
                postorder_tra(root);
                cout<<endl;
                break;

            case 4:
                cout<<"Levelorder Traversal: ";
                levelOrderTraversal(root);
                cout<<endl;
                break;
            default:
                cout<<"Enter valid choice";
                break;
        }

    }
};
int main()
{
    BinaryTree tree;
    int value;
    char cont;

    do
    {
        cout<<"Enter the value to insert in the binary tree: ";
        cin>>value;
        tree.insert(value);

        cout<<"Do you want to insert new data [Say 'y' or 'Y' for inserting & 'n' or 'N' for exiting]: ";
        cin>>cont;
    }while(cont=='y' || cont=='Y');

    tree.display();
}
