#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
class BST
{
public:
    void inorder(node *root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            cout<<root->key<<" ";
            inorder(root->right);
        }
    }

    struct node *newNode(int item)
    {
        struct node *temp =  new node;
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    struct node* insert(struct node* node, int key)
    {
        if (node == NULL)
            return newNode(key);

        if (key < node->key)
            node->left  = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);


        return node;
    }

    struct node* iterative_search(node *node,int k)
    {
        while(node != NULL && node->key != k)
        {
            if(k < node->key)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return node;
    };

    struct node* minimum(node* x)
    {
        while(x->left != NULL)
        {
            x = x->left;
        }
        return x;
    };

};




int main()
{
    BST bst1;
    struct node *root = NULL;
    root = bst1.insert(root, 50);
    bst1.insert(root, 30);
    bst1.insert(root, 20);
    bst1.insert(root, 40);
    bst1.insert(root, 70);
    bst1.insert(root, 60);
    bst1.insert(root, 80);

    cout<<"Inorder: "<<endl;
    bst1.inorder(root);

    node* searchNode = bst1.iterative_search(root,80);
    if(searchNode != NULL)
        cout<<"\nFound "<<searchNode->key;
    else
        cout<<"\nNot Found!!";

    cout<<"\nMinimum is : "<<bst1.minimum(root)->key;


    return 0;
}

