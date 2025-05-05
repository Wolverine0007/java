#include<iostream>
using namespace std;

class Node {
    public:
    int data, height;
    Node *left, *right;

    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};


int getHeight(Node* root){
    if(!root){
        return 0;
    }

    return root->height;
}


Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* childRight = child->right;
    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}


Node* leftRotation(Node* root){
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;


    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insertNode(Node* root, int value){
    if (!root)
        return new Node(value);

    if (value > root->data)
        root->right = insertNode(root->right, value);
    else if (value < root->data)
        root->left = insertNode(root->left, value);

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check balance
    int balance = getHeight(root->left) - getHeight(root->right);

    // LL
    if (balance > 1 && value < root->left->data)
        return rightRotation(root);

    // RR
    if (balance < -1 && value > root->right->data)
        return leftRotation(root);

    // LR
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;  // already balanced
}




void preorder(Node* root){
    if(!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void postorder(Node* root){
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


void nonRecursiveInorder(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

// Function to do non-recursive preorder traversal of AVL Tree
void nonRecursivePreorder(Node* root) {
    if (root == NULL)
        return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right)  s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

// Function to do non-recursive postorder traversal of AVL Tree
void nonRecursivePostorder(Node* root) {
    if (root == NULL)
        return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right)  s1.push(current->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main(){
    Node *root = NULL;

    cout << "Welcome to AVL Tree Program :)" << endl;

    int value;
    bool check = true;

    while(check){

        cout << "\n\t1. Insert Value\n";
        cout << "\t2. Preorder Recursive\n";
        cout << "\t3. Inorder Recursive\n";
        cout << "\t4. Postorder Recursive\n";
        cout << "\t5. Non recursive Preorder Recursive\n";
        cout << "\t6. Non recursive Inorder Recursive\n";
        cout << "\t7. Non recursive Postorder Recursive\n";
        cout << "\t-> ";
        int choice;
        cin >> choice;

        switch(choice){
            case 1:
            cout << "\tEnter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            break;

            case 2:
            cout << "\tPreorderTraversal: ";
            preorder(root);
            break;

            case 3:
            cout << "\tInorder Traversal: ";
            inorder(root);
            break;

            case 4:
            cout << "\tPostorder Traverasal: ";
            postorder(root);
            break;

            case 5:
            cout << "\tNon Recusive PreorderTraversal: ";
            preorder(root);
            break;

            case 6:
            cout << "\tNon Recusive Inorder Traversal: ";
            inorder(root);
            break;

            case 7:
            cout << "\tNon Recusive Postorder Traverasal: ";
            postorder(root);
            break;
            
        }

        cout << "\n\tDo You want to continue?(Y/N): ";
        char ch;
        cin >> ch;
        check = (ch == 'Y' || ch == 'y') ? true : false;
    }

    return 0;
}