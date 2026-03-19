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
        while (true) {
            if (data < curr->data) {
                if (!curr->left) {
                    curr->left = new Node(data);
                    return;
                }
                curr = curr->left;
            } 
            else {
                if (!curr->right) {
                    curr->right = new Node(data);
                    return;
                }
                curr = curr->right;
            }
        }
    }
    void leftView() {
        leftViewUtil(root, 0);
    }
private:
    int max_level = -1;
    void leftViewUtil(Node* node, int level) {
        if (!node) return;
        if (level > max_level) {
            cout << node->data << " ";
            max_level = level;
        }
        leftViewUtil(node->left, level + 1);
        leftViewUtil(node->right, level + 1);
    }
};
int main(){
    Tree t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(12);
    t.insert(18);
    cout << "Left View: ";
    t.leftView();
    cout << endl;
}
