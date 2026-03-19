#include <bits/stdc++.h>
using namespace std;
class Tree{
    struct Node{
        int data;
        Node* left=NULL;
        Node* right=NULL;

        Node(int data){
            this->data=data;
        }
    };
    Node* root=NULL;
    public:
    vector<int> arr;
    void insert(int data) {
        if (!root) {
            root = new Node(data);
            return;
        }
        Node* curr = root;
    };
    bool inorder(Node* root){
        if(root==NULL){
            return NULL;
        }
        inorder(root->left);
        arr.push_back(root->data); 
        inorder(root->right);
    }
    
};


// searching an element