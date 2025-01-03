#include<stdio.h>
#include<stdlib.h>
struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};
struct tree* createNode(int data){
    struct tree *n = (struct tree*)malloc(sizeof(struct tree));
    n->info = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inOrder(struct tree* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->info);
        inOrder(root->right);
    }
}
int isBST(struct tree* root){
    static struct tree* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->info <= prev->info){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

// searching in binary search tree
struct tree* search (struct tree* root , int key){
    if(root==NULL){
        return NULL;
    }if(root->info==key){
        return root;
    }else if(key < root->info){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}


int main(){
    // Root node of the tree.
    struct tree * r = createNode(5);
    // left subnodes of the tree.
    struct tree * l1 = createNode(3);
    struct tree * l2 = createNode(2);
    struct tree * l3 = createNode(4);
    //  Right subnodes of the tree.
    struct tree * r1 = createNode(7);
    struct tree * r2 = createNode(6);
    struct tree * r3 = createNode(8);
    r->left = l1;
    l1->left = l2;
    l1->right = l3;
    r->right = r1;
    r1->left = r2;
    r1->right = r3;

    printf("Running..\n");
    printf("inOrder..\n");
    inOrder(r);
    printf("\nIs Binary Search Tree or not\n%d",isBST(r));
    int k;
    scanf("%d",&k);
    struct tree* s = search(r,k);
    printf("\nSearched element is :\n%d",s->info);

    return 0;
}
