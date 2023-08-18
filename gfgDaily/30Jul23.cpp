/*
    Initiation time: 30/07/2023 20:57
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
    Problem Statement:
    Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout << endl;

#define MOD 1000000007

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node * leftLeaf(Node *root){
    if (root == NULL)return NULL;
    if (root->left == NULL) return root;
    return leftLeaf(root->left);
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    // If root->data == x->data, then successor is on the right subtree o.w Null
    if (root->data == x->data){
        return leftLeaf(root->right);
    }
    if ((root->data) < (x->data)){
        return inOrderSuccessor(root->right, x);
    }
    if ((root->data) > (x->data)){
        Node * ans = inOrderSuccessor(root->left, x);
        if (ans){
            return root;
        }
        return root;
    }
}

int main()
{

    return 0;
}