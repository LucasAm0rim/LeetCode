#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

bool checkTree(struct TreeNode *root) {
    if (root->val == (root->left->val + root->right->val)){
        return true;
    } else {
        return false;
    }
}

struct TreeNode *build_TreeNode(int valRoot, int valLeft, int valRight){
    struct TreeNode *root = calloc(1,sizeof(struct TreeNode));
    if (root == NULL){
        printf("Calloc Failed\n");
        exit(EXIT_FAILURE);
    }
    root->val = valRoot;

    root->left = calloc(1,sizeof(struct TreeNode));
    if (root->left == NULL){
        printf("Calloc Failed\n");
        exit(EXIT_FAILURE);
    }
    root->left->val = valLeft;

    root->right = calloc(1,sizeof(struct TreeNode));
    if (root->right == NULL){
        printf("Calloc Failed\n");
        exit(EXIT_FAILURE);
    }    
    root->right->val = valRight;

    return root;
}

void print_usage(char *argv[]){
    printf("usage: %s -t <tree>\n", argv[0]);
    printf("example: %s -t 10,5,5\n", argv[0]);
}

int main (int argc, char *argv[]){
    int c;
    char *treeValues = NULL;
    struct TreeNode *root = calloc(1,sizeof(struct TreeNode));
    if (root == NULL){
        printf("Calloc Failed\n");
        exit(EXIT_FAILURE);
    }
    
    while ((c = getopt(argc, argv, "t:")) != -1){
        switch (c){
            case 't':
                treeValues = optarg;
                break;
            case '?':
                //print_usage(argv);
                break;
            
            default:
                return -1;
        }
    }

    if (treeValues){
        char *treeRoot = strtok(treeValues, ",");
        char *treeLeft = strtok(NULL,",");
        char *treeRight = strtok(NULL,",");
        root = build_TreeNode(atoi(treeRoot), atoi(treeLeft), atoi(treeRight));

        if (checkTree(root) == true){
            printf("True\n");
        } else {
            printf("False\n");
        }

        free(root->left);
        free(root->right);
        free(root);
        root = NULL;
        
        //root = build_TreeNode(10, 5, 5);
    } else {
        printf("\nTree is a required argument.\n");
        print_usage(argv);
    }

}
