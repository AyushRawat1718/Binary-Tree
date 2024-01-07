/*
Question - Given a Binary Tree. Return true, if for every node in the tree other than leaf nodes, its value is equal to the sum of 
it's left subtree's and right subtree's value. Else return false.

Note: A empty tree is also considered to be a valid sum tree.
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
Approach (For every node we have to check whether it's left subtree is valid, right subtree is valid & the node itself is valid).
*/

pair<bool, int> helper_func(BTNode* root){
    if (root == NULL){
        return {true, 0};
    }
        
    if (root->left_ptr == NULL && root->right_ptr == NULL){
        return {true, root->data};
    }
        
    pair<bool, int> left_subtree = helper_func(root->left_ptr);
    pair<bool, int> right_subtree = helper_func(root->right_ptr);
        
    bool res_1 = left_subtree.first && right_subtree.first && ((left_subtree.second + right_subtree.second) == root->data);
    int res_2 = root->data + left_subtree.second + right_subtree.second;
        
    return {res_1, res_2};
}

bool sumTree(BTNode* root){
    pair<bool, int> p = helper_func(root);

    if (p.first) cout<<"Given Tree is a valid Sum Tree\n";
    else cout<<"Given Tree is not a valid Sum Tree\n";
}

int main(){
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    sumTree(root);

    return 0;
}