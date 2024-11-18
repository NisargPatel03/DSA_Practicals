#include<iostream>
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
            data=x;
            left=nullptr;
            right=nullptr;
        }
};

Node* createBinaryTreefromArray(int* arr[], int n, int index)
{
    if(index>=n || arr[index] == nullptr)
    {
        return nullptr;
    }
    Node* root = new Node(*arr[index]);

    root->left = createBinaryTreefromArray(arr, n, 2*index+1);
    root->right = createBinaryTreefromArray(arr, n, 2*index+2);

    return root;
}

int depth(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int leftdepth = depth(root->left);
    int rightdepth = depth(root->right);

    return max(leftdepth, rightdepth)+1;
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

int main()
{
    int n;
    cout<<"Enter the size of array to make a Binary Tree: ";
    cin>>n;
    int* arr[n];
    string input;

    for(int i=0; i<n; i++)
    {
        cout<<"Element-"<<i+1<<": ";
        cin>>input;

        if(input=="NULL" || input=="null")
        {
            arr[i]=nullptr;
        }
        else
        {
            int value = stoi(input);
            arr[i]= new int(value);
        }
    }
    Node* root = createBinaryTreefromArray(arr,n,0);

    cout<<"Depth of Binary Tree is: "<<depth(root)<<endl;
    inorder_tra(root);
}
