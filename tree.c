// #include<stdio.h>
// #include<stdlib.h>

// struct tree {
//     int info;
//     struct tree* left;
//     struct tree* right;
// };

// struct tree* createNode(int data){
//     struct tree *n = (struct tree*)malloc(sizeof(struct tree));
//     n->info = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

// int main(){
//     // creating the root node
//     struct tree *root,*r1,*l1;
//     root = (struct tree*)malloc(sizeof(struct tree));
//     root->info = 45;
//     root->left = l1;
//     root->right = r1;
//     // creating the first left node of the tree.
//     l1 = (struct tree*)malloc(sizeof(struct tree));
//     l1->info = 44;
//     l1->left = NULL;
//     l1->right = NULL;
//     // creating the first right node of the tree.
//     r1 = (struct tree*)malloc(sizeof(struct tree));
//     r1->info = 46;
//     r1->left = NULL;
//     r1->right = NULL;

//     // Here above the repetition too much so i think i have to make a function to minimize the redundancy.
//     struct tree * r2 = createNode(47);
//     // and then you can easily point the pointer as required.
//     // ba bye..

//     printf("Running..");

//     return 0;
// }




        // PreOrder traversal of the tree


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

void preOrder(struct tree* root){
    if(root!=NULL){
        printf("%d ",root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct tree* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->info);
    }
}

void inOrder(struct tree* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->info);
        inOrder(root->right);
    }
}

struct tree* search(struct tree* root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->info==value){
        return root;
    }
    else if(root->info<value){
        return search(root->left,value);
    }else{
        return search(root->right,value);
    }
}

struct tree* searchIter(struct tree* root, int value){
    while(root!=NULL){
    if(root->info==value){
        return root;
    }
    else if (value<root->info){
        root = root->left;
    }else{
        root = root->right;
    }}
    return NULL;
}

void insert(struct tree* root,int value){
    struct tree* prev = NULL;
    while(root!=NULL){
        prev=root;
        if(value==root->info){
            printf("Unsuccessful, Already exists.");
            return;
        }else if(value<root->info){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    struct tree* new = createNode(value);
    if(value<prev->info){
        prev->left = new;
    }else{
        prev->right = new;
    }
}

struct tree* inOrderPredecessor(struct tree* root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct tree* delNode(struct tree* root, int value) {

    // Base case
    // root node
    if (root == NULL)
        return root;
    // deletion
    // child node
    if(root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }
    // If key to be searched is in a subtree
    // internal nodes
    if (root->info > value)
        root->left = delNode(root->left, value);
    else if (root->info < value)
        root->right = delNode(root->right, value);
    else {
        // When value is equal to root
        struct tree* pre = inOrderPredecessor(root);
        root->info = pre->info;
        root->left = delNode(root->left,pre->info);
    }
    return root;
}

int main(){
    // Root node of the tree.
    struct tree * r = createNode(45);
    // left subnodes of the tree.
    struct tree * l1 = createNode(43);
    struct tree * l2 = createNode(42);
    struct tree * l3 = createNode(44);
    //  Right subnodes of the tree.
    struct tree * r1 = createNode(47);
    struct tree * r2 = createNode(46);
    struct tree * r3 = createNode(48);
    r->left = l1;
    l1->left = l2;
    l1->right = l3;
    r->right = r1;
    r1->left = r2;
    r1->right = r3;

    insert(r,6);
    insert(r,7);
    printf("\nRunning..\n");
    printf("\npreorder..\n");
    preOrder(r);
    printf("\npostorder..\n");
    postOrder(r);
    printf("\ninOrder..\n");
    inOrder(r);

    delNode(r,48);
    delNode(r,46);
    printf("\n");
    inOrder(r);

    return 0;
}




