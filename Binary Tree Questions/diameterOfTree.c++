// Question - You will be given the root node of the binary tree, return the diamater of the tree.
// Diameter of the tree is the number of nodes on the longest path between any two nodes

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

//Approach - 1
int diameter(BTNode* root){
    if (root == NULL){
        return 0;
    }

    int opt_1 = diameter(root->left_ptr); //Calculating the longest diamater on the left side.
    int opt_2 = diameter(root->right_ptr); //Calculating the longest diamater on the left side.
    int opt_3 = heightOfTree(root->left_ptr) + heightOfTree(root->right_ptr) + 1;//Calculating the longest diamater passing through root node.

    //Finding the max value
    return max(opt_1, max(opt_2, opt_3));
}

//Optimized Approach
//In this try to combine the height function and the diamater function to reduce the function call stack

pair<int, int> helper_func(BTNode* root){
    if (root == NULL){
        pair<int, int> p = {0,0};
        return p;
    }

    pair<int, int> left = helper_func(root->left_ptr);
    pair<int, int> right = helper_func(root->right_ptr);

    int opt_1 = left.first;
    int opt_2 = right.first;
    int opt_3 = left.second + right.second + 1;

    int diamater = max(opt_1, max(opt_2, opt_3));
    int height = max(left.second, right.second) + 1;

    pair<int, int> ans = {diamater, height};

    return ans;
}

int diamater_optimized(BTNode* root){
    pair<int, int> temp = helper_func(root);
    return temp.first;

}

int main() {
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    cout<<"Diameter of the Tree: "<<diameter(root)<<endl;
    cout<<"Diameter of the Tree: "<<diamater_optimized(root)<<endl;
    return 0;
}