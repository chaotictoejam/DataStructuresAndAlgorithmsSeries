// A simple C++ program to illustrate implementing a binary-tree
// To run:
//    g++ -o BinaryTree binary-tree.cpp (this commmand compiles the code)
//    ./BinaryTree (this runs the file we declared as the output)

#include <iostream>
#include <queue>

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
    Node* search(int value);
    void printLevelOrder();
    void printInorder();
    void printPreorder();
    void printPostorder();
    
   private:
    void destroy(Node* leaf);
    void insert(int value, Node* leaf);
    Node* search(int value, Node* leaf);
    Node* deleteNode(int value, Node* leaf);
    void printInorder(Node* leaf);
    void printPreorder(Node* leaf);
    void printPostorder(Node* leaf);
    Node* root;
};

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(Node* leaf) {
    if (leaf != NULL) {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int value) {
    if (root == NULL) {
        root = new Node;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else {
        insert(value, root);
    }
}

void BinaryTree::insert(int value, Node* leaf) {
    if (value < leaf->value) {
        if (leaf->left == NULL) {
            leaf->left = new Node;
            leaf->left->value = value;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        } else {
            insert(value, leaf->left);
        }
    } else {
        if (leaf->right == NULL) {
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

Node* BinaryTree::search(int value, Node* leaf) {
    if (leaf == NULL) {
        return NULL;
    } else {
        if (value == leaf->value) {
            return leaf;
        }
        if (value < leaf->value) {
            // Traverse down the left side of the tree
            return search(value, leaf->left);
        } else {
            // Traverse down the right side of the tree
            return search(value, leaf->right);
        }
    }
}

void BinaryTree::deleteNode(int value) {
    // The root could potentially change and therefore may need to be updated
    root = deleteNode(value, root);
}

Node* BinaryTree::deleteNode(int value, Node* leaf) {
    if (leaf == NULL) {
        return NULL;
    } else {
        if (value == leaf->value) {
            if (leaf->right == NULL) {
                // Node has only one child to the left
                Node* temp = leaf->left;
                delete leaf;
                return temp;
            } else if (leaf->left == NULL) {
                // Node has only one child to the right
                Node* temp = leaf->right;
                delete leaf;
                return temp;
            } else  // Node has both children (Deletion by merge)
            {
                // Find the right most child of the left subtree
                Node* succ = leaf->left;
                while (succ->right != NULL) {
                    succ = succ->right;
                }

                // Set the new succesors right subtree to the deleted node
                succ->right = leaf->right;

                delete leaf;
                return succ;
            }
        }
        // Recursion to find node
        if (value < leaf->value) {
            leaf->left = deleteNode(value, leaf->left);
            return leaf;
        } else {
            leaf->right = deleteNode(value, leaf->right);
            return leaf;
        }
    }
}

void BinaryTree::printLevelOrder() {
    if(root == NULL) {
        cout << "Tree is empty!" << endl;
    } else {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            cout << n->value << " ";
            if(n->left != NULL) {
                q.push(n->left);
            }
            if(n->right != NULL) {
                q.push(n->right);
            }
        }
        cout << endl;
    }
}

void BinaryTree::printInorder() {
    printInorder(root);
    cout << endl;
}

void BinaryTree::printInorder(Node* leaf) {
    if(leaf != NULL) {
        printInorder(leaf->left);
        cout << leaf->value << " ";
        printInorder(leaf->right);
    }
}

void BinaryTree::printPreorder() {
    printPreorder(root);
    cout << endl;
}

void BinaryTree::printPreorder(Node* leaf) {
    if(leaf != NULL) {
        cout << leaf->value << " ";
        printPreorder(leaf->left);
        printPreorder(leaf->right);
    }
}

void BinaryTree::printPostorder() {
    printPostorder(root);
    cout << endl;
}

void BinaryTree::printPostorder(Node* leaf) {
    if(leaf != NULL) {
        printPostorder(leaf->left);
        printPostorder(leaf->right);
        cout << leaf->value << " ";
    }
}

int main() {
    BinaryTree* tree = new BinaryTree();

    tree->printLevelOrder();
    
    tree->insert(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(1);
    tree->insert(4);
    tree->insert(6);
    tree->insert(9);

    tree->printLevelOrder();
    tree->printInorder();
    tree->printPreorder();
    tree->printPostorder();
}
