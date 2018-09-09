#include<iostream>
using namespace std;
struct node
{
    int key;
    struct node *left,*right;
} *root;


class BST
{
public:
    node *root = NULL;
    void iterative_insert(int k)
    {
        node *temp = new node;
        temp->key = k;
        temp->left = temp->right = NULL;
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            node *cur = root;
            node *par = NULL;
            while(cur != NULL)
            {
                if(cur->key > k)
                {
                    par = cur;
                    cur = cur->left;
                    if(cur == NULL)
                    {
                        par->left = temp;
                    }
                    return;
                }
                else
                {
                    par = cur;
                    cur = cur->right;
                    if(cur == NULL)
                    {
                        par->right = temp;
                    }
                    return;
                }
            }
        }
    }

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
    bst1.iterative_insert(30);
    bst1.iterative_insert(20);
    bst1.iterative_insert(40);
    bst1.iterative_insert(70);
    bst1.iterative_insert(60);
    bst1.iterative_insert(80);

    cout<<"Inorder: "<<endl;
    //bst1.inorder(root);




}
