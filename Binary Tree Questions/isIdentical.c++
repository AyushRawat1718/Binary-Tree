/*
Question - You will be given the root nodes of two binary tree, check whether both of them are identical.

Both of the trees are identical if the values of all the corresponding nodes are equal.
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
Approach -> Trees would be identical, when for every node the corresponding value will be similar, and the left subtree & right subtree
are identical.
*/

bool isIdentical(BTNode* root_1, BTNode* root_2){
    //When either one of the node or both the nodes is/are null
    if (root_1 == NULL && root_2 == NULL) return true;
    if (root_1 == NULL && root_2 != NULL) return false;
    if (root_1 != NULL && root_2 == NULL) return false;

    //When both of them are not null
    bool self_check = (root_1->data == root_2->data);
    bool right_check = isIdentical(root_1->right_ptr, root_2->right_ptr);
    bool left_check = isIdentical(root_1->left_ptr, root_2->left_ptr);

    return self_check && right_check && left_check; 
}

int main(){
    cout<<"Build First Tree\n";
    BTNode* root_1 = NULL;
    root_1 = buildTree_LevelWise();

    cout<<"Build Second Tree\n";
    BTNode* root_2 = NULL;
    root_2 = buildTree_LevelWise();

    if (isIdentical(root_1, root_2)) cout<<"Trees are identical\n";
    else cout<<"Trees are non-identical\n";

    return 0;
}