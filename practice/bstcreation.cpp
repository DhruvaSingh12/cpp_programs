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

    Node* insertion(Node* root, int value){
        if(root==NULL){
            return ;
        }
        else if(root->data>value){
            root->left=insertion(root->left, value);
        }
        else{
            root->right=insertion(root->right, value);
        }
        return root;
    }

    void create(vector<int> nums){
        for(int i=0; i<nums.size(); i++){
            insertion(root, nums[i]);
        }
    }
};


// creating bst - O(nlogn)