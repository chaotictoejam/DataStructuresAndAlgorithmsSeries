#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int value);
        void deleteNode(int value);
        Node *search(int value);
    private:
        void destroy(Node* leaf);
        void insert(int value, Node* leaf);
        Node* search(int value, Node* leaf);
        Node* deleteNode(int value, Node *leaf);
        Node* root;
};

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(Node *leaf) {
    if(leaf != NULL) {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int value) {
    if(root == NULL) {
        root = new Node;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else {
        insert(value, root);
    }
}

void BinaryTree::insert(int value, Node* leaf) {
    if(value < leaf->value) {
        if(leaf->left == NULL) {
            leaf->left = new Node;
            leaf->left->value = value;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        } else {
            insert(value, leaf->left);
        }
    } else {
        if(leaf->right == NULL) {
            leaf->right = new Node;
            leaf->right->value = value;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        } else {
            insert(value, leaf->right);
        }
    }
}

Node* BinaryTree::search(int value) {
    return search(value, root);
}

Node* BinaryTree::search(int value, Node *leaf) {
    if(leaf == NULL) {
        return NULL;
    } else {
        if(value == leaf->value){
            return leaf;
        }
        if(value < leaf->value){
            // Traverse down the left side of the tree
            return search(value, leaf->left);
        } else
        {
            // Traverse down the right side of the tree
            return search(value, leaf->right);
        }
    }
}

void BinaryTree::deleteNode(int value) {
    // The roo could potentially change and therefore may need to be updated
    root = deleteNode(value, root);
}

Node* BinaryTree::deleteNode(int value, Node *leaf) {
    if(leaf == NULL) {
        return NULL;
    } else {
        if(value == leaf->value){
            if(leaf->right == NULL) {
                // Node has only one child to the left
                Node *temp = leaf->left;
                delete leaf;
                return temp;
            } else if (leaf->left == NULL) {
                // Node has only one child to the right
                Node *temp = leaf->right;
                delete leaf;
                return temp;
            }
            else // Node has both children (Deletion by merge)
            {
                // Find the right most child of the left subtree
                Node* succ = leaf->left;
                while(succ->right != NULL) {
                    succ = succ->right;
                }

                // Set the new succesors right subtree to the deleted node
                succ->right = leaf->right;
                
                delete leaf;
                return succ;
            }
        }
        // Recursion to find node
        if(value < leaf->value) {
            leaf->left = deleteNode(value, leaf->left);
            return leaf;
        } else {
            leaf->right = deleteNode(value, leaf->right);
            return leaf;
        }
    }
}
