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

//This is just one of the way to build binary tree(not standard)

BTNode* buildTree(BTNode* &root){
    int data;

    cout<<"Enter the data: ";
    cin>>data;

    if (data == -1) return NULL;

    root = new BTNode(data);

    cout<<"Enter the data for the Left Node of "<<root->data<<" ->\n";
    root->left_ptr = buildTree(root->left_ptr);

    cout<<"Enter the data for the Right Node of "<<root->data<<" ->\n";
    root->right_ptr = buildTree(root->right_ptr);

    return root;
}


//---------------------------------------------------Main Logic Code-----------------------------------------------------------------------

//Preorder Traversal in Iterative Approach

void preOrder_Iterative(BTNode* &root){
    if (root == NULL){
        cout<<"Tree is Empty\n";
        return;
    }
    else{
        cout<<"PreOrder Traversal: ";
        stack<BTNode*> st;

        st.push(root);

        while (!st.empty()){

            BTNode* temp = st.top();

            st.pop();

            cout<<temp->data<<" ";

            if (temp->right_ptr != NULL){
                st.push(temp->right_ptr);
            }

            if (temp->left_ptr != NULL){
                st.push(temp->left_ptr);
            }
        }
    }
}



int main() {
    BTNode* root = NULL;
    root = buildTree(root);
    preOrder_Iterative(root);

    
    return 0;
}