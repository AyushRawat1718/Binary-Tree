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

//In this question we just have to traverse the tree and count those nodes which don't have the left and right child.

//Using Inorder Approach
void inOrder_Traversal(BTNode* &root, int &count){
    if (root == NULL){
        return;
    }

    inOrder_Traversal(root->left_ptr, count);

    if ((root->left_ptr == NULL) && (root->right_ptr == NULL)){
        count++;
    }

    inOrder_Traversal(root->right_ptr, count);
}

int countLeafNodes(BTNode* &root){
    int counter = 0;
    inOrder_Traversal(root, counter);
    return counter;
}

int main() {
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    cout<<"No. of Leaf Nodes in Tree: "<<countLeafNodes(root);

    return 0;
}