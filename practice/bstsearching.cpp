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
    void insert(int data) {
        if (!root) {
            root = new Node(data);
            return;
        }
        Node* curr = root;
    };
    int solve(Node* root, int target){
        if(root==NULL){
            return NULL;
        }
        else if(root->data==target){
            return root->data;
        }
        else if(root->data>target){
            solve(root->left, target);
        }
        else{
            solve(root->right, target);
        }
        return NULL;
    }
};


// searching an element