#include <iostream>
#include <stack>
using namespace std;

class node {
	public:
    int data;
    node* left;
    node* right;
    bool lthread; 
    bool rthread;
};

 node* createNode(int key) {
 	
    node* newNode = new node;
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = true;
    newNode->rthread = true;
    return newNode;
}

node* insertInThreadedTree(node* root, int key) {
    node* newNode = createNode(key);

    if (root == NULL) {
        root = newNode;
        return root;
    }

    node* temp = root;
    while (true) {
        if (key < temp->data) {
            if ( temp->lthread) {
                 newNode->left = temp->left;
                 newNode->right = temp;
                 temp->left = newNode;
                 temp->lthread = false;
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->rthread) {
                newNode->right = temp->right;
                newNode->left = temp;
                temp->right = newNode;
                temp->rthread = false;
                break;
            } else {
                temp = temp->right;
            }
        }
    }
    return root;
}

// Recursive inorder traversal

void inOrder(node* root) {
    if (root == NULL)
        return;
        
    if (!root->lthread)
        inOrder(root->left);
        
    cout << root->data << " ";
        
    if (!root->rthread)
        inOrder(root->right);
}

// Recursive preorder traversal
void preOrder(node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (!root->lthread)
        preOrder(root->left);
    if (!root->rthread)
        preOrder(root->right);
}
// Recursive postorder traversal
void postOrder(node* root) {
    if (root == NULL)
        return;
    if (!root->lthread)
        postOrder(root->left);
    if (!root->rthread)
        postOrder(root->right);
    cout << root->data << " ";
}
 node* inorderSuccessor(node* root)
    {
        // If rthread is set, we can quickly find
        if (root->rthread == true)
            return root->right;
 
        // Else return leftmost child of right subtree
        root = root->right;
        while (root->lthread == false)
            root = root->left;
        return root;
    }
    
// Non-recursive Inorder
    void inorder_non(node* root)
    {
        if (root == NULL)
            cout<<endl<<"\t Tree is empty";
 
        // Reach leftmost Node
        node* temp = root;
        while (temp->lthread == false)
            temp = temp->left;
 
        // One by one print successors
        //cout<<endl<<"\t Tree is as :-";
        while (temp != NULL) {
            cout<<" "<<temp->data;
            temp = inorderSuccessor(temp);
        }
}
//NON-Recusive Preorder
 void preorder_non(node *root)
    {
        node *temp;
        if(root==NULL)
        {
            cout<<"Tree is empty";
            return;
        }
        temp=root;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->lthread==false)
                temp=temp->left;
            else if(temp->rthread==false)
                temp=temp->right;
            else
            {
                while(temp!=NULL && temp->rthread==true)
                    temp=temp->right;    
                if(temp!=NULL)
                    temp=temp->right;   
            }
        }
    }
    //Non-Recursive postorder
    void postorder_non(node* root)
    {
        stack<node*> S1;
        stack<node*> S2;
        S1.push(root);
        while(!S1.empty())
        {
            S2.push(S1.top());
            node* temp=S1.top();
            S1.pop();
            if(temp->lthread==false) 
			S1.push(temp->left);
			
            if(temp->rthread==false) 
			S1.push(temp->right);
        }
        while(!S2.empty())
        {
            node* temp=S2.top();
            S2.pop();
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
   int main() 
   {
    node* root = NULL;
    int choice;
    int val;

    while (true) {
        cout << "\n1. Insert into threaded tree";
        cout << "\n2. Print Inorder Traversal";
        cout << "\n3. Print Preorder Traversal";
        cout << "\n4. Print Postorder Traversal";
        cout << "\n5. Print Non-Recursive Inorder Traversal";
        cout << "\n6. Print Non-Recursive Preorder Traversal";
        cout << "\n7. Print Non-Recursive Postorder Traversal";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insertInThreadedTree(root, val);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Non-Recursive Inorder Traversal: ";
                inorder_non(root);
                cout << endl;
                break;
            case 6:
                cout << "Non-Recursive Preorder Traversal: ";
                preorder_non(root);
                cout << endl;
                break; 
            case 7:
                cout << "Non-Recursive Postorder Traversal: ";
                postorder_non(root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting...";
                exit(0);
            default:
              cout << "Invalid choice!";  
        }
    }

    return 0;
}

