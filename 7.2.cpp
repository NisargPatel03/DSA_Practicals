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
        root->right = insert(root->right,key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

Node* BuildBST(int* arr[], int n)
{
    Node* root = nullptr;

    for(int i=0; i<n; i++)
    {
        if(arr[i]!=nullptr)
        {
            root = insert(root,*arr[i]);
        }
    }
    return root;
}

void Store_Inorder(Node* root, int arr[], int& index)
{
    if(root==nullptr)
    {
        return;
    }
    Store_Inorder(root->left, arr, index);
    arr[index++]=root->key;
    Store_Inorder(root->right, arr, index);
}
int main()
{
    int n;
    cout<<"Enter the size of array to make a Binary Search Tree: ";
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

    Node* root = BuildBST(arr,n);
    int storeInorder[n];
    int index=0;
    Store_Inorder(root, storeInorder, index);

    cout<<"Enter the number to find the Kth smallest element: ";
    int k;
    cin>>k;
    for(int i=0; i<index; i++)
    {
        if(k-1==i)
        {
            cout<<storeInorder[i]<<" ";
        }
    }
}
