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
    Node* root = NULL;
public:
    void insert(int data) {
        if (!root) {
            root = new Node(data);
            return;
        }
        Node* curr = root;
    };
    void topview(){
        map<int, Node> mp;
        queue<pair<Node, int>> q;
        q.push(curr, 0);
        while(!q.empty()){
            pair
        }
    }
}

// leetcode top view, bottom view, left view, printing all elements horizontally, lowest common ancestor 