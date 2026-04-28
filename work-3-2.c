#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
}TreeNode;
TreeNode *createNode(char data){
    TreeNode* NewNode=(TreeNode *)malloc(sizeof(TreeNode));
    if(NewNode==NULL){
        printf("Memory apllication failed");
        return NULL;
    }
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}
void preOrder(TreeNode* root){
    if(root==NULL){
        return ;
    }
    printf("%c ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode* root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    printf("%c ",root->data);
    inOrder(root->right);
}
void posOrder(TreeNode* root){
    if(root==NULL){
        return ;
    }
    posOrder(root->left);
    posOrder(root->right);
    printf("%c ",root->data);
}
int main(){
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->data='D';
    root->left=createNode('A');
    root->left->left=createNode('T');
    root->left->right=createNode('T');
    root->left->left->left=createNode('A');
    root->left->left->right=createNode('S');
    root->right=createNode('R');
    root->right->left=createNode('U');
    root->right->right=createNode('C');
    root->right->right->left=createNode('T');
    root->right->right->right=createNode('R');
    root->right->right->left->right=createNode('U');
    root->right->right->right->left=createNode('E');
    printf("pre: ");
    preOrder(root);
    printf("\n");
    printf("in: ");
    inOrder(root);
    printf("\n");
    printf("pos: ");
    posOrder(root);
    printf("\n");
    return 0;
}