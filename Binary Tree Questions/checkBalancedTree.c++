/*
Question - You will be given the root node of the binary tree, check whether the tree is balanced or not

A node of tree is said to be balanced when the difference of heights of left subtree and right subtree is 1. A tree is said to be balanced
when all of the nodes of the tree are balanced

*/

#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------Required Code-----------------------------------------------------------------------
struct BTNode{
    int data;
    BTNode* left_ptr;
    BTNode* right_ptr;

    BTNode(int data){
        this->data = data;
        this->left_ptr = this->right_ptr = NULL;
    }
};

BTNode* buildTree_LevelWise(){
    cout<<"Enter Data for the Root Node: ";
    queue<BTNode*> q;
    int data;
    cin>>data;
    BTNode* root_node = new BTNode(data);
    q.push(root_node);
    
    while (!q.empty()){
        BTNode* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter data for the Left Node of "<<temp->data<<": ";
        cin>>leftData;
        if (leftData != -1){
            temp->left_ptr = new BTNode(leftData);
            q.push(temp->left_ptr);    
        }

        int rightData;
        cout<<"Enter data for the Right Node of "<<temp->data<<": ";
        cin>>rightData;
        if (rightData != -1){
            temp->right_ptr = new BTNode(rightData);
            q.push(temp->right_ptr);            
        }        
    }
    return root_node;
}

int heightOfTree(BTNode* &root){
    if (root == NULL) return 0;

    int leftHeight = heightOfTree(root->left_ptr);
    int rightHeight = heightOfTree(root->right_ptr);
    
    return (1 + max(leftHeight, rightHeight));
}

//---------------------------------------------------Main Logic Code-----------------------------------------------------------------------
/*
Approach - 1 (For checking whether a node is balanced or not we must ensure that it's right subtree & left subtree is balanced, and for the
node we will check by the difference b/w height of left subtree and right subtree.
*/

bool isBalanced(BTNode* root){
    if (root == NULL){
        return true;
    }

    bool left_check = isBalanced(root->left_ptr);
    bool right_check = isBalanced(root->right_ptr);
    bool self_check = (abs(heightOfTree(root->left_ptr) - heightOfTree(root->right_ptr)) <= 1);

    return (left_check && right_check && self_check);
}

// Optimized Approach -> In this try to combine the isBalanced function and the height func to reduce the function call stack

pair<bool, int> helper_func(BTNode* root){
    if (root == NULL) {
        pair<bool, int> p = {true, 0};
        return p;
    }

    pair<int, int> left_subTree = helper_func(root->left_ptr);
    pair<int, int> right_subTree = helper_func(root->right_ptr);

    bool left_check = left_subTree.first;
    bool right_check = right_subTree.first;

    bool self_check = (abs(left_subTree.second - right_subTree.second) <= 1);

    bool isBalanced_res = (left_check && right_check && self_check);
    int height_res = 1 + max(left_subTree.second, right_subTree.second);

    return {isBalanced, height_res};
}

bool isBalanced_optimized(BTNode* root){
    pair<bool, int> p = helper_func(root);
    return p.first;
}

int main() {
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    
    if (isBalanced(root)) cout<<"Tree is Balanced\n";
    else cout<<"Tree is not Balanced\n";

    if (isBalanced_optimized(root)) cout<<"Tree is Balanced\n";
    else cout<<"Tree is not Balanced\n";

    return 0;
}