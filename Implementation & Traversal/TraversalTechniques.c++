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
    cout<<endl;
} 

// Inorder Traversal in Iterative Approach
void inOrder_Iterative(BTNode* &root){
    if (root == NULL){
        cout<<"Tree is Empty\n";
        return;
    }
    cout<<"InOrder Traversal: ";
    stack<BTNode*> st;
    BTNode* temp = root;   
    while (true){
        if (temp != NULL){
            st.push(temp);
            temp = temp->left_ptr;
        }
        else{
            if (st.empty()) break;
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp = temp->right_ptr;
        }
    }
    cout<<endl;
}

// Postorder Traversal in Iterative Approach

// Using 2 Stack
void postOrder_Iterative_1(BTNode* &root){
    if (root == NULL) {
        cout<<"Tree is Empty\n";
        return;
    }
    cout<<"PostOrder Traversal: ";
    stack<BTNode*> st_1;
    stack<BTNode*> st_2;

    st_1.push(root);

    while (!st_1.empty()){
        BTNode* temp = st_1.top();
        st_2.push(temp);
        st_1.pop();

        if (temp->left_ptr != NULL){
            st_1.push(temp->left_ptr);
        }
        if (temp->right_ptr != NULL){
            st_1.push(temp->right_ptr);
        }
    }
    while (!st_2.empty()){
        cout<<st_2.top()->data<<" ";
        st_2.pop();
    }
    cout<<endl;
}

// Using 1 Stack
void postOrder_Iterative_2(BTNode* &root){
    if (root == NULL) {
        cout<<"Tree is Empty\n";
        return;
    }
    cout<<"PostOrder Traversal: ";
    stack<BTNode*> st;

    BTNode* current_node = root;

    while ((current_node != NULL) || (!st.empty())){
        if (current_node != NULL){
            st.push(current_node);
            current_node = current_node->left_ptr;
        }
        else{
            BTNode* temp = st.top();
            if (temp->right_ptr == NULL){
                cout<<temp->data<<" ";
                st.pop();

                while (!st.empty() && st.top()->right_ptr == temp){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else{
                current_node = temp->right_ptr;
            }
        }
    }
}

int main() {
    BTNode* root = NULL;
    root = buildTree(root);
    preOrder_Iterative(root);
    inOrder_Iterative(root);
    postOrder_Iterative_1(root);
    postOrder_Iterative_2(root);

    return 0;
}