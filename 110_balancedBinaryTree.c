//leetcode
//https://leetcode.com/problems/balanced-binary-tree/description/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh, rh;
    lh = maxDepth(root->left);
    rh = maxDepth(root->right);
    if (lh - rh > 1 || rh - lh > 1) // Condição para verificar o balanceamento
    {
        return false;
    }
    return (isBalanced(root->left) && isBalanced(root->right));
}

int main() 
{
    // criando uma árvore de exemplo para teste
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    if (isBalanced(root))
        printf("A árvore está balanceada.\n");
    else
        printf("A árvore não está balanceada.\n");

    
    free(root->left);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}