#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* root){
    if(root==NULL){
        return NULL;
    }
    return root->height;
}

struct node* createNode(int value){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int getBF(struct node* root){
    if(root==NULL){
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}

struct node* rightRotate(struct node* second){
    struct node* first = second->left;
    struct node* firstChild = first->right;

    first->right = second;
    second->left = firstChild;

    second->height = max(getHeight(second->right),getHeight(second->left));
    first->height = max(getHeight(first->right),getHeight(first->left));

    return first;
}

struct node* leftRotate(struct node* first){
    struct node* second = first->left;
    struct node* secondChild = second->right;

    second->left = first;
    first->right = secondChild;

    second->height = max(getHeight(second->right),getHeight(second->left));
    first->height = max(getHeight(first->right),getHeight(first->left));

    return second;
}

struct node* insert(struct node* root,int value){
    if(root==NULL){
        return (createNode);
    }
    if(value<root->data){
        root->left = insert(root->left,value);
    }else if(value>root->data){
        root->right = insert(root->right,value);
    }
    return root;


}

int main(){

    return 0;
}
