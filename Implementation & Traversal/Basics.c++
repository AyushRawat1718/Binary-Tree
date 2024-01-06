#include <bits/stdc++.h>
using namespace std;

//Every Node of the Binary tree has data and  left ptr, right ptr for keeping track of the left subtree, right subtree of the node.
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

//Building Tree Level Wise
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

//Traversing Order is Level wise starting from Root Node of the tree i.e Level 0
void levelOrderTraversal(BTNode* root){

    if (root == NULL){
        cout<<"Tree is Empty\n";
        return;
    } 
    cout<<"Level Order Traversal ->\n";

    queue<BTNode*> q; //For storing the nodes

    q.push(root);

    q.push(NULL); //Indicator for moving to next line.

    while (!q.empty()){
        BTNode* temp = q.front();
        q.pop();

        //This means the certain level is completely traversed.
        if (temp == NULL){
            cout<<endl;

            // Checking whether any nodes still present in the queue
            if (!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";

            if (temp->left_ptr != NULL){
                q.push(temp->left_ptr);
            }

            if (temp->right_ptr != NULL){
                q.push(temp->right_ptr);
            }
        }
        
    } 
    cout<<endl;
}

//Traversing order is "Left Subtree -> Node -> Right Subtree" 
void inOrderTraversal(BTNode* root){
    if (root == NULL) return;

    inOrderTraversal(root->left_ptr);
    cout<<root->data<<" ";
    inOrderTraversal(root->right_ptr);


}

//Traversing order is "Left Subtree -> Right Subtree -> Node"
void postOrderTraversal(BTNode* root){
    if (root == NULL) return;

    postOrderTraversal(root->left_ptr);
    postOrderTraversal(root->right_ptr);
    cout<<root->data<<" ";

}

//Traversing order is "Node -> Left Subtree -> Right Subtree"
void preOrderTraversal(BTNode* root){
    if (root == NULL) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left_ptr);
    preOrderTraversal(root->right_ptr);
}

int main() {
    BTNode* root = NULL;
    // root = buildTree(root);
    
    root = buildTree_LevelWise();

    levelOrderTraversal(root);

    cout<<"InOrder Traversal: ";
    inOrderTraversal(root);
    cout<<endl;
    
    cout<<"PostOrder Traversal: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"PreOrder Traversal: ";
    preOrderTraversal(root);
    cout<<endl;

    return 0;
}