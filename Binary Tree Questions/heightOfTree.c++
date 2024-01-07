// Question - You will be given the root node of the binary tree, return the height of the Binary Tree.
// Height Of Binary Tree -> Longest path lenght from root node to leaf node

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
int heightOfTree(BTNode* &root){
    if (root == NULL) return 0;

    int leftHeight = heightOfTree(root->left_ptr);
    int rightHeight = heightOfTree(root->right_ptr);
    
    return (1 + max(leftHeight, rightHeight));
}

int main(){
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    cout<<"Height of the Tree is: "<<heightOfTree(root)<<endl;

    return 0;
}