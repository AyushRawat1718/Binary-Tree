/*
Question -> Your task is to create the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns 
a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.
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

void reverse_array(vector<int> &vec){
    int start = 0;
    int end = vec.size()-1;
    while(start < end){
        swap(vec[start++], vec[end--]);
    }

}
//---------------------------------------------------Main Logic Code-----------------------------------------------------------------------

/*
Approach -> Traverse the complete tree levelwise, while inserting the elements of the tree in a list and after every level completion
 just insert '-1' as a seperator. After that create a new list and do required changes.
*/

vector<int> zigZagTraversal(BTNode* root){

    vector<int> temp_1;
    if (root == NULL) return temp_1;
    queue<BTNode*> q;
    q.push(root);
    q.push(NULL); //Separator

    while (!q.empty()){
        BTNode* temp = q.front();
        q.pop();
        if (temp == NULL){
            temp_1.push_back(-1);
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp_1.push_back(temp->data);
            if (temp->left_ptr) q.push(temp->left_ptr);
            if (temp->right_ptr) q.push(temp->right_ptr);

        }
    }
    //Vector 'Temp_1' contains the level order traversal of the Tree, levels separated by -1.

    vector<int> ans;
    vector<int> temp_2;
    bool reverse = false;

    for(int i=0; i<temp_1.size(); i++){
        if (temp_1[i] == -1){
            if (reverse) reverse_array(temp_2);
            for (auto x : temp_2) ans.push_back(x);
            reverse = !(reverse);
            temp_2.clear();
        }
        else{
            temp_2.push_back(temp_1[i]);
        }
    }
    return ans;
}

int main(){
    BTNode* root = NULL;
    root = buildTree_LevelWise();
    vector<int> vec = zigZagTraversal(root);
    cout<<"Zig Zag Traversal of Tree ->";
    for(auto x : vec) cout<<x<<" ";
    cout<<endl;
    return 0;
}