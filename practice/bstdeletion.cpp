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
    Node* solve(Node* root, int target){
        if(root==NULL){
            return NULL;
        }
        else if(root->data>target){
            root->right=solve(root->left, target);
        }
        else if(root->data<target){
            root->left=solve(root->right, target);
        }
        else if(root->data==target){
            if(root->right==NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else{
                Node* is = InorderSuccessor(root->right);
                root->data=is->data;
                delete is;
                root->right=solve(root->right, target);
            }
        }
        return root;
    }
    Node* InorderSuccessor(Node* root){
        
    }
};


// deleting an element