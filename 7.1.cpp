#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;

        Node(int x)
        {
            key=x;
            left=nullptr;
            right=nullptr;
        }
};

Node* insert(Node* root, int key)
{
    if(root==nullptr)
    {
        return new Node(key);
    }

    if(root->key==key)
    {
        return root;
    }

    if(root->key<key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

Node* search(Node* root, int key)
{
    if(root==nullptr || root->key==key)
    {
        return root;
    }
    if(root->key<key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}
void inorder_tra(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    inorder_tra(root->left);
    cout<<root->key<<" ";
    inorder_tra(root->right);
}

int main()
{
    Node* root = new Node(4);
    root = insert(root,2);
    root = insert(root,7);
    root = insert(root,1);
    root = insert(root,3);

    cout<<"Enter the number to get searched: ";
    int s;
    cin>>s;
    (search(root,s)!=nullptr)?cout<<"Found":cout<<"Not Found";
}
