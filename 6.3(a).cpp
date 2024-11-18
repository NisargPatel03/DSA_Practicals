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

void rightView(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            // Only print the last node at each level
            if (i == levelSize - 1) {
                cout << current->data << " ";
            }

            // Enqueue left and right children
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
}

void leftView(Node* root)
{
    if(root==nullptr) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int levelSize = q.size();

        for(int i=0; i<levelSize; i++)
        {
            Node* current = q.front();
            q.pop();

            if(i==0)
            {
                cout<<current->data<<" ";
            }

            if(current->left!=nullptr) q.push(current->left);
            if(current->right!=nullptr) q.push(current->right);
        }
    }
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
    cout<<"Right Binary Tree View: ";
    rightView(root);
    cout<<endl;
    cout<<"Left Binary Tree View: ";
    leftView(root);
}
