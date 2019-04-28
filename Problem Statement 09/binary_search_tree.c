#include<stdio.h>

#include<malloc.h>

#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * tree = NULL;
void preorder(struct node * tree) {
    if (tree != NULL) {
        printf("%d ", tree -> data);
        preorder(tree -> left);
        preorder(tree -> right);
    }
}
void inorder(struct node * tree) {
    if (tree != NULL) {
        inorder(tree -> left);
        printf("%d ", tree -> data);
        inorder(tree -> right);
    }
}
void postorder(struct node * tree) {
    if (tree != NULL) {
        postorder(tree -> left);
        postorder(tree -> right);
        printf("%d ", tree -> data);
    }
}
void insert() {
    struct node * newNode, * nodeptr, * parentptr;
    int val;
    newNode = (struct node * ) malloc(sizeof(struct node));
    printf("Enter a value = ");
    scanf("%d", & val);
    printf("\n");
    newNode -> data = val;
    newNode -> left = newNode -> right = NULL;
    if (tree == NULL) {
        tree = newNode;
        tree -> left = NULL;
        tree -> right = NULL;
    } else {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr -> data) {
                nodeptr = nodeptr -> left;
            } else if (val > nodeptr -> data) {
                nodeptr = nodeptr -> right;
            } else {
                break;
            }
        }
        if (val < parentptr -> data) {
            parentptr -> left = newNode;
        } else if (val > parentptr -> data) {
            parentptr -> right = newNode;
        } else {
            printf("\nRepition Not Allowed!!\n\n");
        }
    }
}
int main(void) {
        int opt;
        while (1) {
            printf("\nEnter a choice: \n1.Insert\n2.preorder\n3.inorder\n4.postorder\n\n ");
            scanf("%d", & opt);
            switch (opt) {
                case 1:
                    insert();
                    break;
                case 2:
                    preorder(tree);
                    break;
                case 3:
                    inorder(tree);
                    break;
                case 4:
                    postorder(tree);
                    break;
                default:
                    printf("\nWrong Option Selected !!\n\n");
            }
        }
        return (0);
}
