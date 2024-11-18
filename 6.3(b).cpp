#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x)
        {
            data = x;
            left=nullptr;
            right=nullptr;
        }
};

Node* createBinaryTreefromArray(int* arr[], int n, int index)
{
    if(index>=n || arr[index]==nullptr)
    {
        return nullptr;
    }

    Node* root = new Node(*arr[index]);
    root->left = createBinaryTreefromArray(arr, n, 2*index+1);
    root->right = createBinaryTreefromArray(arr, n, 2*index+2);

    return root;
}

void printleaves(Node* root)
{
    if(root==nullptr)
    {
        return;
    }

    printleaves(root->left);

    if(!(root->left) && !(root->right))
    {
        cout<<root->data<<" ";
    }

    printleaves(root->right);
}

void printBoundaryLeft(Node* root)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->left)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(Node* root)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->right)
    {
        printBoundaryRight(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printBoundaryRight(root->left);
        cout<<root->data<<" ";
    }
}

void printBoundary(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    printBoundaryLeft(root->left);

    printleaves(root->left);
    printleaves(root->right);

    printBoundaryRight(root->right);
}
int main()
{
    int n;
    cout<<"Enter the size of array to make a binary tree: ";
    cin>>n;
    int* arr[n];
    string input;

    for(int i=0; i<n; i++)
    {
        cout<<"Element-"<<i+1<<": ";
        cin>>input;

        if(input=="null" || input=="NULL")
        {
            arr[i]=nullptr;
        }
        else
        {
            int value = stoi(input);
            arr[i] = new int(value);
        }
    }

    Node* root = createBinaryTreefromArray(arr, n, 0);

    printBoundary(root);
}
