#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool withinBounds(int val, double max, double min){
    if(val > min){
        if(val < max){
            return true;
        }
        else return false;
    }
    else return false;
}

bool recursive(struct TreeNode* root,  double max, double min){
    if (root == NULL) return true;
    if(root->left == NULL || withinBounds(root->left->val, root->val, min)){
        if(recursive(root->left, root->val, min)==true){
            if(root->right == NULL || withinBounds(root->right->val, max, root->val)){
                return(recursive(root->right, max, root->val));
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
       
bool isValidBST(struct TreeNode* root){
    double min = pow(-2,31)-1; double max = pow(2,31)+1;
    return recursive(root, max, min);
}
int main(){
    return 0;
}