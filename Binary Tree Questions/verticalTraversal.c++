/*
Question -> You will be given the root node of the tree, return a vector containing the vertical traversal of the tree.
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

void verticalTraversal(BTNode* root){
    cout<<"Vertical Traversal :";

    if(root == NULL) return ;

    map<int, vector<int>> nodes;
    queue<pair<BTNode*, pair<int, int>>> q;

    q.push({root, {0,0}});

    while (!q.empty()){
        pair<BTNode*, pair<int, int>> current_node_info = q.front();
        q.pop();

        BTNode* current_node = current_node_info.first;
        int current_level = current_node_info.second.first;
        int current_dist = current_node_info.second.second;

        nodes[current_dist].push_back(current_node->data);

        if (current_node->left_ptr) q.push({current_node->left_ptr, {current_level+1, current_dist-1}});
        if (current_node->right_ptr) q.push({current_node->right_ptr, {current_level+1, current_dist+1}});
    }

    for (auto node : nodes){
        for (auto element : node.second){
            cout<<element<<" ";
        }
    }
    cout<<endl;
}

int main() {
    BTNode* root = NULL;
    root = buildTree_LevelWise(); 
    verticalTraversal(root);
    return 0;
}