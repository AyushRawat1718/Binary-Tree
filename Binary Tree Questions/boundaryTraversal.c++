/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

> Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel 
preferring the left subtree over the right subtree. 
> Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
> Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could 
reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in 
the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
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

//---------------------------------------------------Main Logic Code-----------------------------------------------------------------------
/*
Approach -> In this there are three parts of traversal
(1) Left Part Traversal (Prefer Left nodes over Right nodes), exclude the leaf nodes
(2) Leaf Traversal (Traverse all the leaf nodes from Left to Right)
(3) Reverse Right Part Traversal (Prefer Right nodes over Left nodes), exclude the leaf nodes
*/

void LeftTraversal(BTNode* root, vector<int> &ans){
    if (root == NULL || (root->left_ptr == NULL && root->right_ptr == NULL)) return;
    ans.push_back(root->data);
    if (root->left_ptr) LeftTraversal(root->left_ptr, ans);
    else LeftTraversal(root->right_ptr, ans);
    
    return;
}

void LeafTraversal(BTNode* root, vector<int> &ans){
    if (root == NULL) return;
    LeafTraversal(root->left_ptr, ans);
    if (root->left_ptr == NULL && root->right_ptr == NULL) {
        ans.push_back(root->data);
        return;
    }
    LeafTraversal(root->right_ptr, ans);

    return;
}

void RightTraversal(BTNode* root, vector<int> &ans){
    if (root == NULL || (root->left_ptr == NULL && root->right_ptr == NULL)) return;
    if (root->right_ptr) RightTraversal(root->right_ptr, ans);
    else RightTraversal(root->left_ptr, ans);
    ans.push_back(root->data);
    
    return;
}

vector<int> boundaryTraversal(BTNode* root){
    vector<int> ans;
    if (root == NULL) return ans;
    ans.push_back(root->data);
    if(root->left_ptr == NULL && root->right_ptr == NULL) return ans;
    LeftTraversal(root->left_ptr, ans);
    LeafTraversal(root, ans);
    RightTraversal(root->right_ptr, ans);
    return ans;
}

int main(){
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    vector<int> ans = boundaryTraversal(root);
    cout<<"Boundary Traversal of the Tree -> ";
    for (auto x: ans) cout<<x<<" ";
    return 0;
}