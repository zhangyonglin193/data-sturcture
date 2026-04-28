#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
TreeNode *createNode(int data){
    TreeNode *NewNode=(TreeNode *)malloc(sizeof(TreeNode));
    if(NewNode==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}
void preOrder(TreeNode *root){
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
    root=createNode(3);
    root->left=createNode(4);
    root->right=createNode(6);
    root->left->left=createNode(9);
    root->left->right=createNode(5);
    root->right->left=createNode(2);
    root->right->right=createNode(7);
    preOrder(root);
    return 0;
}